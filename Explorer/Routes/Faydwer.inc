1| -------------------------------------------------------------------------------------------------------
|                                    Faydwer Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 7/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Butcherblock > Ocean of Tears > Butcherblock > South Kaladim >  North Kaladim >  South Kaladim > 
| Route Cont: Butcherblock >  Dagnor's Cauldron > Unrest  > Dagnor's Cauldron > Kedge Keep > PoK> 
| Route Cont: Greater Feydark > Clan Crushbone > Greater Feydark > North Felwithe > South Felwithe> North Felwithe >
| Route Cont: North Felwithe > Greater Faydark > Lesser Feydark > Castle Mistmoore > Lesser Feydark > Steamfont >
| Route Cont: Ak'anon
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub Faydwer

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,Faydwer]}==1) /return	
	/lazyfind on

	/declare pokFaydwer			int outer 0
	/declare butcherFaydwer		int outer 0
	/declare kaladim 			int outer 0
	/declare cauldron 			int outer 0
	/declare gfay 				int outer 0
	/declare lfay 				int outer 0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Faydwer ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - Faydwer
|--------------------------------------------------------------------------------------

	/call checkPotionStock

:Faydwer
	
	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call pokFaydwer
	/if (${Zone.ID}==68)						/call butcherFaydwer	
	/if (${Zone.ID}==409)						/call oot	
	/if (${Zone.ID}==67)						/call kaladimb
	/if (${Zone.ID}==70)						/call cauldron
	/if (${Zone.ID}==63)						/call unrest
	/if (${Zone.ID}==64)						/call kedge
	/if (${Zone.ID}==54)						/call gfay
	/if (${Zone.ID}==58)						/call crushbone
	/if (${Zone.ID}==62)						/call felwitheb
	/if (${Zone.ID}==57)						/call lfay
	/if (${Zone.ID}==59)						/call mistmoore
	/if (${Zone.ID}==55)						/call FaydwerComplete
	
	/delay 30s !${Navigation.Active}																			
 
/goto :Faydwer	

/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub FaydwerComplete	
	/delay 5s
	/echo ${White}You have completed Exploring: ${Green}Faydwer.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s	
	/ini "${RouteIniFileName}" "CompletedRoutes" "Faydwer" "1"
	/delay 1s
	/call Completed	
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub pokFaydwer
	/delay 1s
	/if (${pokFaydwer}==0) 		{
								/call travelToZone butcher
	} else /if (${pokFaydwer}==1)	{
								/call travelToZone gfaydark
	}
/return


Sub butcherFaydwer
	/delay 1s
	/if (${butcherFaydwer}==0) 			{
										/call invisMe
										/call gotoOOT
	} else /if (${butcherFaydwer}==1)	{
										/call invisMe
										/call travelToZone kaladimb
	} else /if (${butcherFaydwer}==2)	{
										/call cancellevi
										/call invisMe
										/call travelToZone cauldron
										}	
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[butcher]}
/return	

Sub gotoOOT
	/delay 1s
	/echo Traveling to ${Green}Ocean of Tears
	/squelch /nav loc 1355 3260 8
	/delay 3m !${Navigation.Active}
	/makemevisible
	/delay 2s
	/if (${SpawnCount[npc Translocator radius 20]}) /target npc Translocator_Fithop
	/delay 5s ${Target.ID}
	/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Translocator Fithop]}) 	{
																					/say Travel to Ocean of Tears
																					}
	/delay 8s !${Zone.ShortName.Equal[butcher]}
/return

Sub OOT
	/delay 1s
	/makemevisible
	/squelch /nav spawn npc Translocator_Narrik
	/delay 10s !${Navigation.Active}
	/delay 2s
	/varset butcherFaydwer 1
	/if (${SpawnCount[npc Translocator radius 10]}) /target npc Translocator_Narrik
	/delay 5s ${Target.ID}
	/if (${Target.Distance}<15 && ${Target.CleanName.Equal[Translocator Narrik]}) 	{
																					/say Travel to Butcherblock
																					}
	/delay 8s !${Zone.ShortName.Equal[oot]}
/return

Sub kaladimb
	/delay 2s
	/varset butcherFaydwer 2
	/delay 4s
	/call travelToZone butcher
	/delay 2s
	/delay 8s !${Zone.ShortName.Equal[kaladimb]}	
/return
	
Sub cauldron
	/delay 1s
	/if (${cauldron}==0) 		{
								/call invisMe
								/call travelToZone unrest
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[cauldron]}
	} else /if (${cauldron}==1)	{
								/call invisMe
								/echo Traveling to $(Green}Kedge Keep
								/squelch /nav loc -943 -973 -345
								/delay 3m !${Navigation.Active}								
								/call travelToZone kedge
								/delay 8s !${Zone.ShortName.Equal[cauldron]}
								}	
/return

Sub unrest
	/delay 2s
	/varset cauldron 1
	/delay 4s
	/call travelToZone cauldron
	/delay 2s
	/delay 8s !${Zone.ShortName.Equal[unrest]}	
/return

Sub kedge
	/delay 2s
	/varset pokFaydwer 1
	/echo ${Green}Short Cut the next path. Inc Evac
	/delay 3s
	/call evac
/return

Sub gfay
	/delay 1s
	/if (${gfay}==0) 			{
								/call invisMe
								/call travelToZone crushbone
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[gfaydark]}
	} else /if (${gfay}==1)	{
								/call invisMe
								/call travelToZone felwitheb
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[gfaydark]}
	} else /if (${gfay}==2)	{
								/call invisMe
								/call travelToZone lfaydark
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[gfaydark]}
								}	
/return

Sub crushbone
	/delay 1s
	/squelch /nav loc -595 165 0
	/varset gfay 1
	/delay 1s
	/squelch /nav loc -745 165 0
	/delay 3s
	/delay 25s !${Navigation.Active}
/return


Sub felwitheb
	/delay 1s
	/varset gfay 2
	/delay 3s
	/call travelToZone gfaydark
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gfaydark]}
/return

Sub lfay
	/delay 1s
	/if (${lfay}==0) 			{
								/call invisMe
								/call travelToZone mistmoore
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[lfaydark]}
	} else /if (${lfay}==1)	{
								/call invisMe
								/call travelToZone akanon
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[lfaydark]}
								}	
/return


Sub mistmoore
	/delay 2s
	/varset lfay 1
	/delay 4s
	/call travelToZone lfaydark
	/delay 2s
	/delay 8s !${Zone.ShortName.Equal[kaladimb]}	
/return
	