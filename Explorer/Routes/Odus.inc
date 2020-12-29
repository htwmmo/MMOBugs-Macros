1| -------------------------------------------------------------------------------------------------------
|                                    Odus Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 11/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Gulf of Gunthak > Stoneburnt Mountains >  Warrens >  Paineel > Ruins of old Paineel > PoK
| Route Cont: Tox Forrest >  Erudin > Erudin Palace > Erudin > Erudin Crossing
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub Odus

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,Odus]}==1) /return
	/lazyfind on

	/declare pokOdus	int outer 0
	/declare erud		int outer 0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Odus ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - Odus
|--------------------------------------------------------------------------------------

	/call checkPotionStock

:Odus

	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call pokOdus
	/if (${Zone.ID}==224)						/call gunthakOdus	
	/if (${Zone.ID}==100)						/call travelToZone paineel	
	/if (${Zone.ID}==75)						/call paineel
	/if (${Zone.ID}==39)						/call hole
	/if (${Zone.ID}==414)						/call toxOdus
	/if (${Zone.ID}==24)						/call erudnext
	/if (${Zone.ID}==23)						/call erudnint
	/if (${Zone.ID}==98)						/call OdusComplete
	
	/delay 30s !${Navigation.Active}																			
 
/goto :Odus	

/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub OdusComplete	
	/delay 5s
	/echo ${White}You have completed Exploring: ${Green}Odus.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "Odus" "1"
	/delay 1s
	/call Completed	
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub pokOdus
	/call invisMe
	/delay 1s
	/if (${pokOdus}==0) 		{
								/call travelToZone gunthak
	} else /if (${pokOdus}==1)	{
								/squelch /nav door id 18 click
	}
/return

Sub toxOdus
	/delay 1s
	/call travelToZone erudnext
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[toxxulia]}
/return	

Sub gunthakOdus
	/delay 2s
	/varset pokOdus 1
	/delay 4s
	/call travelToZone stonebrunt
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gunthak]}	
/return
	
Sub paineel
	/delay 1s
	/echo Traveling to ${Green}The Runis of Old Paineel
	/delay 3s
	/squelch /nav door id 3 click
	/delay 3m !${Navigation.Active}
	/squelch /nav loc 630 -940 -98
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[paineel]}		
/return	
	
Sub hole
	/delay 2s
	/echo ${Green}Short Cut the next path. Inc Evac
	/delay 3s
	/call evac
/return

Sub erudnext

	/if (${erud}==0) 		{
							/call invisMe
							/call EqAtFront
							/squelch /nav loc -1409 -254 -45
							/delay 1m !${Navigation.Active}
							/face heading 0
							/delay 1s						
							:lowerportal
							/while  (${Me.Z}<-1) {
												/keypress forward hold
												/delay 0.5s
												/keypress forward lift
												/goto :lowerportal
												}
							/if  (${Me.Z}>-1) /call travelToZone erudnint
							/delay 3m !${Navigation.Active}								
	} else /if (${erud}==1)	{
							/call invisMe
							/delay 1s
							/squelch /nav loc -644 -269 72
							/delay 3m !${Navigation.Active}
							/keypress forward hold
							/delay 1s	
							/keypress forward lift
|							/call EqAtFront
							/delay 1s
							/squelch /nav loc 97 -345 24
							/delay 2s
							/delay 2m !${Navigation.Active}
							/if (${SpawnCount[npc Translocator radius 20]}) /target npc Translocator_Eniela
							/delay 5s ${Target.ID}
							/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Translocator Eniela]}) 	{
																											/makemevisible
																											/say Erud's Crossing
																											}
							/delay 8s !${Zone.ShortName.Equal[erudnext]}	
							}
							
								
							
							
/return

Sub erudnint
	/call invisMe
	/delay 1s
	/varset erud 1
	/call travelToZone erudnext
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[toxxulia]}	
/return