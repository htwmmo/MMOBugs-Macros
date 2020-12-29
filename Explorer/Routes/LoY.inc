| -------------------------------------------------------------------------------------------------------
|                                    Legacy of Ykesha Route for Explorer.Mac
|                                       			By: Fizz
|                                       		Started: 5/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Gulf of Gunthak > Crypt of Nadox > Hate's Fury, The Scorned Maiden > Crypt of Nadox
| Route cont: Torgiran Mines > Dulak's Harbor > The Dead Hills > Ethernere > Tower of Rot > Ethernere
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub LoY

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,LoY]}==1) /return
	/lazyfind on

    /declare nadox				int outer	0
	/declare deadhills			int outer	0
    /declare ethernereLoY		int outer	0
	
	/varset completed 0
		
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Legacy of Ykesha ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - LoY
|--------------------------------------------------------------------------------------
	
	/call checkPotionStock 
	/call invisMe
	
:LoY
	
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0) 	/call travelToZone gunthak
	/if (${Zone.ID}==224) 						/call gunthakLoY
	/if (${Zone.ID}==227) 						/call nadox
	/if (${Zone.ID}==228) 						/call hatesfury	
	/if (${Zone.ID}==226) 						/call torgiran
	/if (${Zone.ID}==225) 						/call dulak	
	/if (${Zone.ID}==771) 						/call deadhills
	/if (${Zone.ID}==772) 						/call ethernereLoY
	/if (${Zone.ID}==775) 						/call travelToZone ethernere
	/if (${Zone.ID}==773)						/call LoYComplete
	
	/delay 2m !${Navigation.Active}
	
	/goto :LoY
																																								
/return			


| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub LoYComplete
	/echo ${White}You have completed Exploring: ${Green}Legacy of Ykesha.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "LoY" "1"
	/delay 1s		
	/call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub gunthakLoY
    /delay 1s
	/call travelToZone nadox	
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gunthak]}
/return


Sub nadox
    /delay 1s
	/call Navigating
	/call invisMe
	
	/if (${nadox}==0) 			{
								/delay 1s
								/echo Traveling to ${Green}Hates Fury
								/squelch /nav loc -1704 1545	-103
								/delay 2m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[nadox]}
	} else /if (${nadox}==1)	{
								/delay 1s
								/echo Traveling to ${Green}Mines of Torgiran
								/squelch /nav loc -82 -433 22
								/delay 2m !${Navigation.Active}
								/squelch /doortarget id 19
								/click left door
								/delay 3s
								/call travelToZone torgiran	
								/delay 1m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[nadox]}
								}
/return

Sub hatesfury
        /delay 2s
		/varset nadox 1
        /delay 2s
		/squelch /nav loc 155 -1030 -1
		/delay 2s
		/delay 8s !${Zone.ShortName.Equal[hatesfury]}
/return

Sub torgiran
        /delay 1s
		/squelch /nav loc -366 -634 3.56
		/delay 2m !${Navigation.Active}
		/delay 8s !${Zone.ShortName.Equal[torgiran]}
/return

Sub dulak
        /delay 1s
		/echo Traveling to ${Green}The Deadhills
		/squelch /nav loc -1160 -87 -28
		/delay 2m !${Navigation.Active}
		/squelch /doortarget id 51
		/click left door
		/delay 8s !${Zone.ShortName.Equal[dulak]}
/return

Sub deadhills	
	/if (${deadhillsLoY}==0) 			{
									/delay 1s
									/call travelToZone ethernere
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[deadhills]}
	} else /if (${deadhillsLoY}==1)	{
									/delay 1s
									/call invisMe
									/varset ethernereLoY 1
									/squelch /nav loc -86 -30 63
									/delay 1m !${Navigation.Active}
									/squelch /doortarget id 18
									/click left door
									/delay 3s
									/call travelToZone towerofrot
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[deadhills]}
									}
/return

Sub ethernereLoY
	/if (${ethernereLoY}==0) 		{
									/delay 1s
									/varset deadhillsLoY 1
									/delay 2s
									/call travelToZone deadhills
									/delay 8s !${Zone.ShortName.Equal[ethernere]}
	} else /if (${ethernereLoY}==1)	{
									/delay 1s
									/echo Traveling to ${Green}Void
									/nav door id 8 click
									/delay 8s !${Zone.ShortName.Equal[ethernere]}
									}
/return