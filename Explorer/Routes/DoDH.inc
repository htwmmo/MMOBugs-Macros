| -------------------------------------------------------------------------------------------------------
|                                   Depths of Darkhollow Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 23/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Nektulos Forrest > Corathus Creep > The Undershore > Ruins of Illsain > The Undershore >
| Route cont: > Fear Itself > Morell's Castle > Sanction Somnium > Erudin Burning > Grounds > Well
|
| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub DoDH

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,DoDH]}==1) /return
	/lazyfind on
	
    /declare undershore			int outer	0
	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Depths of Darkhollow ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - DoDH
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	/call invisMe
	

:DoDH
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone eastkorlach
	/if (${Zone.ID}==362) 						/call eastkorlach
| Path 1
	/if (${Zone.ID}==347) 						/call illsalin 
| Path 2
	/if (${Zone.ID}==358) 						/call westkorlach 
	/if (${Zone.ID}==354) 						/call drachnidhive 
	/if (${Zone.ID}==351) 						/call DoDHComplete 
		
	/delay 2m !${Navigation.Active}
	/goto :DoDH
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub DoDHComplete	
	/echo ${White}You have completed Exploring: ${Green}Depths of Darkhollow. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "DoDH" "1"
	/delay 2s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub eastkorlach
	/call Navigating
	/call invisMe
	/delay 1s
	/if (${undershore}==0) 			{
									/call travelToZone illsalin
	} else /if (${undershore}==1)	{
									/call travelToZone westkorlach
									}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[eastkorlach]}							
/return

sub illsalin
	/delay 2s
	/varset undershore 1
	/delay 2s
	/call travelToZone eastkorlach
/return
	
Sub westkorlach
	/delay 1s
	/echo Traveling to ${Green}The Hive
	/squelch /nav loc  -1680  -640 361
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[westkorlach]}		
/return	
	
Sub drachnidhive
	/delay 1s
	/echo Traveling to ${Green}Dreadspire
	/squelch /nav door id 4 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[drachnidhive]}		
/return	