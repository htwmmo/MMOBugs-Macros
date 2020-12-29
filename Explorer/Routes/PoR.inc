| -------------------------------------------------------------------------------------------------------
|                                    Prophecy of Ro Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 23/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Nektulos Forrest > Corathus Creep > The Undershore > Ruins of Illsain > The Undershore >
| Route cont: > Fear Itself > Morell's Castle > Sanction Somnium > Erudin Burning > Grounds > Well
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub PoR

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,PoR]}==1) /return
	/lazyfind on

    /declare PoKPoR		int outer	0
    /declare arcstone	int outer	0
	
	/varset completed 0


	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Prophecy of Ro ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - PoR
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	

:PoR
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKPoR
| Path 1
	/if (${Zone.ID}==413) 		/call innothulePoR 
	/if (${Zone.ID}==393) 		/call southroPoR
	/if (${Zone.ID}==376) 		/call takishruins
	/if (${Zone.ID}==378) 		/call elddar  
| Path 2
	/if (${Zone.ID}==383) 		/call WFreeport
	/if (${Zone.ID}==369) 		/call arcstone 
	/if (${Zone.ID}==370) 		/call relic 
	
	/if (${Zone.ID}==382) 		/call EFreeport
	/if (${Zone.ID}==372) 		/call devastation
	
	/if (${Zone.ID}==374) 		/call rage
	
	/if (${Zone.ID}==380) 		/call PoRComplete
	
	/delay 2m !${Navigation.Active}
	/goto :PoR
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub PoRComplete	
	/echo ${White}You have completed Exploring: ${Green}Prophecy of Ro. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "PoR" "1"
	/delay 2s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub PoKPoR
	/delay 1s
	/if (${PoKPoR}==0) 			{
								/call travelToZone innothuleb
	} else /if (${PoKPoR}==1)	{
								/call travelToZone freeportwest
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

Sub innothulePoR
	/call Navigating
	/call invisMe
	/delay 1s
	/call travelToZone southro
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[innothuleb]}							
/return
	
Sub southroPoR
	/delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone takishruins
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[southro]}							
/return

Sub takishruins
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Eldaar Forest
	/squelch /nav door id 3 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

Sub elddar
	/delay 2s
	/call Navigating
	/call invisMe
	/echo ${Green}Taking a shortcut....
	/varset PoKPoR 1
	/delay 2s
	/call Evac
/return
	
Sub WFreeport
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Arcstone, Isle of Spirits
	/squelch /nav loc 210 -770 -118
	/delay 2m !${Navigation.Active}
	/squelch /doortarget id 3 
	/squelch /click left door
	/call travelToZone arcstone	
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[freeportwest]}							
/return

Sub arcstone
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Relic, the Artifact City
    /squelch /nav loc -188 1670 10
	/delay 1s
    /squelch /nav loc 240 -957 406
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[arcstone]}							
/return

Sub relic
	/delay 2s
	/call cancelLevi
	/delay 2s
	/echo I believe I can fly..... I believe we're about to die!!!
	/squelch /moveto loc 552 870 -278
	/delay 8s !${Zone.ShortName.Equal[relic]}							
/return

Sub EFreeport
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Devastation
	/squelch /nav door id 3 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[freeportwest]}							
/return


Sub devastation
	/delay 1s
	
	/call Navigating
	/call invisMe
    /echo Traveling to ${Green}Sverag, Stronghold of Rage
	:doorkill
    /squelch /nav loc 2034 2474 45
	/delay 3m !${Navigation.Active}
	/target stronghold_door00
    /if (${Target.ID} && ${Target.CleanName.Equal[stronghold door]} && ${Target.PctHPs} > 0) 	{
																								/attack on
																								/delay 5
																								/goto :doorkill
																								}
    /squelch /moveto loc 2034 2300 40
    /delay 8s !${Zone.ShortName.Equal[devastation]}
    }				
/return

Sub rage
	/delay 2
	/echo Traveling to ${Green}The Theatre of Blood
	/alt activate 574
/return
