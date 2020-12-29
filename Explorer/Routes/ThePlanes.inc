| -------------------------------------------------------------------------------------------------------
|                                   The Planes Route for Explorer.Mac
|                                       		By: Fizz
|                                       	Started: 28/9/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Nexus > Lceanium > Nexus > PoK > Fear > PoK > Air > Hate
|
| -------------------------------------------------------------------------------------------------------

Sub ThePlanes

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,ThePlanes]}==1) /return
	/lazyfind on

    /declare planes				int outer	0
    /declare lceaniumPlanes		int outer	0
    /declare nexusPlanes		int outer	0
    /declare tranquilityPlanes	int outer	0
	
	/varset completed 0
	
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}The Planes ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - ThePlanes
|--------------------------------------------------------------------------------------
	
	/call checkPotionStock
	
:OP
	
	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,ThePlanes]}==1) /return
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call planes
	/if (${Zone.ID}==152) 						/call nexusPlanes
	/if (${Zone.ID}==794) 						/call lceaniumPlanes
	/if (${Zone.ID}==47) 						/call feerrottPlanes
	/if (${Zone.ID}==72) 						/call fearplane
	/if (${Zone.ID}==203) 						/call tranquilityPlanes
	/if (${Zone.ID}==71) 						/call airplane	
	/if (${Zone.ID}==382) 						/call travelToZone freeportsewers	
	/if (${Zone.ID}==384) 						/call travelToZone freeportwest
	/if (${Zone.ID}==383) 						/call freeport2pok
	/if (${Zone.ID}==186) 						/call ThePlanesComplete	
	
	/delay 2m !${Navigation.Active}
	
	/goto :OP																																										
/return



| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub ThePlanesComplete	
	/echo ${White}You have completed Exploring: ${Green}The Planes. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s	
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "ThePlanes" "1"
	/delay 1s
	/call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub planes
    /delay 1s
	/call Navigating
	/call invisMe
	
	
	/if (${planes}==0) 			{
								/nav door id 4 click
								/delay 2m !${Navigation.Active}
								/delay 2s
								/notify LargeDialogWindow LDW_NoButton leftmouseup
								/delay 8s !${Zone.ShortName.Equal[poknowledge]}
	} else /if (${planes}==1)	{
								/call travelToZone nexus
								/delay 2m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[poknowledge]}
	} else /if (${planes}==2)	{
								/call travelToZone potranquility
								/delay 2m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[poknowledge]}
								}
/return


Sub feerrottPlanes
    /delay 1s
	/call Navigating
	/call invisMe
	/delay 1s
	/if (${Me.Height}<3.4) {
							/squelch /nav loc -2367 2603 17
							/delay 3m !${Navigation.Active}
							/face fast heading 176.22
							/delay 5
							/while (${Zone.ShortName.Equal[feerrott]}) {
																		:EnterFear			
																		/keypress forward hold
																		/keypress jump hold
																		/delay 1s
																		/if (${Me.Z}<-2400) /goto :EnterFear
																		/keypress forward lift
																		}
							}
	
	/if (${Me.Height}>3.41) {
							/call travelToZone fearplane
							/delay 2m !${Navigation.Active}
							/delay 8s !${Zone.ShortName.Equal[feerrott]}
							}
	
    /keypress forward
/return

Sub fearplane
	/call Navigating
	/varset planes 1
    /delay 1s
	/call evac
	/delay 8s !${Zone.ShortName.Equal[fearplane]}
/return

Sub nexusPlanes

/if (${FindItemCount[Cloudy Stone of Veeshan]}>0 && ${FindItemCount[Fuligan Soulstone of Innoruuk]}>0) 	{
																										/echo ${Teal}It appears you have the stones, so we have no need to go buy them....
																										/varset planes 2
																										/varset nexusPlanes 1
																										/delay 2s
																										}
	/if (${nexusPlanes}==0) 		{
									/delay 2s
									/nav spawn npc Jayson_Bri`Tian
									/delay 2m !${Navigation.Active}
									/makemevisible
									/delay 2s
									/varset planes 2
									/if (${SpawnCount[npc Jayson radius 10]}) /target npc Jayson_Bri`Tian
									/delay 5s ${Target.ID}
									/if (${Target.Distance}<15 && ${Target.CleanName.Equal[Jayson Bri`Tian]}) 	{
																												/say Spire Stone of Lceanium
																												/delay 3s
																												/autoinventory
																												/delay 2s
																												/squelch /nav loc 0 0 -30
																												/while (${Zone.ID}==152) 	{
																																			/delay 20s
																																			/echo ${Yellow}Waiting on Portal
																																			}
																												}
																											
									/delay 8s !${Zone.ShortName.Equal[nexus]}
								
	} else /if (${nexusPlanes}==1)	{
									/delay 1s
									/call travelToZone Poknowledge
									/delay 1m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[nexus]}
	}
/return

Sub lceaniumPlanes

	/if (${lceaniumPlanes}==0) 	{
								/delay 1s
								/call invisMe
								/while (${GameTime.Night}) {
															/echo ${Yellow} It appears that the store is ${Red}Closed. 
															/echo ${Yellow} The store opens at 7am.
															/echo ${Yellow} Time is ${Pink}${GameTime.Time24}. 
															/delay 30s
															}
								/if (${GameTime.Day}) 		{
															/echo ${Yellow} The store is ${Green}Open.
															/echo ${Yellow} Time to shop!.
															/nav spawn npc Rossette_Mosgrow
															/delay 3m !${Navigation.Active}
															}
								/if (${SpawnCount[npc Rossette radius 10]}) /target npc Rossette Mosgrow
								/delay 5s ${Target.ID}
								/if (${Target.Distance}<10 && ${Target.CleanName.Equal[Rossette Mosgrow]}) 	{
																											/varset lceaniumPlanes 1
																											/delay 2s
																											
																											/if (${FindItemCount[Cloudy Stone of Veeshan]}<1) 			{
																																										/call BuyItem "Cloudy Stone of Veeshan" 1
																																										}																											
																											/if (${FindItemCount[Fuligan Soulstone of Innoruuk]}<1) 	{
																																										/call BuyItem "Fuligan Soulstone of Innoruuk" 1
																																										}
																											/if (${FindItemCount[Cloudy Stone of Veeshan]}>0 && ${FindItemCount[Fuligan Soulstone of Innoruuk]}>0) 	{
																																																					/nomodkey /notify MerchantWnd MW_Done_Button LeftMouseUp
																																																					}
																											}
	} else /if (${lceaniumPlanes}==1)	{
										/echo ${Green}Got what we need, let's go.
										/delay 1s
										/call invisMe
										/squelch /nav spawn npc Greeter_Okula
										/delay 3m !${Navigation.Active}
										/delay 2s
										/varset nexusPlanes 1
										/if (${SpawnCount[npc Greeter radius 10]}) /target npc Greeter_Okula
										/delay 5s ${Target.ID}
										/if (${Target.Distance}<15 && ${Target.CleanName.Equal[Greeter Okula]}) {
																												/makemevisible
																												/delay 1s
																												/say Spire Stone of Lceanium
																												/delay 3s
																												/autoinventory
																												/squelch /nav loc 1349 1448 -55
																												/delay 8s !${Zone.ShortName.Equal[lceanium]}
																												/while (${Zone.ID}==794) 	{
																																			/delay 20s
																																			/echo ${Yellow}Waiting on Portal
																																			}
																												}
										}
/return

Sub tranquilityPlanes
    /delay 1s
	/call Navigating
	
	/if (${tranquilityPlanes}==0) 	{
									/delay 2s
									:movetoRelm
									/squelch /nav spawn npc Relm_M`Loch
									/delay 5s !${Navigation.Active}
									/if (${SpawnCount[npc Relm radius 10]}) /target npc Relm_M`Loch
									/delay 5s ${Target.ID}
									/if (${Target.Distance}>10) /goto :movetoRelm
									/if (${Target.Distance}<10 && ${Target.CleanName.Equal[Relm M`Loch]}) 	{
																											/makemevisible	
																											/ctrlkey /itemnotify "Cloudy Stone of Veeshan" leftmouseup
																											/delay 2s ${Cursor.ID}==${FindItem[=Cloudy Stone of Veeshan].ID}
																											/while (${Cursor.ID}) 	{
																																	/click left target
																																	/delay 5 !${Cursor.ID}
																																	}
																											/notify GiveWnd GVW_Give_Button leftmouseup
																											/delay 2s !${Window[GiveWnd].Open}
																											}																					
	} else /if (${tranquilityPlanes}==1)	{
											/delay 2s
											:movetoRelm
											/squelch /nav spawn npc Relm_M`Loch
											/delay 5s !${Navigation.Active}
											/if (${SpawnCount[npc Relm radius 10]}) /target npc Relm_M`Loch
											/delay 5s ${Target.ID}
											/if (${Target.Distance}>10) /goto :movetoRelm
											/if (${Target.Distance}<10 && ${Target.CleanName.Equal[Relm M`Loch]}) 	{
																													/makemevisible	
																													/ctrlkey /itemnotify "Fuligan Soulstone of Innoruuk" leftmouseup
																													/delay 2s ${Cursor.ID}==${FindItem[=Fuligan Soulstone of Innoruuk].ID}
																													/while (${Cursor.ID}) 	{
																																			/click left target
																																			/delay 5 !${Cursor.ID}
																																			}
																													/notify GiveWnd GVW_Give_Button leftmouseup
																													/delay 2s !${Window[GiveWnd].Open}
																													}
											}
										/delay 8s !${Zone.ShortName.Equal[potranquility]}		
/return


Sub Airplane
	/delay 1s
	/varset tranquilityPlanes 1
	/delay 1s
	/keypress forward hold
	/delay 5s
	/keypress forward lift
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return

Sub freeport2pok
	/delay 1s
	/squelch /nav door id 41 click 
	/delay 8s !${Zone.ShortName.Equal[freeportwest]}
/return