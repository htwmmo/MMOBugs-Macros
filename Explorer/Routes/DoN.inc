| -------------------------------------------------------------------------------------------------------
|                                    Dragons of Norrath Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 29/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Broodlands >Stillmoon > The Ascent > The Nest > Lavaspinners Lair > Tirranun's Delve
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub DoN

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,DoN]}==1) /return
	/lazyfind on
	
	/declare brood				int outer	0
	/declare stillmoon			int outer	0
	/declare delvea				int outer	0

	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Dragons of Norrath ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - DoN
|--------------------------------------------------------------------------------------

	/call checkPotionStock
	
:DoN

	/call GMCheck	
	/delay 1s
	/call Navigating
	/call invisMe
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone broodlands
	/if (${Zone.ID}==337) 						/call brood
	/if (${Zone.ID}==338) 						/call stillmoona	
	/if (${Zone.ID}==339)						/call stillmoonb
	/if (${Zone.ID}==340)						/call exitThunder
	/if (${Zone.ID}==343)						/call exitNest
	/if (${Zone.ID}==341) 						/call delvea
	/if (${Zone.ID}==342) 						/call exitdelveb
	
	/delay 2m !${Navigation.Active}
	/goto :DoN	
/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub DoNComplete	
	/echo ${White}You have completed Exploring: ${Green}Dragons of Norrath. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "DoN" "1"
	/delay 1s
    /call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------
	
Sub brood
	/delay 1s
	/call Navigating
	/call invisMe
	
	/if (${brood}==0) 			{
								/delay 1s
								/call travelToZone stillmoona
								/delay 3s
	} else /if (${brood}==1)	{
								/delay 1s
								/call travelToZone thenest
	} else /if (${brood}==2)	{
								/delay 1s
								/call travelToZone thundercrest
	} else /if (${brood}==3)	{
								/delay 1s
								/call todelvea
								}			
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[broodlands]}			
/return

Sub stillmoona
	/delay 1s
	/if (${stillmoon}==0) 			{
									/delay 1s
									/call travelToZone stillmoonb
									/delay 3s
	} else /if (${stillmoon}==1)	{
									/delay 1s
									/varset brood 1
									/call travelToZone broodlands
									}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[stillmoona]}
/return		

Sub stillmoonb
	/delay 5s
	/varset stillmoon 1
	/call travelToZone stillmoona
	/delay 3s
	/delay 8s !${Zone.ShortName.Equal[stillmoonb]}	
/return			

Sub exitNest
        /delay 1s
		/echo Returning to ${Green}The Broodlands		
		/varset brood 2	
		/squelch /nav loc 244.69 -175.91 -84
		/delay 3s	
		/delay 8s !${Zone.ShortName.Equal[thenest]}
/return

Sub exitThunder
        /delay 1s	
		/echo Returning to ${Green}The Broodlands
		/varset brood 3	
		/squelch /nav loc -1846.74 164.9 110
		/delay 10s	
		/delay 8s !${Zone.ShortName.Equal[thundercrest]}
/return

Sub todelvea
        /delay 1s
		/echo Traveling to ${Green}Lavaspinner's Lair
		/squelch /nav loc -1211.07 -942.54 -11.7
		/delay 3s	
        /delay 3m !${Navigation.Active}
		/delay 8s !${Zone.ShortName.Equal[broodlands]}
/return

Sub delvea
	/if (${delvea}==0) 			{
								/delay 1s
								/echo Traveling to ${Green}Tirranun's Delve
								/squelch /nav loc -390.37 -63.42 10.7
								/delay 3s	
								/delay 3m !${Navigation.Active}
								/squelch /doortarget
								/delay 1
								/click left door
								/delay 8s !${Zone.ShortName.Equal[delvea]}
	} else /if (${delvea}==1)	{
								/call DoNComplete
								}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[delvea]}
/return

Sub exitdelveb
        /delay 1s
		/echo Returning to ${Green}Lavaspinner's Lair
		/varset delvea 1		
		/doortarget
		/delay 1
		/click left door
/return
