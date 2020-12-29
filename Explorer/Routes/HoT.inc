| -------------------------------------------------------------------------------------------------------
|                                    House of Thule Route for Explorer.Mac
|                                       			By: Fizz
|                                       		Started: 4/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Feerrott - The Dream > Lower House > The Library > Alkabor's Nightmare> Miragul's Nightmare
| Route cont: > Fear Itself > Morell's Castle > Sanction Somnium > Erudin Burning > Grounds > Well
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub HoT

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,HoT]}==1) /return
	/lazyfind on

    /declare lowerhouse			int outer	0
    /declare upperhouse			int outer	0
    /declare housegarden		int outer	0
    /declare morellcastle		int outer	0
	
	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}House of Thule ${Teal}**

|--------------------------------------------------------------------------------------
| Travel Loop - HoT
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	/call invisMe
	
:HoT
	
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call feerrott2
	/if (${Zone.ID}==700) 						/call hothule
	/if (${Zone.ID}==701) 						/call lowerhouse
	/if (${Zone.ID}==702) 						/call upperhouse	
	/if (${Zone.ID}==704) 						/call thulelibrary
	/if (${Zone.ID}==705) 						/call HoTComplete	
	/if (${Zone.ID}==706) 						/call fallen
	/if (${Zone.ID}==707) 						/call morellcastle
	/if (${Zone.ID}==708) 						/call somnium
	/if (${Zone.ID}==709)						/call alkabormare
	/if (${Zone.ID}==710) 						/call miragulmare
	/if (${Zone.ID}==711) 						/call thuledream
	
	/delay 2m !${Navigation.Active}
	
	/goto :HoT
																																														
/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub HoTComplete	
		/echo ${White}You have completed Exploring: ${Green}House of Thule. 
		/echo ${Yellow}Moving to Poknowledge
		/delay 2s
		/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
		/delay 2s
		/varset completed 1		
		/delay 1s
		/ini "${RouteIniFileName}" "CompletedRoutes" "HoT" "1"
		/delay 1s
  		/call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub feerrott2
		/delay 1s
		/squelch /nav door id 4 click
		/delay 2m !${Navigation.Active}		
		/delay 2s
		/notify LargeDialogWindow LDW_YesButton leftmouseup
		/delay 8s !${Zone.ShortName.Equal[poknowledge]}
/return

		
Sub hothule
		/call Navigating
		/call invisMe
		/delay 1s
		/squelch /nav loc -1400 928 -6
        /delay 2m !${Navigation.Active}
		/squelch /doortarget 
		/click left door
		/delay 8s !${Zone.ShortName.Equal[feerrott2]}
/return

Sub lowerhouse
    /delay 1s
	/call Navigating
	/call invisMe
	
	/if (${lowerhouse}==0) 			{
									/delay 1s
									/call travelToZone thulelibrary	
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse1]}
	} else /if (${lowerhouse}==1)	{
									/delay 1s
									/call upstairs	
									/delay 1m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse1]}
	} else /if (${lowerhouse}==2)	{
									/delay 1s
									/call travelToZone fallen	
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse1]}
	} else /if (${lowerhouse}==3)	{
									/delay 1s
									/call travelToZone well
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse1]}
	}
/return

Sub thulelibrary
        /delay 1s
		/varset lowerhouse 1
        /delay 1s
		/call travelToZone thulehouse1
        /delay 3s
		/delay 8s !${Zone.ShortName.Equal[thulelibrary]}
/return

Sub fallen
        /delay 1s
		/varset lowerhouse 3
        /delay 1s
		/squelch /nav loc -13.4 63.8 -2.56
        /delay 3s
		/squelch /doortarget id 18 
		/click left door
		/delay 8s !${Zone.ShortName.Equal[fallen]}
/return

Sub upstairs
	    /delay 1s
		/squelch /nav loc 371 82 65
        /delay 2m !${Navigation.Active}
		/squelch /doortarget id 19
		/click left door
		/delay 8s !${Zone.ShortName.Equal[thulehouse1]}
/return		
		
Sub upperhouse
	/delay 1s
	/call Navigating
	/call invisMe 
	
	/if (${upperhouse}==0) 			{
									/delay 1s
									/call travelToZone alkabormare
									/squelch /nav door ID 3 click
									/delay 1m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse2]}
	} else /if (${upperhouse}==1)	{
									/delay 1s
									/call travelToZone miragulmare
									/delay 1m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse2]}
	} else /if (${upperhouse}==2)	{
									/delay 1s
									/call EqAtFront
									/squelch /nav door id 88 click
									/delay 3s
									/delay 2m !${Navigation.Active}
									
									:stage
									/if (${SpawnCount[npc Andre radius 8]}) {
																			/call travelToZone thuledream
									} else {
											/goto :stage
											}
									/delay 3s
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse2]}
	} else /if (${upperhouse}==3)	{
									/delay 1s
									/if (${Me.Height}<3.71) {
															/call shrinkMe
															}
									/call invisMe									
									/call travelToZone morellcastle	
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse2]}
	} else /if (${upperhouse}==4)	{
									/delay 1s
									/varset lowerhouse 2
									/delay 1s
									/squelch /nav door id 83 click
									/delay 2m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[thulehouse2]}
	}
/return
			
Sub alkabormare
    /delay 1s
	/squelch /nav loc 52 1031 -29.3
    /delay 2m !${Navigation.Active}
	/makemevisible
    /delay 2s
	/varset upperhouse 1
	/if (${SpawnCount[npc Dreezil radius 18]}) /target npc Dreezil_Stickens_Pocketdip
	/delay 5s ${Target.ID}
	/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Dreezil Stickens Pocketdip]}) 	{
																							/say leave
		} else {
				/echo Dreezil Wasn't in range or not targeted, ending macro
				/end
				}
	/delay 8s !${Zone.ShortName.Equal[alkabormare]}
/return

Sub miragulmare
	/delay 1s
	/varset upperhouse 2
	/delay 1s
	/call travelToZone thulehouse2
	/delay 8s !${Zone.ShortName.Equal[miragulmare]}	
/return

Sub thuledream
	/delay 1s
	/varset upperhouse 3
	/delay 1s
	/call travelToZone thulehouse2
	/delay 8s !${Zone.ShortName.Equal[thuledream]}		
/return

Sub morellcastle
	/delay 1s
	/varset upperhouse 4
	/delay 1s
	/call Navigating
	/call invisMe
	
	/if (${morellcastle}==0) 		{
									/delay 1s
									/call travelToZone somnium
									/squelch /nav door ID 3 click
									/delay 1m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[morellcastle]}
	} else /if (${morellcastle}==1)	{
									/delay 1s
									/call travelToZone thulehouse2
									/delay 1m !${Navigation.Active}
									/delay 8s !${Zone.ShortName.Equal[morellcastle]}
	}
/return

Sub somnium
	/delay 1s
	/varset morellcastle 1
	/delay 1s
	/call travelToZone morellcastle
	/delay 8s !${Zone.ShortName.Equal[somnium]}	
/return

