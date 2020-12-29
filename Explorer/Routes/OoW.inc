1| -------------------------------------------------------------------------------------------------------
|                                    Omans of War Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 7/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Dranik Scar > Harbriners Spire > Nobles Causeway > Wall of Slaughter > Muramite ProvingGrounds > 
| Route Cont: Riftseekers Sanctum >  PoK > Dranik Scar > Bloodfi1elds > Ruined City of Dranik > PoTactics> PoWar> 
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub OoW
	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,OOW]}==1)	/return

	/lazyfind on		
	/declare dranik		int outer 0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Omans of War ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - Omans of War
|--------------------------------------------------------------------------------------

	/call checkPotionStock

:OOW
	
	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,OOW]}==1)	/return
	
	/call GMCheck	
	/delay 1s
	/call Navigating
		
	/if (${Zone.ID}==202 && ${completed}==0)	/call PoD	
	/if (${Zone.ID}==302)						/call dranik	
	/if (${Zone.ID}==335)						/call harbingers	
	/if (${Zone.ID}==334)						/call riftseekers
	/if (${Zone.ID}==336)						/call OoWComplete
	
	/delay 30s !${Navigation.Active}																			
 
/goto :OoW	

/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub OoWComplete	
	/delay 5s
	/echo ${White}You have completed Exploring: ${Green}Omans of War.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "OoW" "1"
	/delay 1s        
	/call Completed	
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub PoD	
		/call Navigating
		/delay 1s
		/squelch /nav loc 42.8 575.27 0
		/delay 3s
		/delay 45s !${Navigation.Active}
		/if (${SpawnCount[npc Priest radius 15]}) /target npc Priest_of_Discord
		/delay 4s ${Target.ID}
		/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Priest of Discord]}) {
																					/makemevisible
																					/say wish to go
																					}
		/delay 16s
/return

Sub dranik
	/delay 1s
	/if (${dranik}==0) 			{
								/call invisMe
								/call travelToZone harbingers
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[draniksscar]}
	} else /if (${dranik}==1)	{
								/call invisMe
								/call travelToZone riftseekers
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[draniksscar]}
	} else /if (${dranik}==2)	{
								/call invisMe
								/call travelToZone dranik
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[draniksscar]}
								}	
/return	

Sub harbingers
	/delay 1s
	/varset dranik 1
	/call travelToZone draniksscar
	/delay 3s
	/delay 8s !${Zone.ShortName.Equal[harbingers]}
/return

Sub wallofslaughter
	/delay 1s
	/echo Traveling to ${Green}Muramite Proving Grounds
	/squelch /nav loc 1981 -1699 106
	/delay 3s
	/delay 3m !${Navigation.Active}
	/nav door id 1 click
	/delay 8s !${Zone.ShortName.Equal[wallofslaughter]}
/return

Sub riftseekers
	/delay 1s
	/varset dranik 2
	/echo ${Green}Short Cut the next path. Inc Evac
	/delay 2s
	/call evac
/return