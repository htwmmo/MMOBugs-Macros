
|- ExplorerSubs.inc - By Fizz
|- Version 0.0.2
|- Started: 09/14/2020


| -------------------------------------------------------------------------------------
| SUB : Zones Check
| -------------------------------------------------------------------------------------
		
Sub travelToZone(string zoneName)
    /if (${Zone[${zoneName}].ID}) {
        /delay 1s
        /lazytravel ${Zone[${zoneName}].ShortName}
        /echo Traveling to ${Green}${Zone[${zoneName}]}
    }
/return
	

| -------------------------------------------------------------------------------------
| SUB : Check for GM's
| -------------------------------------------------------------------------------------

Sub GMCheck
/if (${Spawn[gm].ID}) {
  /beep
  /beep
  /echo GM entered the zone!
  /echo For safety reasons the macro is ending...
  /endmacro
}
/return

| -------------------------------------------------------------------------------------
| Event SUBs
| -------------------------------------------------------------------------------------

Sub Event_ZONE_BLOCKED(Line,strZoneName)
        /varset FailedToZone 1
        /doevents flush ZONE_BLOCKED
    /return
	
Sub Event_INSTANCE_NOT_READY
        /varset FailedToZone 1
        /doevents flush INSTANCE_NOT_READY
/return


Sub Event_PORTAL_ATTUNED
        /varset PortalAttuned 1
        /doevents flush PORTAL_ATTUNED
    /return

    
| -------------------------------------------------------------------------------------
| SUB: buildIllusionArray
| ------------------------------------------------------------------------------------- 
Sub buildIllusionArray
    /if (!${Defined[arrIllusionClickies]}) /declare arrIllusionClickies[20] string outer
    /varset arrIllusionClickies[1] Visage of Nillipus
    /varset arrIllusionClickies[2] Delightful Visage of the Answerer
    /varset arrIllusionClickies[3] Eyepiece of the Fancy Tinker
    /varset arrIllusionClickies[4] Mask of Tinkering
    /varset arrIllusionClickies[5] Miniature Eyepatch
    /varset arrIllusionClickies[6] Visage of the Tyrannosaurus
    /varset arrIllusionClickies[7] Guise of the Gilded Gnomework
    /varset arrIllusionClickies[8] Mask of the Grumpy Goblin
    /varset arrIllusionClickies[9] Polymorph Wand: Forest Fairy
    /varset arrIllusionClickies[10] Visage of the Frozen Goblin
    /varset arrIllusionClickies[11] Desiccated Halfling Mask
    /varset arrIllusionClickies[12] Besmirched Mask of Conception
    /varset arrIllusionClickies[13] Sootstained Shroud of Creation
    /varset arrIllusionClickies[14] Fairy Wing
    /varset arrIllusionClickies[15] Polymorph Wand: Simple Gnomework
    /varset arrIllusionClickies[16] Guise of the Deceiver
    /varset arrIllusionClickies[17] Mask of the Chetari
    /varset arrIllusionClickies[18] Oddtune, the Chaotic Minstrel
    /varset arrIllusionClickies[19] Woven Shadow Stone
    /varset arrIllusionClickies[20] Visage of the Primal Kerran
/return


| -------------------------------------------------------------------------------------
| SUB: castLevi
| ------------------------------------------------------------------------------------- 
Sub castLevi
    /declare levAttempts int         local       0
	/if (${Me.Levitating}) /return
	
	/if (${levAbility}) {
	    :leviMe
        /call checkAggro

        /varcalc levAttempts ${levAttempts}+1
		
        /if (${levAbility}==1) /alt act ${Me.AltAbility[Group Perfected Levitation]}
		/if (${levAbility}==2) /alt act ${Me.AltAbility[Perfected Dead Men Floating]}
		/if (${levAbility}==3) /alt act ${Me.AltAbility[Shauri's Sonorous Clouding]}
        /if (${levAbility}==4) /alt act ${Me.AltAbility[Perfected Levitation]}
        /if (${levAbility}==5) /alt act ${Me.AltAbility[Perfected Dead Man Floating]}
        /if (${levAbility}==6) /alt act ${Me.AltAbility[Bobbing Corse]}
        /if (${levAbility}==7) /alt act ${Me.AltAbility[Elemental Form: Air]}
        /if (${levAbility}==8) /alt act ${Me.AltAbility[Noteworthy Disguise: Blue Drake II]}
        /if (${levAbility}==9) /alt act ${Me.AltAbility[Divine Steed]}
        /if (${levAbility}==10) /alt act ${Me.AltAbility[Steed of Souls]}
		/delay 10s (${Me.Levitating})
		
		/if (${Me.Levitating}) /return
		/if (${levAttempts}<4) /goto :leviMe
	} 

    /varset levAttempts 0
    :useLevClickie
    /if (${FindItem[=${levClickie}].Name.Length} && ${FindItemCount[=${levClickie}]}) {
        /call checkAggro
		
        /while (${FindItem[=${levClickie}].TimerReady}) {
            /delay 1
        }
        /target clear
        /delay 2s !${Target.ID}
        /target ${Me.CleanName}
        /delay 2s ${Target.ID}
        /useitem ${levClickie}
        /delay 5 ${Window[CastingWindow].Open}
        /delay ${Math.Calc[${FindItem[=${levClickie}].CastTime}/100].Int} !${Me.Casting.ID}
        /if (${levClickie.Equal[Philter of Gulon's Impunity]}) /varset levPotionCount ${FindItemCount[=Philter of Gulon's Impunity]}
        /if (!${Me.Levitating} && (${levAttempts}<4)) {
            /varcalc levAttempts ${levAttempts}+1
            /goto :useLevClickie
        }
    }
    /if (!${levPotionCount} && !${Me.Levitating})  {
        /endmacro
    }
    /deletevar levAttempts
/return


| -------------------------------------------------------------------------------------
| SUB: cancelLevi
| ------------------------------------------------------------------------------------- 
Sub cancelLevi
    /if (!${Me.Levitating}) /return
    /declare intBuffSlot int local 1
    /declare intSDBuffSlot int local 1

    /for intBuffSlot 0 to 42
        /if (${Me.Buff[${intBuffSlot}].HasSPA[57]}) {
                /echo ${Yellow}Removing buff #${intBuffSlot}: \am ${Me.Buff[${intBuffSlot}]}
            /removebuff "${Me.Buff[${intBuffSlot}]}"
            /delay 2s !${Me.Buff[${intBuffSlot}].ID}
        }
    /next intBuffSlot
    /for intSDBuffSlot 0 to 30
        /if (${Me.Song[${intSDBuffSlot}].HasSPA[57]})  {
                /echo ${Yellow}Removing: \a-m ${Me.Song[${intBuffSlot}]}
            /removebuff "${Me.Song[${intSDBuffSlot}]}"
            /delay 2s !${Me.Song[${intBuffSlot}].ID}
        }
    /next intBuffSlot
    /deletevar intBuffSlot
    /deletevar intSDBuffSlot
/return

| -------------------------------------------------------------------------------------
| SUB: Invis Checker
| ------------------------------------------------------------------------------------- 
Sub Navigating

    /delay 5s ${Navigation.Active}
    /while (${Navigation.Active} && !${FailedToZone}) {
        /call checkAggro
        /if (${Me.Class.Name.Equal[Bard]}) /call castSelos
        /if (!${Me.Invis} && !${Select[${Zone.ID},96,202,203,344,152,150,151,345,187]} && !${InvisOff}) {
            /nav Pause
            /delay 2s !${Me.Moving}
            /delay 5s
            /echo Pausing, until we're invis.
            /call InvisMe
            /delay ${Me.Casting.CastTime.Float}s ${Me.Casting.ID}
            /if (${Me.Invis} && !${Select[${Zone.ID},96,202,203,344,152,150,151,345,187]} ) /echo We're Invisible again, lets move.
			/delay 5s
            /nav Pause
        }
        /delay 1
        /doevents
    }
/return


| -------------------------------------------------------------------------------------
| SUB: cancelSelos
| ------------------------------------------------------------------------------------- 
Sub cancelSelos
    /declare intBuffSlot int local 1
    /declare intSDBuffSlot int local 1

    /for intBuffSlot 0 to 42
        /if (${Me.Buff[${intBuffSlot}].HasSPA[3]}) {
                /echo ${Yellow}Removing buff #${intBuffSlot}: \am ${Me.Buff[${intBuffSlot}]}
            /removebuff "${Me.Buff[${intBuffSlot}]}"
            /delay 2s !${Me.Buff[${intBuffSlot}].ID}
        }
    /next intBuffSlot
    /for intSDBuffSlot 0 to 30
        /if (${Me.Song[${intSDBuffSlot}].HasSPA[3]})  {
                /echo ${Yellow}Removing: \a-m ${Me.Song[${intBuffSlot}]}
            /removebuff "${Me.Song[${intSDBuffSlot}]}"
            /delay 2s !${Me.Song[${intBuffSlot}].ID}
        }
    /next intBuffSlot
    /deletevar intBuffSlot
    /deletevar intSDBuffSlot
/return

| -------------------------------------------------------------------------------------
| SUB: castSelos
| ------------------------------------------------------------------------------------- 
Sub castSelos
/if (${Me.Buff[Selo's Accelerando].ID} || ${Me.Buff[Selo's Accelerato].ID}) {
/return
} else /if (${Me.AltAbilityReady[Selo's Sonata]}) {
/alt act ${Me.AltAbility[Selo's Sonata]}
}
/return

| -------------------------------------------------------------------------------------
| SUB: EqAtFront
| -------------------------------------------------------------------------------------
Sub EqAtFront
    /if (!${EverQuest.Foreground}) {
        /while (!${EverQuest.Foreground}) {
            /popup *** EQ MUST BE THE FOREGROUND APP FOR THIS ZONE ***
            /beep
            /delay 15
        }
        /call MQP foreground
    }
/return

| -------------------------------------------------------------------------------------
| SUB: DangerRoute
| -------------------------------------------------------------------------------------
Sub DangerRoute
    /if (!${EverQuest.Foreground}) {
        /while (!${EverQuest.Foreground}) {
            /popup *** Dangerous Route - Recommend Watching ***
            /beep
            /delay 15
        }
        /call MQP danger
    }
/return




| -------------------------------------------------------------------------------------
| SUB: killQuest (Name of quest)
| ------------------------------------------------------------------------------------- 
Sub killQuest(string taskname)
    /declare intTaskIndex   int   local 0
    /if (!${Window[TaskWND].Open}) 	{
									/echo ****Debug  Opening Task window
									/keypress CMD_TOGGLETASKWIN
									/delay 1s ${Window[TaskWND].Open}
									}

    /if (${Window[TaskWND].Open}) 	{
									/varset intTaskIndex ${Window[TaskWnd].Child[TASK_TaskList].List[${taskname},3]}
									/if (${intTaskIndex}) 	{
															/notify TaskWnd TASK_TaskList listselect ${intTaskIndex}
															/echo ****Debug  Removing task: \am ${Window[TaskWnd].Child[TASK_TaskList].List[${intTaskIndex},3]}
															/nomodkey /notify TaskWnd TASK_AbandonButton leftmouseup
															/delay 5 ${Window[ConfirmationDialogBox].Open}
															/if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
															/delay 5 !${Window[ConfirmationDialogBox].Open}
															/echo ****Debug  Closing Task Window
	} else {
			/echo ****Debug  No task found matching: ${taskname}
			}
    /while (${Window[TaskWND].Open}) 	{
										/delay 1
										/cleanup
										}
	} else 	{
			/echo ****Debug  Taskwnd didnt open, or something went wrong.
			}
/return


| -------------------------------------------------------------------------------------
| SUB: fatalError
| ------------------------------------------------------------------------------------- 
Sub fatalError(string strErrorIn)
    /error Fatal error occurred in ${Yellow}$strErrorIn. ${Teal}  Ending Macro.
    /endmacro 
/return

| -------------------------------------------------------------------------------------
| SUB: findIllusionClickie
| ------------------------------------------------------------------------------------- 
Sub findIllusionClickie

    /declare intCounter int         local       0
    /call buildIllusionArray
    /for intCounter 1 to ${arrIllusionClickies.Size}
        /if (${FindItemCount[=${arrIllusionClickies[${intCounter}]}]}) {
            /ini "${PotionIniFileName}" "General" "shrinkClickie" "${arrIllusionClickies[${intCounter}]}"
            /break
        }
    /next intCounter
	
    /if (!${FindItem[=${shrinkClickie}].Name.Length} && !${shrinkAbility}) {
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

    /if (${intLowestCT} < 10000000 ) {
        /echo Found new invis Clickie - Updating INI invisClickie = ${strClickieName}
        /if (${intClickieBagSlot}>-1) {
            |- Update the INI with the item name
            /ini "${PotionIniFileName}" "General" "invisClickie" "${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}"
            |- Update inviskClickie with item name
            /varset invisClickie ${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}
        } else {
            |- Update the INI with the item name
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
            |- Update the INI with the item name
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
    /declare intSlot int         	local       0
    /declare intBagSlot int         local       0
    /declare intClickieSlot 		int local 	-1
    /declare intClickieBagSlot 		int local 	-1
    /declare intLowestCT 			int local	1000000
    /declare strClickieName 		string local "Duck"

    /for intSlot 0 to 22
	
         /if (${Me.Inventory[${intSlot}].ID} && ${Me.Inventory[${intSlot}].EffectType.Find[Click]} && ${Me.Inventory[${intSlot}].Spell.HasSPA[89]} && !${Me.Inventory[${intSlot}].Name.Find[Metamorph]}) {
            |- Is the cast time lower than the current best option?
            /if ((${Me.Inventory[${intSlot}].CastTime.Raw} < ${intLowestCT}) && (${Me.Inventory[${intSlot}].Name.NotEqual[Philter of the Ant]}) && (${Me.Inventory[${intSlot}].Name.NotEqual[Erollisi's Boundless Heart Hare]}) && (${Me.Inventory[${intSlot}].Name.NotEqual[Anizok's Minimizing Device]}) ) {

                /varset intLowestCT ${Me.Inventory[${intSlot}].CastTime.Raw}
                /varset intClickieSlot ${intSlot}
                /varset strClickieName ${Me.Inventory[${intSlot}].Name}
            }
        }
    /next intSlot
    
    /for intSlot 23 to 32
        /if (${Me.Inventory[${intSlot}].Container}) {
            /for intBagSlot 1 to ${Me.Inventory[${intSlot}].Container}
                /if (${Me.Inventory[${intSlot}].Item[${intBagSlot}].ID} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].EffectType.Find[Click]} && ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Spell.HasSPA[89]} && !${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.Find[Metamorph]}) {
                    |- Is the cast time lower than the current best option?
                    /if ((${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw} < ${intLowestCT}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Philter of the Ant]}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Erollisi's Boundless Heart Hare]}) && (${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name.NotEqual[Anizok's Minimizing Device]}) ) {

                        /varset intLowestCT ${Me.Inventory[${intSlot}].Item[${intBagSlot}].CastTime.Raw}
                        /varset intClickieSlot ${intSlot}
                        /varset intClickieBagSlot ${intBagSlot}
                        /varset strClickieName ${Me.Inventory[${intSlot}].Item[${intBagSlot}].Name}
                    }
                }
            /next intBagSlot
        }
    /next intSlot
    
    /if (${intLowestCT} < 1000000 ) {
	
        /ini "${PotionIniFileName}" "General" "shrinkClickie" "${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}"
        |- Update shrinkClickie with item name
        /varset shrinkClickie ${Me.Inventory[${intClickieSlot}].Item[${intClickieBagSlot}].Name}
    } else {
        /call findIllusionClickie
    }
/return

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

|-------------------------------------------------------------|
| Sub loadPlugin
|-------------------------------------------------------------|
Sub loadPlugin(string pluginname,bool blnSilent)
    /if (!${Bool[${Plugin[${pluginname}].Name.Equal[${pluginname}]}]}) {
        /if (!${blnSilent}) /echo ${Red}** Warning${Teal} ${pluginname} wasn't loaded, ${Green} attempting to load ${pluginname}!
        /plugin ${pluginname} noauto
    }
    /delay 8s ${Bool[${Plugin[${pluginname}].Name.Equal[${pluginname}]}]}
    /if (!${Bool[${Plugin[${pluginname}].Name.Equal[${pluginname}]}]}) {
        /echo ${Red}error Could not load required plugin ${pluginname}, ending macro.
        /endmacro
    }
/return

|-------------------------------------------------------------|
| Sub unloadPlugin
|-------------------------------------------------------------|
Sub unloadPlugin(string pluginname,bool blnSilent)
    /if (${Bool[${Plugin[${pluginname}].Name.Equal[${pluginname}]}]}) {
        /if (!${blnSilent}) /echo ${Red}** Warning${Teal} ${pluginname} is not compatible with this macro, ${Green} attempting to unload ${pluginname}!
        /plugin ${pluginname} unload noauto
    }
    /delay 8s !${Bool[${Plugin[${pluginname}].Name.Equal[${pluginname}]}]}
    /if (${Bool[${Plugin[${pluginname}].Name.Equal[${pluginname}]}]}) {
        /echo ${Red}error Could not unload incompatible plugin ${pluginname}, ending macro.
        /endmacro
    }
/return


| -------------------------------------------------------------------------------------
| SUB: Pause Macro
| -------------------------------------------------------------------------------------
Sub MQP (string cMessage)
    /declare navWasActive bool local 0
    /if (${Navigation.Active}) /varset navWasActive 1
    /if (${navWasActive}) 	{ 
							/nav pause
							/echo ${Black}*****  ${Red}MACRO and NAVIGATION are PAUSED ${Black}*****
        
    } else 					{
							/echo ${Orange}************  ${Red}MACRO is PAUSED ${Orange}************
    }
    |- Custom messages
    /if (${cMessage.Length}) 	{
								/if (${cMessage.Equal[foreground]}) /echo ${Teal}Pathing not great here. ${Green}EQ ${Red}**MUST**${Teal} be at the foreground for this zone.
								/if (${cMessage.Equal[danger]}) /echo ${Teal}Mobs may see through invis, it is suggested to watch this route. Use /nav pause & /mqp to take control.
								/if (${cMessage.Equal[stuck]}) /echo Please get us back to the Plane of Knowledge.
								/if (${cMessage.Equal[ldonGrpLeader]}) /echo ${Yellow}We must be group leader to get LDoN Adventure.
								/if (${cMessage.Equal[ldonNeed3]}) /echo ${Yellow}You need at least 3 group members for LDoN Adventure.
								/if (${cMessage.Equal[needMoney]}) /echo You need more money to proceed.			
								}
    /if (${navWasActive}) 	{
							/echo ${Orange}*****  ${Red}MACRO and NAVIGATION are PAUSED  ${Orange}*****
							/echo Type ('/mqp off') when you are ready to proceed.
							/echo Also unpause the navigation ('/nav pause') when you are ready to proceed.
							
    } else 					{
							/echo ${Orange}************  ${Red}MACRO is PAUSED  ${Orange}************
							/echo Type ('/mqp off') when you are ready to proceed.
							}
    /beep
    /beep
    /beep
    /mqp on
/return


| -------------------------------------------------------------------------------------
| Sub: rogueInvis
| -------------------------------------------------------------------------------------
Sub rogueInvis
    |Check to see if we are sneaking and hiding
    |If I'm already SoS, we can exit this sub early
 	/if (!${Me.Sneaking} && !${Me.Invis}) /echo Now you see me... Now you don't!
    :checkagain
	/if (${Me.Sneaking} && ${Me.Invis}) /return
	/if (${Me.Sneaking}) {
		/echo Hiding
		/doability Hide
	} else {
		/doability Sneak
		/delay 3s ${Me.Sneaking}
		/echo Sneaking
	}
	/goto :checkagain
/return


| -------------------------------------------------------------------------------------
| SUB: std_target
| -------------------------------------------------------------------------------------
Sub std_target

    /if ( ${Spawn[${Param0}].Targetable} && ${Target.ID}!=${Spawn[${Param0}].ID} ) {
        /target id ${Spawn[${Param0}].ID}
        /delay 20 ( ${Target.ID} || ${Target.ID}==${Spawn[${Param0}].ID} )
    }
/return ${If[${Target.ID}==${Spawn[${Param0}].ID} && ${Bool[${Target.ID}]},TRUE,FALSE]}



|-------------------------------------------------------------------------------------------------
| Buy Stuff - /call BuyItem "item name" Qty  (code by Chatwiththisname)
|-------------------------------------------------------------------------------------------------

Sub BuyItem(string itemToGet,int amount)
    /echo ${Yellow}Buying ${Purple}${itemToGet} ${White}x${Green} ${amount}
    /declare startingCount int local ${FindItemCount[${itemToGet}]}
        /if (${Target.ID}) {
							/if (!${Window[MerchantWnd].Open}) {
																/invoke ${Target.RightClick}
																}
							}
        /delay 10s ${Window[MerchantWnd].Child[MW_ItemList].List[${itemToGet},2]}
        /notify MerchantWnd MW_ItemList listselect ${Window[MerchantWnd].Child[MW_ItemList].List[${itemToGet},2]}
        /delay 5
        /nomodkey /notify MerchantWnd MW_Buy_Button leftmouseup
        /delay 1s ${Window[QuantityWnd].Open}
        /if (${Window[QuantityWnd].Open}) {
            /notify QuantityWnd QTYW_Slider newvalue ${amount}
            /notify QuantityWnd QTYW_Accept_Button leftmouseup
        }
        /delay 5s ${FindItemCount[${itemToGet}]}>${startingCount}
    }
/return



| -------------------------------------------------------------------------------------
| SUB: Evac - shortcut route to return to PoK
| -------------------------------------------------------------------------------------    
Sub Evac
    /declare intCounter         int     local       0
	
 :Evacloop
    /call checkAggro
	
	|- Guild Lobby
    /if (${Zone.ShortName.Equal[guildlobby]}) 	{
												/lazyfind on
												/lazytravel poknowledge
												/delay 3s
												}
 	
    /if ((${blnHasStein}) && (!${FindItem[=Drunkard's Stein].TimerReady}) ) {
        /useitem "Drunkard's Stein"
    } else /if (${blnHasBrick} && (!${FindItem[=Brick of Knowledge].TimerReady})) {
        /useitem "Brick of Knowledge"
    } else /if (${Me.AltAbilityReady[Throne of Heroes]}) {
        /alt act ${Me.AltAbility[Throne of Heroes]}
    } else /if ((${Me.Class.PureCaster}) && (${Me.AltAbilityReady[Gate]})) {
        /alt act ${Me.AltAbility[Gate]}
    } else /if ((${gatePotionCount}>0) && (!${FindItem[=Philter of Major Translocation].TimerReady}) ) {
        /useitem "Philter of Major Translocation"
    } else /if (${intBulwarkCount} && !${FindItem[=Bulwark of Many Portals].TimerReady}) {
        /if (${FindItem[=Bulwark of Many Portals].Charges}>0) {
            /useitem "Bulwark of Many Portals"
        } else {
            /itemnotify in pack${Math.Calc[${FindItem[=Bulwark of Many Portals].ItemSlot}-22].Int} ${Math.Calc[${FindItem[=Bulwark of Many Portals].ItemSlot2}+1].Int} leftmouseup
            /delay 2s ${Cursor.ID}==${FindItem[=Bulwark of Many Portals].ID}
            /destroy
            /delay 2s !${Cursor.ID}
            /varset intBulwarkCount ${FindItemCount[=Bulwark of Many Portals]}
            /goto :Evacloop
        }
    } else /if ((${intEthBrewCount}>0) && (!${FindItem[=Ethernere Travel Brew].TimerReady}) ) {
        /useitem "Ethernere Travel Brew"
    } else /if ((${blnHasBinden}) && (!${FindItem[=The Binden Concerrentia].TimerReady}) && ${FindItemCount[=Quintessence of Knowledge]} ) {
        /useitem "The Binden Concerrentia"
    } else /if ((${blnHasFabledBinden}) && (!${FindItem[=The Fabled Binden Concerrentiae].TimerReady}) && ${FindItemCount[=Quintessence of Knowledge]} ) {
        /useitem "The Fabled Binden Concerrentiae"
    } else {
        /beep
        /echo ${Teal}It appears our evac options haven't refreshed yet.
        /call MQP stuck
        /goto :Evacloop
    }

    |- Cast Delay
    /delay 5 ${Window[CastingWindow].Open}
    /delay ${Me.Casting.CastTime.Float}s !${Me.Casting.ID}
    /while ((${Zone.ShortName.NotEqual[poknowledge]} && ${Zone.ShortName.NotEqual[guildlobby]})) {
        /delay 1s
        /doevents
        /varcalc intCounter ${intCounter}+1
        /if (${intCounter}>44) {
            /varset intCounter 0
            /echo Evac appears to have been interrupted. Let me try that again.
            /goto :Evacloop
        }
	}
    /varset gatePotionCount ${FindItemCount[=Philter of Major Translocation]}
    /varset intEthBrewCount ${FindItemCount[=Ethernere Travel Brew]}
    /delay 2s

    /if (${Zone.ShortName.Equal[guildlobby]}) 	{
												/lazytravel poknowledge
												/delay 3s
												}
/return

| -------------------------------------------------------------------------------------
| SUB: killQuest (Name of quest)
| ------------------------------------------------------------------------------------- 
Sub killQuest(string taskname)
    /declare intTaskIndex   int   local 0
    /if (!${Window[TaskWND].Open}) {
        /echo Opening Task window
        /keypress CMD_TOGGLETASKWIN
        /delay 1s ${Window[TaskWND].Open}
    }

    /if (${Window[TaskWND].Open}) {
        /varset intTaskIndex ${Window[TaskWnd].Child[TASK_TaskList].List[${taskname},3]}
        /if (${intTaskIndex}) {
            /notify TaskWnd TASK_TaskList listselect ${intTaskIndex}
            /echo Removing task: \am ${Window[TaskWnd].Child[TASK_TaskList].List[${intTaskIndex},3]}
            /nomodkey /notify TaskWnd TASK_AbandonButton leftmouseup
            /delay 5 ${Window[ConfirmationDialogBox].Open}
            /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
            /delay 5 !${Window[ConfirmationDialogBox].Open}
            /echo Closing Task Window
        } else {
            /echo No task found matching: ${taskname}
        }
        /while (${Window[TaskWND].Open}) {
            /delay 1
            /cleanup
        }
    } else {
    /echo Taskwnd didnt open, or something went wrong.
    }
/return

| -------------------------------------------------------------------------------------
| SUB: Completed
| -------------------------------------------------------------------------------------    
Sub Completed
    /declare intCounter         int     local       0
	/varset completed 1
	
 :Evacloop
    /call checkAggro
	
	|- Guild Lobby
    /if (${Zone.ShortName.Equal[guildlobby]}) 	{
												/lazytravel poknowledge
												/delay 3s
												/lazyfind off
												}
 	
    /if ((${blnHasStein}) && (!${FindItem[=Drunkard's Stein].TimerReady}) ) {
        /useitem "Drunkard's Stein"
    } else /if (${blnHasBrick} && (!${FindItem[=Brick of Knowledge].TimerReady})) {
        /useitem "Brick of Knowledge"
    } else /if (${Me.AltAbilityReady[Throne of Heroes]}) {
        /alt act ${Me.AltAbility[Throne of Heroes]}
    } else /if ((${Me.Class.PureCaster}) && (${Me.AltAbilityReady[Gate]})) {
        /alt act ${Me.AltAbility[Gate]}
    } else /if ((${gatePotionCount}>0) && (!${FindItem[=Philter of Major Translocation].TimerReady}) ) {
        /useitem "Philter of Major Translocation"
    } else /if (${intBulwarkCount} && !${FindItem[=Bulwark of Many Portals].TimerReady}) {
        /if (${FindItem[=Bulwark of Many Portals].Charges}>0) {
            /useitem "Bulwark of Many Portals"
        } else {
            /itemnotify in pack${Math.Calc[${FindItem[=Bulwark of Many Portals].ItemSlot}-22].Int} ${Math.Calc[${FindItem[=Bulwark of Many Portals].ItemSlot2}+1].Int} leftmouseup
            /delay 2s ${Cursor.ID}==${FindItem[=Bulwark of Many Portals].ID}
            /destroy
            /delay 2s !${Cursor.ID}
            /varset intBulwarkCount ${FindItemCount[=Bulwark of Many Portals]}
            /goto :Evacloop
        }
    } else /if ((${intEthBrewCount}>0) && (!${FindItem[=Ethernere Travel Brew].TimerReady}) ) {
        /useitem "Ethernere Travel Brew"
    } else /if ((${blnHasBinden}) && (!${FindItem[=The Binden Concerrentia].TimerReady}) && ${FindItemCount[=Quintessence of Knowledge]} ) {
        /useitem "The Binden Concerrentia"
    } else /if ((${blnHasFabledBinden}) && (!${FindItem[=The Fabled Binden Concerrentiae].TimerReady}) && ${FindItemCount[=Quintessence of Knowledge]} ) {
        /useitem "The Fabled Binden Concerrentiae"
    } else {
        /beep
        /echo ${Teal}It appears our evac options haven't refreshed yet.
        /call MQP stuck
        /goto :Evacloop
    }

    |- Cast Delay
    /delay 5 ${Window[CastingWindow].Open}
    /delay ${Me.Casting.CastTime.Float}s !${Me.Casting.ID}
    /while ((${Zone.ShortName.NotEqual[poknowledge]} && ${Zone.ShortName.NotEqual[guildlobby]})) {
        /delay 1s
        /doevents
        /varcalc intCounter ${intCounter}+1
        /if (${intCounter}>44) {
            /varset intCounter 0
            /echo Evac appears to have been interrupted. Let me try that again.
            /goto :Evacloop
        }
	}
    /varset gatePotionCount ${FindItemCount[=Philter of Major Translocation]}
    /varset intEthBrewCount ${FindItemCount[=Ethernere Travel Brew]}
    /delay 2s

    /if (${Zone.ShortName.Equal[guildlobby]}) 	{
												/lazytravel poknowledge
												/delay 3s
												/lazyfind off
												}

    /if (${Zone.ShortName.Equal[poknowledge]}) 	{
												/lazyfind off
												}
/return

