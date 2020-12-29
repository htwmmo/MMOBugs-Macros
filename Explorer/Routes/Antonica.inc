| -------------------------------------------------------------------------------------------------------
|                                    Antonica Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 28/9/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Shadowrest > Blackfeather Roost > Frostcrypt > Vergalid Mines > Ashengate > Bixiewarfront >
| Route cont: Ethernere > Highkeep > Valley of King Xorbb > Rivervale > befallen > Freeport Sewer >
| Route cont: FreeportEast > Argith > Ethernere > Lower Guk > Grobb > Cazic Thule > Oggok > Arena >
| Route cont: Splitpaw > Surefall > Jaggedpine Forrest > Nedaria's Landing > Qeynos > QeynosCats > 
| Route cont: South Qeynos > Sol Temple > Nejena > Sol A > Sol B > Sol C >Stillmoon > The Ascent >
| Route cont: The Nest > Lavaspinners Lair > delveb > Neriak Forth Gate > Ethernere > PoK
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub Antonica

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,Antonica]}==1) /return
	/lazyfind on
	
    /declare pokant       		int outer	0	  
    /declare commonlands   		int outer	0  
    /declare sro       			int outer	0   
    /declare arginhiz   		int outer	0
	/declare guk   				int outer	0
	/declare feerrott   		int outer	0
	/declare paw   				int outer	0
	/declare qhills				int outer	0
    /declare surefall			int outer	0
    /declare jaggedpine			int outer	0
	/declare NQeynos   			int outer	0
	/declare everfrost 			int outer	0
    /declare solb   			int outer	0

	/varset DoExpansion 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Antonica ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - Antonica
|--------------------------------------------------------------------------------------

	/call checkPotionStock
	/call checkPotionStock levi
	
:Antonica
					
	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call PokAnt
	/if (${Zone.ID}==6) 						/call travelToZone beholder
	/if (${Zone.ID}==16) 						/call beholder
	/if (${Zone.ID}==11) 						/call runnyeye	
	/if (${Zone.ID}==415) 						/call travelToZone rivervale
	/if (${Zone.ID}==19) 						/call travelToZone commonlands		
	/if (${Zone.ID}==408) 						/call commonlands
	/if (${Zone.ID}==36) 						/call befallen
	/if (${Zone.ID}==383) 						/call freeportwest
	/if (${Zone.ID}==384) 						/call travelToZone freeporteast	
	/if (${Zone.ID}==382) 						/call travelToZone southro
	/if (${Zone.ID}==393) 						/call sro	
	/if (${Zone.ID}==776) 						/call arginhiz	
	/if (${Zone.ID}==413) 						/call innothuleb
	/if (${Zone.ID}==65) 						/call upperguk
	/if (${Zone.ID}==66) 						/call lowerguk
	/if (${Zone.ID}==52) 						/call exitGrobb
	/if (${Zone.ID}==47) 						/call feerrott	
	/if (${Zone.ID}==48) 						/call cazicthule
	/if (${Zone.ID}==49) 						/call oggokexit	
	/if (${Zone.ID}==77) 						/call travelToZone southkarana
	/if (${Zone.ID}==14) 						/call skarana
	/if (${Zone.ID}==18) 						/call paw	
	/if (${Zone.ID}==12) 						/call westkarana
	/if (${Zone.ID}==4) 						/call qeytoqrg
	/if (${Zone.ID}==3) 						/call surefall
	/if (${Zone.ID}==181)						/call jaggedpine
	/if (${Zone.ID}==182)						/call nedariaAnt
	/if (${Zone.ID}==2) 						/call NQeynos		
	/if (${Zone.ID}==45) 						/call qcatexit	
	/if (${Zone.ID}==1) 						/call qeynos
	/if (${Zone.ID}==17) 						/call blackburrow
	/if (${Zone.ID}==30) 						/call everfrost
	/if (${Zone.ID}==29) 						/call halas
	/if (${Zone.ID}==73) 						/call permafrost		
	/if (${Zone.ID}==80) 						/call travelToZone najena		
	/if (${Zone.ID}==44) 						/call travelToZone soldunga
	/if (${Zone.ID}==31) 						/call sola	
	/if (${Zone.ID}==32) 						/call solb
	/if (${Zone.ID}==278) 						/call AntonicaComplete		
	
	/delay 2m !${Navigation.Active}
/goto :Antonica	
/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub AntonicaComplete	
	/echo ${White}You have completed Exploring: ${Green}Antonica. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "Antonica" "1"
	/delay 1s
    /call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------
	
Sub PokAnt
	/delay 1s
	/if (${pokant}==0) 			{
								/delay 1s
								/call travelToZone highkeep
	} else /if (${pokant}==1) 	{
								/delay 1s
								/call travelToZone soltemple 
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}			
/return	


Sub beholder
    /delay 1s
	/call invisMe
	/call Navigating
	/varset pokant 1
	/echo Traveling to ${Green}Clan Runnyeye	
	/squelch /nav loc 901 -1867.82 5.1
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[beholder]}
/return

Sub runnyeye
    /delay 1s
	/call invisMe
	/call Navigating
	/echo Traveling to ${Green}Misty Thicket	
	/squelch /nav loc 255 151.21 5.1
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[runnyeye]}
/return

Sub commonlands
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${commonlands}==0) 		{
									/call travelToZone befallen
	} else /if (${commonlands}==1) {
									/call travelToZone freeportwest
	}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[commonslands]}	
/return	

Sub befallen
    /delay 1s
	/call invisMe
	/call Navigating
	/varset commonlands 1
    /squelch /nav loc -55 35.25 0
    /delay 3s
	/delay 8s !${Zone.ShortName.Equal[befallen]}
/return
	
Sub freeportwest 
    /delay 1s
	/call invisMe
	/call Navigating
    /squelch /nav loc 960.90 -162.57 -71.76
    /delay 3s
    /delay 2m !${Navigation.Active}
    /squelch /moveto loc 1025.96 -157.87 -80.43
    /delay 3s
    /delay 1m !${Me.Moving}
    /squelch /moveto loc 1027.87 -130.37 -81.43
    /delay 3s
	/delay 8s !${Zone.ShortName.Equal[freeportwest]}
/return

Sub Sro
	/delay 1s
	/call invisMe
	/call Navigating
	/call travelToZone innothuleb
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[southro]}
/return

Sub innothuleb
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${guk}==0) 		{							
							/echo Traveling to ${Green}The City of Guk
							/squelch /nav loc -10 -1120 24
							/delay 3m !${Navigation.Active}
							/squelch /nav loc -10 -1180 24
							/delay 3m !${Navigation.Active}
							/if (${Zone.ID}==413 && ${Me.Y} >-1160)	/squelch /moveto -10 -1120 24
	} else /if (${guk}==1) {
							/call travelToZone grobb
	} else /if (${guk}==2) {
							/call invisMe
							/call travelToZone feerrott
							}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[innothuleb]}
/return	

Sub upperguk 
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${guk}==0) 		{
							/delay 1s
							/call EqAtFront
							/keypress FIRST_PERSON_CAMERA
							/delay 3s
							/nav loc 1158.53 -164.76 -87.27
							/delay 3s
							/delay 3m !${Navigation.Active}
							/squelch /moveto loc 1157.43 -191.63 -79.97
							/delay 2s !${Me.Moving}
							/squelch /nav loc 1196.53 -210.06 -83.97
	} else /if (${guk}==1) {
							/keypress FIRST_PERSON_CAMERA
							/call EqAtFront
							/call shrinkMe
							/delay 1s
							/call travelToZone innothuleb
							}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[guktop]}	
/return	

Sub lowerguk 
    /delay 1s
	/call invisMe
	/call Navigating
	/keypress FIRST_PERSON_CAMERA
    /squelch /nav loc 1195.77 -199.76 -83.97
	/varset guk 1 
    /delay 3s
	/delay 8s !${Zone.ShortName.Equal[gukbottom]}
/return

Sub exitGrobb
    /delay 1s
	/call invisMe
	/call Navigating
	/varset guk 2
    /squelch /nav loc -150 50 0
    /delay 3s
	/delay 8s !${Zone.ShortName.Equal[grobb]}
/return

Sub feerrott
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${feerrott}==0) 		{
								/delay 1s
								/call travelToZone cazicthule
								/delay 4m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[feerrott]}
	} else /if (${feerrott}==1) {
								/delay 1s
								/call invisMe
								/call travelToZone oggok
								/delay 4m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[feerrott]}
	} else /if (${feerrott}==2) {
								/delay 1s
								/call invisMe
								/call travelToZone arena
								/delay 4m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[feerrott]}
	}
/return	

Sub cazicthule
	/delay 1s
	/varset feerrott 1
	/call travelToZone feerrott
	/delay 18s !${Zone.ShortName.Equal[cazicthule]}
/return

Sub oggokexit 
        /delay 1s
		/echo Traveling to ${Green}Feerrott	
		/varset feerrott 2 		
        /squelch /nav loc -419 -96 -0.00
        /delay 3s
	/delay 8s !${Zone.ShortName.Equal[oggok]}
/return

Sub skarana	
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${paw}==0) 		{
							/delay 1s
							/echo Traveling to ${Green}The Lair of the Splitpaw		
							/squelch /nav loc -3120 915.61 -11.80
							/delay 3s
							/delay 4m !${Navigation.Active}
							/delay 8s !${Zone.ShortName.Equal[southkarana]}
	} else /if (${paw}==1) {
							/delay 1s
							/call travelToZone qey2hh1
							/delay 4m !${Navigation.Active}
							/delay 8s !${Zone.ShortName.Equal[southkarana]}
	}	
/return		

Sub Paw
	/delay 1s
	/call invisMe
	/call Navigating
	/varset paw 1
	/delay 1s
	/call travelToZone southkarana
    /delay 8s !${Zone.ShortName.Equal[paw]}
/return

	
Sub westkarana 
    /delay 1s
	/call invisMe
	/call Navigating
	/echo Traveling to ${Green}Qeynos Hills	
    /squelch /nav loc 68 80 -7
    /delay 3s
	/delay 7m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[qey2hh1]}
/return

Sub qeytoqrg
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${qhills}==0) 			{
								/delay 1s
								/echo Traveling to ${Green}Surefall Glade
								/squelch /nav loc 5189 115.50 -2
								/delay 3m !${Navigation.Active}
								/squelch /nav loc 5209 88.50 -6.6
	} else /if (${qhills}==1) 	{
								/delay 1s
								/call travelToZone qeynos2
	} else /if (${qhills}==2)	{
								/delay 1s
								/echo Traveling to ${Green}Blackburrow
								/squelch /nav loc 3444 -1115.50 0
								/delay 3m !${Navigation.Active}
								/keypress forward
	}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[qeytoqrg]}
/return	

Sub surefall 
    /delay 1s
	/call invisMe
	/call Navigating
	/varset qhills 1
	/if (${surefall}==0) 		{
								/echo Traveling to ${Green}Jaggedpine Forrest
								/squelch /nav door ID 3 click
	} else /if (${surefall}==1)	{
								/call travelToZone qey2hh1	
								}
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[qrg]}							
/return

Sub jaggedpine
    /delay 1s
	/call invisMe
	/call Navigating
	/varset surefall 1
	/if (${jaggedpine}==0) 			{
									/squelch /nav loc -578 2762 4.9
									/delay 2m !${Navigation.Active}
									/squelch /doortarget 
									/click left door
									/delay 1s
									/call travelToZone nedaria
	} else /if (${jaggedpine}==1)	{
									/squelch /nav loc -584 2810 4.9
									/delay 1m !${Navigation.Active}
									/squelch /doortarget 
									/click left door
									/delay 1s
									/nav door ID 2 click
									}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[jaggedpine]}
/return

Sub nedariaAnt
    /delay 5s
	/varset jaggedpine 1
    /delay 1s
	/call travelToZone jaggedpine
	/delay 8s !${Zone.ShortName.Equal[nedaria]}
/return

Sub NQeynos
    /delay 1s
	/call invisMe
	/call Navigating
	/if (${NQeynos}==0) 		{
								/delay 1s
								/call invisMe
								/echo Traveling to ${Green}Qeynos Aquaduct System	
								/squelch /nav loc 176.77 70.67 -35.94
								/delay 3s
	} else /if (${NQeynos}==1)	{
								/delay 1s
								/call travelToZone qeynos
	} else /if (${NQeynos}==2)	{
								/delay 1s
								/varset qhills 2
								/call travelToZone qeytoqrg
								}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[qeynos2]}								
/return

Sub qcatexit
    /delay 1s
	/call invisMe
	/call Navigating	
	/echo Traveling to ${Green}North Qeynos
	/varset NQeynos	1
    /delay 1s
	/squelch /nav loc 636.21 120.43 -37.9
	/delay 8s !${Zone.ShortName.Equal[qcat]}
/return

Sub qeynos
    /delay 1s
	/call invisMe
	/call Navigating
	/varset NQeynos	2
    /delay 1s
	/call travelToZone qeynos2
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[qeynos]}
/return

Sub blackburrow
	/delay 1s
	/call invisMe
	/call Navigating
	/echo Traveling to ${Green}Everfrost Peak
	/squelch /nav loc 105 -342 0
	/delay 3s	
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[blackburrow]}
/return

Sub everfrost
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${everfrost}==0) 			{
									/call travelToZone halas
	} else /if (${everfrost}==1)	{
									/call travelToZone permafrost
	} else /if (${everfrost}==2)	{
									/call travelToZone poknowledge
									}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[everfrost]}
/return

Sub halas
	/delay 4s
	/call invisMe
	/call Navigating
	/varset everfrost 1
	/call travelToZone Everfrost
	/delay 8s !${Zone.ShortName.Equal[halas]}
/return

Sub permafrost
	/delay 4s
	/call invisMe
	/call Navigating
	/varset everfrost 2
	/call travelToZone Everfrost
	/delay 8s !${Zone.ShortName.Equal[permafrost]}
/return

Sub Sola
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${Me.Height}>3.71) /call shrinkMe	
	/call invisMe
	/keypress FIRST_PERSON_CAMERA
	/call EqAtFront
	/call travelToZone soldungb
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[soldunga]}
/return

Sub solb
	/delay 1s
	/call castLevi
	/call invisMe
	/call Navigating
	/if (${solb}==0) 		{
							/delay 1s
							/echo Traveling to ${Green}The Caverns of Excile
							/keypress FIRST_PERSON_CAMERA
							/call EqAtFront
							/call cancelLevi
							/squelch /nav loc -1023 -443 -15.9	
							/delay 3s	
							/delay 8s !${Navigation.Active}
							/face heading 320
							/keypress forward hold
							/delay 1
							/keypress jump hold
							/delay 1
							/squelch /nav loc -965 -500 -32
	} else /if (${solb}==1) {
							/delay 1s
							/call EqAtFront
							/squelch /nav loc -1022 -446 -18
							/delay 15s !${Navigation.Active}
							/delay 1s
							/keypress FIRST_PERSON_CAMERA
							/face heading 315
							/look 85
							/delay 1s
							/keypress forward hold	
							/delay 0.2s
							/keypress jump hold
							/delay 5s
							/delay 15s !${Navigation.Active}
	} else /if (${solb}==2) {
							/delay 1s
							/call travelToZone neriakc 
							}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[soldungb]}
/return
