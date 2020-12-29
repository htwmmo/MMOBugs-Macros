| -------------------------------------------------------------------------------------------------------
|                                    TSS Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 4/12/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Blackfeather Roost > Frostcrypt > Vergalid Mines > Ashengate > Bixiehive > Crescent Reach
|
| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub TSS

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,TSS]}==1) /return
	/lazyfind on
	
    /declare moors       		int outer	0
    /declare mesa       		int outer	0
    /declare sunderock       	int outer	0
    /declare direwind	   		int outer	0
    /declare ethernereAnt   	int outer	0

	/varset DoExpansion 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}The Serpent's Spine ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - TSS
|--------------------------------------------------------------------------------------

	/call checkPotionStock
	
:TSS
					
	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone moors
	/if (${Zone.ID}==395)   					/call moors
	/if (${Zone.ID}==397)   					/call mesa
	/if (${Zone.ID}==398)   					/call roost
	/if (${Zone.ID}==402) 						/call frostcrypt
	/if (${Zone.ID}==399 && ${mesa}==2) 		/call steppes1
	/if (${Zone.ID}==403)						/call sunderock
	/if (${Zone.ID}==404)						/call exitvergalid
	/if (${Zone.ID}==405)						/call direwind
	/if (${Zone.ID}==406)						/call exitAshengate
	/if (${Zone.ID}==394) 						/call cresentreach
	/if (${Zone.ID}==396) 						/call TSSComplete	
	
	/delay 2m !${Navigation.Active}
/goto :TSS	
/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub TSSComplete	
	/echo ${White}You have completed Exploring: ${Green}The Serpent's Spine. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "TSS" "1"
	/delay 1s
    /call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------
	

Sub moors
	/delay 1s	
	/if (${moors}==0) 			{
								/call travelToZone mesa
	} else /if (${moors}==1)	{
								/call travelToZone crescent
	} else /if (${moors}==2) 	{
								/call travelToZone stonehive
								}			
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[moors]}
/return	

Sub mesa
	/delay 1s
	
	/if (${mesa}==0) 		{
							/varset moors 1
							/delay 2s
							/call travelToZone roost
	} else /if (${mesa}==1) {
							/call travelToZone frostcrypt
	} else /if (${mesa}==2) {
							/call travelToZone sunderock
	} else /if (${mesa}==3) {
							/call travelToZone moors
							}			
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[mesa]}
/return	

Sub roost
	/delay 1s
	/varset mesa 1
	/call cancelLevi
	/delay 1s
	/call travelToZone mesa
	/delay 8s !${Zone.ShortName.Equal[roost]}
/return

Sub frostcrypt
	/delay 1s
	/varset mesa 2
	/delay 1s
	/call travelToZone steppes
	/delay 8s !${Zone.ShortName.Equal[frostcrypt]}
/return
	
Sub steppes1
		/delay 1s
		/call invisMe
		/echo Traveling to ${Green}Gora Mesa
        /squelch /nav loc -2453.6 -904.75 -1.5
        /delay 3s
        /delay 2m !${Navigation.Active}
		/delay 8s !${Zone.ShortName.Equal[steppes]}
/return

Sub sunderock
	/delay 1s
	/call invisMe
	/call Navigating
	/varset mesa 3
	/if (${sunderock}==0) 			{
									/call entervergalid
	} else /if (${sunderock}==1) 	{
									/call travelToZone direwind
	} else /if (${sunderock}==2) 	{
									/call travelToZone mesa
									}	
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[sunderock]}									
/return	


Sub entervergalid
        /delay 1s
		/echo Traveling to ${Green}Vergalid Mines
        /squelch /nav loc -915.32 -1624.59 213.92
        /delay 3s
        /delay 2m !${Navigation.Active}
		/squelch /doortarget
		/delay 1s
		/click left door
		/delay 8s !${Zone.ShortName.Equal[sunderock]}
/return
		
Sub exitvergalid
		/delay 3s
		/varset sunderock 1
		/delay 1s
		/squelch /doortarget
		/delay 1s
		/click left door
		/delay 8s !${Zone.ShortName.Equal[vergalid]}
/return
		
Sub direwind
	/delay 1s
	/call invisMe
	/call Navigating
	/varset sunderock 2	
	/if (${direwind}==0) 			{
									/call travelToZone ashengate
	} else /if (${direwind}==1) 	{
									/call navhill
	} else /if (${direwind}==2) 	{
									/call travelToZone sunderock									
									}	
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[direwind]}									
/return	
		
Sub exitashengate
    /delay 1s
	/call invisMe
	/call Navigating
	/call cancelLevi
	/varset direwind 1	
	/delay 2s
    /squelch /nav loc -389.92 0.5 9.5
    /delay 4s
	/keypress forward hold
	/delay 1s
	/keypress forward lift
	/delay 8s !${Zone.ShortName.Equal[ashengate]}
/return

Sub navhill
    /delay 1s
	/keypress FIRST_PERSON_CAMERA
	/call invisMe
    /squelch /nav loc 3249 104 779
	/delay 10s !${Navigation.Active}
	/squelch /nav loc 3208 -226 628
	/delay 4s !${Navigation.Active}
	/squelch /nav loc 3138 -220 616
	/delay 3s !${Navigation.Active}
	/squelch /nav loc 3146 223 397
	/delay 8s !${Navigation.Active}
	/varset direwind 2
	/delay 2s
/return
	
Sub cresentreach
	/delay 2s
	/call invisMe
	/call Navigating
	/varset moors 2
	/delay 2s	
	/call travelToZone moors
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[cresentreach]}
/return	
