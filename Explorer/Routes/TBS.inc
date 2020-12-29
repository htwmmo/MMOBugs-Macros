| -------------------------------------------------------------------------------------------------------
|                                    The Buried Sea Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 23/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Toxx Forest > Barren Coast > Buried Sea > Katta Castrum > Thalassius > Katta Castrum > 
| Route cont: Jewel of Atiki > Katta Castrum > Silyssar > Katta Castrum > Zhisza > Katta Castrum > 
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub TBS

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,TBS]}==1) /return
	/lazyfind on
    /declare kattaTBS		int outer	0
	
	/varset DoExpansion 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}The Buried Sea ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - TBS
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	

:TBS
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKTBS
	/if (${Zone.ID}==422) 						/call barren
	/if (${Zone.ID}==423) 						/call buriedsea
	/if (${Zone.ID}==416) 						/call kattaTBS
	/if (${Zone.ID}==417) 						/call thalassius
	/if (${Zone.ID}==418) 						/call akiiti 
	/if (${Zone.ID}==419) 						/call zhisza
	/if (${Zone.ID}==420) 						/call TBSComplete
		
	/delay 2m !${Navigation.Active}
	/goto :TBS
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub TBSComplete	
	/echo ${White}You have completed Exploring: ${Green}The Buried Sea. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "TBS" "1"
	/delay 2s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub PoKTBS
	/delay 1s
	/call travelToZone barren
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

Sub barren
	/delay 1s
	/call invisMe	
	/echo Heading to catch board the ${Green}Isabeau
    /squelch /nav loc -186 -345 1
	/delay 3m !${Navigation.Active}
    /face heading 270
	/call embarkIsabeau
	/delay 4m !${Zone.ShortName.Equal[barren]}							
/return
	
Sub buriedsea
	/delay 1s
	/call Navigating
	/call invisMe
	/call disembarkIsabeau
	/echo Traveling to ${Green}Katta Castrum
    /squelch /nav loc -220 390 46
	/squelch /target clear
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[buriedsea]}							
/return

Sub kattaTBS
	/delay 1s
	/call Navigating
	/call invisMe
	/if (${kattaTBS}==0) 		{
								/echo Traveling to ${Green}Thalassius, The Coral Keep
								/squelch /nav door id 28
	} else /if (${kattaTBS}==1)	{
								/echo Traveling to ${Green}Jewel of Atiki
								/squelch /nav door id 27
	} else /if (${kattaTBS}==2)	{
								/echo Traveling to ${Green}Zhisza, the Shissar Sanctuary
								/squelch /nav door id 29
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

Sub thalassius
	/call Navigating
	/call invisMe
	/delay 2s
	/varset kattaTBS 1
	/delay 2s
	/echo Traveling to ${Green}Katta Castrum
	/nav door id 7
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thalassius]}							
/return

Sub akiiti
	/call Navigating
	/call invisMe
	/delay 2s
	/varset kattaTBS 2
	/delay 2s
	/echo Traveling to ${Green}Katta Castrum
	/squelch /nav door id 14
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[akiiti]}							
/return

Sub zhisza
	/call Navigating
	/call invisMe
	/delay 1s
	/echo Traveling to ${Green}Silyssar, New Chelsith
    /squelch /nav loc -308 64 25	
	/delay 3m !${Navigation.Active}
    /squelch /target clear
    /squelch /doortarget id 1
    /delay 2s ${Switch.ID}==1
    /click left door
    /delay 8
    /squelch /target clear
    /nav door id 2 click
    /delay 8s !${Zone.ShortName.Equal[zhisza]}		
/return
