| -------------------------------------------------------------------------------------------------------
|                                         Veil of Alaris Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 26/10/2020
| -------------------------------------------------------------------------------------------------------
| Route: PoK > Steamfont > Argath > Beasts Domain > Argath > Valley > Sarith > Rubak Oseak > Sarith > 
| Route Cont: Erillion > Resplendent > Pillars > Windsong > Pillars > Resplendent > City of Bronze >
| Route Cont: Sepulcher of Order
 -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub VoA

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,VoA]}==1) /return
	/lazyfind on
	
    /declare argathVoA		 int outer	0
    /declare sarithVoA	 	int outer	0
	/declare resplendentVoA	int outer	0
    /declare pillars	 	int outer	0
	
	/varset completed 0


	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Veil of Alaris ${Teal}**


|--------------------------------------------------------------------------------------
| Travel Loop - VoA
|--------------------------------------------------------------------------------------

	/call checkPotionStock

:VoA
		
	/call GMCheck	
	/delay 1s
	/call Navigating
	/call invisMe

	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone steamfontmts
	/if (${Zone.ID}==448) 						/call SteamfontVoA
	/if (${Zone.ID}==724) 						/call Argath1
	/if (${Zone.ID}==728) 						/call beastdomain
	/if (${Zone.ID}==726) 						/call sarithcity
	/if (${Zone.ID}==727) 						/call rubak
	/if (${Zone.ID}==729) 						/call resplendent
	/if (${Zone.ID}==730) 						/call pillarsalra
	/if (${Zone.ID}==731) 						/call windsong
	/if (${Zone.ID}==732) 						/call cityofbronze
	/if (${Zone.ID}==733) 						/call VoAComplete
	
	/delay 2m !${Navigation.Active}
	/goto :VoA
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub VoAComplete	
	/echo ${White}You have completed Exploring: ${Green}Veil of Alaris. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "VoA" "1"
	/delay 2s	
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub SteamfontVoA
		/call Navigating
		/call invisMe
		/delay 1s
		/echo Traveling to ${Green}Argath, Bastion of Illdaera
		/squelch /nav loc -1085 -1100 -18
		/delay 45s !${Navigation.Active}
        /call embarkAirship
/return

Sub Argath1
	/delay 1s
	/call Navigating
	/call invisMe
	/if (${argathVoA}==0) 			{
								/if (!${blnPorted}) {
													/call disembarkAirship
													/delay 1s
													/varset argathVoA 1
													}
	} else /if (${argathVoA}==1)	{
								/echo Traveling to ${Green}Beasts' Domain
								/call invisMe
								/squelch /nav loc 394 47.71 -333
								/delay 3m !${Navigation.Active}
								/doortarget
								/delay 1s
								/click left door
								/delay 10s		
	} else /if (${argathVoA}==2)	{
								/call travelToZone sarithcity	
								}									
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[argath]}							
/return
		
Sub beastdomain		
		/delay 2s	
		/call Navigating
		/call invisMe
		/varset argathVoA 2
		/delay 2s
		/echo Traveling to ${Green}Argath, Bastion of Illdaera
		/nav door id 2 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[beastdomain]}				
/return
		
Sub sarithcity
	/delay 1s
	/call Navigating
	/call invisMe
	/if (${sarithVoA}==0) 			{
									/echo Traveling to ${Green}Rubak Oseka, Temple of the Sea
									/squelch /nav loc  -1155 -1200 25	
									/delay 4m !${Navigation.Active}
									/squelch /doortarget id 143 
									/click	left door
	} else /if (${sarithVoA}==1)	{
									/call travelToZone resplendent	
									}									
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[sarithcity]}							
/return

Sub rubak	
	/delay 2s	
	/call Navigating
	/call invisMe
	/varset sarithVoA 1
	/delay 1s
	/echo Traveling to ${Green}Sarith, City of Tides
    /squelch /nav door id 5 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[rubak]}				
/return


Sub resplendent
	/delay 1s
	/call Navigating
	/call invisMe
	/if (${resplendentVoA}==0) 			{
										/call travelToZone pillarsalra	
	} else /if (${resplendentVoA}==1)	{
										/call travelToZone cityofbronze	
										}									
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[sarithcity]}							
/return

Sub pillarsalra
	/delay 1s
	/call Navigating
	/varset resplendentVoA 1
	/call invisMe
	/if (${pillars}==0) {
						/echo Traveling to ${Green}Windsong Sanctuary
						/squelch /nav loc 105 0 855									
						/delay 3m !${Navigation.Active}
						/squelch /target clear
						/squelch /doortarget id 78
						/if (${Switch.Z}!=${Switch.DefaultZ}) 		{
																	/squelch /doortarget id 95
																	/click left door
																	}
						/squelch /doortarget id 78
						/while (${Switch.Z}!=${Switch.DefaultZ}) 	{
																	/delay 1s
																	}
						/squelch /target clear
						/squelch /moveto loc 0 0
						/delay 10s ${MoveTo.Stopped}
						/squelch /doortarget id 78
						/click left door
						/delay 8s !${Zone.ShortName.Equal[pillarsalra]}	
	} else /if (${pillars}==1)	{
								/call travelToZone resplendent	
								}									
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[pillars]}							
/return

Sub windsong
	/delay 2s	
	/call Navigating
	/call invisMe
	/varset pillars 1
	/delay 1s
	/echo Traveling to ${Green}Pillars of Alra
	/squelch /nav loc -123 -1212 3
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[windsong]}				
/return

Sub cityofbronze
	/delay 1s
	/echo Traveling to ${Green}Sepulcher of Order
	/squelch /nav loc 9 1307 3
	/delay 3m !${Navigation.Active}
	/squelch /doortarget id 111
	/click left door
	/delay 3s
	/squelch /nav loc  230 -1561 -38
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[cityofbronze]}
/return

       
| -------------------------------------------------------------------------------------
| SUB: embarkAirship
| -------------------------------------------------------------------------------------    
Sub embarkAirship
    /declare blnAirShipWait 			bool local 1
    /declare intWaitCounter int         local      0
    /echo ${White}Waiting for the ship.
    /face loc -1085,-1085,-11
    /while (${blnAirShipWait}) {
        /varcalc intWaitCounter ${intWaitCounter}+1
        /if (${Spawn[loc -1034 -985 -36 radius 10].ID}) {
            /delay 1s
            /varset blnAirShipWait 0
        } else /if (!${Spawn[loc -1034 -985 -36 radius 10].ID}) {
            /delay 1s
            /if (${Math.Calc[${intWaitCounter}%30]}==29) /echo ${White}Waiting for ship still...
        }
        /delay 1
    }
    /varset intWaitCounter 0
    /echo ${White}All Aboard!
    /call cancelLevi
    /squelch /target clear
    /squelch /moveto loc -1083 -1035 -20
    /delay 4s ${MoveTo.Stopped}
    /face loc -1085,-1135,-11
    /while (${Zone.ID}!=724 && ${Me.Z}<30) {
        /varcalc intWaitCounter ${intWaitCounter}+1
        /delay 1s
        /if (${Math.Calc[${intWaitCounter}%45]}==44) /echo ${White}Waiting to depart.
    }
    /while (${Zone.ID}!=724) {
        /delay 1s
    }
/return


| -------------------------------------------------------------------------------------
| SUB: disembarkAirship
| -------------------------------------------------------------------------------------    
Sub disembarkAirship
    /declare blnAirShipWait bool local 1
    /declare intWaitCounter int         local       0
    /echo ${White}Waiting for the ship to reach the dock.
    /while (${blnAirShipWait}) {
        /varcalc intWaitCounter ${intWaitCounter}+1
        /if (${Spawn[loc 774 756 -51 radius 10].ID}) {
            /delay 1s
            /varset blnAirShipWait 0
        } else {
            /delay 1s
            /if (${Math.Calc[${intWaitCounter}%30]}==29) /echo ${White}Still waiting to dock...
        }
    }
    /echo ${White}All Ashore!
    /squelch /target clear
    /squelch /moveto loc 681 842 -35
    /delay 8s !${MoveTo.Stopped}
    /squelch /moveto loc 636 800 -29
    /delay 8s !${MoveTo.Stopped}
    /delay 2s
/return
		