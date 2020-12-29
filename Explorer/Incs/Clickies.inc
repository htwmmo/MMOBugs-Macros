
| -------------------------------------------------------------------------------------
| SUB: inputItemSearch
| ------------------------------------------------------------------------------------- 
Sub inputItemSearch(InStr)
	/declare char string local
	/declare i int local
	/for i 1 to ${InStr.Length}
		/varset char ${InStr.Mid[${i},1]}
		/if (!${char.Length}) {
			/nomodkey /keypress Space chat
		} else {
			/if (${char.Left[1].Equal[(]}) /return
			/if (${char.Left[1].Equal[)]}) /return
			/nomodkey /keypress ${char} chat
		}
	/next i
/return

| -------------------------------------------------------------------------------------
| SUB: findIllusionClickie
| ------------------------------------------------------------------------------------- 
Sub findIllusionClickie
    |- We're going to check for Illusion clickies that might be used in place of a shrink clickie first
    /declare intCounter int         local       0
    /call buildIllusionArray
    |/invisMe Scanning inventory for illusion clickes to use as shrink sources.
    /for intCounter 1 to ${arrIllusionClickies.Size}
        |/invisMe Searching for Illusion Clickie #${intCounter}: \ag${arrIllusionClickies}\ax
        /if (${FindItemCount[=${arrIllusionClickies[${intCounter}]}]}) {
            /Echo Found clickie!
            /ini "${PotionIniFileName}" "General" "shrinkClickie" "${arrIllusionClickies[${intCounter}]}"
            /break
        }
    /next intCounter
    |- We don't have a Shrink AA or clickie.  But we have potions!!!!
    /if (!${FindItem[=${shrinkClickie}].Name.Length} && !${shrinkAbility}) {
            /echo \aySetting Shrink to use Potions.
            /ini "${PotionIniFileName}" "General" "shrinkClickie" "Philter of the Ant"
            /varset shrinkClickie ${Ini[${PotionIniFileName},General,shrinkClickie]}
    }
/return

| -------------------------------------------------------------------------------------
| SUB: findInvisClickies
| ------------------------------------------------------------------------------------- 
Sub findInvisClickies
    /declare intSlot int         local       0
    /declare intBagSlot int         local       0
    /declare intClickieSlot int local -1
    /declare intClickie2Slot int local -1
    /declare intClickieBagSlot int local -1
    /declare intClickie2BagSlot int local -1
    /declare intLowestCT int local 10000000
    /declare int2ndLowestCT int local 10000000
    /declare strClickieName string local "Ghost"
    /declare strClickie2Name string local "Ghost"
    |- For each worn item slot
    /for intSlot 0 to 22
        |- Does the item in this slot have a click-Shrink effect?
        /if (${Me.Inventory[${intSlot}].ID} && ${Me.Inventory[${intSlot}].EffectType.Find[Click]} && (${Me.Inventory[${intSlot}].Spell.HasSPA[12]} || ${Me.Inventory[${intSlot}].Spell.HasSPA[314]} )) {
            |- Is the cast time lower than the current best option?
            /if (${Me.Inventory[${intSlot}].CastTime.Raw} < ${intLowestCT} && ${Me.Inventory[${intSlot}].Name.NotEqual[Cloudy Potion]}) {
                |- Move current discovered clickie to clickie2
                /varset int2ndLowestCT intLowestCT
                /varset intClickie2Slot intClickieSlot
                /varset strClickie2Name strClickieName
                |- Update Cast time, intClickieSlot, and strClickieName
                /varset intLowestCT ${Me.Inventory[${intSlot}].CastTime.Raw}
                /varset intClickieSlot ${intSlot}
                /varset strClickieName ${Me.Inventory[${intSlot}].Name}
            } else /if (${Me.Inventory[${intSlot}].CastTime.Raw} < ${int2ndLowestCT} && ${Me.Inventory[${intSlot}].Name.NotEqual[Cloudy Potion]}) {
                |- Update Cast time, intClickieSlot, and strClickieName
                /varset int2ndLowestCT ${Me.Inventory[${intSlot}].CastTime.Raw}
                /varset intClickie2Slot ${intSlot}
                /varset strClickie2Name ${Me.Inventory[${intSlot}].Name}
            }
        }
    /next intSlot

    |- For each Inventory Slot
    /for intSlot 23 to 32
        /if (${Me.Inventory[${intSlot}].Container}) {
            /for intBagSlot 1 to ${Me.Inventory[${intSlot}].Container}
                /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].ID} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].EffectType.Find[Click]} && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[12]} || ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[314]})) {
                    |- Is the cast time lower than the current best option?
                  /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime} < ${intLowestCT} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Cloudy Potion]}) {
                        |- Move current discovered clickie to clickie2
                        /if (${strClickieName.NotEqual[Ghost]}) {
                            /varset int2ndLowestCT ${intLowestCT}
                            /varset intClickie2Slot ${intClickieSlot}
                            /varset intClickie2BagSlot ${intClickieBagSlot}
                            /varset strClickie2Name ${strClickieName}
                        }
                        |- Update Cast time, intClickieSlot, and strClickieName
                        /varset intLowestCT ${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw}
                        /varset intClickieSlot ${intSlot}
                        /varset intClickieBagSlot ${intBagSlot}
                        /varset strClickieName ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name}
                    } else /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime} < ${int2ndLowestCT} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Cloudy Potion]}) {
                        |- Update Cast time, intClickieSlot, and strClickieName
                        /varset int2ndLowestCT ${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw}
                        /varset intClickie2Slot ${intSlot}
                        /varset intClickie2BagSlot ${intBagSlot}
                        /varset strClickie2Name ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name}
                    }
                }
            /next intBagSlot
        }
    /next intSlot
    
    |- Did we find a clickie?
    /if (${intLowestCT} < 10000000 ) {
        /echo Found new invis Clickie - Updating INI invisClickie = ${strClickieName}
        /if (${intClickieBagSlot}>-1) {
            |- Update INI
            /ini "${PotionIniFileName}" "General" "invisClickie" "${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}"
            |- Update inviskClickie with item name
            /varset invisClickie ${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}
        } else {
            |- Update INI
            /ini "${PotionIniFileName}" "General" "invisClickie" "${Me.Inventory[${intClickieSlot}].Name}"
            |- Update invisClickie with item name
            /varset invisClickie ${Me.Inventory[${intClickieSlot}].Name}
        }

    } else {
        /echo No invis clickie or AA was found.  But we can use cloudy potions.  Storing the setting in my INI file.
        /ini "${PotionIniFileName}" "General" "invisClickie" "Cloudy Potion"
    }
    |- Did we find a second clickie?
    /if (${int2ndLowestCT} < 10000000 ) {
        /echo Found new invis Clickie - Updating INI invisClickie2 = ${strClickie2Name}
        /if (${intClickie2BagSlot}>-1) {
            |- Update INI 
            /ini "${PotionIniFileName}" "General" "invisClickie2" "${Me.Inventory[${intClickie2Slot}].Item[${intClickie2BagSlot}].Name}"
            |- Update invisClickie2 with item name
            /varset invisClickie2 ${Me.Inventory[${intClickie2Slot}].Item[${intClickie2BagSlot}].Name}
        } else {
            |- Update the INI with the item name
            /ini "${PotionIniFileName}" "General" "invisClickie2" "${Me.Inventory[${intClickie2Slot}].Name}"
            |- Update invisClickie2 with item name
            /varset invisClickie2 ${Me.Inventory[${intClickie2Slot}].Name}
        }

    } else {
                /ini "${PotionIniFileName}" "General" "invisClickie2" "Cloudy Potion"
    }
    /deletevar intSlot
    /deletevar intBagSlot
    /deletevar intClickieSlot
    /deletevar intClickie2Slot
    /deletevar intClickieBagSlot
    /deletevar intClickie2BagSlot
    /deletevar intLowestCT
    /deletevar int2ndLowestCT
    /deletevar strClickieName
    /deletevar strClickie2Name
/return

| -------------------------------------------------------------------------------------
| SUB: findIVUClickies
| ------------------------------------------------------------------------------------- 
Sub findIVUClickies
    /declare intSlot int         local       0
    /declare intBagSlot int         local       0
    /declare intClickieSlot int local -1
    /declare intClickieBagSlot int local -1
    /declare intLowestCT int local 1000000
    /declare strClickieName string local "Duck"

    |- For each worn item slot
    /for intSlot 0 to 22
        |- Does the item in this slot have a click-IVU effect?
         /if (${Me.Inventory[${intSlot}].ID} && ${Me.Inventory[${intSlot}].EffectType.Find[Click]} && (${Me.Inventory[${intSlot}].Spell.HasSPA[28]} || ${Me.Inventory[${intSlot}].Spell.HasSPA[315]})) {
            |- Is the cast time lower than the current best option?
            /if (${Me.Inventory[${intSlot}].CastTime.Raw} < $intLowestCT) {
                |- Update Cast time, intClickieSlot, and strClickieName
                /varset intLowestCT ${Me.Inventory[${intSlot}].CastTime.Raw}
                /varset intClickieSlot ${intSlot}
                /varset strClickieName ${Me.Inventory[${intSlot}].Name}
            }
        }
    /next intSlot
    
    |- For each Inventory Slot
    /for intSlot 23 to 32
        /if (${Me.Inventory[${intSlot}].Container}) {
            /for intBagSlot 1 to ${Me.Inventory[${intSlot}].Container}
                /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].ID} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].EffectType.Find[Click]} && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[28]} || ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[315]}) && !${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.Find[Metamorph]}) {
                    |- Is the cast time lower than the current best option?
                    /if ((${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw} < ${intLowestCT}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Philter of Unlife Awareness]}) ) {
                        |- Update Cast time, intClickieSlot, and strClickieName
                        /varset intLowestCT ${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw}
                        /varset intClickieSlot ${intSlot}
                        /varset intClickieBagSlot ${intBagSlot}
                        /varset strClickieName ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name}
                    }					
                }
            /next intBagSlot
        }
    /next intSlot
    
    |- Did we find a clickie?
    /if (${intLowestCT} < 1000000 ) {
        |- Update the INI with the item name
        /ini "${PotionIniFileName}" "General" "ivuClickie" "${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}"
        |- Update ivuClickie with item name
        /varset ivuClickie ${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}
    } else {
        /echo No IVU clickie or AA was found.  But we can use potions.  Storing the setting in my INI file.
        /ini "${PotionIniFileName}" "General" "ivuClickie" "Philter of Unlife Awareness"
    }
/return


| -------------------------------------------------------------------------------------
| SUB: findLevClickie
| ------------------------------------------------------------------------------------- 
Sub findLevClickie
    /declare intSlot int         local       0
    /declare intBagSlot int         local       0
    /declare intClickieSlot int local -1
    /declare intClickieBagSlot int local -1
    /declare intLowestCT int local 1000000
    /declare strClickieName string local "Duck"

    |- For each worn item slot
    /for intSlot 0 to 22
        |- Does the item in this slot have a click-Lev effect?
         /if (${Me.Inventory[${intSlot}].ID} && ${Me.Inventory[${intSlot}].EffectType.Find[Click]} && ${Me.Inventory[${intSlot}].Spell.HasSPA[57]} && ${Me.Inventory[${intSlot}].Name.Find[Metamorph]}) {
            |- Is the cast time lower than the current best option?
            /if (${Me.Inventory[${intSlot}].CastTime.Raw} < $intLowestCT) {
                |- Update Cast time, intClickieSlot, and strClickieName
                /varset intLowestCT ${Me.Inventory[${intSlot}].CastTime.Raw}
                /varset intClickieSlot ${intSlot}
                /varset strClickieName ${Me.Inventory[${intSlot}].Name}
            }
        }
    /next intSlot
    
    |- For each Inventory Slot
    /for intSlot 23 to 32
        /if (${Me.Inventory[${intSlot}].Container}) {
            /for intBagSlot 1 to ${Me.Inventory[${intSlot}].Container}
                /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].ID} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].EffectType.Find[Click]} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[57]} && !${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.Find[Metamorph]}) {
                    |- Is the cast time lower than the current best option?
                    /if ((${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw} < ${intLowestCT}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Philter of Gulon's Impunity]}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Whirligig Flyer Control Device]}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Steed of Souls]})  && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Snow Griffin Saddle]})) {
                        |- Update Cast time, intClickieSlot, and strClickieName
                        /varset intLowestCT ${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw}
                        /varset intClickieSlot ${intSlot}
                        /varset intClickieBagSlot ${intBagSlot}
                        /varset strClickieName ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name}
                    }					
                }
            /next intBagSlot
        }
    /next intSlot
    
    |- Did we find a clickie?
    /if (${intLowestCT} < 1000000 ) {
        |- Update the INI with the item name
        /ini "${PotionIniFileName}" "General" "levClickie" "${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}"
        |- Update levClickie with item name
        /varset levClickie ${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}
    } else {
        /echo No lev clickie or AA was found.  But we can use potions.  Storing the setting in my INI file.
        /ini "${PotionIniFileName}" "General" "levClickie" "Philter of Gulon's Impunity"
    }
/return


| -------------------------------------------------------------------------------------
| SUB: findShrinkClickie
| ------------------------------------------------------------------------------------- 
Sub findShrinkClickie
    /declare intSlot int         local       0
    /declare intBagSlot int         local       0
    /declare intClickieSlot int local -1
    /declare intClickieBagSlot int local -1
    /declare intLowestCT int local 1000000
    /declare strClickieName string local "Duck"

    |- For each worn item slot
    /for intSlot 0 to 22
        |- Does the item in this slot have a click-Shrink effect?
         /if (${Me.Inventory[${intSlot}].ID} && ${Me.Inventory[${intSlot}].EffectType.Find[Click]} && ${Me.Inventory[${intSlot}].Spell.HasSPA[89]} && !${Me.Inventory[${intSlot}].Name.Find[Metamorph]}) {
            |- Is the cast time lower than the current best option?
            /if ((${Me.Inventory[${intSlot}].CastTime.Raw} < ${intLowestCT}) && (${Me.Inventory[${intSlot}].Name.NotEqual[Philter of the Ant]}) && (${Me.Inventory[${intSlot}].Name.NotEqual[Erollisi's Boundless Heart Hare]}) && (${Me.Inventory[${intSlot}].Name.NotEqual[Anizok's Minimizing Device]}) ) {
                |- Update Cast time, intClickieSlot, and strClickieName
                /varset intLowestCT ${Me.Inventory[${intSlot}].CastTime.Raw}
                /varset intClickieSlot ${intSlot}
                /varset strClickieName ${Me.Inventory[${intSlot}].Name}
            }
        }
    /next intSlot
    
    |- For each Inventory Slot
    /for intSlot 23 to 32
        /if (${Me.Inventory[${intSlot}].Container}) {
            /for intBagSlot 1 to ${Me.Inventory[${intSlot}].Container}
                /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].ID} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].EffectType.Find[Click]} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[89]} && !${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.Find[Metamorph]}) {
                    |- Is the cast time lower than the current best option?
                    /if ((${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw} < ${intLowestCT}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Philter of the Ant]}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Erollisi's Boundless Heart Hare]}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Anizok's Minimizing Device]}) ) {
                        |- Update Cast time, intClickieSlot, and strClickieName
                        /varset intLowestCT ${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw}
                        /varset intClickieSlot ${intSlot}
                        /varset intClickieBagSlot ${intBagSlot}
                        /varset strClickieName ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name}
                    }
                }
            /next intBagSlot
        }
    /next intSlot
    
    |- Did we find a clickie?
    /if (${intLowestCT} < 1000000 ) {
        |- Update the INI with the item name
        /ini "${PotionIniFileName}" "General" "shrinkClickie" "${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}"
        |- Update shrinkClickie with item name
        /varset shrinkClickie ${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}
    } else {
        /call findIllusionClickie
    }
/return
