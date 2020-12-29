
|----------------------------------------------------------------------------------------------------------
| INFO: Locations of boats in Barren Coast & Buried Sea
|----------------------------------------------------------------------------------------------------------
Sub embarkIsabeau
|----------------------------------------------------------------------------------------------------------

	/echo ${White}Waiting for the ${Green}Isabeau${White} to arrive at the dock.
	/call cancelLevi
	:WaitForIsabeau1
	
	/if (${Spawn[Isabeau].Loc.Equal[-185.37, -548.87]})		{
															/echo ${White}All Aboard!
															/moveto loc -187 -544 22
															/delay 5s
															/face heading 90
															/delay 5s
															/echo Traveling to ${Green}The Buried Sea
															/delay 4m !${Zone.ShortName.Equal[barren]}
															/if (${Spawn[Isabeau].Moving}) /delay 5s
															/return
															}	

	/if (!${Spawn[Isabeau].Loc.Equal[-185.37, -548.87]})	{															
															/delay 30s
															/echo ${White}Waiting for the ${Green}Isabeau${White} to arrive at the dock.
															/goto :WaitForIsabeau1
															}
/return


|-----------------------------------------------------------------------------------------------------------
Sub disembarkIsabeau
|-----------------------------------------------------------------------------------------------------------

    /echo ${White}Waiting for the ${Green}Isabeau${White} to arrive at the dock.
	/delay 30s
	:WaitForIsabeau2
	
	/if (${Spawn[Isabeau].Loc.Equal[147.00, 2827.87]}) 	{
														/echo ${White}All Ashore!
														/moveto loc 105 2880 329
														/delay 4s
														/return
														}
														
	/if (${Spawn[Isabeau].Moving})	{
									/delay 15s
									/echo ${White}Still waiting for the ${Green}Isabeau${White} to dock...
									/goto :WaitForIsabeau2
									}
/return


|----------------------------------------------------------------------------------------------------------
Sub embarkBaron
|----------------------------------------------------------------------------------------------------------

    /echo ${White}Waiting for ${Green}The Chaste Baron${White} to arrive at the dock.
	/call cancelLevi
	:WaitForBaron1
	
	/if (${Spawn[The Chaste Baron].Loc.Equal[-77.00, -554.00]})		{
																	/echo ${White}All Aboard!
																	/moveto loc -40 -560 20
																	/delay 90s
																	/echo Traveling to ${Green}Brother Island
																	/delay 2m ${Spawn[The_Chaste_Baron].Moving}
																	/if (${Spawn[The_Chaste_Baron].Moving}) /delay 5s																											
																	/return
																	}	

	/if (!${Spawn[The Chaste Baron].Loc.Equal[-77.00, -554.00]})	{															
																	/delay 30s
																	/echo ${White}Waiting for ${Green}The Chaste Baron${White} to arrive at the dock.
																	/goto :WaitForBaron1
																	}
/return

|-----------------------------------------------------------------------------------------------------------
Sub disembarkBaron
|-----------------------------------------------------------------------------------------------------------
 
	/echo ${White}Waiting for ${Green}The Chaste Baron${White} to arrive at dock.
	/delay 30s
	:WaitForBaron2

	/if (${Spawn[The Chaste Baron].Loc.Equal[-4188.00, -2625.00]}) 	{
																	/echo ${White}All Ashore!
																	/moveto loc -4141 -2595 317
																	/delay 8s
																	/return
																	}	
																	
	/if (${Spawn[The Chaste Baron].Moving})	{														
											/delay 15s
											/echo ${White}Still waiting for ${Green}The Chaste Baron${White} to at the dock...
											/goto :WaitForBaron2
											}
/return

|----------------------------------------------------------------------------------------------------------
Sub embarkBloodwail
|----------------------------------------------------------------------------------------------------------
	
	/echo ${White}Waiting for ${Green}The Bloodwail${White} to arrive at the dock.
	/call cancelLevi
	:WaitForBloodwail1
	
	/if (${Spawn[Bloodwail].Loc.Equal[-5433.75, -3092.62]})		{
																/echo ${White}All Aboard!	
																/moveto loc -5431 -3099	
																/delay 5s
																/face heading 0
																/echo Traveling to ${Green}Thuliasaur Island 
																/delay 2m ${Spawn[Bloodwail].Moving}
																:wailloop
																/if (${Spawn[Bloodwail].Moving}) /goto :wailloop
																/delay 3s !${Zone.ShortName.Equal[brotherisland]}
																/return	
																}	

	/if (!${Spawn[Bloodwail].Loc.Equal[-5433.75, -3092.62]})	{															
																/delay 30s
																/echo ${White}Still waiting for ${Green}The Bloodwail${White} to arrive...	
																/goto :WaitForBloodwail1
																}
/return

|-----------------------------------------------------------------------------------------------------------
Sub disembarkBloodwail
|-----------------------------------------------------------------------------------------------------------

    /echo ${White}Waiting for the ${Green}Bloodwail${White} to arrive at the dock.
	/delay 30s
	:WaitForBloodwail2
	
	/if (${Spawn[Bloodwail].Loc.Equal[-5433.75, -3092.62]})	{
															/echo ${White}All Ashore!
															/moveto loc -5347 -3100 325
															/delay 8s
															/return
															}
														
	/if (${Spawn[Bloodwail].Moving})	{
										/delay 30s
										/echo ${White}Still waiting for the ${Green}Bloodwail${White} to dock...
										/goto :WaitForBloodwail2
										}
/return


		
		