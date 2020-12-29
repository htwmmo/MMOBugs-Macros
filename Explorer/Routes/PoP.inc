| -------------------------------------------------------------------------------------------------------
|                                    Planes of Power Route for Explorer.Mac
|													By: Fizz
|                                       		Started: 28/9/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > PoTranq> PoDecay > PoDisease > PoAir> PoTorment> PoFire> PoNightmare> 
| Route Cont: Lair of TT>  PoJustice> PoValor> Halls of Honor> Halls of Honor B> PoTactics> PoWar> 
| Route Cont: PoInnovation> PoWater> PoEarth> EarthB> Sol Tower> PoK
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub PoP

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,PoP]}==1) /return
	/lazyfind on

	/declare PoTranq 		int outer 0
	/declare hoh 			int outer 0
	/declare terris			int outer 0	
	/varset completed		0	
	

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Planes of Power ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - Planes of Power
|--------------------------------------------------------------------------------------

	/call checkPotionStock
	/call restockPotions
		
:PoP

	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0) 	/call PoPpok
	/if (${Zone.ID}==203) 						/call PoTranq	
	/if (${Zone.ID}==215) 						/call air
	/if (${Zone.ID}==205) 						/call DiseaseExit
	/if (${Zone.ID}==200) 						/call Exitdecay
	/if (${Zone.ID}==207) 						/call torment
	/if (${Zone.ID}==217) 						/call fire
	/if (${Zone.ID}==204) 						/call nightmareb
	/if (${Zone.ID}==221) 						/call terris
	/if (${Zone.ID}==201) 						/call justice
	/if (${Zone.ID}==214) 						/call tactics
	/if (${Zone.ID}==211) 						/call honora
	/if (${Zone.ID}==220) 						/call honorb
	/if (${Zone.ID}==208) 						/call valor
	/if (${Zone.ID}==213) 						/call war
	/if (${Zone.ID}==210) 						/call stormExit
	/if (${Zone.ID}==209) 						/call botExit
	/if (${Zone.ID}==206) 						/call innovExit
	/if (${Zone.ID}==216) 						/call water
	/if (${Zone.ID}==218) 						/call Eartha
	/if (${Zone.ID}==222) 						/call Earthb
	/if (${Zone.ID}==219) 						/call ExitTimea
	/if (${Zone.ID}==212) 						/call PoPComplete
										
	/delay 30s !${Navigation.Active}																			
 
/goto :PoP	

/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub PoPComplete	
	/delay 5s
	/echo ${White}You have completed Exploring: ${Green}Planes of Power.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${terris}==1)	{
						/echo ${Yellow}You will need to Complete the hedge event in PoNightmare to complete this route.
						}
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "PoP" "1"
	/delay 1s        
	/call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub PoPpok
	/delay 1s
	/if (${PoTranq}==0) 		{
								/call travelToZone potranquility
	} else /if (${PoTranq}==16)	{
								/call travelToZone potranquility
	}
/return


Sub PoTranq
	/delay 1s
	/if (${PoTranq}==0) 		{
								/call PoAir
	} else /if (${PoTranq}==1)	{	
								/call cancellevi
								/call travelToZone PoDisease
	} else /if (${PoTranq}==2)	{
								/call cancellevi
								/call CoDecay
	} else /if (${PoTranq}==3)	{
								/call travelToZone potorment
	} else /if (${PoTranq}==4)	{
								/call pofire
	} else /if (${PoTranq}==5)	{
								/echo Traveling to ${Green}Plane of Nightmare
								/squelch /nav loc -194 -1276 -905
								/delay 3m !${Navigation.Active}
								/squelch /doortarget id 84
								/delay 2s ${Switch.ID}==84
								/click left door
	} else /if (${PoTranq}==6)	{
								/call poJust
	} else /if (${PoTranq}==7)	{
								/call travelToZone potactics
	} else /if (${PoTranq}==8)	{
								/call travelToZone hohonora
	} else /if (${PoTranq}==9)	{
								/call travelToZone povalor
|	} else /if (${PoTranq}==10)	{
|								/call travelToZone powar
	} else /if (${PoTranq}==10)	{
								/call storm
	} else /if (${PoTranq}==11)	{
								/call bot
	} else /if (${PoTranq}==12)	{
								/call poinnovation
	} else /if (${PoTranq}==13)	{
								/call travelToZone powater
	} else /if (${PoTranq}==14)	{
								/call earth
	} else /if (${PoTranq}==15)	{
								/call time
	} else /if (${PoTranq}==16)	{
								/call travelToZone solrotower
								}	
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[PoTranquility]}
/return	

Sub PoAir  
    /delay 1s
	/echo Traveling to ${Green}The Plane of Air
	/squelch /nav loc 831.37 -686.78 -610.84
	/delay 3s	
	/call cancellevi
    /delay 30s !${Navigation.Active}
	/squelch /doortarget ID 80
	/delay 1s
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return

Sub air  
    /delay 5s
	/varset PoTranq 1
	/delay 1s	
    /call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[poair]}
/return
  
Sub DiseaseExit 
	/delay 1s
	/varset PoTranq 2
	/echo Returning to ${Green}The Plane of Tranquility
	/if (${Me.Height}<3.71) {
							/delay 1s
							/call EqAtFront
							/squelch /nav loc -1230 -1848 -59.5
							/delay 3s
							/face heading 300
							/delay 1s
							/keypress forward hold
							/keypress jump hold
							/delay 1s
							/keypress forward lift
							}
	/if (${Me.Height}>3.71) {
							/squelch /nav loc -1230 -1848 -59.5
							/delay 2s
							}
							
	/squelch /moveto loc -1185 -1940 -57
	/delay 2s	
	/doortarget
	/delay 1s
	/click left door
	/delay 8s !${Zone.ShortName.Equal[podisease]}
/return

Sub CoDecay
	/delay 1s
	/echo Traveling to ${Green}The Crypt of Decay
	/squelch /nav loc 1899 -1112.78 -885.84
	/delay 3s	
    /delay 90s !${Navigation.Active}
	/doortarget ID 11
	/delay 1s
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return

Sub Exitdecay  
    /delay 2s
	/varset PoTranq 3
	/delay 2s	
    /call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[codecay]}
/return

Sub torment  
    /delay 2s
	/varset PoTranq 4
	/delay 2s	
    /call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[potorment]}
/return

  
Sub PoFire
	/delay 1s
	/echo Traveling to ${Green}The Plance of Fire
	/squelch /nav loc 260 -2190 -930
	/delay 3s	
    /delay 30s !${Navigation.Active}
	/squelch /doortarget ID 81
	/delay 1s
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return

Sub fire  
    /delay 2s
	/varset PoTranq 5
	/delay 2s	
    /call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[pofire]}
/return

Sub nightmare  
    /delay 1s
	/echo Traveling to ${Green}The Plance of Nightmare
	/squelch /nav loc -194 -1280 -906
	/delay 3s	
    /delay 1m !${Navigation.Active}
	/squelch /doortarget ID 84
	/delay 1s
	/click left door
    /call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[pofire]}
/return

Sub nightmareb
	/delay 1s
	/call InvisMe
	/cal Navigating
			
    :NRetry
	/if (${PoTranq}==5) 		{
								/echo Traveling to ${Green}The Lair of Terris Thule
								/squelch /nav loc 198 -1938 122
								/delay 2m !${Navigation.Active}
								/squelch /doortarget id 58
								/delay 2s ${Switch.ID}==58
								/click left door
								/delay 2s
								/doevents
								/if (${FailedToZone}) 	{
														/echo ${Red}***Warning${Teal} Flag required to zone into ${Green} The Lair of Terris Thule${Teal} - Skipping that zone.
														/echo ${White}Complete the Hedge quest to gain access
														/varset PoTranq 6
														/varset terris 1
														/goto :NRetry
														}	
	} else /if (${PoTranq}==6) {
								/echo Traveling to ${Green}The Plane of Tranquility
								/doevents flush
								/varset FailedToZone 0
								/nav Door ID 59 click
								/delay 2m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[ponightmare]}
								}	
/return

Sub terris
    /delay 2s
	/varset PoTranq 6
	/delay 2s
	/squelch /nav loc 34 1654 -338
	/delay 5s !${Navigation.Active}
	/doortarget ID 0
	/click left door
	/delay 8s !${Zone.ShortName.Equal[ponightmareb]}
/return

Sub poJust  
    /delay 1s
	/echo Traveling to ${Green}The Plane of Justice
	/squelch /nav loc -0.3 -614.61 -509.1
	/delay 3s	
    /delay 30s !${Navigation.Active}
	/squelch /doortarget ID 37
	/delay 1s
	/click left door		
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return

Sub justice  
    /delay 1s
	/echo Traveling to ${Green}The Plane of Tranquility
	/varset PoTranq 7
	/delay 1s	
    /squelch /nav loc 1.85 354.4 1
    /delay 30s !${Navigation.Active}
	/squelch /doortarget ID 33
	/delay 1s
	/click left door		
	/delay 8s !${Zone.ShortName.Equal[pojustice]}
/return

Sub Tactics
	/delay 2s
	/varset PoTranq 8
	/delay 2s
	/call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[potactics]}
/return

Sub honora
	/delay 1s
	/call InvisMe
	/cal Navigating
	/if (${hoh}==0) 			{
								/call travelToZone hohonorb
	} else /if (${hoh}==1) {
								/delay 3s							
								/varset PoTranq 9
								/call travelToZone potranquility
								/delay 2m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[ponightmare]}
								}	
/return


Sub honorb
	/delay 2s
	/varset hoh 1
	/delay 2s
	/call travelToZone hohonora
	/delay 8s !${Zone.ShortName.Equal[hohonorb]}
/return	
	
Sub valor
	/delay 1s
	/varset PoTranq 10
	/delay 1s
	/call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[povalor]}
/return		

Sub war
	/delay 2s
	/varset PoTranq 11
	/delay 2s
	/call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[powar]}
/return	

Sub storm
	/delay 1s
	/echo Traveling to ${Green}The Plane of Storms
	/squelch /nav loc -750 1227 -919
	/delay 2m !${Navigation.Active}
	/squelch /doortarget ID 15
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return	

Sub stormExit
	/delay 1s
	/varset PoTranq 12
	/delay 5s
	/call travelToZone potranquility
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poearthb]}
/return	

Sub bot
	/delay 1s
	/echo Traveling to ${Green}The Bastion of Thunder
	/squelch /nav loc -678 1808 -925
	/delay 25s !${Navigation.Active}
	/squelch /doortarget ID 47
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return	

Sub botExit
	/delay 2s
	/echo Traveling to ${Green}The Plane of Tranquility
	/varset PoTranq 13
	/squelch /nav loc 245 180 -1628
	/delay 15s !${Navigation.Active}
	/squelch /doortarget ID 67
	/click left door
	/delay 8s !${Zone.ShortName.Equal[bothunder]}
/return	

Sub poinnovation
	/delay 1s
	/echo Traveling to ${Green}The Plane of Innovation
	/squelch /nav loc -1543 -7 -919
	/delay 2m !${Navigation.Active}
	/squelch /doortarget ID 7
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return	

Sub innovExit
	/delay 2s
	/varset PoTranq 14
	/delay 2s
	/call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[poinnovation]}
/return	
	
Sub water
	/delay 2s
	/varset PoTranq 15
	/delay 2s
	/call travelToZone potranquility
	/delay 8s !${Zone.ShortName.Equal[powater]}
/return	
	
Sub earth
	/delay 2s
	/echo Traveling to ${Green}The Plane of Earth
	/squelch /nav loc -1334 2220 -708
	/delay 30s !${Navigation.Active}
	/squelch /doortarget ID 82
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return	
	
Sub Eartha
	/delay 1s
	/if (${PoTranq}==14) 		{
								/echo Traveling to ${Green}Ragrax, Stronghold of the Twelve
								/squelch /nav loc 152 -1165 74
								/delay 5s !${Navigation.Active}
								/squelch /doortarget ID 10 
								/click left door
								/delay 8s !${Zone.ShortName.Equal[poeartha]}
	} else /if (${PoTranq}==15) {
								/echo Traveling to ${Green}Plane of Tranquility
								/squelch /nav loc 252 -1165 74
								/delay 5s !${Navigation.Active}
								/squelch /doortarget ID 11 
								/click left door
								/delay 8s !${Zone.ShortName.Equal[poeartha]}
								}	
/return	
	
Sub Earthb
	/delay 2s
	/varset PoTranq 15
	/delay 5s
	/call travelToZone poeartha
	/delay 8s !${Zone.ShortName.Equal[poearthb]}
/return	

Sub time
	/delay 1s
	/echo Traveling to ${Green}The Plane of Time
	/squelch /nav loc -2230 1295 -907
	/delay 50s !${Navigation.Active}
	/squelch /doortarget ID 17
	/click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}
/return	

Sub ExitTimea
	/delay 2s
	/echo Traveling to ${Green}The Plane of Knowledge
|	/squelch /nav loc 62 -40.6 8
	/delay 30s !${Navigation.Active}
	/makemevisible
	/squelch /nav spawn npc Herald_of_Druzzil_Ro
	/delay 4s
	/varset PoTranq 16
       /delay 6s !${Navigation.Active}
	/if (${SpawnCount[npc Herald radius 15]}) /target npc Herald_of_Druzzil_Ro
		/delay 4s ${Target.ID}
		/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Herald of Druzzil Ro]}) {
		/say send
	} else {
			/echo Herald Wasn't in range or not targeted, ending macro
			/end
		}
	/delay 8s !${Zone.ShortName.Equal[potimea]}
/return
