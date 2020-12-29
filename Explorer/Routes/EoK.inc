| ----------------------------------------------------------------------------------------------------------------------------------------------
|                                    EoK Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 8/11/2020
| ----------------------------------------------------------------------------------------------------------------------------------------------
|
| Route: PoK > Nexus > Lceanium > Scorched Woods > Chardok > Scorched Woods > Frontier Mountains  > Droga > Frontier Mountains > Gates > Kor'Sha

|
| ----------------------------------------------------------------------------------------------------------------------------------------------

| ----------------------------------------------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| ----------------------------------------------------------------------------------------------------------------------------------------------

Sub EoK

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,EoK]}==1) /return
	/lazyfind on
	
    /declare scorched		int outer	0
    /declare FMEoK			int outer	0

	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Empires of Kunark ${Teal}**

|-------------------------------------------------------------------------------------------------------------------------------------------------
| Travel Loop - EoK
|-------------------------------------------------------------------------------------------------------------------------------------------------

	/call checkPotionStock
	
:EoK

	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKEoK 
	/if (${Zone.ID}==152) 						/call nexusEoK
	/if (${Zone.ID}==794) 						/call lceanium
	/if (${Zone.ID}==790) 						/call scorched
	/if (${Zone.ID}==800)						/call chardokEoK
	/if (${Zone.ID}==791)						/call FMEoK
	/if (${Zone.ID}==788)						/call DrogaEoK
	/if (${Zone.ID}==793)						/call GatesEoK
	/if (${Zone.ID}==799)						/call EoKComplete
		
	/delay 2m !${Navigation.Active}
/goto :EoK	
/return

|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Route Complete
|-------------------------------------------------------------------------------------------------------------------------------------------------

Sub EoKComplete	
	/echo ${White}You have completed Exploring: ${Green}Empires of Kunark. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "EoK" "1"
	/delay 1s
    /call Completed
/return
		
|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Stages
|-------------------------------------------------------------------------------------------------------------------------------------------------
	
Sub PoKEoK
	/delay 1s
	/call travelToZone nexus
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}			
/return	

Sub nexusEoK
	/delay 2s
	/nav spawn npc Jayson_Bri`Tian
	/delay 2m !${Navigation.Active}
	/makemevisible
	/delay 2s
	/if (${SpawnCount[npc Jayson radius 10]}) /target npc Jayson_Bri`Tian
	/delay 5s ${Target.ID}
	/if (${Target.Distance}<15 && ${Target.CleanName.Equal[Jayson Bri`Tian]})	{
																				/say Spire Stone of Lceanium
																				/delay 3s
																				/autoinventory
																				/delay 2s
																				/squelch /nav loc 0 0 -30
																				/while (${Zone.ID}==152) 	{
																											/delay 20s
																											/echo ${Yellow}Waiting on Portal
																											}
																				}
	/delay 8s !${Zone.ShortName.Equal[nexus]}
/return

Sub lceanium
	/delay 1s
	/call Navigating
	/call invisMe
    /call travelToZone scorchedwoods
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[lceanium]}							
/return

Sub scorched
	/delay 1s
	/call invisMe
	/call Navigating
	/call DangerRoute
	/if (${scorched}==0) 		{
								/squelch nav loc 968 -309 
								/delay 4m !${Navigation.Active}
								/call travelToZone chardoktwo
	} else /if (${scorched}==1)	{
								/squelch nav loc 1267 -1834 -225
								/delay 4m !${Navigation.Active}
								/squelch nav loc -1091 -1527 -270
								/delay 4m !${Navigation.Active}
								/call travelToZone frontiermtnsb
								}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[tempesttemple]}			
/return	

Sub chardokEoK
	/delay 2s
	/call invisMe
	/call Navigating
	/call DangerRoute
	/varset scorched 1
	/call travelToZone scorchedwoods
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[endlesscaverns]}
/return	


Sub FMEoK
	/delay 1s
	/call invisMe
	/call Navigating
	/varset scorched 2
	/if (${FMEoK}==0) 			{
								/echo Traveling to ${Green}Temple of Droga
								/squelch /nav loc 3542 2812 112
	} else /if (${FMEoK}==1)	{
								/call travelToZone korshaext
								}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[tempesttemple]}			
/return	

Sub DrogaEoK
	/delay 2s
	/call invisMe
	/call Navigating
	/varset FMEoK 1
	/call travelToZone frontiermtnsb
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[endlesscaverns]}
/return	

Sub GatesEoK
	/delay 1s
	/call invisMe
	/call Navigating
	/call DangerRoute
	/call travelToZone korshaint
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[endlesscaverns]}
/return	