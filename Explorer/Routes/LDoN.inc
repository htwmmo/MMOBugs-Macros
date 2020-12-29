| -------------------------------------------------------------------------------------
|                                     Lost Dungeons of Norrath
|									 Core code supplied by CwTN
| -------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| ------------------------------------------------------------------------------------- 
Sub LDoN

	/varset completed 0
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Lost Dungeons of Norrath ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - Lost Dungeons of Norrath
|--------------------------------------------------------------------------------------

	/lazyfind on
	/call checkGroupMemberCount
	/call checkGroupLeaderStatus
|	/call dropAdventure

:LDoN
	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone everfrost
	/if (${Zone.ID}==30)						/call EverfrostLDoN
	/if (${Zone.ID}==68)						/call ButcherLDoN
	/if (${Zone.ID}==393)						/call SouthRoLDoN
	/if (${Zone.ID}==392)						/call NorthRoLDoN
	/if (${Zone.ID}==408)						/call CommonsLDoN
	
	/delay 5s
	/delay 3m !${Navigation.Active}
	/goto :LDoN
/return
		
| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub LDoNComplete	
	/delay 5s
	/echo ${White}You have completed Exploring: ${Green}Lost Dungeons of Norrath.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "LDoN" "1"
	/delay 1s        
	/call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub EverfrostLDoN
	/delay 1s
	/call invisMe
	/squelch /nav spawn npc Mannis_McGuyett
	/delay 3m !${Navigation.Active}
	/call checkTasks
			
	/while (${LDoN-MM}) {
						/call exploreCampZones
						}
			/varset CampComplete 0
			/call switchCamps everfrost butcher
/return

Sub ButcherLDoN
		/while (${Zone.ShortName.Equal[butcher]}) {
			/call checkTasks
			/while (${LDoN-MC}) {
				/call exploreCampZones
			}
			/varset CampComplete 0
			/call switchCamps butcher southro
		}
/return

Sub SouthRoLDoN
		/while (${Zone.ShortName.Equal[southro]}) {
			/call checkTasks
			/while (${LDoN-DG}) {
				/call exploreCampZones
			}
			/varset CampComplete 0
			/call switchCamps southro northro
		}
/return

Sub NorthRoLDoN
		/while (${Zone.ShortName.Equal[northro]}) {
			/call checkTasks
			/while (${LDoN-TH}) {
				/call exploreCampZones
			}
			/varset CampComplete 0
			/call switchCamps northro commonlands
		}
/return

Sub CommonsLDoN
		/while (${Zone.ShortName.Equal[commonlands]}) {
			/call checkTasks
			/while (${LDoN-RH}) {
				/call exploreCampZones
			}
			/varset CampComplete 0
			
			/call LDoNComplete
		}
/return

Sub InnothuleLDoN
        /while (${Zone.ShortName.Equal[innothuleb]}) {
			/echo Traveling to ${Green}Southern Desert of Ro
			/nav loc 2636 1028 7
        }
/return


|--------------------------------------------------------------------------------
|SUB: checkTasks
|--------------------------------------------------------------------------------
Sub checkTasks
	/if (${Zone.ShortName.Equal[everfrost]}) {
		/if (!${LDoN-MM-Menagerie} && !${LDoN-MM-Laboratory} && !${LDoN-MM-SpiderDen} && !${LDoN-MM-Theater} && !${LDoN-MM-Wastes} && !${LDoN-MM-Heart} && !${LDoN-MM-Banquet} && !${LDoN-MM-Library} && !${LDoN-MM-Gallery} && !${LDoN-MM-FrostHalls} ) {
			/varset LDoN-MM 0
			/varset CampComplete 1
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul" 1
		}
	} else /if (${Zone.ShortName.Equal[butcher]}) {
		/if (!${LDoN-MC-Cavern} && !${LDoN-MC-Grotto} && !${LDoN-MC-Asylum} && !${LDoN-MC-Chamber} && !${LDoN-MC-Sepulcher} && !${LDoN-MC-SummGround} && !${LDoN-MC-Cesspit} && !${LDoN-MC-Aisles} && !${LDoN-MC-Halls} && !${LDoN-MC-Sanctuary} ) {
			/varset LDoN-MC 0
			/varset CampComplete 1
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore" 1
		}
	} else /if (${Zone.ShortName.Equal[southro]} && ${strLDONName.Equal[Deepest_Guk]}) {
		/if (!${LDoN-DG-Cauldron} && !${LDoN-DG-Chapel} && !${LDoN-DG-Mushroom} && !${LDoN-DG-Sanctuary} && !${LDoN-DG-Crypt} && !${LDoN-DG-Aquaduct} && !${LDoN-DG-Prison} && !${LDoN-DG-Garden}) {
			/varset LDoN-DG 0
			/varset CampComplete 1
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk" 1
		}
	} else /if (${Zone.ShortName.Equal[northro]}) {
		/if (!${LDoN-TH-Tower} && !${LDoN-TH-Observatory} && !${LDoN-TH-Palace} && !${LDoN-TH-Chamber} && !${LDoN-TH-Prismatic} && !${LDoN-TH-Library} && !${LDoN-TH-River} && !${LDoN-TH-Tides} && !${LDoN-TH-Sandfall} && !${LDoN-TH-Temple} ) {
			/varset LDoN-TH 0
			/varset CampComplete 1
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz" 1
		}
	} else /if (${Zone.ShortName.Equal[commonlands]}) {
		/if (!${LDoN-RH-Hollows} && !${LDoN-RH-Forge} && !${LDoN-RH-Arena} && !${LDoN-RH-Quarries} && !${LDoN-RH-Fort} && !${LDoN-RH-GladPit} && !${LDoN-RH-Barracks} && !${LDoN-RH-Halls} && !${LDoN-RH-Vale} && !${LDoN-RH-Bridges} ) {
			/varset LDoN-RH 0
			/varset CampComplete 1
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark" 1
		}
	}	
/return


|--------------------------------------------------------------------------------
|SUB: checkGroupLeaderStatus
|--------------------------------------------------------------------------------
Sub checkGroupLeaderStatus
	/while (!${Group.Member[0].Leader}) {
		/beep
		/call MQP ldonGrpLeader
	}

/return

|--------------------------------------------------------------------------------
|SUB: checkGroupMemberCount
|--------------------------------------------------------------------------------
Sub checkGroupMemberCount
	/while (${Group.Members}<2) {
		/call MQP ldonNeed3
	}
/return

|--------------------------------------------------------------------------------
|SUB: decideAdventure
|-------------------------------------------------------------------------------
Sub decideAdventure
	/declare intCounter			int			local		0
	/declare intZoneListTotal	int			local		${Math.Calc[${lstBossZones.Count[|]}+1]}

	/if (!${lstBossZones.Count[|]}) {
		/if (${LDoN-${lstBossZones}}) /varset AdventureNeeded 1
	} else /if (${lstBossZones.Count[|]}) {
		/for intCounter 1 to ${intZoneListTotal}
			/if (${LDoN-${lstBossZones.Arg[${intCounter},|]}}) {
				/varset AdventureNeeded 1
				/break
				}
		/next intCounter
	}
/return


|--------------------------------------------------------------------------------
|SUB: declineAdventureWait
|--------------------------------------------------------------------------------
Sub declineAdventureWait
	/echo ${White}Declining adventure.  Waiting for refresh.
	/notify AdventureRequestWnd AdvRqst_DeclineButton leftmouseup
	/declare intCounter		int		local		0
	/for intCounter 0 to 65
		/if (${Window[AdventureRequestWND].Open}) /notify AdventureRequestWnd AdvRqst_DeclineButton leftmouseup
		/delay 1s 
		/doevents
	/next intCounter
/return


|--------------------------------------------------------------------------------
|SUB: dropAdventure
|--------------------------------------------------------------------------------
Sub dropAdventure
    /bcga //windowstate AdventureRequestWnd open
    /delay 5
    /bcga //notify AdventureRequestWnd AdvRqst_RequestButton leftmouseup
    /delay 1s
    /bcga //notify ConfirmationDialogBox CD_Yes_Button leftmouseup
    /bcga //windowstate AdventureRequestWnd close
    /delay 5	
/return

|--------------------------------------------------------------------------------
|SUB: exploreCampZones
|--------------------------------------------------------------------------------
Sub exploreCampZones
	/if (${CampComplete}) /return
	/call setCampVariables
	/call navToAdvRecruiter
	/call getAdventure
	/if (!${CampComplete}) {
		/call navToAdventure
		/call dropAdventure
		/call checkTasks
		/call navToCamp
		/call resetAdventureVariables
	}
/return


|--------------------------------------------------------------------------------
|SUB: extractAdventureZI
|--------------------------------------------------------------------------------
Sub extractAdventureZI
	/declare intCounter		int		local  		0
	/declare intListTotal	int		local		${Math.Calc[${lstAdventureZIs.Count[|]}+1]}
	/for intCounter 1 to ${intListTotal}
		/if (${AdventureText.Find[${lstAdventureZIs.Arg[${intCounter},|]}]}) {
			/varset TaskEntrance ${lstAdventureZIs.Arg[${intCounter},|]}
			/break
		}
	/next intCounter
/return


|--------------------------------------------------------------------------------
|SUB: extractBossName
|--------------------------------------------------------------------------------
Sub extractBossName
	/declare intCounter		int		local  		0
	/declare intListTotal	int		local 		${Math.Calc[${lstBosses.Count[|]}+1]}

	/delay 2s
	/varset AdventureText ${Window[AdventureRequestWnd].Child[AdvRqst_NPCText].Text}
	/if (${AdventureText.Find[Your last Adventure request has not expired.]}) {
		/return adventureExpired
	} else /if (${AdventureText.Find[Your adventure request failed.]}) {
		/delay 2s
		/call dropAdventure
		/return requestFailed
	} else {
		/for intCounter 1 to ${intListTotal}
			/if (${AdventureText.Find[${lstBosses.Arg[${intCounter},|]}]}) {
				/varset BossName ${lstBosses.Arg[${intCounter},|]}
				/break
			}
		/next intCounter
	}
/return


|--------------------------------------------------------------------------------
|SUB: getAdventure
|--------------------------------------------------------------------------------
Sub getAdventure
	/while (!${AdventureNeeded} && !${CampComplete}) {
		/call checkTasks
		/call openRecruiter
		/call setAdventureRisk
		/call setAdventureType
		/call requestAdventure
		/call extractBossName
		/call extractAdventureZI
		/if (${Macro.Return.NotEqual[adventureExpired]} && ${Macro.Return.NotEqual[requestFailed]}) {
			/call lookupBossZones ${strLDONName} ${BossName}
			/if (${lstBossZones.Equal[NULL]}) {
                /call declineAdventureWait                
                /continue
            }
			/call decideAdventure
			/if (${AdventureNeeded}) {
				|- Accept Adventure
				/notify AdventureRequestWnd AdvRqst_AcceptButton leftmouseup
			} else {
				/call declineAdventureWait
			}
		} else {
			/call declineAdventureWait
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: lookupBossZone
|--------------------------------------------------------------------------------
Sub lookupBossZones(string strZoneSection)
	/varset lstBossZones ${Ini[${iniBossZoneLookups},${strZoneSection},${BossName}]}
/return

|--------------------------------------------------------------------------------
|SUB: navToAdventure
|--------------------------------------------------------------------------------
Sub navToAdventure
	/delay 2s
	/bcga //windowstate AdventureRequestWnd close
	/varset AdventureNavigation 0
	/if (${strLDONName.Equal[Miraguls_Menagerie]}) {
		/call Everfrost2LDoNEnterances
	} else /if (${strLDONName.Equal[Mistmoores_Catacombs]}) {
		/call Butcher2LDoNEntrance
	} else /if (${strLDONName.Equal[Deepest_Guk]}) {
		/call SRo2DGEntrance
	} else /if (${strLDONName.Equal[Takish-Hiz]}) {
		/call NRo2LDoNEntrance
	} else /if (${strLDONName.Equal[Rujarkian_Hills]}) {
		/call CommonsLDoNEntrance
	}
/return

|--------------------------------------------------------------------------------
|SUB: navToAdvRecruiter
|--------------------------------------------------------------------------------
Sub navToAdvRecruiter
	/call setCampVariables
	/squelch /target clear
	/squelch /nav spawn npc ${AdvRecruiter}
/return

|--------------------------------------------------------------------------------
|SUB: navToCamp
|--------------------------------------------------------------------------------
Sub navToCamp
	/echo ${Green}Returning to camp.
	/varset AdventureNavigation 0
	/if (${strLDONName.Equal[Miraguls_Menagerie]}) {
		/call EverfrostLDoNCamp
	} else /if (${strLDONName.Equal[Mistmoores_Catacombs]}) {
		/call ButcherLDoNCamp
	} else /if (${strLDONName.Equal[Deepest_Guk]}) {
		/call SRoLDoNCamp
	} else /if (${strLDONName.Equal[Takish-Hiz]}) {
		/call NRoLDoNCamp
	} else /if (${strLDONName.Equal[Rujarkian_Hills]}) {
		/call CommonsLDoNCamp
	}
/return

|--------------------------------------------------------------------------------
|SUB: SRoLDoNCamp
|--------------------------------------------------------------------------------
Sub SRoLDoNCamp
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/if (${Zone.ShortName.Equal[southro]}) {
			/echo Traveling to ${Green}The Wayfarer's Camp
			/nav loc -152 -353 109
			/varset AdventureNavigation 1
		}

		/while (${Zone.ShortName.Equal[innothuleb]}) {
			/echo Traveling to ${Green}Southern Desert of Ro
			/if (${SpawnCount[id ${Me.ID} loc -1115 -6 radius 20]}) {
				/nav loc 64 -1118 27
			} else {
			}
			/nav loc 2636 1028 7
			/while (${Zone.ShortName.Equal[innothuleb]}) {
				/delay 1
			}
		}

		/while (${Zone.ShortName.Equal[guktop]}) {
			/echo Traveling to ${Green}Innothule Swamp
			/call shrinkMe
			/nav loc -35 81 0
			/while (${Zone.ShortName.Equal[guktop]}) {
				/delay 1
			}
		}
	}
/return

|--------------------------------------------------------------------------------
|SUB: SRo2DGEntrance
|--------------------------------------------------------------------------------
Sub SRo2DGEntrance
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/while (${Zone.ShortName.Equal[southro]}) {
			/nav loc -614 -218 140
			/squelch /target clear
			/squelch /moveto loc -640 -151 137
			/while (${Zone.ShortName.Equal[southro]}) {
				/delay 1
			}
		}

		/while (${Zone.ShortName.Equal[innothuleb]}) {
			/if (${TaskEntrance.Equal[a rotting tree trunk]}) {
				:DG1ReEntry
				/bcga //windowstate AdventureRequestWnd close
				/squelch /nav loc 940 571 14
				/delay 3m !${Navigation.Active}
				/squelch /doortarget id 3
                /delay 2s ${Switch.ID}==3
                /click left door
			} else {
					/echo Traveling to ${Green}The City of Guk
					/squelch /nav loc -10 -1120 24
					/delay 3m !${Navigation.Active}
					/squelch /nav loc -10 -1180 24
					/delay 3m !${Navigation.Active}
					/if (${Zone.ID}==413 && ${Me.Y} >-1160)	/squelch /moveto -10 -1120 24
					}
			/delay 1s 
			/doevents
			/if (${FailedToZone}) 	{
									/varset FailedToZone 0
									/goto :DG1ReEntry
									}
			/while (${Zone.ShortName.Equal[innothuleb]}) 	{
															/delay 1
															}
		}

		/if (${Zone.ID}==65) {
			/bcga //windowstate AdventureRequestWnd close
			/call shrinkMe
			:DG2ReEntry
			/nav door id 1 click
			/delay 1s 
			/while (${Zone.ShortName.Equal[guktop]})	{
														/delay 1
														/doevents
														/if (${FailedToZone})	{
																				/varset FailedToZone 0
																				/goto :DG2ReEntry
																				}
														}
		}
		/while (${Zone.ShortName.Find[guk]} && ${Zone.ShortName.NotEqual[guktop]}) {
			/if (!${Defined[i]}) /declare i int local 1
			/while (${i}) {
				/varset AdventureNavigation 1
				/call markZoneComplete
				/call checkTasks
				/call exitAdventureZone
				/varset i 0
			}
			/delay 1
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: navToMagus
|--------------------------------------------------------------------------------
Sub navToMagus
	/call setCampVariables
	/squelch /target clear
	/squelch /nav spawn npc ${MagusName}
	/delay 3m !${Navigation.Active}
/return

|--------------------------------------------------------------------------------
|SUB: ButcherLDoNCamp
|--------------------------------------------------------------------------------
Sub ButcherLDoNCamp
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/if (${Zone.ShortName.Equal[butcher]}) {
			/echo Traveling to ${Green}The Wayfarer's Camp
			/nav loc -1116 -2555 0
			/varset AdventureNavigation 1
		}

		/while (${Zone.ShortName.Equal[gfaydark]}) {
			/echo Traveling to ${Green}Butcherblock Mountains
			/nav loc -1645 2690 4
			/while (${Zone.ShortName.Equal[gfaydark]}) {
				/delay 1
			}
		}

		/while (${Zone.ShortName.Equal[lfaydark]}) {
			/echo Traveling to ${Green}The Greater Faydark
			/nav loc 2197 -1200 0
			/while (${Zone.ShortName.Equal[lfaydark]}) {
				/delay 1
			}
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: Butcher2LDoNEntrance
|--------------------------------------------------------------------------------
Sub Butcher2LDoNEntrance
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/while (${Zone.ShortName.Equal[butcher]}) {
			/nav loc -1222 -3195 0
			/delay 3m !${Navigation.Active}
			/while (${Zone.ShortName.Equal[butcher]}) {
				/delay 1
			}
		}

		/while (${Zone.ShortName.Equal[gfaydark]}) {
			/echo Traveling to ${Green}The Lesser Faydark
			/nav loc -2722 -1032 0
				/delay 3m !${Navigation.Active}
			/while (${Zone.ShortName.Equal[gfaydark]}) {
				/delay 1
			}
		}

		/while (${Zone.ShortName.Equal[lfaydark]}) {
			:MCReEntry
			/bcga //windowstate AdventureRequestWnd close
			/if (${TaskEntrance.Equal[an unearthed grave]}) {
				/echo Traveling to an ${Green}Unearthed Grave Entrance
				/squelch /nav loc -120 3874 -39.57
|				/nav door id 10 click
				/delay 4m !${Navigation.Active}
				/squelch /doortarget id 10 
				/squelch /click left door				
			} else {
				/echo Traveling to a ${Green}Crypt Entrance
				/nav loc -731 3775 0
				/delay 3m !${Navigation.Active}
				/nav loc -742 3837 2
				/delay 3m !${Navigation.Active}
				/squelch /face fast heading 112
				/squelch /moveto loc -761 3869 2
			}
			/delay 1s 
			/while (${Zone.ShortName.Equal[lfaydark]}) {
				/delay 1
				/doevents
				/if (${FailedToZone}) {
					/varset FailedToZone 0
					/goto :MCReEntry
				}
			}
		}
		/while (${Zone.ShortName.Find[mmc]}) {
			/if (!${Defined[i]}) /declare i int local 1
			/while (${i}) {
				/varset AdventureNavigation 1
				/call markZoneComplete
				/call checkTasks
				/call exitAdventureZone
				/varset i 0
			}
			/delay 1
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: EverfrostLDoNCamp
|--------------------------------------------------------------------------------
Sub EverfrostLDoNCamp
	/echo Traveling to ${Green}The Wayfarer's Camp
	/nav loc 1763 -5021 -59
	/varset AdventureNavigation 1
/return


|--------------------------------------------------------------------------------
|SUB: Everfrost LDoN Enterances
|--------------------------------------------------------------------------------
Sub Everfrost2LDoNEnterances
	/declare blnWait	bool	outer 	1
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/while (${Zone.ShortName.Equal[everfrost]}) {
			
			/bcga //windowstate AdventureRequestWnd close
			:MMReEntry
			/if (${TaskEntrance.Equal[a snowy mine]}) {
				/if (${blnWait}) {
					/delay 25s
				}
				/varset blnWait 0
				/echo ${Green}Moving to mine entrance
				/nav loc 2740 -4679 -103
				/delay 3m !${Navigation.Active}
				/nav door id 1 click
			} else {
				/echo ${Green}Moving to portal entrance
				/nav door id 3 click
			}
			/delay 1s 
			/while (${Zone.ShortName.Equal[everfrost]}) {
				/delay 1
				/doevents
				/if (${FailedToZone}) {
					/varset FailedToZone 0
					/goto :MMReEntry
				}
			}
		}
		|/while (${Select[TRUE,${Zone.ShortName.Find[mira_]},${Zone.ShortName.Find[mirb_]},${Zone.ShortName.Find[mirc_]},${Zone.ShortName.Find[mird_]},${Zone.ShortName.Find[mire_]},${Zone.ShortName.Find[mirf_]},${Zone.ShortName.Find[mirg_]},${Zone.ShortName.Find[mirh_]},${Zone.ShortName.Find[miri_]},${Zone.ShortName.Find[mirj_]}]}) {
		/while (${Zone.ShortName.Find[mir]}) {
			/if (!${Defined[i]}) /declare i int local 1
			/while (${i}) {
				/varset AdventureNavigation 1
				/call markZoneComplete
				/call checkTasks
				/call exitAdventureZone
				/varset i 0
			}
			/delay 1
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: CommonsLDoNCamp
|--------------------------------------------------------------------------------
Sub CommonsLDoNCamp
	|- Nav route: southro > northro > commonlands
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/if (${Zone.ShortName.Equal[commonlands]}) {
			/echo Traveling to ${Green}The Wayfarer's Camp
			/nav loc -1756 -2600 38
			/varset AdventureNavigation 1
		}

		/while (${Zone.ShortName.Equal[southro]}) {
			/echo Traveling to ${Green}Northern Desert of Ro
			/call switchCamps southro commonlands
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: South Ro Entrance
|--------------------------------------------------------------------------------
Sub CommonsLDoNEntrance
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/while (${Zone.ShortName.Equal[commonlands]}) {
			/call switchCamps commonlands southro
		}

		/while (${Zone.ShortName.Equal[southro]}) {
			:RHReEntry
			/bcga //windowstate AdventureRequestWnd close
			/if (${TaskEntrance.Equal[through a cave in Southern Ro]}) {
				/nav door id 2 click
			} else {
				/echo ${Red}****ERROR Bad entry point for TakHiz
			}
			/delay 1s 
			/while (${Zone.ShortName.Equal[southro]}) {
				/delay 1
				/doevents
				/if (${FailedToZone}) {
					/varset FailedToZone 0
					/goto :RHReEntry
				}
			}
		}
		/while (${Zone.ShortName.Find[ruj]}) {
			/if (!${Defined[i]}) /declare i int local 1
			/while (${i}) {
				/varset AdventureNavigation 1
				/call markZoneComplete
				/call checkTasks
				/call exitAdventureZone
				/varset i 0
			}
			/delay 1
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: NRoLDoNCamp
|--------------------------------------------------------------------------------
Sub NRoLDoNCamp
	/echo Traveling to ${Green}The Wayfarer's Camp
	/nav loc 7873 -585 99
	/varset AdventureNavigation 1
/return


|--------------------------------------------------------------------------------
|SUB: North Ro Entrance
|--------------------------------------------------------------------------------
Sub NRo2LDoNEntrance
	/varset AdventureNavigation 0
	/while (!${AdventureNavigation}) {
		/while (${Zone.ShortName.Equal[northro]}) {
			:THReEntry
			/bcga //windowstate AdventureRequestWnd close
			/if (${TaskEntrance.Equal[a quicksand pit in Northern Ro]}) {
				/nav door id 4 click
			}
			/delay 1s 
			/while (${Zone.ShortName.Equal[northro]}) {
				/delay 1
				/doevents
				/if (${FailedToZone}) {
					/varset FailedToZone 0
					/goto :THReEntry
				}
			}
		}
		/while (${Zone.ShortName.Find[tak]}) {
			/if (!${Defined[i]}) /declare i int local 1
			/while (${i}) {
				/varset AdventureNavigation 1
				/call markZoneComplete
				/call checkTasks
				/call exitAdventureZone
				/varset i 0
			}
			/delay 1
		}
	}
/return


|--------------------------------------------------------------------------------
|SUB: openRecruiter
|--------------------------------------------------------------------------------
Sub openRecruiter
	/squelch /target clear
	/squelch /target ${AdvRecruiter}
	/delay 3s ${Target.ID}==${Spawn[${AdvRecruiter}].ID}
	/squelch /nomodkey /click right	target
/return


|--------------------------------------------------------------------------------
|SUB: requestAdventure
|--------------------------------------------------------------------------------
Sub requestAdventure
	/call checkGroupMemberCount
	/delay 1s
	/squelch /notify AdventureRequestWnd AdvRqst_RequestButton leftmouseup
/return


|--------------------------------------------------------------------------------
|SUB: exitAdventureZone
|--------------------------------------------------------------------------------
Sub exitAdventureZone
	/varset strZonePrefix ${Zone.ShortName.Left[3]}
	
| Everfrost
|--------------------------------------------------
	/if (${strZonePrefix.Equal[mir]}) {
		/nav door MPORTAL700E click dist=15
	} else /if (${strZonePrefix.Equal[mmc]}) 	{
												/if (${strZoneSuffix.Equal[d]} || ${strZoneSuffix.Equal[e]} || ${strZoneSuffix.Equal[f]} || ${strZoneSuffix.Equal[j]}) {
												/nav door MISTPRTL700E click dist=15
		} else /if (${strZoneSuffix.Equal[a]} || ${strZoneSuffix.Equal[b]} || ${strZoneSuffix.Equal[c]}) {
												/nav door MISTPORT701E click dist=15
		} else /if (${strZoneSuffix.Equal[i]}) {
			/squelch /face fast door id 5
			/squelch /moveto  loc -263 589
			/delay 2s ${MoveTo.Stopped}
			/squelch /doortarget id 5
			/delay 2s ${Switch.ID}==5
			/click left door
		} else /if (${strZoneSuffix.Equal[g]}) {
			/squelch /moveto  loc 413 419
			/delay 2s ${MoveTo.Stopped}
			/squelch /face fast door id 5
			/squelch /moveto  loc 398 420
			/delay 2s ${MoveTo.Stopped}
			/squelch /doortarget id 5
			/delay 2s ${Switch.ID}==5
			/click left door
		} else {
			/nav door MISTPRTL701E click dist=15
		}
		
|-Butcherblock
|---------------------------------------------------
|- MMCa
		/if (${Zone.ID}==233) {
			/delay 2s
			/squelch /nav door id 1 click
|- MMCb
		} else /if (${Zone.ID}==238) {
			/delay 2s
			/squelch /nav door id 36 click
|- MMCc
		} else /if (${Zone.ID}==243) {
			/delay 2s
			/squelch /nav door id 4 click
|- MMCd
		} else /if (${Zone.ID}==248) {
			/delay 2s
			/squelch /moveto loc -637 -146
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 1
			/delay 2s
			/click left door	
|- MMCe
		} else /if (${Zone.ID}==253) {
			/delay 2s
			/squelch /moveto loc 389 -605
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 1
			/delay 2s
			/click left door
|- MMCf			
		} else /if (${Zone.ID}==258) {
			/delay 2s
			/squelch /moveto  loc 391 -205
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 1
			/delay 2s
			/click left door
|- MMCg			
		} else /if (${Zone.ID}==263) {
			/delay 2s
			/squelch /moveto loc 398 419
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 5
			/delay 2s
			/click left door
|- MMCh			
		} else /if (${Zone.ID}==268) {
			/delay 2s
			/squelch /moveto loc -322 -370
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 5
			/delay 2s
			/click left door
|- MMCi
		} else /if (${Zone.ID}==272) {
			/delay 2s
			/squelch /moveto loc -262 589
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 5
			/delay 2s
			/click left door
|- MMCj
		} else /if (${Zone.ID}==276) {
			/delay 2s
			/squelch /moveto loc 543 270
			/delay 4s ${MoveTo.Stopped}
			/squelch /doortarget id 6
			/delay 2s
			/click left door
		}

|- Guk
|---------------------------------------------------		
	} else /if (${strZonePrefix.Equal[guk]} && ${Zone.ShortName.NotEqual[guktop]}) {
				/delay 6s
				/nav door GKPORTAL701E click dist=10
		
|- Guke
		} else /if (${Zone.ID}==249) {
			/delay 6s
			/squelch /nav door id 1 click	
|- Gukf
		} else /if (${Zone.ID}==254) {
			/delay 6s
			/squelch /nav door id 1 click			
				
				

|- NRo					
|---------------------------------------------------
|- Taka
		} else /if (${Zone.ID}==231) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Takb
		} else /if (${Zone.ID}==236) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Takc
		} else /if (${Zone.ID}==241) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Takd
		} else /if (${Zone.ID}==246) {
			/delay 4s
			/squelch /nav door id 3 click			
|- Take
		} else /if (${Zone.ID}==251) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Takf
		} else /if (${Zone.ID}==256) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Takg
		} else /if (${Zone.ID}==261) {
			/delay 4s
			/squelch /nav door id 83 click
|- Takh
		} else /if (${Zone.ID}==266) {
			/delay 4s
			/squelch /nav door id 81 click
|- Taki
		} else /if (${Zone.ID}==270) {
			/delay 4s
			/squelch /nav door id 51 click

|- Takj
		} else /if (${Zone.ID}==274) {
			/delay 4s
			/squelch /nav door id 59 click

|- Commons				
|-----------------------------------------------	
|- Ruja
		} else /if (${Zone.ID}==230) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Rujb
		} else /if (${Zone.ID}==235) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Rujc
		} else /if (${Zone.ID}==240) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Rujd
		} else /if (${Zone.ID}==245) {
			/delay 4s
			/squelch /nav door id 1 click			
|- Ruje
		} else /if (${Zone.ID}==250) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Rujf
		} else /if (${Zone.ID}==255) {
			/delay 4s
			/squelch /nav door id 1 click	
|- Rujg
		} else /if (${Zone.ID}==260) {
			/delay 4s
			/squelch /nav door id 1 click
|- Rujh
		} else /if (${Zone.ID}==265) {
			/delay 4s
			/squelch /nav door id 1 click
|- Ruji
		} else /if (${Zone.ID}==269) {
			/delay 4s
			/squelch /nav door id 1 click

|- Rujj
		} else /if (${Zone.ID}==273) {
			/delay 4s
			/squelch /nav door id 1 click		

				}
	}

/return

|--------------------------------------------------------------------------------
|SUB: resetAdventureVariables
|--------------------------------------------------------------------------------
Sub resetAdventureVariables
	/varset MagusName
	/varset AdvRecruiter
	/varset AdventureText
	/varset lstBosses
	/varset BossName
	/varset lstBossZones
	/varset AdventureNeeded
	/varset strLDONName
	/varset lstAdventureZIs
	/varset TaskEntrance
	/varset strZonePrefix
	/varset strZoneSuffix
/return



|--------------------------------------------------------------------------------
|SUB: setAdventureRisk (1 for normal, 2 for high)
|--------------------------------------------------------------------------------
Sub setAdventureRisk
	/squelch /notify AdventureRequestWnd AdvRqst_RiskCombobox listselect 2
/return


|--------------------------------------------------------------------------------
|SUB: setAdventureType
|--------------------------------------------------------------------------------
Sub setAdventureType
	/squelch /notify AdventureRequestWnd AdvRqst_TypeCombobox listselect 2
/return


|--------------------------------------------------------------------------------
|SUB: setCampVariables
|--------------------------------------------------------------------------------
Sub setCampVariables
	/if (${Zone.ShortName.Equal[everfrost]}) {
		/varset strLDONName Miraguls_Menagerie
		/varset MagusName ${EverfrostMagus}
		/varset AdvRecruiter ${EverfrostNPC}
		/varset lstBosses Shyar the Shard|Glacius|Grand Sage Havori|The Flesh of Osoros|Painsinger|The Nibbler|Elder Phalanea|Pulgrish the Ancient|Summoner Sghrene|Orgogzolok|Soulroar|Jebreusulun|Towering Monstrosity|Beguiler Chetrea|The Silent Choir|Synarcanic Essence|Synarcanic Presence|The Fireborn|The Prime Steward|Charaex the Mastodon|Ancient Marrow|Bilach of Avarice|Riddlesting|Sionul the Savage|Zubruiz the Mindful|Vkaziz the Defiler|Soulstorm|The Dream Defiler|Ianlai the Corrupted|Balaeluo the Inflictor|Tateaad the Sage
		/varset lstAdventureZIs a snowy mine|a glimmering portal of magic
	} else /if (${Zone.ShortName.Equal[butcher]}) {
		/varset strLDONName Mistmoores_Catacombs
		/varset MagusName ${ButcherMagus}
		/varset AdvRecruiter ${ButcherNPC}
		/varset lstBosses Ulyist Son of Night|Khestin the Bold|Fesset the Leech|Master Larithim|Warlord Thavrin|Serpen the Lost|Prince Aviatis|Kuren K`sayen|The Keeper of Flesh|Grandsteward M`rakish|The Keeper of Blood|Numleou the Learned|Keeper of Breath|Yavrin|Harvestmaster Viestri|Avedranna|Empress Atiache|Dierdri the Raven|Bial the Blade|The Widow|Midwife M`seri|Crypt Watcher|Lady Tsaellia|Sivli Starsiren|Baelthorn Born of Blood|Hhovris|Fleshspinner|Eclipse|Huketsa the Ageless|Oneblood
		/varset lstAdventureZIs a crypt in Lesser Faydark|an unearthed grave
	} else /if (${Zone.ShortName.Equal[southro]}) {
		/varset strLDONName Deepest_Guk
		/varset MagusName ${SRoMagus}
		/varset AdvRecruiter ${SRoNPC}
		/varset lstBosses Gaz Commander Nezeim|Lokta Ancient Giddib|Lord Drigo|Poxtongue|Yaszil the Assassin|Arch Lich Xakasis|Zukta Luiv|Aikyik of the Cauldron|Korta Archpriest Bhotea|Bazrael Firefall|Tazih the Eternal|The Cauldron Keeper|Witness of Hate|Madakan|polluted Korta messenger|Oime Ugun|Zukta Likae|Shinta Captain Yaem|Yunta Spiritmaster Efferael|Uthiur the Fallen|Jinta Archwizard Zxiri|Shadowcreeper|Jinta Savant Grisk|Darta Berserker Tiriut|Airerick the Nightdweller
		/varset lstAdventureZIs a rotting tree trunk|a barricaded door
	} else /if (${Zone.ShortName.Equal[northro]}) {
		/varset strLDONName Takish-Hiz
		/varset MagusName ${NRoMagus}
		/varset AdvRecruiter ${NRoNPC}
		/varset lstBosses Tempest|High Flowkeeper Meirgad|Queen Ederissa|Petroglyph|King Bohagord|Guard Captain Raston|Master Maexon|Grand Librarian Enarel|Lord Pasreet|Chancellor Etometh|Shadow Assassin Juni|Prince Jerranad|Deceiver Yerik|Antlion Burrower|Master Architect Naida|The Great Summoning|Arch Priest Grylith|Zelifa Corollaire|The Keeper of the Tides|Lord Pasreet|High Preservationist Dorjan|Grilnir the Unrelenting|Vagrant Nalikad|Sand Spirit of the South|Mistress Solavia
		/varset lstAdventureZIs a quicksand pit in Northern Ro
	} else /if (${Zone.ShortName.Equal[commonlands]}) {
		/varset strLDONName Rujarkian_Hills
		/varset MagusName ${CommonlandsMagus}
		/varset AdvRecruiter ${CommonlandsNPC}
		/varset lstBosses Nsat Egne|Tjumen Mayok Ibu|Tjumuen Ghendi|Fendr the Spiritcaller|Noyon Kteggen|Noyon Ztun|Captive Coin Bleeder|Steelslave Trader|Murdering Slave|Farmished Slave|Bloodied Harrower|Ubril Vkelrel|Sikl the Manslayer|Warmaster Skooru|Pyol Skinsear|Elokoh the Trainer|Urett Marl|Fhenit Fleshflayer|Dokolet of Rujark|Vokrek of Rujark|Maotog One Tusk|Tehyul Master of Steel|Vdure Bonecrusher|Xendren Marl|Urut Egne|Kyten the Sightless|The Rujarkian Jeweler|Orlok Dtuak|Orlok Nebendis
		/varset lstAdventureZIs through a cave in Southern Ro
	}	
/return



|--------------------------------------------------------------------------------
|SUB: switchCamps (curCamp/destCamp as zone ShortNames)
|--------------------------------------------------------------------------------
Sub switchCamps(str curCamp,str destCamp)
	/declare strPortPhrase			string	local

	/if (${destCamp.Equal[everfrost]}) {
		/varset strPortPhrase Everfrost
	} else /if (${destCamp.Equal[butcher]}) {
		/varset strPortPhrase Butcherblock
	} else /if (${destCamp.Equal[southro]}) {
		/varset strPortPhrase South Ro
	} else /if (${destCamp.Equal[northro]}) {
		/varset strPortPhrase North Ro
	} else /if (${destCamp.Equal[commonlands]}) {
		/varset strPortPhrase Commonlands
	}

|- Original zone
	/while (${Zone.ShortName.Equal[${curCamp}]}) {
		/call navToMagus
		/makemevisible
		/delay 4s !${Me.Invis}
		/squelch /target clear
		/target ${MagusName}
		/delay 2s ${Target.ID}==${Spawn[${MagusName}].ID}
		/delay 3s
		/say ${strPortPhrase}
		/say Nedaria's Landing
		/while (${Zone.ShortName.Equal[${curCamp}]}) 	{
			/delay 1
		}												
	}
	
|- Nedaria's Landing
	/while (${Zone.ShortName.Equal[nedaria]}) {
		/echo Traveling to ${Green}${Zone[${destCamp}].Name}
		/squelch /target clear
		/squelch /nav spawn npc Magus_Wenla
		/target npc Magus_Wenla
		/makemevisible
		/delay 10s ${Target.ID}==${Spawn[Magus_Wenla].ID}
		/say ${strPortPhrase}
		/while (${Zone.ShortName.Equal[nedaria]}) {
			/delay 1
		}
	}
/return



|--------------------------------------------------------------------------------
|SUB: markZoneComplete
|--------------------------------------------------------------------------------
Sub markZoneComplete
	/varset strZonePrefix ${Zone.ShortName.Left[3]}
	/declare strZoneNameRemainder	string 	local	${Zone.ShortName.Right[5]}
	/varset strZoneSuffix ${strZoneNameRemainder.Left[1]}
	/if (${strZonePrefix.Equal[mir]}) {
		/if (${strZoneSuffix.Equal[a]}) {
			/varset LDoN-MM-Gallery 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Gallery" 1
		} else /if (${strZoneSuffix.Equal[b]}) {
			/varset LDoN-MM-Menagerie 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Menagerie" 1
		} else /if (${strZoneSuffix.Equal[c]}) {
			/varset LDoN-MM-SpiderDen 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-SpiderDen" 1
		} else /if (${strZoneSuffix.Equal[d]}) {
			/varset LDoN-MM-Banquet 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Banquet" 1
		} else /if (${strZoneSuffix.Equal[e]}) {
			/varset LDoN-MM-FrostHalls 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-FrostHalls" 1
		} else /if (${strZoneSuffix.Equal[f]}) {
			/varset LDoN-MM-Wastes 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Wastes" 1
		} else /if (${strZoneSuffix.Equal[g]}) {
			/varset LDoN-MM-Heart 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Heart" 1
		} else /if (${strZoneSuffix.Equal[h]}) {
			/varset LDoN-MM-Laboratory 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Laboratory" 1
		} else /if (${strZoneSuffix.Equal[i]}) {
			/varset LDoN-MM-Theater 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Theater" 1
		} else /if (${strZoneSuffix.Equal[j]}) {
			/varset LDoN-MM-Library 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Library" 1
		}
	} else /if (${strZonePrefix.Equal[mmc]}) {
		/if (${strZoneSuffix.Equal[a]}) {
			/varset LDoN-MC-Cavern 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Cavern" 1
		} else /if (${strZoneSuffix.Equal[b]}) {
			/varset LDoN-MC-Grotto 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Grotto" 1
		} else /if (${strZoneSuffix.Equal[c]}) {
			/varset LDoN-MC-Asylum 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Asylum" 1
		} else /if (${strZoneSuffix.Equal[d]}) {
			/varset LDoN-MC-Chamber 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Chamber" 1
		} else /if (${strZoneSuffix.Equal[e]}) {
			/varset LDoN-MC-Sepulcher 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Sepulcher" 1
		} else /if (${strZoneSuffix.Equal[f]}) {
			/varset LDoN-MC-SummGround 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-SummGround" 1
		} else /if (${strZoneSuffix.Equal[g]}) {
			/varset LDoN-MC-Cesspit 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Cesspit" 1
		} else /if (${strZoneSuffix.Equal[h]}) {
			/varset LDoN-MC-Aisles 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Aisles" 1
		} else /if (${strZoneSuffix.Equal[i]}) {
			/varset LDoN-MC-Halls 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Halls" 1
		} else /if (${strZoneSuffix.Equal[j]}) {
			/varset LDoN-MC-Sanctuary 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Sanctuary" 1
		}
	} else /if (${strZonePrefix.Equal[guk]}) {
		/if (${strZoneSuffix.Equal[a]}) {
			/varset LDoN-DG-Cauldron 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Cauldron" 1
		} else /if (${strZoneSuffix.Equal[b]}) {
			/varset LDoN-DG-Crypt 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Crypt" 1
		} else /if (${strZoneSuffix.Equal[c]}) {
			/varset LDoN-DG-Aquaduct 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Aquaduct" 1
		} else /if (${strZoneSuffix.Equal[d]}) {
			/varset LDoN-DG-Mushroom 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Mushroom" 1
		} else /if (${strZoneSuffix.Equal[e]}) {
			/varset LDoN-DG-Prison 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Prison" 1
		} else /if (${strZoneSuffix.Equal[f]}) {
			/varset LDoN-DG-Chapel 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Chapel" 1
		} else /if (${strZoneSuffix.Equal[g]}) {
			/varset LDoN-DG-Garden 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Garden" 1
		} else /if (${strZoneSuffix.Equal[h]}) {
			/varset LDoN-DG-Sanctuary 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Sanctuary" 1
		}
	} else /if (${strZonePrefix.Equal[tak]}) {
		/if (${strZoneSuffix.Equal[a]}) {
			/varset LDoN-TH-Library 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Library" 1
		} else /if (${strZoneSuffix.Equal[b]}) {
			/varset LDoN-TH-Tower 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Tower" 1
		} else /if (${strZoneSuffix.Equal[c]}) {
			/varset LDoN-TH-Temple 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Temple" 1
		} else /if (${strZoneSuffix.Equal[d]}) {
			/varset LDoN-TH-Observatory 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Observatory" 1
		} else /if (${strZoneSuffix.Equal[e]}) {
			/varset LDoN-TH-River 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-River" 1
		} else /if (${strZoneSuffix.Equal[f]}) {
			/varset LDoN-TH-Sandfall 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Sandfall" 1
		} else /if (${strZoneSuffix.Equal[g]}) {
			/varset LDoN-TH-Chamber 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Chamber" 1
		} else /if (${strZoneSuffix.Equal[h]}) {
			/varset LDoN-TH-Tides 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Tides" 1
		} else /if (${strZoneSuffix.Equal[i]}) {
			/varset LDoN-TH-Palace 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Palace" 1
		} else /if (${strZoneSuffix.Equal[j]}) {
			/varset LDoN-TH-Prismatic 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Prismatic" 1
		}
	} else /if (${strZonePrefix.Equal[ruj]}) {
		/if (${strZoneSuffix.Equal[a]}) {
			/varset LDoN-RH-Quarries 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Quarries" 1
		} else /if (${strZoneSuffix.Equal[b]}) {
			/varset LDoN-RH-Halls 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Halls" 1
		} else /if (${strZoneSuffix.Equal[c]}) {
			/varset LDoN-RH-Bridges 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Bridges" 1
		} else /if (${strZoneSuffix.Equal[d]}) {
			/varset LDoN-RH-GladPit 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-GladPit" 1
		} else /if (${strZoneSuffix.Equal[e]}) {
			/varset LDoN-RH-Hollows 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Hollows" 1
		} else /if (${strZoneSuffix.Equal[f]}) {
			/varset LDoN-RH-Fort 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Fort" 1
		} else /if (${strZoneSuffix.Equal[g]}) {
			/varset LDoN-RH-Vale 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Vale" 1
		} else /if (${strZoneSuffix.Equal[h]}) {
			/varset LDoN-RH-Forge 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Forge" 1
		} else /if (${strZoneSuffix.Equal[i]}) {
			/varset LDoN-RH-Arena 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Arena" 1
		} else /if (${strZoneSuffix.Equal[j]}) {
			/varset LDoN-RH-Barracks 0
			/ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Barracks" 1
		}
	}
/return