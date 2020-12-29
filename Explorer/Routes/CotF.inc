| ----------------------------------------------------------------------------------------------------------------------------------------------
|                                    CotF Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 8/11/2020
| ----------------------------------------------------------------------------------------------------------------------------------------------
|
| Route: Innothule > SRo > Argin-Hiz > Ethernere > Argin-Hiz > SRo > Innothule > PoK
| Route: Bixiewarfront > Ethernere > Argin-Hiz > SRo > Innothule > PoK
| Route: Nektulos Forrest > Neriak Forth Gate > Ethernere > Argin-Hiz > SRo > Innothule > PoK
| Route: Gulf of Gunthak > Dulak's Harbor > Dead Hills > Ethernere > Tower of Rot > Dead Hills > Ethernere > The Void > PoK
|
| ----------------------------------------------------------------------------------------------------------------------------------------------

| ----------------------------------------------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| ----------------------------------------------------------------------------------------------------------------------------------------------

Sub CotF

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,CotF]}==1) /return
	/lazyfind on
	
    /declare PoKCotF       			int outer	0	  
    /declare ethernereCotF   		int outer	0     
    /declare deadhillsCotF       	int outer	0   
    /declare sroCotF      			int outer	0 
    /declare swampCotF      		int outer	0     
    /declare arginhizCotF   		int outer	0

	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Call of the Forsaken ${Teal}**

|-------------------------------------------------------------------------------------------------------------------------------------------------
| Travel Loop - CotF
|-------------------------------------------------------------------------------------------------------------------------------------------------

	/call checkPotionStock
	
:CotF
					
	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call PoKCotF 
	
| Path 1
	/if (${Zone.ID}==413) 	/call innothulebCotF
	/if (${Zone.ID}==393) 	/call sroCotF
	/if (${Zone.ID}==776) 	/call arginhizCotF
	/if (${Zone.ID}==772) 	/call ethernereCotF
	
| Path 2
	/if (${Zone.ID}==770) 	/call bfCotF
	
| Path 3	
	/if (${Zone.ID}==25) 	/call nektulosCotF	
	/if (${Zone.ID}==42) 	/call enterForthGateCotF			
	/if (${Zone.ID}==43) 	/call travelToZone ethernere
	
| Path 4		
	/if (${Zone.ID}==224) 	/call gunthakCotF
	/if (${Zone.ID}==225) 	/call dulakCotF	
	/if (${Zone.ID}==771) 	/call deadhillsCotF
	/if (${Zone.ID}==775) 	/call rotCotF
	
	/if (${Zone.ID}==773)	/call CotFComplete
		
	/delay 2m !${Navigation.Active}
/goto :CotF	
/return

|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Route Complete
|-------------------------------------------------------------------------------------------------------------------------------------------------

Sub CotFComplete	
	/echo ${White}You have completed Exploring: ${Green}Call of the Forsaken. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/ini "${RouteIniFileName}" "CompletedRoutes" "CotF" "1"
	/delay 1s
    /call Completed
/return
		
|-------------------------------------------------------------------------------------------------------------------------------------------------
| SUB : Stages
|-------------------------------------------------------------------------------------------------------------------------------------------------
	
Sub PoKCotF
	/delay 1s
	/if (${PoKCotF}==0) 		{
								/call travelToZone innothuleb
	} else /if (${PoKCotF}==1) 	{
								/call travelToZone bixiewarfront
	} else /if (${PoKCotF}==2) 	{
								/call travelToZone neriakc
|								/call travelToZone nektulos
	} else /if (${PoKCotF}==3) 	{
								/call travelToZone dulak 
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}			
/return	

|Path 1
|--------------------------

Sub innothulebCotF
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${swampCotF}==0) 			{							
									/call travelToZone southro
	} else /if (${swampCotF}==1) 	{
									/call travelToZone poknowledge
									}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[innothuleb]}
/return	

Sub SroCotF
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${sroCotF}==0) 		{
								/delay 1s
								/varset swampCotF 1
								/call travelToZone arginhiz
	} else /if (${sroCotF}==1)	{
								/call travelToZone innothuleb
								}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[southro]}
/return

Sub arginhizCotF
	/delay 1s
	/call invisMe
	/call Navigating
	/if (${arginhizCotF}==0) 		{
									/delay 1s
									/varset PoKCotF 1
									/call travelToZone ethernere
	} else /if (${arginhizCotF}==1)	{
									/delay 1s
									/varset sroCotF 1
									/call travelToZone southro									
									}
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[arginhiz]}	
/return

|Path 2
|--------------------------

Sub bfCotF
	/delay 1s
	/call invisMe
	/call Navigating
	/varset PoKCotF 2
	/call travelToZone ethernere
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[bixiewarfront]}
/return	

|Path 3
|--------------------------
Sub nektulosCotF
	/delay 1s
	/call invisMe
	/call Navigating
	/call travelToZone neriakc
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[bixiewarfront]}
/return	

Sub enterForthGateCotF
    /delay 1s
	/call invisMe
	/call Navigating
	/varset PoKCotF 3
	/echo Traveling to ${Green}Neriak Forth Gate
	/squelch /nav loc 908.88 -1770.42 -69.9
	/delay 3s	
    /delay 3m !${Navigation.Active}
/return

|Path 4
|--------------------------

Sub gunthakCotF
    /delay 1s
	/call travelToZone dulak	
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[gunthak]}
/return

Sub dulakCotF
        /delay 1s
		/echo Traveling to ${Green}The Deadhills
		/squelch /nav loc -1160 -87 -28
		/delay 2m !${Navigation.Active}
		/squelch /doortarget id 51
		/click left door
		/delay 8s !${Zone.ShortName.Equal[dulak]}
/return

Sub deadhillsCotF	
	/delay 1s
	/call invisMe
	/call Navigating
	
	/if (${deadhillsCotF}==0) 			{
										/varset PoKCotF 4
										/varset ethernereCotF 1
										/call travelToZone ethernere
	} else /if (${deadhillsCotF}==1)	{
										/echo Traveling to ${Green}Tower of Rot
										/squelch /nav loc -86 -30 63
										/delay 1m !${Navigation.Active}
										/squelch /doortarget id 18
										/click left door
										/delay 3s
										/call travelToZone towerofrot
										}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[deadhills]}
/return

Sub rotCotF
	/delay 1s
	/call invisMe
	/call Navigating
	/varset ethernereCotF 2
	/call travelToZone ethernere
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[towerofrot]}
/return	

|Ethernere
|-----------------------------

Sub ethernereCotF
	/if (${ethernereCotF}==0) 			{
										/delay 2s
										/varset arginhizCotF 1
										/call travelToZone arginhiz
	} else /if (${ethernereCotF}==1)	{
										/delay 1s
										/varset deadhillsCotF 1
										/call travelToZone deadhills
										/delay 8s !${Zone.ShortName.Equal[ethernere]}
	} else /if (${ethernereCotF}==2)	{
										/delay 1s
										/echo Traveling to ${Green}Void
										/nav door id 8 click
										/delay 8s !${Zone.ShortName.Equal[ethernere]}
										} 
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[ethernere]}
/return
		
