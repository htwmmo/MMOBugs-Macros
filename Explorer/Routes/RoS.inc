| ----------------------------------------------------------------------------------------------------------------------------------------------
|                                    RoS Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 18/11/2020
| ----------------------------------------------------------------------------------------------------------------------------------------------
|
| Route: PoK > Nexus > Lceanium > Scorched Woods > Skyfire > Veeshan's Peak > Gorowyn > Overthere > Howling Stone > Sathir's Tomb
| Should you have access to VP - not sure why you'd be running this route but it will Evac in VP and return to Skyfire 
|
| ----------------------------------------------------------------------------------------------------------------------------------------------

| ----------------------------------------------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| ----------------------------------------------------------------------------------------------------------------------------------------------

Sub RoS

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,RoS]}==1) /return
	/lazyfind on
	
    /declare sfRos		int outer	0

	/varset DoExpansion 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Ring of Scale ${Teal}**

|-------------------------------------------------------------------------------------------------------------------------------------------------
| Travel Loop - RoS
|-------------------------------------------------------------------------------------------------------------------------------------------------

	/call checkPotionStock
	/call checkPotionStock ivu
	
:RoS

	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKRoS 
	/if (${Zone.ID}==152) 						/call nexusEoK
	/if (${Zone.ID}==794) 						/call lceanium
	/if (${Zone.ID}==790)						/call scorchedRos
	/if (${Zone.ID}==814)						/call skyfireRoS
	/if (${Zone.ID}==816)						/call VpRoS
	/if (${Zone.ID}==792)						/call Gorowyn
	/if (${Zone.ID}==815)						/call OTRoS
	/if (${Zone.ID}==813)						/call HSRoS
	/if (${Zone.ID}==789)						/call RoSComplete
	
	/delay 2m !${Navigation.Active}
/goto :RoS	
/return

|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Route Complete
|-------------------------------------------------------------------------------------------------------------------------------------------------

Sub RoSComplete	
	/echo ${White}You have completed Exploring: ${Green}Ring of Scale. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "RoS" "1"
	/delay 1s
    /call Completed
/return
		
|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Stages
|-------------------------------------------------------------------------------------------------------------------------------------------------
	
Sub PoKRoS
	/delay 1s
	/call travelToZone nexus
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}			
/return	

Sub scorchedRos
	/delay 1s
	/call invisMe
	/call Navigating
	/call DangerRoute
	/call travelToZone skyfiretwo
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[tempesttemple]}			
/return	

Sub skyfireRoS
	/delay 1s
	/call invisMe
	/call Navigating
	/call DangerRoute
	:VPRetry
	/if (${sfRos}==0) 		{
							/echo Traveling to ${Green}Veeshan's Peak
							/squelch /nav loc 2816 2072 -181
							/delay 2m !${Navigation.Active}
							/squelch /doortarget id 7
							/delay 2s ${Switch.ID}==7
							/click left door
							/delay 2s
							/doevents
							/if (${FailedToZone}) 	{
													/echo ${Red}***Warning${Teal} Flag required to zone into ${Green} Veeshan's Peak ${Teal}- Skipping that zone.
													/echo ${White}Complete the progression to gain access
													/varset sfRos 1
													/goto :VPRetry
													}	
								
								
	} else /if (${sfRos}==1) 	{
								/call travelToZone gorowyn						
	} else /if (${sfRos}==2) 	{
								/call travelToZone overtheretwo
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[skyfiretwo]}			
/return	

Sub VpRoS
	/delay 2s
	/call invisMe
	/call Navigating
	/varset sfRos 1
	/delay 2s
	/call Evac
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gorowyn]}
/return	

Sub gorowyn
	/delay 2s
	/call invisMe
	/call Navigating
	/varset sfRos 2
	/delay 2s
	/call travelToZone skyfiretwo
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gorowyn]}
/return	

Sub OTRoS
	/delay 1s
	/call invisMe
	/call Navigating
	/call DangerRoute
	/call travelToZone charasistwo
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[overtheretwo]}
/return	

Sub HSRoS
	/delay 1s
	/call invisMe
	/call Navigating
	/call DangerRoute
	/call travelToZone charasisb
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[charasistwo]}
/return	