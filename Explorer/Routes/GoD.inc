1| -------------------------------------------------------------------------------------------------------
|                                    Gates of Discord Route for Explorer.Mac
|                                       	By: Fizz
|                                       Started: 7/10/2020
| -------------------------------------------------------------------------------------------------------
|
| Route: PoK > Guild Lobby > Natimbi > Abysmal Sea > Natimbi > Muramite ProvingGrounds > 
| Route Cont: Riftseekers Sanctum >  PoK > Dranik Scar > Bloodfi1elds > Ruined City of Dranik > PoTactics> PoWar> 
|
| -------------------------------------------------------------------------------------------------------

| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub GoD

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,GoD]}==1) /return
	/lazyfind on

	/declare natimbi 			int outer 0
	/declare qinimi 			int outer 0
	/declare kodtaz 			int outer 0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Gates of Discord ${Teal}**
	
|--------------------------------------------------------------------------------------
| Travel Loop - Gates of Discord
|--------------------------------------------------------------------------------------

	/call checkPotionStock
		
:GoD
	
	/call GMCheck	
	/delay 1s
	/call Navigating
	
	/if (${Zone.ID}==202 && ${completed}==0)	/call travelToZone guildlobby	
	/if (${Zone.ID}==344)						/call lobbyGoD	
	/if (${Zone.ID}==182)						/call nedariaGoD	
	/if (${Zone.ID}==279)						/call abysmal
	/if (${Zone.ID}==280)						/call natimbi
	/if (${Zone.ID}==281)						/call qinimi
	/if (${Zone.ID}==284)						/call travelToZone riwwi
	/if (${Zone.ID}==282)						/call travelToZone barindu
	/if (${Zone.ID}==283)						/call barindu
	/if (${Zone.ID}==293)						/call travelToZone yxtta
	/if (${Zone.ID}==291)						/call travelToZone qvic
	/if (${Zone.ID}==295)						/call travelToZone txevu
	/if (${Zone.ID}==297)						/call GoDComplete
	/delay 30s !${Navigation.Active}																			
 
/goto :GoD	

/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub GoDComplete	
	/delay 5s
	/echo ${White}You have completed Exploring: ${Green}Gates of Discord.
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "GoD" "1"
	/delay 1s
    /call Completed		
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub lobbyGoD	
		/call Navigating
		/delay 1s
		/squelch /nav spawn npc Magus_Alaria
		/delay 2m !${Navigation.Active}
		/if (${SpawnCount[npc Magus radius 15]}) /target npc Magus_Alaria
			/delay 4s ${Target.ID}
			/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Magus Alaria]}) {
																						/makemevisible
																						/say Nedaria's Landing
																						}
		/delay 8s !${Zone.ShortName.Equal[guildlobby]}
/return

Sub nedariaGoD
		/delay 1s
		/squelch /nav spawn npc Magus_Wenla
		/delay 2m !${Navigation.Active}
		/if (${SpawnCount[npc Magus radius 15]}) /target npc Magus_Wenla
			/delay 4s ${Target.ID}
			/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Magus Wenla]}) 	{
																					/makemevisible
																					/say Abysmal Sea
																					}
		/delay 8s !${Zone.ShortName.Equal[guildlobby]}
/return

Sub abysmal
		/delay 1s
		/squelch /nav spawn npc Magus_Pellen
		/delay 2m !${Navigation.Active}
		/if (${SpawnCount[npc Magus radius 15]}) /target npc Magus_Pellen
			/delay 4s ${Target.ID}
			/if (${Target.Distance}<20 && ${Target.CleanName.Equal[Magus Pellen]}) {
																					/makemevisible
																					/say Natimbi
																					}
		/delay 8s !${Zone.ShortName.Equal[guildlobby]}
/return

Sub natimbi
	/delay 1s
	/call invisMe
	/if (${natimbi}==0) 		{
								/call travelToZone qinimi
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[natimbi]}
	} else /if (${natimbi}==1)	{
								/call invisMe
								/call travelToZone kodtaz
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[natimbi]}
								}	
/return	


Sub qinimi
	/delay 1s
	/call invisMe
	/if (${qinimi}==0) 		{
								/call travelToZone ferubi
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[qinimi]}
	} else /if (${qinimi}==1)	{
								/varset natimbi 1
								/call travelToZone natimbi
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[qinimi]}
								}	
/return	

Sub barindu
	/delay 1s
	/varset qinimi 1
	/delay 3s
	/nav loc -1541 765 -126
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[barindu]}
/return
	

Sub kodtaz
	/delay 1s
	/call invisMe
	/if (${kodtaz}==0) 			{
								/varset natimbi 2
								/call travelToZone yxtta
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[kodtaz]}
	} else /if (${kodtaz}==1)	{
								/call invisMe
								/call travelToZone qvic
								/delay 3m !${Navigation.Active}
								/delay 8s !${Zone.ShortName.Equal[kodtaz]}
								}	
/return	

Sub yxtta
	/delay 2s
	/varset kodtaz 1
	/delay 2s
	/call travelToZone kodtaz
	/delay 3s
	/delay 8s !${Zone.ShortName.Equal[kodtaz]}
/return