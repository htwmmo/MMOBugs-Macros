| -------------------------------------------------------------------------------------------------------------
|                                   Ruins of Kunark Route for Explorer.Mac
|                                       		By: Fizz
|                                       	Started: 28/9/2020
| -------------------------------------------------------------------------------------------------------------
|
| Route: Overthere > Howling Stones > POK > Butcherblock > Firiona Vie > Swamp of No Hope > East Cabilis >
| Route: West Cabilis > Lake of Ill Omen > Veksar > Lake of Ill Omen > Frontier Mtns > Droga > Frontier Mtns >
| Route: Nurga > Frontier Mtns > Dreadlands > Karnors Castle > Burning Woods > Chardok > Chardok B > 
| Route: Chardok > Burning Woods > Skyfire > Veeshans Peak > POK > Overthere > Warslik Woods > Dalnir >
| Route: Warslik Woods > Field of Bone > Kurns Tower > Field of Bone > Kaesora > Field of Bone > 
| Route: Emerald Jungle > Sebilis
| -------------------------------------------------------------------------------------------------------------

Sub Rok

	/lazyfind on

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,Rok]}==1) /return
	
    /declare pokRok			int outer	0
    /declare illoman		int outer	0
    /declare frontier		int outer	0
    /declare dl				int outer	0
    /declare ot				int outer	0
    /declare char1			int outer	0
    /declare sf				int outer	0
    /declare charasis		int outer	0
	/declare wsw			int outer	0	
	/declare fob			int outer	0
	/declare ej				int outer	0	
	
	/varset completed 0	
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Ruins of Kunark${Teal}**
			

|-----------------------------------------------------------------------------------------------------------
| Travel Loop - Rok
|-----------------------------------------------------------------------------------------------------------
	
	/call checkPotionStock


:rok
	
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call pokRok
	
|-Path 1
	/if (${Zone.ID}==93) 			/call overthere
	/if (${Zone.ID}==105) 			/call charasis
	
|-Path 2	
	/if (${Zone.ID}==68)			/call gotoTim
	/if (${Zone.ID}==96) 			/call timorous	
	/if (${Zone.ID}==84) 			/call firiona
	/if (${Zone.ID}==106) 			/call cabeast
	/if (${Zone.ID}==85) 			/call illoman	
	/if (${Zone.ID}==109) 			/call veksar
	/if (${Zone.ID}==92) 			/call frontier
	/if (${Zone.ID}==81) 			/call droga
	/if (${Zone.ID}==107) 			/call nugra	
	/if (${Zone.ID}==86) 			/call dreadlands	
	/if (${Zone.ID}==102) 			/call karnors	
	/if (${Zone.ID}==277) 			/call chardokb
	/if (${Zone.ID}==103) 			/call chardok
	/if (${Zone.ID}==91) 			/call skyfire
	/if (${Zone.ID}==108) 			/call vp
	
|-Path 3
	/if (${Zone.ID}==79) 			/call warslikswood
	/if (${Zone.ID}==104) 			/call dalnir
	/if (${Zone.ID}==78) 			/call fieldofbone
	/if (${Zone.ID}==97) 			/call kurn
	/if (${Zone.ID}==88) 			/call kaesora
	/if (${Zone.ID}==94) 			/call emeraldjungle
	/if (${Zone.ID}==90) 			/call com
	/if (${Zone.ID}==89) 			/call RokComplete	
	
	/delay 2m !${Navigation.Active}
	
	/goto :rok																																										
/return



| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub RokComplete	
	/echo ${White}You have completed Exploring: ${Green}Ruins of Kunark. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "Rok" "1"
	/delay 1s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub pokRok
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${pokRok}==0) 			{
								/call travelToZone overthere
	} else /if (${pokRok}==1)	{
								/lazyfind on
								/call travelToZone butcher
	} else /if (${pokRok}==2)	{
								/call travelToZone overthere
	}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}
/return

Sub overthere
    /delay 1s
	/call Navigating
	/call invisMe
	
	
	/if (${ot}==0) 			{
							/call travelToZone charasis
	} else /if (${ot}==1)	{
							/call travelToZone warslikswood
							}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[overthere]}
/return


Sub charasis
	/delay 1s
	/varset ot 1
	/varset pokRok 1
	/delay 2s
	/echo ${Yellow}Taking a shortcut, Evac incoming
	/call Evac
/return


Sub gotoTim
	/delay 1s
	/squelch /nav loc 856 3175 8
	/delay 3m !${Navigation.Active}
	/makemevisible
	/delay 2s
	/if (${SpawnCount[npc Translocator radius 20]}) /target npc Translocator_Gethia
	/delay 5s ${Target.ID}
	/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Translocator Gethia]}) 	{
																					/makemevisible
																					/say Travel to Timorous Deep
																					}
	/delay 8s !${Zone.ShortName.Equal[butcher]}
/return

Sub timorous
	/delay 1s
	/squelch /nav loc -4548 -3260 20
	/delay 2s
	/delay 2m !${Navigation.Active}
	/if (${SpawnCount[npc Translocator radius 20]}) /target npc Translocator_Deela
	/delay 5s ${Target.ID}
	/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Translocator Deela]}) 	{
																					/makemevisible
																					/say Firiona Vie
																					}
	/delay 8s !${Zone.ShortName.Equal[timorous]}
/return

Sub firiona
    /delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone cabeast
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[firiona]}
/return

Sub cabeast
    /delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone lakeofillomen
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[cabeast]}
/return


Sub illoman
    /delay 1s
	/call Navigating
	/call invisMe
	/if (${illoman}==0) 		{
									/call travelToZone veksar
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[lakeofillomens]}
	} else /if (${illoman}==1)	{
									/call travelToZone frontiermtns
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[lakeofillomens]}
	}
/return

Sub veksar
	/delay 1s
	/varset illoman 1
	/delay 1s
	/squelch /nav loc -660 32 -30
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[veksar]}
/return

Sub frontier
    /delay 1s
	/call Navigating
	/call invisMe
	/if (${frontier}==0)  		{
								/call travelToZone droga
	} else /if (${frontier}==1)	{
								/call travelToZone nurga 
	} else /if (${frontier}==2)	{
								/call travelToZone dreadlands
								}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[frontiermtns]}
/return

Sub droga
	/delay 2s
	/call Navigating
	/varset frontier 1
	/delay 3s
	/call travelToZone frontiermtns
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[droga]}
/return

Sub nugra
	/delay 1s
	/call Navigating
	/varset frontier 2
	/delay 1s
	/call travelToZone frontiermtns
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[nugra]}
/return

Sub dreadlands
    /delay 1s
	/call Navigating
	/call invisMe
	/if (${dl}==0)  		{
							/call travelToZone karnor
	} else /if (${dl}==1)	{
							/call travelToZone chardok 
							} 
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[dreadlands]}
/return

Sub karnors
	/delay 1s
	/call Navigating
	/varset dl 1
	/delay 1s
	/squelch /nav loc 115 451 0
	/if (${Me.Y}>401) /nav loc 115 351 0
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[karnors]}
/return

Sub chardok
    /delay 1s
	/call Navigating
	/call invisMe
	
	/if (${char1}==0)  		{
							/call travelToZone chardokb
	} else /if (${char1}==1)	{	
							/delay 1s
							/call Navigating
							/delay 1s
							/if (${Me.Height}<3.4) {
													/call EqAtFront
													/squelch /nav loc 260 598 85
													/delay 3m !${Navigation.Active}
													/delay 3s
													/face heading 110
													/keypress forward hold
													/delay 1s
													/keypress jump hold
													/delay 1s
													/keypress forward lift
													}
													
							
							/call travelToZone skyfire
							/delay 3m !${Navigation.Active}
							/delay 8s !${Zone.ShortName.Equal[chardok]}
							}

/return

Sub chardokb
	/delay 2s
	/varset char1 1
	/call Navigating
	/delay 3s
	/squelch /nav door id 37 click
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[chardokb]}
/return

Sub Skyfire
    /delay 1s
	/call Navigating
	/call invisMe
	/if (${sf}==0) 			{
							/echo Traveling to ${Green}Veeshans Peak
							/squelch /nav loc 2395 3009  -85
							/delay 3m !${Navigation.Active}
							/if (${Me.Height}<3.4) {
													/call EqAtFront
													/face heading 0
													/while (${Me.Y}<2450) 	{
																			/keypress forward hold
																			/keypress jump hold
																			/delay 3
																			}
													}
							/nav loc 2778 2974 -81
							/delay 10s !${Navigation.Active}
							/doortarget id 135
							/click left door
							/delay 8s !${Zone.ShortName.Equal[skyfire]}
	} else /if (${sf}==1)	{
							/call travelToZone charasis
							/delay 3m !${Navigation.Active}
							/delay 8s !${Zone.ShortName.Equal[skyfire]}
							}
/return

 Sub vp
	/delay 1s
	/varset pokRok 2
	/delay 2s
	/echo ${Yellow}Taking a shortcut, Evac incoming
	/call Evac
/return

Sub warslikswood
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${wsw}==0) 		{
							/echo Traveling to ${Green}Dalnir
							/squelch /nav loc 2569 4528 -244
	} else /if (${wsw}==1)	{
							/call travelToZone fieldofbone
	}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[fieldofbone]}
/return

 Sub dalnir
	/delay 4s
	/varset wsw 1
	/call travelToZone warslikswood
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[dalnir]}
/return

Sub fieldofbone
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${fob}==0) 			{
								/echo Traveling to ${Green}Kurn's Tower
								/squelch /nav loc 459 1022 61
								/delay 3m !${Navigation.Active}
								/delay 4s
								/squelch /nav loc 458 1060 61
	} else /if (${fob}==1)	{
								/echo Traveling to ${Green}Kaesora
								/squelch /nav loc -1893 -125 -132
	} else /if (${fob}==2)	{
								/echo Traveling to ${Green}Emerald Jungle
								/squelch /nav loc -1992 -1295 -6
	}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[fieldofbone]}
/return

Sub kurn
	/delay 2s
	/varset fob 1
	/call Navigating
	/delay 2s
	/squelch /nav loc -283 45 0
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[kurn]}
/return

Sub kaesora
	/delay 2s
	/varset fob 2
	/call Navigating
	/delay 2s
	/squelch /call travelToZone fieldofbone
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[kaesora]}
/return

Sub emeraldjungle
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${ej}==0) 			{
							/call travelToZone citymist
	} else /if (${ej}==1)	{
							/call travelToZone sebilis	 
	}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[emeraldjungle]}
/return

Sub com
	/delay 2s
	/varset ej 1
	/call Navigating
	/delay 2s
	/call travelToZone emeraldjungle
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[citymist]}
/return
