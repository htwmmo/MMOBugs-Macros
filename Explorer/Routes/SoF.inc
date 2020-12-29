1| -------------------------------------------------------------------------------------------------------
|                                    Secrets of Faydwer Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 7/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Steamfont > Loping Plains > Bloodmoon Keep > Loping Plains >  Hills of Shade >
| Route Cont: Loping Plains > Steamfont > Dragonscale Hills > Crystallos > Dragonscale Hills > Mechanotus >
| Route Cont: Gyrospire Beza > Mechanotus > Gyrospire Zeka > Mechanotus > Steamfactory > Mechanotus >
| Route Cont: Shipworkshop > Mechanotus > Meldrath's Majestic Manion
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub SoF

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,SoF]}==1) /return
	/lazyfind on

	/declare steamf					int outer 0
	/declare loping 				int outer 0
	/declare dragonscale 			int outer 0
	/declare mechanotus 			int outer 0
	
	/varset completed 0	
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Secrets of Faydwer ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - SoF
|--------------------------------------------------------------------------------------

	/call checkPotionStock

:SoF

	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone steamfontmts	
	/if (${Zone.ID}==448)						/call steamf
	/if (${Zone.ID}==443)						/call loping	
	/if (${Zone.ID}==445)						/call bloodmoon	
	/if (${Zone.ID}==444)						/call hills
	/if (${Zone.ID}==442)						/call dragonscale
	/if (${Zone.ID}==446)						/call crystallos
	/if (${Zone.ID}==436)						/call mechanotus
	/if (${Zone.ID}==440)						/call gyrospireb
	/if (${Zone.ID}==441)						/call gyrospirez
	/if (${Zone.ID}==438)						/call steamfactory
	/if (${Zone.ID}==439)						/call shipworkshop	
	/if (${Zone.ID}==437)						/call SoFComplete
	
	/delay 30s !${Navigation.Active}																			
 
/goto :SoF	

/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub SoFComplete	
	/delay 5s
	/echo ${White}You have completed Exploring ${Green}Secrets of Faydwer.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "SoF" "1"
	/delay 1s    
	/call Completed	
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub steamf
	/call Navigating
	/call invisMe
	/delay 1s
	/if (${steamf}==0) 			{
								/call travelToZone lopingplains
	} else /if (${steamf}==1)	{
								/call travelToZone dragonscale
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[steamfontmts]}							
/return


Sub loping
	/call Navigating
	/call invisMe
	/varset steamf 1
	/delay 1s
	/if (${loping}==0) 		{
								/call gotoBloodmoon
	} else /if (${loping}==1)	{
								/call travelToZone hillsofshade
	} else /if (${loping}==2)	{
								/call travelToZone steamfontmts
								
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[lopingplains]}
/return


Sub gotoBloodmoon
	/delay 1s
	/squelch /nav loc -1783 95.5 207
	/delay 3m !${Navigation.Active}
    /squelch /doortarget id 4
    /click left door
	/delay 8s !${Zone.ShortName.Equal[bloodmoon]}
/return

Sub bloodmoon
	/delay 2s
	/varset loping 1
	/delay 2s
    /squelch /doortarget id 53
    /click left door
	/delay 8s !${Zone.ShortName.Equal[bloodmoon]}
/return

Sub hills
	/delay 2s
	/varset loping 2
	/delay 2s
	/call travelToZone lopingplains
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[bloodmoon]}
/return

Sub dragonscale
	/call Navigating
								/call invisMe
	/delay 1s
	/if (${dragonscale}==0) 		{
									/call travelToZone crystallos
	} else /if (${dragonscale}==1)	{
									/call cannon						
									}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[dragonscale]}		
/return

Sub crystallos
	/delay 2s
	/varset dragonscale 1
	/delay 2s
	/call travelToZone dragonscale
	/delay 8s !${Zone.ShortName.Equal[crystallos]}
/return

Sub cannon
	/delay 1s
    /echo Traveling to ${Green}Fortress Mechanotus
	/squelch /nav loc 3731.52 -2383.6 75.75
	/delay 3s
    /delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[dragonscale]}
/return

Sub mechanotus
	/call Navigating
	/call invisMe
	/call cancellevi
	/delay 1s
	/if (${mechanotus}==0) 			{
									/call beza
	} else /if (${mechanotus}==1)	{
									/call zeka
	} else /if (${mechanotus}==2)	{
									/call gotoSteamfactory
	} else /if (${mechanotus}==3)	{
									/call travelToZone shipworkshop
	} else /if (${mechanotus}==4)	{
									/call lifts
									}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[mechanotus]}
/return

Sub beza
	/delay 1s
    /echo Traveling to the ${Green}Gyrospire Beza
	/squelch /nav door id 1 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[mechanotus]}
/return

Sub gyrospireb
	/delay 1s
    /echo Traveling to ${Green}Fortress Mechanotus
	/varset mechanotus 1
    /squelch /nav door id 2 click
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gyrospireb]}
/return

Sub zeka
	/delay 1s
    /echo Traveling to the \agGyrospire Zeka
	/squelch /nav door id 2 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[mechanotus]}
/return

Sub gyrospirez
	/delay 1s
    /echo Traveling to ${Green}Fortress Mechanotus
	/varset mechanotus 2
    /squelch /nav door id 2 click
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gyrospirez]}
/return

Sub gotoSteamfactory
	/delay 1s
	/squelch /nav loc -120 1300 396
	/delay 3s
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[shipworkshop]}
/return

Sub steamfactory
	/delay 1s
	/varset mechanotus 3
    /echo Traveling to ${Green}Fortress Mechanotus
	/squelch /nav loc 136 407.5 168
	/delay 8s
	/doortarget id 1
	/click left door
	/delay 30s !${Zone.ShortName.Equal[shipworkshop]}
/return


Sub shipworkshop
	/delay 2s
	/varset mechanotus 4
	/delay 2s
    /call travelToZone mechanotus
	/delay 8s !${Zone.ShortName.Equal[shipworkshop]}
/return


Sub lifts
	/delay 1s
	/call EqAtFront
	/squelch /nav loc -291 -56 404
    /delay 1m !${Navigation.Active}
	/delay 1s
	/call EqAtFront
	/squelch /nav loc -227 -56 404
	/delay 9s	
	/keypress forward hold
	/delay 2s	
	/keypress forward lift
	/call EqAtFront
	/squelch /nav loc 141 -56 476
    /delay 30s !${Navigation.Active}
	/delay 9s
	/keypress forward hold
	/delay 2s	
	/keypress forward lift
	/call EqAtFront
	/squelch /nav loc 516 -56 549
    /delay 30s !${Navigation.Active}
	/delay 9s
	/keypress forward hold
	/delay 2s	
	/keypress forward lift
	/squelch /nav loc 1508 14.5 662
	/delay 3s
    /delay 2m !${Navigation.Active}
	/squelch /doortarget OBJ_MMC_MAINDR
	/click left door 
	/delay 7s		
/return
