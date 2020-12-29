| -------------------------------------------------------------------------------------------------------
|                                         Underfoot Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 26/10/2020
| -------------------------------------------------------------------------------------------------------
| Route: PoK > Nektulos > Corathus Creep > Lichen Creep > Arthicrex > Fungal Forest > Arthicrex > 
| Route Cont: Volska's Husk > Convorteum > Volska's Husk > Arthicrex > > Underquarry > Foundation > 
| Route Cont: Underquarry > Pellucid Grotto > Cooling chamber > Brell's Rest > Kernagir > Brell's Temple 
 -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub Underfoot

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,Underfoot]}==1) /return
	/lazyfind on
	
    /declare arthicrex	int outer	0
    /declare husk		int outer	0
    /declare uquarry	int outer	0
    /declare brest		int outer	0
	
	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Underfoot ${Teal}**


|--------------------------------------------------------------------------------------
| Travel Loop - Underfoot
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	/call invisMe
	

:Underfoot
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone corathus
	/if (${Zone.ID}==365)						/call corathus
	/if (${Zone.ID}==487)						/call lichencreep
	/if (${Zone.ID}==485)						/call arthicrex
	/if (${Zone.ID}==481)						/call fungalforest
	/if (${Zone.ID}==489)						/call volska
	/if (${Zone.ID}==491)						/call convorteum
	/if (${Zone.ID}==482)						/call underquarry
	/if (${Zone.ID}==486)						/call foundation
	/if (${Zone.ID}==488)						/call pellucid	
	/if (${Zone.ID}==483)						/call coolingchamber
	/if (${Zone.ID}==480)						/call brellsrest
	/if (${Zone.ID}==484)						/call kernagir
	/if (${Zone.ID}==490)						/call UFComplete
		
	/delay 2m !${Navigation.Active}
	/goto :Underfoot
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub UFComplete	
		/echo ${White}You have completed Exploring: ${Green}Depths of Darkhollow. 
		/echo ${Yellow}Moving to Poknowledge
		/delay 2s
		/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
		/delay 2s
		/ini "${RouteIniFileName}" "CompletedRoutes" "Underfoot" "1"
		/delay 2s
		/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub corathus
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Lichen Creep
	/squelch /nav door id 109
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[corathus]}							
/return

Sub lichencreep
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Arthicrex
	/squelch /nav loc -1242 80 -5
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[corathus]}							
/return

Sub arthicrex
	/call Navigating
	/call invisMe
	/call DangerRoute
	/delay 1s
	/if (${arthicrex}==0) 			{
									/echo Traveling to ${Green}Volska`s Husk
									/squelch /nav door id 31
	} else /if (${arthicrex}==1)	{
									/echo Traveling to ${Green}Fungal Forest
									/squelch /nav door id 33
	} else /if (${arthicrex}==2)	{
									/call travelToZone underquarry	
									}									
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[arthicrex]}							
/return

Sub volska
	/call Navigating
	/call invisMe
	/call EqAtFront
	/varset arthicrex 1
	/delay 1s
	/if (${husk}==0) 		{
							/echo Traveling to ${Green}Convorteum
							/squelch /nav door id 3
	} else /if (${husk}==1)	{
							/echo Traveling to ${Green}Arthicrex
							/squelch /nav door id 2
							}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[stonesnake]}							
/return

Sub convorteum
	/delay 2s
	/call Navigating
	/call invisMe
	/varset husk 1
	/delay 1s
	/echo Traveling to ${Green}Volska`s Husk
	/squelch /nav door id 13
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[convorteum]}	
/return

Sub fungalforest
	/delay 2s
	/call Navigating
	/call invisMe
	/varset arthicrex 2
	/echo Traveling to ${Green}Arthicrex
	/squelch /nav door id 4
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[fungalforest]}	
/return

Sub underquarry
	/call Navigating
	/call invisMe
	/delay 1s
	/if (${uquarry}==0) 			{
									/call travelToZone foundation
	} else /if (${uquarry}==1)	{
									/call travelToZone pellucid
									}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[underquarry]}							
/return

Sub foundation
	/delay 1s
	/call Navigating
	/call invisMe
	/varset uquarry 1
	/delay 2s
	/call travelToZone underquarry
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[foundation]}	
/return

Sub pellucid
	/delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone coolingchamber
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[pellucid]}	
/return

Sub coolingchamber
	/delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone brellsrest
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[coolingchamber]}	
/return

Sub brellsrest
	/call Navigating
	/call invisMe
	/delay 1s
	/if (${brest}==0) 			{
								/echo Traveling to ${Green}Kernagir, The Shining City
								/squelch /nav door id 3	click
	} else /if (${brest}==1)	{
								/echo Traveling to ${Green}Brell`s Temple
								/squelch /nav door id 1	click
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[brellsrest]}							
/return

Sub kernagir
	/delay 2s
	/call Navigating
	/call invisMe
	/varset brest 1
	/echo Traveling to ${Green}Brell's Rest
	/squelch /nav door id 36 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[shiningcity]}	
/return
