1| -------------------------------------------------------------------------------------------------------
|                                    Scars of Velious Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 7/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Great Divide > Thurgadin  > Icewell Keep > Thurgadin > Great Divide > Velketor's Labyrinth >
| Route Cont:  Great Divide > Plane of Mischief > Cobalt Scar > Western Wastes > Dragon Necropolis > 
| Route Cont: Western Wastes > Temple of Veeshan > Pok > Great Divide > Plane of Mischief > Cobalt Scar > 
| Route Cont: Skyshrine > Wakening Lands > Plane of Growth Pok > Great Divide > Eastern Wastes >
| Route Cont: Kael > Sleeper
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub SoV
	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,SoV]}==1) /return
	/lazyfind on

	/declare gd1			int outer 0
	/declare thurga 		int outer 0
	/declare cscar 			int outer 0
	/declare wwaste			int outer 0
	/declare ewaste			int outer 0
	
	/varset completed 0
	
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Scars of Velious ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - SoV
|--------------------------------------------------------------------------------------

	/call checkPotionStock

:SoV
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone greatdivide
	/if (${Zone.ID}==118) 						/call greatdivideSoV
	
| Path 1
	/if (${Zone.ID}==115) 		/call thurgadina 
	/if (${Zone.ID}==129) 		/call thurgadinb 
	/if (${Zone.ID}==112) 		/call velketor 
	/if (${Zone.ID}==126) 		/call mischiefplane 
	/if (${Zone.ID}==117) 		/call cobaltscar 
	/if (${Zone.ID}==125) 		/call sirens 
	/if (${Zone.ID}==120) 		/call westwastes 
	/if (${Zone.ID}==123) 		/call necropolis 
	/if (${Zone.ID}==124) 		/call templeveeshan 
	
| Path 2
	/if (${Zone.ID}==114) 		/call skyshrine 
	/if (${Zone.ID}==127) 		/call growthplane 

| Path 3
	/if (${Zone.ID}==116) 		/call eastwastes 
	/if (${Zone.ID}==121) 		/call crystal 
	/if (${Zone.ID}==113) 		/call kael 
	/if (${Zone.ID}==128) 		/call sleeper
	/if (${Zone.ID}==110) 		/call iceclad 
	/if (${Zone.ID}==111) 		/call SoVComplete 
	/delay 2m !${Navigation.Active}
	/goto :SoV
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub SoVComplete	
	/echo ${White}You have completed Exploring: ${Green}Scars of Veeshan. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "SoV" "1"
	/delay 2s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub SoVpok
    /delay 1s
	
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}
/return

Sub greatdivideSoV
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${gd1}==0) 		{
							/call cancelLevi
							/echo Traveling to ${Green}Thurgadin
							/squelch /nav loc 97 -110 97
	} else /if (${gd1}==1)	{
							/call travelToZone velketor
	} else /if (${gd1}==2)	{
							/call travelToZone mischiefplane
	} else /if (${gd1}==3)	{
							/call travelToZone eastwastes
	}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[greatdivide]}
/return

Sub thurgadina
    /delay 1s
	/varset gd1 1
	/call shrinkMe
	/call Navigating
	/call invisMe
		
	/if (${thurga}==0) 			{
								/echo Traveling to ${Green}Icewell Keep
								/squelch /nav loc 293 -3 -1
								/if (${Me.Y} > 275) /moveto 314 -5 -1
	} else /if (${thurga}==1)	{
								/echo Traveling to ${Green}The Great Divide
								/squelch /nav loc -1252 10 -5
	}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thurgadina]}
/return

Sub thurgadinb
	/delay 2s
	/varset thurga 1
	/delay 2s
	/nav loc 69 42 -1
    /delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thurgadinb]}
/return
	
Sub velketor
	/delay 2s
	/varset gd1 2
	/delay 2s
	/squelch /nav loc 624 -70 -155
    /if (${Me.Y} > 625) /moveto loc 600 -73 -156
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thurgadinb]}
/return

Sub mischiefplane
	/delay 1s
	/squelch /nav loc -1026 -356 96
	/squelch /doortarget id 226
    /click left door
    /delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[mischiefplane]}
/return
	
Sub cobaltscar
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${cscar}==0) 			{
								/call travelToZone sirens
	} else /if (${cscar}==1)	{
								/call travelToZone skyshrine
	}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[cobaltscar]}
/return
	
Sub westwastes
    /delay 1s
	/call Navigating
	/call invisMe
		
	/if (${wwaste}==0) 			{
								/call travelToZone necropolis
	} else /if (${wwaste}==1)	{
								/call travelToZone templeveeshan
	}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[westwastes]}
/return	

Sub sirens
	/delay 2s
	/varset cscar 1
	/echo Traveling to ${Green}Western Wastes
    /squelch /nav loc 244 -74 0
    /delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[necropolis]}
/return
		

Sub necropolis
	/delay 2s
	/varset wwaste 1
	/delay 2s
	/echo Traveling to ${Green}Western Wastes
    /squelch /nav door id 59 click
    /delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[necropolis]}
/return
		
Sub templeveeshan
	/delay 2s
	/echo ${Green}Taking shortcut
	/delay 2s
	/call Evac
/return
	
Sub skyshrine
	/delay 1s
	/varset gd1 3
	/call cancelLevi
    /call travelToZone growthplane
    /delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[skyshrine]}
/return

Sub growthplane
	/delay 2s
	/echo ${Green}Taking shortcut
	/delay 2s
	/call Evac
/return
	
Sub eastwastes
    /delay 1s
	/call Navigating
	/call invisMe
	/if (${ewaste}==0) 			{
								/call travelToZone crystal
	} else /if (${ewaste}==1)	{
								/call travelToZone kael
	} else /if (${ewaste}==2)	{
								/echo Traveling to ${Green}Sleepers Tomb
								/squelch /nav door id 44 click
	} else /if (${ewaste}==3)	{
								/call travelToZone iceclad
	}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[eastwastes]}
/return
	
Sub crystal
	/delay 4s
	/varset ewaste 1
	/squelch /nav loc 460 313 -78
    /delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[crystal]}
/return

Sub kael
	/delay 4s
	/varset ewaste 2
    /call travelToZone eastwastes
    /delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[kael]}
/return

Sub sleeper
	/delay 4s
	/varset ewaste 3
	/squelch /nav Door id 53 click
    /delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[sleeper]}
/return

Sub iceclad
	/delay 1s
    /echo Traveling to ${Green}Tower of Frozen Shadow
	/squelch /nav loc 1719 2862 121
    /doortarget id 13
    /click left door
    /delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[sleeper]}
/return