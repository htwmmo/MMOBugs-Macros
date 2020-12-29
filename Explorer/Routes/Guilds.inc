| -------------------------------------------------------------------------------------
|                                         	Guilds Route
|                                       Started: 16/10/2020
| -------------------------------------------------------------------------------------
| Required: Guild Hall, Guild Lobby
|
| -------------------------------------------------------------------------------------
| SUB: Guilds
| ------------------------------------------------------------------------------------- 
Sub Guilds
    
	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,Guilds]}==1) /return
	/lazyfind on
	
	/declare gl int outer 0
	
	/varset completed 0
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Guild Locals ${Teal}**
| -------------------------------------------------------------------------------------
    
:lobbyloop
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call lobbyloop
	/if (${Zone.ID}==344) 			/call lobby1
	/if (${Zone.ID}==345) 			/call exitGH
	
	/goto :lobbyloop
	
/return

| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub LobbyComplete	
	/echo ${White}You have completed Exploring: ${Green}Guild Locals. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "Guilds" "1"
	
	/call travelTozone Poknowledge	
	/delay 4s
	/lazyfind off
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------
	
	
Sub lobbyloop
	/delay 1
	/call travelTozone guildlobby
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}
/return
		
Sub lobby1
    /delay 1s
	/call Navigating
	
	/if (${gl}==0) 			{
							/delay 1s
							/nav door  id 3 click
							/delay 2m !${Navigation.Active}
							/delay 8s !${Zone.ShortName.Equal[guildlobby]}
	} else /if (${gl}==1)	{
							/delay 1s
							/call LobbyComplete
							/delay 8s !${Zone.ShortName.Equal[guildlobby]}
							}
/return
	
Sub exitGH
	/delay 3
	/varset gl 1
	/delay 2s
	/squelch /nav door id 1 click
	/delay 8s !${Zone.ShortName.Equal[guildhall]}
/return
	