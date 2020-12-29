| -------------------------------------------------------------------------------------
|                                    Shadows of Luclin Route
|                                       Started: 16/10/2020
| -------------------------------------------------------------------------------------

| Route: PoK > Bazaar > Shadow Haven > Paludal Caverns > Shadewearer Thicket >
| Route: Shar Val > Hollowshade Moors > Grimling Forest > Acrylia Caverns > Grimling Forest >
| Route: Tenebrous Mountains > Katta Castellum > Twilight Sea > Fungus Grove > Echo Caverns >
| Route: Shadow Haven > Echo Caverns  > The Deep > Ssraeshza Temple > The Grey > 
| Route: Scarlet Desert > Grieg's End > Dawnshroud Peaks > Sanctus Seru > Marus Seru >
| Route: Mons Letalis > Marus Seru > Netherbian Lair > Dawnshroud Peaks > Maiden's Eye >
| Route: Akheva Ruins > Maiden's Eye > Umbral Plains > Vex Thal 
| -------------------------------------------------------------------------------------

Sub SoL
	
	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,SoL]}==1) /return
	
	/lazyfind on
	
	
    /declare pokSoL			int outer	0
    /declare shaven			int outer	0
    /declare grimling		int outer	0
	/declare twil			int outer	0
	/declare grey			int outer	0
	/declare dawn			int outer	0
	/declare maiden			int outer	0
	/declare umbral			int outer	0
	
	/varset completed 0
	
	
	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Shadows of Luclin ${Teal}**
			

|--------------------------------------------------------------------------------------
| Travel Loop - SoL
|--------------------------------------------------------------------------------------
	
	/call checkPotionStock

:SoL
		
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)	/call pokSoL
	
|-Path 1

	/if (${Zone.ID}==151) 			/call bazaar
	/if (${Zone.ID}==150) 			/call shadowhaven
	/if (${Zone.ID}==155) 			/call sharvahl
	/if (${Zone.ID}==167) 			/call grimling
	/if (${Zone.ID}==154) 			/call acrylia
	/if (${Zone.ID}==172) 			/call tenebrous
	/if (${Zone.ID}==160) 			/call katta
	/if (${Zone.ID}==170) 			/call twilight
	/if (${Zone.ID}==157) 			/call fungusgrove
	/if (${Zone.ID}==171) 			/call thegrey
	/if (${Zone.ID}==162) 			/call ssra
	/if (${Zone.ID}==159) 			/call sseru
	/if (${Zone.ID}==174) 			/call dawnshroud
	/if (${Zone.ID}==163) 			/call griegsend
	/if (${Zone.ID}==173) 			/call maiden
	/if (${Zone.ID}==179) 			/call akheva
	/if (${Zone.ID}==176) 			/call umbral
	/if (${Zone.ID}==158) 			/call vexthal
	/if (${Zone.ID}==161) 			/call netherbian	
	/if (${Zone.ID}==152) 			/call nexusSoL
	/if (${Zone.ID}==153) 			/call echoC
	/if (${Zone.ID}==153) 			/call SoLComplete

	/delay 2m !${Navigation.Active}
	
	/goto :SoL																																										
/return



| ---------------------------------------------------------------------------
| SUB : Route Complete
| ---------------------------------------------------------------------------

Sub SoLComplete	
	/echo ${White}You have completed Exploring: ${Green}Shadows of Luclin. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "SoL" "1"
	/delay 1s
	/call Completed
/return
		
| ---------------------------------------------------------------------------
| SUB : Stages
| ---------------------------------------------------------------------------

Sub pokSoL
    /delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone bazaar
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}
/return

Sub bazaar
    /delay 1s
	/call Navigating
	/call travelToZone shadowhaven
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[bazaar]}
/return

Sub shadowhaven
    /delay 1s
	/call Navigating
	/call invisMe
	
	/if (${shaven}==0) 			{
								/call travelToZone sharvahl
	} else /if (${shaven}==1)	{
								/echo Traveling to ${Green}Echo Caverns
								/squelch /nav loc -1145 1628 -78
								}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[shadowhaven]}
/return

Sub sharvahl
    /delay 1s
	/call Navigating
	/varset shaven 1
	/call invisMe
	/call travelToZone grimling
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[sharvahl]}
/return

Sub grimling
    /delay 1s
	/call Navigating
	/call invisMe
	
	/if (${grimling}==0) 		{
								/call travelToZone acrylia
	} else /if (${grimling}==1)	{
								/call travelToZone tenebrous
								}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[grimling]}
/return

Sub acrylia
    /delay 1s
	/call Navigating
	/delay 1s
	/varset grimling 1
	/call invisMe
	/delay 2s
	/squelch /nav loc 66 -738 0
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[acrylia]}
/return

Sub tenebrous
    /delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Katta Castellum
	/squelch /nav loc -59 1909 -39
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[tenebrous]}
/return

Sub katta
    /delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Twilight Sea
	/squelch /nav loc -350 -1236 -202
	/delay 3m !${Navigation.Active}
	/moveto loc -256 -1140 -270
	/delay 4s
	/nav loc -1805 -1046 -270	
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[katta]}
/return

Sub twilight
    /delay 1s
	/call Navigating
	/call invisMe	
	/if (${twil}==0) 		{
								/call travelToZone fungusgrove
	} else /if (${twil}==1)	{
								/call travelToZone thegrey
								}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[twilight]}
/return

Sub fungusgrove
    /delay 1s
	/call Navigating
	/call invisMe
	/varset twil 1
	/call travelToZone twilight
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[tenebrous]}
/return

Sub thegrey
    /delay 1s
	/call Navigating
	/call invisMe	
	/if (${grey}==0) 		{
							/call travelToZone ssratemple
	} else /if (${grey}==1)	{
							/call travelToZone sseru
							}
	/delay 2m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thegrey]}
/return


Sub ssra
    /delay 1s
	/call Navigating
	/call invisMe
	/varset grey 1
	/call travelToZone thegrey
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[ssratemple]}
/return

Sub sseru
    /delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone dawnshroud
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[ssratemple]}
/return


Sub dawnshroud
    /delay 1s
	/call Navigating
	/call invisMe	
	/if (${dawn}==0) 		{
							/call travelToZone griegsend
	} else /if (${dawn}==1)	{
							/echo Traveling to ${Green}Maiden's Eye
							/squelch /nav loc -780 -2260 87
	} else /if (${dawn}==2)	{
							/call travelToZone netherbian
							}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[dawnshroud]}
/return

Sub griegsend
    /delay 2s
	/call Navigating
	/varset dawn 1
	/delay 2s
	/call invisMe
	/call travelToZone dawnshroud
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[griegsend]}
/return

Sub maiden
    /delay 1s
	/call Navigating
	/varset dawn 2
	/call invisMe	
	/if (${maiden}==0) 			{
								/call travelToZone akheva
	} else /if (${maiden}==1)	{
								/call travelToZone umbral
	} else /if (${maiden}==2)	{
								/call travelToZone dawnshroud
								}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[maiden]}
/return

Sub akheva
    /delay 1s
	/call Navigating
	/varset maiden 1
	/call invisMe
	/call travelToZone maiden
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[griegsend]}
/return

Sub umbral
    /delay 1s
	/call Navigating
	/call invisMe	
	/varset maiden 2
	/if (${umbral}==0) 			{								
								/echo Traveling to ${Green}Vex Thal
								/squelch /nav loc -1898 -739 151
								/delay 3m !${Navigation.Active}
								/squelch /doortarget id 0
								/delay 2s ${Switch.ID}==0
								/click left door
	} else /if (${umbral}==1)	{
							/call travelToZone maiden
							}
	/delay 8s !${Zone.ShortName.Equal[umbral]}
/return

Sub vexthal
    /delay 1s
	/call Navigating
	/varset umbral 1
	/call invisMe
	/call travelToZone umbral
	/delay 5m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[vexthal]}
/return

Sub netherbian
	/delay 1s
	/echo Traveling to ${Green}The Nexus
	/squelch /nav loc 2060 -1030 -71
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[netherbian]}
/return

Sub nexusSoL
	/delay 1s
	/call travelToZone shadowhaven
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[nexus]}
/return

Sub echoC
	/delay 1s
	/call travelToZone thedeep
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[echo]}
/return
		
	