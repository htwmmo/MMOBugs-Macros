| ----------------------------------------------------------------------------------------------------------------------------------------------
|                                    TDS Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 8/11/2020
| ----------------------------------------------------------------------------------------------------------------------------------------------
|
| Route: PoK > Toxx > Barren Coast > Buried Sea > Tempest Temple > Katta Castrum Deluge > Tempest Temple > Caverns of Endless Song > Tempest Temple > 
| Route: Brother Island > Thulisaur > Brother Island > Degmar > Brother Island > Combine Dredge > Arx Mentis 

|
| ----------------------------------------------------------------------------------------------------------------------------------------------

| ----------------------------------------------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| ----------------------------------------------------------------------------------------------------------------------------------------------

Sub TDS

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,TDS]}==1) /return
	/lazyfind on
	
    /declare tempest		int outer	0
    /declare broisle		int outer	0
	/declare onBloodwail	int outer 	0

	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}The Darkened Sea ${Teal}**

|-------------------------------------------------------------------------------------------------------------------------------------------------
| Travel Loop - TDS
|-------------------------------------------------------------------------------------------------------------------------------------------------

	/call checkPotionStock
	
:TDS

	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKTDS 
	/if (${Zone.ID}==422) 						/call barren
	/if (${Zone.ID}==423) 						/call buriedseaTDS
	/if (${Zone.ID}==785)						/call tempesttemple
	/if (${Zone.ID}==780)						/call kattarubble
	/if (${Zone.ID}==782)						/call sirensong
	/if (${Zone.ID}==779)						/call broisland
	/if (${Zone.ID}==783)						/call thuliasaur
	/if (${Zone.ID}==784)						/call degmar
	/if (${Zone.ID}==781)						/call dredge	
	/if (${Zone.ID}==778)						/call TDSComplete
		
	/delay 2m !${Navigation.Active}
/goto :TDS	
/return

|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Route Complete
|-------------------------------------------------------------------------------------------------------------------------------------------------

Sub TDSComplete	
	/echo ${White}You have completed Exploring: ${Green}The Darkened Sea. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "TDS" "1"
	/delay 1s
    /call Completed
/return
		
|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Stages
|-------------------------------------------------------------------------------------------------------------------------------------------------
	
Sub PoKTDS
	/delay 1s
	/call travelToZone barren
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}			
/return	

Sub buriedseaTDS
	/delay 1s
	/call Navigating
	/call invisMe
	/call disembarkIsabeau
	/squelch /target clear
    /call travelToZone tempesttemple
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[buriedsea]}							
/return

Sub tempesttemple
	/delay 1s
	/call invisMe
	/call Navigating
	:tempestRetry
	/if (${tempest}==0) 		{
								/call travelToZone kattacastrumb
	} else /if (${tempest}==1) 	{
								/doevents
								/if (${FailedToZone}) 	{
														/echo ${Red}***Warning${Teal} Flag required to zone into ${Green}Caverns of Endless Song${Teal} - Skipping zone.
														/varset tempest 2
														/varset broisle 5
														/goto :tempestRetry
														}	
								/echo Traveling to ${Green}Caverns of Endless Song
								/squelch /nav loc 840 -23 -43								
	} else /if (${tempest}==2) 	{
								/call toBroIsland
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[tempesttemple]}			
/return	

Sub kattarubble
	/delay 2s
	/call invisMe
	/call Navigating
	/varset tempest 1
	/delay 2s
	/echo Traveling to ${Green}Tempest Temple
	/squelch /nav loc -111 1 23
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[kattacastrumb]}
/return	

Sub sirensong
	/delay 1s
	/call invisMe
	/call Navigating
	/varset tempest 2
	/call travelToZone tempesttemple
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[endlesscaverns]}
/return	

Sub toBroIsland
	/delay 1s
	/call invisMe
	/call Navigating
	/echo Heading to board ${Green}The Chaste Baron
	/squelch /nav loc -35 -495 20
	/delay 5s
	/delay 2m !${Navigation.Active}
	/face heading 270
	/call embarkBaron
	/delay 8s !${Zone.ShortName.Equal[tempesttemple]}
/return	

Sub broisland
	/delay 1s
	/call invisMe
	/call Navigating
	:broRetry
	/if (${broisle}==0) 		{
								/call disembarkBaron
								/varset broisle 1
	} else /if (${broisle}==1) 	{
								/doevents
								/if (${FailedToZone}) 	{
														/varset broisle 5
														/goto :broRetry
														}	
								/call invisMe
								/call Navigating
								/echo Heading to board the ${Green}Bloodwail
								/squelch /nav loc -5320 -3100 325
								/delay 3m !${Navigation.Active}	
								/face heading 180
								/call embarkBloodwail				
	} else /if (${broisle}==2) 	{
								/call invisMe
								/call Navigating
								/doevents flush
								/varset FailedToZone 0
								/call disembarkBloodwail
								/varset broisle 3
	} else /if (${broisle}==3) 	{
								/doevents
								/if (${FailedToZone}) 	{
														/varset broisle 5
														/goto :broRetry
														}	
								/call travelToZone degmar 
								/delay 3m !${Navigation.Active}	
	} else /if (${broisle}==4) 	{	
								/doevents
								/if (${FailedToZone}) 	{
														/varset broisle 5
														/goto :broRetry
														}								
								/call invisMe
								/call Navigating
								/doevents flush
								/varset FailedToZone 0
								/echo Traveling to ${Green}Combine Dredge
								/squelch /nav loc -3167 -4510 305
								/delay 3m !${Navigation.Active}	
	} else /if (${broisle}==5) 	{
								/echo ${Yellow}You need to work on progression to complete this route.
								/delay 3s
								/call TDSComplete
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[brotherisland]}			
/return	

Sub thuliasaur
	/delay 1s
	/call invisMe
	/call Navigating
	/varset broisle 2
	/echo Returning to ${Green}Brother Island
	/delay 4m !${Zone.ShortName.Equal[thuliasaur]}
/return	

Sub degmar
	/delay 2s
	/call invisMe
	/call Navigating
	/varset broisle 4
	/delay 2s
	/call travelToZone brotherisland
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[degmar]}
/return	

Sub dredge
	/delay 2s
	/doevents
	/if (${FailedToZone}) 	{
							/echo ${Red}***Warning${Teal} Flag required to zone into ${Green}Combine Dredge${Teal} - Skipping that zone.
							/echo ${Teal}Complete progression to gain access
							/delay 3s
							/call TDSComplete
							}
	/call invisMe
	/call Navigating
	/delay 2s
	/echo Traveling to ${Green}Anx Mentis
	/squelch /nav door id 81 click
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[degmar]}
/return	

