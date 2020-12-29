
| -------------------------------------------------------------------------------------
| SUB: invisMe
| ------------------------------------------------------------------------------------- 
Sub invisMe(string specialRequest)

	/if (${Me.Invis}) /return alreadyInvis
    /if (${InvisOff}) {
        /echo I'm out of invis potions.  I'm skipping invis'ing myself.
        /return outOfPotions
    }

	/declare invisAttempts int         local       0

    :MakeMeInvis
    /call checkAggro
	/if (${invisAbility}) {
		/if (${invisAbility}==1) {
|- Necro & SK's 
            /if (!${Me.AltAbilityReady[Cloak of Shadows]}) /echo Waiting for Cloak of Shadows to cycle.
            /while (!${Me.AltAbilityReady[Cloak of Shadows]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Cloak of Shadows]}
        } else /if (${invisAbility}==2) {
|- Bards
            /if (!${Me.SpellReady[Shauri's Sonorous Clouding]}) /echo Waiting for Shauri's Sonorous Clouding to cycle.
            /while (!${Me.SpellReady[Shauri's Sonorous Clouding]}) {
                /delay 1
            }
            /casting "Shauri's Sonorous Clouding"
        } else /if (${invisAbility}==3) {
|- Pure Caster Group
            /if (!${Me.AltAbilityReady[Group Perfected Invisibility]}) /echo Waiting for Group Perfected Invisibility to cycle.
            /while (!${Me.AltAbilityReady[Group Perfected Invisibility]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Group Perfected Invisibility]}
        } else /if (${invisAbility}==4) {
|- Pure Caster 
            /if (!${Me.AltAbilityReady[Perfected Invisibility]}) /echo Waiting for Perfected Invisibility to cycle.
            /while (!${Me.AltAbilityReady[Perfected Invisibility]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Perfected Invisibility]}
        } else /if (${invisAbility}==5) {
|- Beastlord
            /if (!${Me.AltAbilityReady[Natural Invisibility]}) /echo Waiting for Natural Invisibility to cycle.
            /while (!${Me.AltAbilityReady[Natural Invisibility]}) {
                /delay 1
            }
		    /alt act ${Me.AltAbility[Natural Invisibility]}
		} else /if (${invisAbility}==6) {
|-Beastlord
            /if (!${Me.AltAbilityReady[Improved Natural Invisibility]})  /echo Waiting for Improved Natural Invisibility to cycle.
            /while (!${Me.AltAbilityReady[Improved Natural Invisibility]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Improved Natural Invisibility]}
        } else /if (${invisAbility}==7) {
|- Druid / Ranger Group
            /if (!${Me.AltAbilityReady[Shared Camouflage]}) /echo Waiting for Shared Camouflage to cycle.
            /while (!${Me.AltAbilityReady[Shared Camouflage]}) {
                /delay 1
            }
		    /alt act ${Me.AltAbility[Shared Camouflage]}
        } else /if (${invisAbility}==8) {
|- Druid / Ranger 
            /if (!${Me.AltAbilityReady[Camouflage]}) /echo Waiting for Camouflage to cycle.
            /while (!${Me.AltAbilityReady[Camouflage]}) {
                /delay 1
            }
		    /alt act ${Me.AltAbility[Camouflage]}
        } else /if (${invisAbility}==9) {
|-Shaman Group
            /if (!${Me.AltAbilityReady[Group Silent Presence]}) /echo Waiting for Silent Presenc to cycle.
            /while (!${Me.AltAbilityReady[Group Silent Presence]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Group Silent Presence]}
        } else /if (${invisAbility}==10) {
|-Shaman
            /if (!${Me.AltAbilityReady[Silent Presence]}) /echo Waiting for Silent Presenc to cycle.
            /while (!${Me.AltAbilityReady[Silent Presence]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Silent Presence]}
        }
        
		/delay 3s ${Me.Invis}
	} else /if (${Me.Class.ShortName.Equal[ROG]}) {
|- Rogue
        /varcalc invisAttempts ${invisAttempts}+1
        /call RogStealth
        /if (${Me.Invis}) /return
    } else {
		/if (${FindItem[=${invisClickie}].Name.Length} && ${FindItemCount[=${invisClickie}]} && ${FindItem[=${invisClickie}].TimerReady} == 0) {
            /if (${invisClickie.NotEqual[Cloudy Potion]}) {
                /delay 1s !${Me.Moving}
                /delay 3
                /if (${invisClickie.Equal[Reusable Steambomb]}  || ${invisClickie.Equal[Cobalt Greaves]}) {
                    /call std_target ${Me.ID}
                }
                /useitem ${invisClickie}
                /delay 5 ${Window[CastingWindow].Open}
                /delay ${Math.Calc[${FindItem[=${invisClickie}].CastTime}/100].Int} !${Me.Casting.ID}
            } else {
                /useitem ${invisClickie}
                /varset invisPotionCount ${FindItemCount[=Cloudy Potion]}
                /if (!${invisPotionCount}) {
                    /echo Out of cloudy potions.
                    /varset InvisOff 1
                }
            }

        |- Clickie #2
        } else /if (${FindItem[=${invisClickie2}].Name.Length} && ${FindItemCount[=${invisClickie2}]} && ${FindItem[=${invisClickie2}].TimerReady} == 0) {
            /if (${invisClickie2.NotEqual[Cloudy Potion]}) {
                /delay 1s !${Me.Moving}
                /delay 3
                /if (${invisClickie2.Equal[Reusable Steambomb]}  || ${invisClickie2.Equal[Cobalt Greaves]}) {
                    /call std_target ${Me.ID}
                }
                /useitem ${invisClickie2}
                /delay 5 ${Window[CastingWindow].Open}
                /delay ${Math.Calc[${FindItem[=${invisClickie2}].CastTime}/100].Int} !${Me.Casting.ID}
            } else {
                /useitem ${invisClickie2}
                /varset invisPotionCount ${FindItemCount[=Cloudy Potion]}
                /if (!${invisPotionCount}) {
                    /echo No cloudy potions.
                /varset InvisOff 1
                }
            }
        }

	}
    
    /delay 2s ${Me.Invis}
    /varcalc invisAttempts ${invisAttempts}+1
    /if (!${Me.Invis} && ${invisAttempts}<5) /goto :MakeMeInvis
    /deletevar invisAttempts
    /if (${specialRequest.Equal[stripLevAndSelos]}) {
        /call cancelLevi
        /call cancelSelos
    } else /if (${specialRequest.Equal[stripLevitate]}) {
        /call cancelLevi
    } else /if (${specialRequest.Equal[stripSelos]}) {
        /call cancelSelos
    }
/return


| -------------------------------------------------------------------------------------
| SUB: ivuMe
| ------------------------------------------------------------------------------------- 
Sub ivuMe(string specialRequest)

	/if (${Me.SPA[28]} || ${Me.SPA[315]} || (${Me.Class.ShortName.Equal[ROG]} && ${Me.Invis} && ${Me.Sneaking}) ) /return activeInvis
    /if (${blnSkipIVU}) {
        /echo No IVU potions.
        /return outOfPotions
    }

	/declare ivuAttempts int         local       0

    :ivuMe
    /call checkAggro
	/if (${ivuAbility}) {
	
		/if (${ivuAbility}==1) {
|- Paladins 
            /if (!${Me.AltAbilityReady[Cloak of Light]}) /echo Waiting for Cloak of Light to cycle.
            /while (!${Me.AltAbilityReady[Cloak of Light]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Cloak of Light]}
        } else /if (${ivuAbility}==2) {
|- Bards
            /if (!${Me.SpellReady[Shauri's Sonorous Clouding]}) /echo Waiting for Shauri's Sonorous Clouding to cycle.
            /while (!${Me.SpellReady[Shauri's Sonorous Clouding]}) {
                /delay 1
            }
            /casting "Shauri's Sonorous Clouding"
        } else /if (${ivuAbility}==3) {
|- Group Ivu
            /if (!${Me.AltAbilityReady[Group Perfected Invisibility to Undead]}) /echo Waiting for Group Perfected Invisibility to Undead to cycle.
            /while (!${Me.AltAbilityReady[Group Perfected Invisibility to Undead]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Group Perfected Invisibility to Undead]}
        } else /if (${ivuAbility}==4) {
            |- Enchanters / Mages / Wizards
            /if (!${Me.AltAbilityReady[Perfected Invisibility to Undead]}) /echo Waiting for Perfected Invisibility to Undead to cycle.
            /while (!${Me.AltAbilityReady[Perfected Invisibility to Undead]}) {
                /delay 1
            }
            /alt act ${Me.AltAbility[Perfected Invisibility to Undead]}
        } else /if (${ivuAbility}==5) {
|- Self Ivu
            /if (!${Me.AltAbilityReady[Innate Invis to Undead]}) /echo Waiting for Innate Invis to Undead to cycle.
            /while (!${Me.AltAbilityReady[Innate Invis to Undead]}) {
                /delay 1
            }
		    /alt act ${Me.AltAbility[Innate Invis to Undead]}
        }
		/delay 3s (${Me.SPA[28]} || ${Me.SPA[315]} )
	} else /if (${Me.Class.ShortName.Equal[ROG]}) {
|- Rogue
        /varcalc ivuAttempts ${ivuAttempts}+1
        /call RogStealth
        /if (${Me.Invis}) /return
    } else {
        |- Clickie
		/if (${FindItem[=${ivuClickie}].Name.Length} && ${FindItemCount[=${ivuClickie}]} && ${FindItem[=${ivuClickie}].TimerReady} == 0) {
            /if (${ivuClickie.NotEqual[Philter of Unlife Awareness]}) {
                /delay 1s !${Me.Moving}
                /delay 3
                /useitem ${ivuClickie}
                /delay 5 ${Window[CastingWindow].Open}
                /delay ${Math.Calc[${FindItem[=${ivuClickie}].CastTime}/100].Int} !${Me.Casting.ID}
            } else {
                /useitem ${ivuClickie}
                /varset ivuPotionCount ${FindItemCount[=Philter of Unlife Awareness]}
                /if (!${ivuPotionCount}) {
                    /echo No IVU potions
                    /varset InvisOff 1
                }
            }
        }
	}
    
    /delay 2s (${Me.SPA[28]} || ${Me.SPA[315]} )
    /varcalc ivuAttempts ${ivuAttempts}+1
    /if (!(${Me.SPA[28]} || ${Me.SPA[315]} ) && ${ivuAttempts}<5) /goto :ivuMe
    /deletevar ivuAttempts
/return


| -------------------------------------------------------------------------------------
| Sub: RogStealth
| -------------------------------------------------------------------------------------

Sub RogStealth

 	/if (!${Me.Sneaking} && !${Me.Invis}) /echo Now you see me, now you don't!
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
| SUB: shrinkMe
| ------------------------------------------------------------------------------------- 

Sub shrinkMe
	/declare shrinkAttempts     int         local       0
    /declare fltMaxHeight       float       local       2.85

	/if (${Me.Height} < ${fltMaxHeight}) /return
    /echo Lets adjsut our height
    /delay 2s !${Me.Moving}
    /delay 5

    :shrinkMe

    /call checkAggro
	/if (${shrinkAbility}) {
							/if (${shrinkAbility}==1) /alt act ${Me.AltAbility[Group Shrink]}
							/if (${shrinkAbility}==2) /alt act ${Me.AltAbility[Shrink]}
							/if (${shrinkAbility}==3) /alt act ${Me.AltAbility[Cunning Disguise: Goblin]}
							/delay 35 (${Me.Height} < ${fltMaxHeight})
							} 

    /if (${FindItem[=${shrinkClickie}].Name.Length} && ${FindItemCount[=${shrinkClickie}]}) {
	
            /while (${FindItem[=${shrinkClickie}].TimerReady}) {
                /delay 1
            }
            /target clear
            /delay 2s !${Target.ID}
            /target ${Me.CleanName}
            /delay 2s ${Target.ID}
            /useitem ${shrinkClickie}
            /delay 5 ${Window[CastingWindow].Open}
            /delay ${Math.Calc[${FindItem[=${shrinkClickie}].CastTime}/100].Int} !${Me.Casting.ID}
            /if (${shrinkClickie.Equal[Philter of the Ant]}) /varset shrinkPotionCount ${FindItemCount[=Philter of the Ant]}
    }
	
    /varcalc shrinkAttempts ${shrinkAttempts}+1
    |- Check if we shrank ourselves
    /if (${Me.Height} > ${fltMaxHeight} && ${shrinkAttempts}<5) /goto :shrinkMe
    /if (${Me.Height} > ${fltMaxHeight}) /return failedToShrink
    /deletevar fltMaxHeight
    /deletevar shrinkAttempts
/return


| -------------------------------------------------------------------------------------
| SUB: checkAggro
| ------------------------------------------------------------------------------------- 
Sub checkAggro
    /while (${Me.XTarget} && !${IgnoreCombat}) {
		/echo ${Red} ***** You have Agro, kill it or run!! *****
        /delay 5
    }
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


