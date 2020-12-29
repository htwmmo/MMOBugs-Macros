| -------------------------------------------------------------------------------------------------------
|                                    Seeds of Destruction Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 23/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Time-A > Void > Toskirakk > Korascian Warrens > Rathe Council Chamber > PoK
| Route cont: PoK > Time-A > Void > Korafax > Void > Bloody Kithicor > Old Commonlands > Bloody Kithicor > 
| Route cont: Void > Old Bloodfields > City of Dranik > Old Bloodfields > The Void > Field of Scale > 
| Route cont: Kurn's Tower > Field of Scale > Kaesora Library > Field of Scale > Kaesora Hatchery >
| Route cont: Field of Scale > Void > Oceangreen Hills > Old Blackburrow > Oceangreen Hills > 
| Route cont:Oceangreen Village > Temple of Bertoxxulous > 
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub SoD

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,SoD]}==1) /return
	/lazyfind on

    /declare voidSoD	int outer	0
    /declare oldkith	int outer	0
    /declare oldbf		int outer	0
    /declare oldfob		int outer	0
    /declare ogh		int outer	0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Seeds of Destruction ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - SoD
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	

:SoD
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKSoD
	/if (${Zone.ID}==219) 	/call timea
	/if (${Zone.ID}==459)	/call voidSoD
	/if (${Zone.ID}==460) 	/call voidSoD
	/if (${Zone.ID}==461) 	/call voidSoD
	/if (${Zone.ID}==462) 	/call voidSoD
	/if (${Zone.ID}==463) 	/call voidSoD
	/if (${Zone.ID}==464) 	/call voidSoD
	/if (${Zone.ID}==465) 	/call voidSoD
	
| Path 1
	/if (${Zone.ID}==470) 	/call discord
| Path 2
	/if (${Zone.ID}==475) 	/call toskirakk
	/if (${Zone.ID}==476) 	/call korascian
	/if (${Zone.ID}==477) 	/call rathechamber 
| Path 3	
	/if (${Zone.ID}==456) 	/call oldkithicor
	/if (${Zone.ID}==457) 	/call oldcommons
| Path 3	
	/if (${Zone.ID}==472) 	/call oldbloodfield
	/if (${Zone.ID}==474) 	/call olddranik 
| Path 4	
	/if (${Zone.ID}==452) 	/call oldfieldofbone
	/if (${Zone.ID}==455) 	/call oldkurn
	/if (${Zone.ID}==453) 	/call oldkaesoraa
	/if (${Zone.ID}==454) 	/call oldkaesorab	
| Path 5	
	/if (${Zone.ID}==466) 	/call oceangreenhills
	/if (${Zone.ID}==468) 	/call oldblackburrow	
	/if (${Zone.ID}==467) 	/call oceangreenvillage
	/if (${Zone.ID}==469) 	/call SoDComplete
	
	/delay 2m !${Navigation.Active}
	/goto :SoD
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub SoDComplete	
	/echo ${White}You have completed Exploring: ${Green}Seeds of Destruction. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "SoD" "1"
	/delay 2s
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub PoKSoD
	/delay 1s
	/echo Traveling to ${Green}The Plane of Time (A)
    /squelch /nav spawn npc Herald_of_Druzzil_Ro
    /call Navigating
    /makemevisible
    /delay 2s !${Me.Invis}
    /target npc Herald_of_Druzzil_Ro
    /delay 10s ${Target.ID}
	/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Herald of Druzzil Ro]}) /say travel
    /say Time
    /delay 8s !${Zone.ShortName.Equal[poknowledge]}						
/return

Sub timea
	/delay 1s
	/echo Traveling to ${Green}The Void
    /squelch /nav door id 2 click
	/delay 3m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[potimea]}						
/return

Sub voidSoD
	/delay 1s
	/call EqAtFront
	/call Navigating
	/if (${voidSoD}==0) 		{
								/call travelToZone discord
	} else /if (${voidSoD}==1)	{
								/call travelToZone toskirakk
	} else /if (${voidSoD}==2)	{
								/echo Traveling to ${Green}The Old Kithicor
								/squelch /nav loc  -41 -95 6.5	
	} else /if (${voidSoD}==3)	{
								/echo Traveling to ${Green}The Old Bloodfields
								/squelch /nav loc  75 318 -24.4
	} else /if (${voidSoD}==4)	{	
								/echo Traveling to ${Green}Field of Scale
								/squelch /nav loc  183 -295 -11								
	} else /if (${voidSoD}==5)	{
								/echo Traveling to ${Green}Oceangreen Hills
								/squelch /nav loc  340 89 38
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

| Path 1
Sub discord
	/delay 2s
	/call Navigating
	/call invisMe
	/varset voidSoD 1
	/squelch /nav door id 38 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thalassius]}							
/return

| Path 2
Sub toskirakk
	/delay 2s
	/call Navigating
	/call invisMe
	/call travelToZone korascian
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thalassius]}							
/return

Sub korascian
	/delay 2s
	/call Navigating
	/call invisMe
	/call EqAtFront
	/call travelToZone rathechamber
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thalassius]}	
/return

Sub rathechamber
	/delay 2s
	/varset voidSoD 2
	/delay 2s
	/echo ${Green}Taking a shortcut.
	/call Evac
/return

| Path 3
Sub oldkithicor
	/delay 1s
	/varset voidSoD 3	
	/call Navigating
	/call invisMe
	/if (${oldkith}==0) 		{
								/echo Traveling to ${Green}The Old Commonlands
								/squelch /nav loc  889 -3137 13
	} else /if (${oldkith}==1)	{
								/echo Traveling to ${Green}The Void
								/squelch /nav loc  1154 -250 9
								/delay 3m !${Navigation.Active}
								/squelch /doortarget id 20
								/delay 2s ${Switch.ID}==20
								/click left door
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oldkithicor]}	
/return	

Sub oldcommons
	/delay 2s
	/varset oldkith 1
	/delay 2s
	/call Navigating
	/call invisMe
	/call travelToZone oldkithicor
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oldcommons]}	
/return

| Path 4
Sub oldbloodfield
	/delay 1s
	/varset voidSoD 4	
	/call Navigating
	/call invisMe
	/if (${oldbf}==0) 			{
								/call travelToZone olddranik
	} else /if (${oldbf}==1)	{
								/echo Traveling to ${Green}The Void
								/squelch /nav door id 3 click
								/delay 3m !${Navigation.Active}
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oldbloodfield]}	
/return	

Sub olddranik
	/delay 2s
	/varset oldbf 1
	/delay 2s
	/call Navigating
	/call invisMe
	/call travelToZone oldbloodfield
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[olddranik]}	
/return

| Path 5
Sub oldfieldofbone
	/delay 1s
	/varset voidSoD 5	
	/call Navigating
	/call invisMe
	/if (${oldfob}==0) 			{								
								/echo Traveling to ${Green}Kurn's Tower
								/nav loc  435 900 103.7
								/delay 3m !${Navigation.Active}
								/squelch /target clear
								/squelch /doortarget id 3
								/delay 2s ${Switch.ID}==3
								/click left door
	} else /if (${oldfob}==1)	{
								/echo Traveling to ${Green}Kaesora Library
								/squelch /nav door id 44 click
								/delay 3m !${Navigation.Active}
	} else /if (${oldfob}==2)	{
								/echo Traveling to ${Green}Kaesora Hatchery
								/squelch /nav door id 36 click
								/delay 3m !${Navigation.Active}
	} else /if (${oldfob}==3)	{
								/echo Traveling to ${Green}The Void
								/squelch /nav door id 45 click
								/delay 3m !${Navigation.Active}
								}
	/delay 8s !${Zone.ShortName.Equal[oldfieldofbone]}	
/return	

Sub oldkurn
	/delay 2s
	/varset oldfob 1
	/call travelToZone oldfieldofbone
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oldfieldofbone]}	
/return

Sub oldkaesoraa
	/delay 2s
	/varset oldfob 2
	/delay 2s
	/call travelToZone oldfieldofbone
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oldfieldofbone]}	
/return
	
Sub oldkaesorab
	/delay 2s
	/varset oldfob 3
	/delay 2s
	/call travelToZone oldfieldofbone
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oldfieldofbone]}	
/return
	
| Path 6
Sub oceangreenhills
	/delay 1s
	/varset voidSoD 5	
	/call Navigating
	/call invisMe
	/if (${ogh}==0) 		{
							/call EnterBlkburrow
	} else /if (${ogh}==1)	{
							/echo Traveling to ${Green}Oceangreen Village
							/squelch /nav loc  0 72 2
							}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oceangreenhills]}	
/return	

Sub EnterBlkburrow
	/echo ${White}Getting permission to enter ${Green}Old Blackburrow.
    /doevents flush
    /varset FailedToZone 0
    /squelch /nav spawn Bracka
    /call Navigating
    /makemevisible
    /delay 5 (!${Me.Invis})
    /target npc Bracka_Darkpaw
    /delay 5 ${Target.ID}
    /say I'll hunt them
    /delay 2s ${Window[TaskWND].Open}
    /invoke ${Window[TaskWND].DoClose}
	/call invisMe
	/squelch /nav loc 3410 -1029 9
	/squelch /target door id 6 
	/click left door
	/delay 3m !${Navigation.Active}
    /while (!${FailedToZone} && ${Zone.ShortName.Equal[oceangreenhills]}) 	{
																			/doevents
																			/delay 1
																			}
/return

Sub oldblackburrow
	/delay 2s
	/call Navigating
	/call invisMe
	/varset ogh 1
	/call travelToZone oceangreenhills
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thalassius]}							
/return


Sub oceangreenvillage
	/delay 2s
	/call Navigating
	/call invisMe
	/call cancelLevi
	/call travelToZone bertoxtemple
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[oceangreenvillage]}	
/return	
