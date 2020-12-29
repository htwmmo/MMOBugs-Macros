| -------------------------------------------------------------------------------------------------------
|                                    The Broken Mirror Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 7/11/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Plane of Tranquility > Plane of Health > 

|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub TBM

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,TBM]}==1) /return
	/lazyfind on
    /declare SulV		int outer	0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}The Broken Mirror ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - TBM
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	
:TBM
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKTBM
	/if (${Zone.ID}==203) 						/call PoTranqTBM
	/if (${Zone.ID}==798) 						/call PoHealth	
	/if (${Zone.ID}==777) 						/call Life	
	/if (${Zone.ID}==795) 						/call CoSul	
	/if (${Zone.ID}==797) 						/call DecayTBM
	/if (${Zone.ID}==796) 						/call TBMComplete
		
	/delay 2m !${Navigation.Active}
	/goto :TBM
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub TBMComplete	
	/echo ${White}You have completed Exploring: ${Green}The Broken Mirror. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/ini "${RouteIniFileName}" "CompletedRoutes" "TBM" "1"
	/delay 2s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub PoKTBM
	/delay 1s
	/call travelToZone potranquility
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

Sub PoTranqTBM
	/delay 1s
	/echo Traveling to ${Green}The Plane of Health
    /squelch /nav loc -345 -1424 -932
	/delay 3m !${Navigation.Active}
	/squelch /doortarget id 13
    /click left door
	/delay 8s !${Zone.ShortName.Equal[potranquility]}							
/return

Sub PoHealth
	/delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone exalted
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[pohealth]}
/return	

Sub Life
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Crypt of Sul
	/squelch /nav door id 89 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[exalted]}							
/return

Sub CoSul
	/delay 4s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Sul Vius: Demiplane of Decay
	/squelch /nav door id 29 click
	/delay 8s !${Zone.ShortName.Equal[cosul]}
/return	
	
Sub DecayTBM
	/delay 2s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Ruins of Lxanvom
	/squelch /nav loc 489 1 -22
	/squelch /doortarget id 104
	/click left door
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[exaltedb]}
/return	