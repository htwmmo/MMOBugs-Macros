| -------------------------------------------------------------------------------------------------------
|                                      Rain of Fear Route for Explorer.Mac
|                                       		    By: Fizz
|                                       	  Started: 28/10/2020
| -------------------------------------------------------------------------------------------------------

| Route: PoK > Steamfont > Argath > Valley > Resplendent Temple > City of Bronze > Shard's Landing > Get Shards!!
| Route 1: Shards Landing > City of Bronze > Resplendent Temple > Grelleth's Palace > Resplendent Temple > Sarith City > Beast's Domain > Vile Oak > Shard`s Landing
| Route 2: PoK > Commonlands > Chapterhouse > Kithicor > Highpass Hold > East Karana> Gorge of Xorbb > Valley of Xorbb > Shard's Landing 
| Route 3: PoK > Great Divide > Eastern Wastes >  Eastern Wastes Zeixshar's > Eastern Wastes > Great Divide > PoMischief > Cobalt Scar > Siren's Grotto > Western Wastes > Dragon Necrop > Breeding Grounds > Shard's Landing
| Route 4: PoK > Nexus > Netherbian Lair > Dawnshroud Peaks > Maiden's Eye > Umbral Plains > Vex Thal > Plane of Shadow > Vex Thal > Umbral Plains > Maiden's Eye > Dawnshroud Peaks > Grieg's End > Scarlet Desert > The Grey > Chelsith Reborn >	 Shard's Landing
| Route HoF: Threshhold > HoF: Rebirth > HoF: Epicenter > PoK
| -------------------------------------------------------------------------------------------------------
| Operational variables     - DO NOT CHANGE
| -------------------------------------------------------------------------------------------------------

Sub RoF

	/if (${Zone.ID}==202 && ${Ini[${RouteIniFileName},CompletedRoutes,RoF]}==1) /return
	/lazyfind on
	
    /declare PoKRoF		int outer	0
    /declare argathRoF	int outer	0
	/declare respRoF	int outer	0
	/declare etree		int	outer	0
	/declare shards		int outer	0
    /declare pillars	int outer	0
	/declare Crystals	int	outer	0
	/declare commonRoF	int	outer	0
	/declare gdrof		int	outer	0
	/declare ewrof		int	outer	0
	/declare nexRoF		int	outer	0
	/declare umbralRoF	int	outer	0
	/declare vexRoF		int	outer	0
	/declare fearheart	int	outer	0
	
	/varset completed 0

	/echo ${Yellow}Starting Route: ${Teal}** ${Green}Rain of Fear ${Teal}**


|--------------------------------------------------------------------------------------
| Travel Loop - RoF
|--------------------------------------------------------------------------------------

	/call checkPotionStock 
	/call invisMe
	
	/call ShardPortalQuests

:RoF
	
	/call GMCheck	
	/delay 1s
	/call Navigating

	/if (${Zone.ID}==202 && ${completed}==0)		/call PoKRoF
	/if (${Zone.ID}==448) 		/call SteamfontRoF
	/if (${Zone.ID}==724) 		/call Argath2
	/if (${Zone.ID}==725) 		/call arelis
	/if (${Zone.ID}==729) 		/call resplendentRoF
	/if (${Zone.ID}==752) 		/call shardslanding
	
	/if (${Zone.ID}==759) 		/call grelleth
	/if (${Zone.ID}==758) 		/call eviltree
	
	/if (${Zone.ID}==408) 		/call commonlandsRoF
	/if (${Zone.ID}==760) 		/call chapterhouse
	
	/if (${Zone.ID}==11) 		/call RunnyeyeRoF
	/if (${Zone.ID}==16) 		/call beholderRoF
	/if (${Zone.ID}==753) 		/call xorbb
	/if (${Zone.ID}==118) 		/call GDRoF
	/if (${Zone.ID}==116) 		/call EWRoF
	/if (${Zone.ID}==755) 		/call EwastesRoF
	/if (${Zone.ID}==756) 		/call crystalshard
	/if (${Zone.ID}==754) 		/call kaelshard
	/if (${Zone.ID}==126) 		/call mischiefRoF
	/if (${Zone.ID}==117) 		/call cscarRoF
	/if (${Zone.ID}==123) 		/call necropolisRoF
	/if (${Zone.ID}==757) 		/call breed
	
	/if (${Zone.ID}==152) 		/call nexusRoF
	/if (${Zone.ID}==176) 		/call umbralRoF
	/if (${Zone.ID}==158) 		/call vexthalRoF
	/if (${Zone.ID}==764) 		/call poshadow
	/if (${Zone.ID}==171) 		/call thegreyRoF
	/if (${Zone.ID}==763)		/call chelsith
	
	
	/if (${Zone.ID}==765) 		/call FearHeart
	/if (${Zone.ID}==768)		/call FearHeartb		
	/if (${Zone.ID}==769) 		/call RoFComplete
	
	/delay 2m !${Navigation.Active}
	/goto :RoF
	
/return	
	
| ------------------------------------------------------------------------------------------------
| SUB : Route Complete
| ------------------------------------------------------------------------------------------------

Sub RoFComplete	
	/echo ${White}You have completed Exploring: ${Green}Rain of Fear. 
	/echo ${Yellow}Moving to Poknowledge
	/delay 2s
	/if (${FindItemCount[=Journeyman's Compass]}) /useitem Journeyman's Compass
	/delay 2s
	/varset completed 1
	/delay 1s
	/ini "${RouteIniFileName}" "CompletedRoutes" "RoF" "1"
	/delay 2s	
	/call Completed
/return
		
| ------------------------------------------------------------------------------------------------
| SUB : Stages
| ------------------------------------------------------------------------------------------------

Sub PoKRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/if (${PoKRoF}==0) 			{
								/call KillQuests	
								/call travelToZone steamfontmts
	} else /if (${PoKRoF}==1)	{
								/call travelToZone commonlands 
	} else /if (${PoKRoF}==2)	{
								/call travelToZone runnyeye
	} else /if (${PoKRoF}==3)	{
								/call travelToZone greatdivide	
	} else /if (${PoKRoF}==4)	{
								/call travelToZone nexus		
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poknowledge]}							
/return

Sub SteamfontRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Argath, Bastion of Illdaera
	/squelch /nav loc -1085 -1100 -18
	/delay 45s !${Navigation.Active}
    /call embarkAirship
/return

Sub Argath2
	/delay 1s
	/call Navigating
	/call invisMe
	/if (${argathRoF}==0) 			{
									/if (!${blnPorted}) {
														/call disembarkAirship
														/delay 1s
														/varset argathRoF 1
														}
	} else /if (${argathRoF}==1)	{
									/call travelToZone arelis	
									}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[argath]}							
/return 

Sub arelis
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Resplendent Temple
	/squelch /nav door id 2 click
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[arelis]}		
/return

Sub resplendentRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/call DangerRoute
	/if (${respRoF}==0) 		{
								/call travelToZone shardslanding	
	} else /if (${respRoF}==1)	{
								/call tuneRes
	} else /if (${respRoF}==2)	{
								/call travelToZone grelleth	
	} else /if (${respRoF}==3)	{
								/call travelToZone eviltree	
								}									
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[resplendent]}							
/return

Sub tuneRes
	/if (${PortaltoGrelleth}==1)	/varset respRoF 2	
	/if (${PortaltoGrelleth}==0) 	/varset respRoF 3
/return
		
Sub shardslanding
	/delay 1s
	/call Navigating
	/call invisMe
	/varset respRoF 1
	/if (${shards}==0) 			{
								/squelch /nav loc 110 -30 0							
								/delay 4m !${Navigation.Active}
								/varset InvisOff 1
								/call getShardQuests								
								/varset Crystals	${FindItemCount[=Dire Tuning Crystal]}
								/if (${Crystals}==0) /call EnterFearHeart
								
								/varset shards 1
	} else /if (${shards}==1)	{
								/varset InvisOff 0
								/call PortalZones
								/if (${Crystals}==0) /call EnterFearHeart
	} else /if (${shards}==2)	{
								/call PortalZones
								/if (${Crystals}==0) /call EnterFearHeart	
	} else /if (${shards}==3)	{
								/call PortalZones
								/if (${Crystals}==0) /call EnterFearHeart
	} else /if (${shards}==4)	{
								/call PortalZones
								/if (${Crystals}==0) /call EnterFearHeart
	} else /if (${shards}==5)	{
								/call PortalZones
								/if (${Crystals}==0) /call EnterFearHeart
	} else /if (${shards}==6)	{
								/call EnterFearHeart
								}
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[argath]}							
/return

Sub grelleth
	/delay 1s
	/varset respRoF 3
	/call UseShard Grelleth
	/call Navigating
	/call invisMe
	/call travelToZone resplendent
	/delay 45s !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[argath]}	
/return

Sub eviltree
	/delay 1s
	/call DangerRoute
	/varset shards 2
	/if (${etree}==0)			{						
								/call UseShard VileOak
								/varset etree 1
	} else /if (${etree}==1)	{
								/call Navigating
								/call invisMe
								/echo Traveling to ${Green}Shard`s Landing
								/keypress forward hold
								/delay 1s
								/keypress forward lift
								/squelch /nav loc -1008 -814 47.3
								}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[eviltree]}	
/return

Sub commonlandsRoF
	/call Navigating
	/call invisMe
	/if (${commonRoF}==0) 			{
									/echo Traveling to ${Green}Chapterhouse
									/squelch /nav door id 2 click	
	} else /if (${commonRoF}==1)	{
									/call travelToZone beholder
									}									
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[resplendent]}							
/return

Sub chapterhouse
    /delay 2s
	/call Navigating
	/call invisMe
    /call UseShard Chapterhouse
	/if (${PortaltoKingXorbb}==1)	{
									/varset commonRoF 1
									/call travelToZone commonlands
									}
							
	/if (${PortaltoKingXorbb}==0)	{
									/call travelToZone shardslanding
									}	
	/delay 4m !${Navigation.Active}		
	/delay 8s !${Zone.ShortName.Equal[chapterhouse]}
/return

Sub RunnyeyeRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Gorge of King Xorbb
    /squelch /nav loc -136 5 0 
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[beholder]}
/return

Sub beholderRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Valley of King Xorbb
    /squelch /nav door id 1 click
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[beholder]}
/return

Sub xorbb
    /delay 2s
	/call Navigating
	/call invisMe
    /call UseShard KingXorbb	
	/echo Traveling to ${Green}Shard's Landing
	/squelch /nav door id 20												
	/delay 4m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[xorbb]}
/return

Sub GDRoF
	/call Navigating
	/call invisMe
	
	/if (${PortaltoEastWastes}==1) 				{
												/call travelToZone eastwastes
	} else /if (${PortaltoEastWastes}==0) 		{
												/call travelToZone mischiefplane
												}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[greatdivide]}							
/return

Sub EWRoF
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}East Wastes: Zeixshi-Kar's Awakening
	/squelch /nav door id 2 click								
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[greatdivide]}							
/return
 
Sub EwastesRoF
	/delay 1s
	/varset gdrof 1				
	/call Navigating
	/call invisMe
	/if (${ewrof}==0) 			{
								/call travelToZone crystalshard
	} else /if (${ewrof}==1)	{
								/call travelToZone kaelshard
	} else /if (${ewrof}==2)	{
								/call tuneEWZ
	} else /if (${ewrof}==3)	{
								/echo Traveling to ${Green}The Great Divide
								/squelch /nav loc -1770 6842 271
	} else /if (${ewrof}==4)	{								
								/varset PoKRoF 4	
								/call travelToZone shardslanding	
								}
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[greatdivide]}							
/return

Sub tuneEWZ
	/if (${PortaltoBreedingGround}==1)	/varset ewrof 3	
	/if (${PortaltoBreedingGround}==0) 	/varset ewrof 4
	/call UseShard EastWastes
/return
										
Sub crystalshard
	/delay 2s
	/call Navigating
	/call invisMe
	/varset ewrof 1
	/call Navigating
	/call invisMe
	/delay 2s
	/echo Traveling to ${Green}East Wastes: Zeixshi-Kar's Awakening
	/squelch /nav loc 466 311 -78
	/delay 45s !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[crystalshard]}	
/return

Sub kaelshard
	/delay 2s
	/call Navigating
	/call invisMe
	/varset ewrof 2
	/call Navigating
	/call invisMe
	/delay 2s
	/echo Traveling to ${Green}East Wastes: Zeixshi-Kar's Awakening
	/squelch /nav loc -129 -775 120
	/delay 45s !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[kaelshard]}	
/return

Sub mischiefRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/squelch /nav loc -1026 -356 96
	/squelch /doortarget id 226
    /click left door
    /delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[mischiefplane]}
/return

Sub cscarRoF
    /delay 1s
	/call Navigating
	/call invisMe
	/call travelToZone necropolis
	/delay 3m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[cobaltscar]}
/return

Sub necropolisRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/squelch /nav loc -87 -2674 17
	/delay 3m !${Navigation.Active}
	/squelch /target clear
	/squelch /doortarget id 7
	/face heading 270
	/keypress forward hold
	/delay 0.5s
	/keypress forward lift
	/click left door
	/delay 8s !${Zone.ShortName.Equal[necropolis]}
/return
	
Sub breed
	/delay 1s
	/call Navigating
	/call invisMe
	/varset PoKRoF 4
	/call UseShard BreedingGround
	/call travelToZone shardslanding
    /delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[breedinggrounds]}
/return

Sub nexusRoF
	/call Navigating
	/call invisMe
	/if (${nexRoF}==0) 			{
								/call travelToZone umbral
	} else /if (${nexRoF}==1)	{
								/call travelToZone thegrey
								}									
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[nexus]}							
/return

Sub umbralRoF
    /delay 1s
	/call Navigating
	/call invisMe
	/if (${umbralRoF}==0) 			{								
									/echo Traveling to ${Green}Vex Thal
									/squelch /nav loc -1898 -739 151
									/delay 3m !${Navigation.Active}
									/squelch /doortarget id 0
									/delay 1s
									/click left door
	} else /if (${umbralRoF}==1)	{
									/call travelToZone thegrey
									}
	/delay 8s !${Zone.ShortName.Equal[umbral]}
/return

Sub vexthalRoF
    /delay 1s
	/call Navigating
	/call invisMe
	/varset umbralRoF 1
	/if (${vexRoF}==0) 			{				
								/call travelToZone poshadow
	} else /if (${vexRoF}==1)	{
								/call travelToZone umbral
								}
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[vexthal]}
/return

Sub poshadow
    /delay 1s
	/call Navigating
	/varset vexRoF 1
	/call UseShard PoShadow
	/call invisMe
	/if (${PortaltoChelsith}==1)	{
									/echo Traveling to ${Green}Vex Thal
									/squelch /nav loc -506 198 -32
									/squelch /doortarget id 46
									/click left door
	} else							{
									/call travelToZone shardslanding
									}	
	/delay 1m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[poshadow]}
/return

Sub thegreyRoF
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}Chelsith Reborn
	/nav loc 1480 1337 -87
	/squelch /target clear
	/squelch /doortarget id 1
	/delay 2s ${Switch.ID}==1
	/click left door
	/delay 4m !${Navigation.Active}
	/delay 8s !${Zone.ShortName.Equal[thegrey]}							
/return

Sub chelsith
    /delay 2s
	/varset shards 6
    /call UseShard Chelsith
|    /echo Traveling to ${Green}Shard's Landing
	/call travelToZone shardslanding
|   /squelch /nav door id 20
	/delay 4m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[chelsithreborn]}
/return

Sub EnterFearHeart
	/delay 1s
	/call Navigating
	/call invisMe
    /echo Traveling to ${Green}The Hearth of Fear: Threshhold
	/squelch /nav door id 18 click
	/delay 4m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[shardslanding]}
/return
	
Sub FearHeart
	/delay 1s
	/call DangerRoute
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Hearth of Fear: Rebirth
	/squelch /nav loc -1250 -1086 -70
	/delay 4m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[heartoffear]}
/return

Sub FearHeartb
	/delay 1s
	/call Navigating
	/call invisMe
	/echo Traveling to ${Green}The Hearth of Fear: Epicenter
	/squelch /nav loc -783 -303 -509
	/delay 4m !${Navigation.Active}
    /delay 8s !${Zone.ShortName.Equal[heartoffear]}
/return

| -------------------------------------------------------------------------------------
| SUB: getShardQuests
| ------------------------------------------------------------------------------------- 
Sub getShardQuests
    /if (${PortaltoBreedingGround}) /call GetShards BreedingGround
    /if (${PortaltoEastWastes}) 	/call GetShards EastWastes
    /if (${PortaltoKingXorbb}) 		/call GetShards KingXorbb
    /if (${PortaltoChapterhouse}) 	/call GetShards Chapterhouse
    /if (${PortaltoPoShadow}) 		/call GetShards PoShadow
    /if (${PortaltoChelsith}) 		/call GetShards Chelsith
    /if (${PortaltoVileOak}) 		/call GetShards VileOak
    /if (${PortaltoGrelleth}) 		/call GetShards Grelleth
/return

| -------------------------------------------------------------------------------------
| SUB: GetShards
| ------------------------------------------------------------------------------------- 
Sub GetShards(string strPortal)

    /declare blnQuestAccepted bool local 0
    /declare strShardTender string local
    /declare strQuestName string local
    |- Shard's Landing
    /while (${Zone.ShortName.Equal[shardslanding]}) {
													/if (${strPortal.Equal[EastWastes]}) 				{
																										/varset strShardTender Leopold_Crunchbasher
																										/varset strQuestName EastWastes
													} else /if (${strPortal.Equal[BreedingGround]}) 	{
																										/varset strShardTender Vdrakii
																										/varset strQuestName BreedingGround
													} else /if (${strPortal.Equal[VileOak]}) 			{
																										/varset strShardTender Bygral_Tamescale
																										/varset strQuestName VileOak
													} else /if (${strPortal.Equal[Grelleth]}) 			{
																										/varset strShardTender Vaytok
																										/varset strQuestName Grelleth
													} else /if (${strPortal.Equal[Chapterhouse]}) 		{
																										/varset strShardTender Sir_Delvas
																										/varset strQuestName Chapterhouse
													} else /if (${strPortal.Equal[KingXorbb]}) 			{
																										/varset strShardTender Soulbound_Construct
																										/varset strQuestName KingXorbb
													} else /if (${strPortal.Equal[Chelsith]}) 			{
																										/varset strShardTender Camellia_Spiretear
																										/varset strQuestName Chelsith
													} else /if (${strPortal.Equal[PoShadow]}) 			{
																										/varset strShardTender Sister_Fealcrest
																										/varset strQuestName PoShadow
													} else 												{
																										/echo ****Debug  ERROR- Bad call to GetShards (${strPortal})
																										}

													/squelch /target clear
													/squelch /nav spawn npc ${strShardTender}
													/call Navigating

													/if (${Zone.ShortName.Equal[eastwastesshard]} || ${Zone.ShortName.Equal[chapterhouse]} || ${Zone.ShortName.Equal[xorbb]} || ${Zone.ShortName.Equal[breedinggrounds]} || ${Zone.ShortName.Equal[chelsithreborn]} || ${Zone.ShortName.Equal[poshadow]} || ${Zone.ShortName.Equal[eviltree]} || ${Zone.ShortName.Equal[grelleth]}) {
																																																																																													/break
																																																																																													}
													/makemevisible
													/delay 2s !${Me.Invis}
													/target npc ${strShardTender}
													/delay 10s ${Target.ID}
													/say Attune

													/delay 10s ${Window[TaskSelectWnd].Open}
													/if (!${Window[TaskSelectWnd].Open}) 	{
																							/echo We must be attuned to this one already... Skipping.
|																							/ini "${MacIniFileName}" "CompletedQuests" "attune${strQuestName}" "1"
																							/ini "${RouteIniFileName}" "CompletedQuests" "Portalto${strQuestName}" "1"
																							/echo ****Debug  Setting runAttune${strQuestName} to 0
																							/varset Portalto${strQuestName} 0
																							/return
													} else 	{
															/notify TaskSelectWnd TSEL_AcceptButton leftmouseup
															/varset blnQuestAccepted 1
															/delay 5s ${Cursor.ID}
															/while (${Cursor.ID}) 	{
																					/autoinv
																					/delay 5
																					}
															/if (${Window[TaskWnd].Open}) /invoke ${Window[TaskWnd].DoClose}
															/deletevar blnQuestAccepted
															/deletevar strShardTender
															/deletevar strQuestName
															/return
															}
													}

    |- Accidental Zoning
    /while (${Zone.ShortName.Equal[eastwastesshard]} || ${Zone.ShortName.Equal[chapterhouse]} || ${Zone.ShortName.Equal[xorbb]} || ${Zone.ShortName.Equal[breedinggrounds]} || ${Zone.ShortName.Equal[chelsithreborn]} || ${Zone.ShortName.Equal[poshadow]} || ${Zone.ShortName.Equal[eviltree]} || ${Zone.ShortName.Equal[grelleth]}) 	{
																																																																																		/echo \amWhoops!\ax  We accidentally zoned over.  We must already be attuned to this portal.
																																																																																		/echo I'm going to skip trying to get this quest.
|																																																																																		/ini "${MacIniFileName}" "CompletedQuests" "attune${strQuestName}" "1"
																																																																																		/ini "${RouteIniFileName}" "CompletedQuests" "Portalto${QuestName}" "1"
																																																																																		/delay 2s
																																																																																		/if (${Zone.ShortName.Equal[chapterhouse]}) /nav door id 113
																																																																																		/if (${Zone.ShortName.Equal[xorbb]}) /nav door id 20
																																																																																		/if (${Zone.ShortName.Equal[breedinggrounds]}) /nav door id 2
																																																																																		/if (${Zone.ShortName.Equal[chelsithreborn]}) /nav door id 149
																																																																																		/if (${Zone.ShortName.Equal[poshadow]}) /nav door id 47
																																																																																		/if (${Zone.ShortName.Equal[eviltree]}) /moveto -1023 -826 53
																																																																																		/if (${Zone.ShortName.Equal[grelleth]}) /nav door id 44
																																																																																		/while (${Zone.ShortName.NotEqual[shardslanding]}) 	{
																																																																																															/delay 2
																																																																																															}
																																																																																		/break
																																																																																		}
	/return








































|---------------------------------------------------------------------------
Sub PortalZones
|---------------------------------------------------------------------------

	/delay 1s
	/delay 1s
	/call Navigating
	/call invisMe
	/echo checking path
   /if (${PortaltoGrelleth}==1) 				{
												/varset respRoF 1
												/echo Grelleth
												/call travelToZone resplendent
   } else /if (${PortaltoVileOak}==1)			{
												/varset respRoF 1
												/echo VileOak
												/call travelToZone resplendent
   } else /if (${PortaltoChapterhouse}==1)		{
												/varset PoKRoF 1
												/echo Chapterhouse
												/call Evac
   } else /if (${PortaltoKingXorbb}==1)			{
												/varset PoKRoF 2
												/echo Xorbb
												/call Evac
   } else /if (${PortaltoEastWastes}==1)		{
												/varset PoKRoF 3
												/echo EastWastes
												/call Evac
   } else /if (${PortaltoBreedingGround}==1)	{
												/varset PoKRoF 3
												/echo BreedingGround
												/call Evac
   } else /if (${PortaltoPoShadow}==1)			{
												/varset PoKRoF 4
												/echo poshadow
												/call Evac
   } else /if (${PortaltoChelsith}==1)			{
												/varset PoKRoF 4
												/echo Chelsith
												/call Evac
	} else										{
												:HeartAttack
												/echo Traveling to ${Green}Heart of Fear: Threshhold
												/nav id door 18
												/delay 8s !${Zone.ShortName.Equal[shardslanding]}
												}
	
/return


| -------------------------------------------------------------------------------------
| SUB: UseShard
| ------------------------------------------------------------------------------------- 
Sub UseShard(string Portal)
    /declare blnNavHold		bool	local	0
    /declare QuestName		string	local
    /varset Crystals ${FindItemCount[=Dire Tuning Crystal]}
    /varset PortalAttuned 0

    /if (${Portal.Equal[EastWastes]}) 			{
												/varset QuestName EastWastes
    } else /if (${Portal.Equal[Breed]}) 		{
												/varset QuestName BreedingGround
    } else /if (${Portal.Equal[VileOak]})		{
												/varset QuestName VileOak
    } else /if (${Portal.Equal[Grelleth]}) 		{
												/varset QuestName Grelleth
    } else /if (${Portal.Equal[Chapterhouse]}) 	{
												/varset QuestName Chapterhouse
    } else /if (${Portal.Equal[KingXorbb]}) 	{
												/varset QuestName KingXorbb
    } else /if (${Portal.Equal[Chelsith]}) 		{
												/varset QuestName Chelsith
    } else /if (${Portal.Equal[PoShadow]}) 		{
												/varset QuestName PoShadow
    } else 										{
												/echo *****debug ERROR- Bad call to UseShard (${Portal})
    }

    /if (${Navigation.Active}) {
        /nav pause on
        /delay 3s !${Me.Moving}
        /varset blnNavHold 1
    }

    /while (${Me.XTarget}) {
        /call combatHandler
    }

    /while (${FindItemCount[=Dire Tuning Crystal]} == ${Crystals}) {
        /useitem Dire Tuning Crystal
        /delay 1s ${Window[CastingWindow].Open}
        /if (${Window[CastingWindow].Open}) {
											/while (${Window[CastingWindow].Open}) {
																					/if (${Me.XTarget}) {
																										/call combatHandler
																										/break
																										}
																					/delay 5
																					}
											/while (!${PortalAttuned}) 	{
																		/doevents
																		/delay 5
																		}
											} else 	{
													/if (${Me.XTarget}) /call combatHandler
													/echo ${White}You are already be attuned to this zone.
													/break
													}		
											/if (${PortalAttuned}) /break
											}
											
    /ini "${RouteIniFileName}" "CompletedQuests" "Portalto${Portal}" "1"
	/varset "Portalto${QuestName}" 0
    /if (${blnNavHold}) /nav pause off
	
    /varset PortalAttuned 0
    /deletevar QuestName
    /deletevar blnNavHold
/return

|------------------------------------------------------------------------------------------------------------------------------
Sub KillQuests
|------------------------------------------------------------------------------------------------------------------------------
	/echo Dropping certain quests if you have them (Remove after fix)

	/call killQuest "Eastern Wastes: Zeixshi-Kar's Awakening Portal Activation"
	/call killQuest "The Breeding Grounds Portal Activation"
	/call killQuest "the Vile Oak Portal Activation"
	/call killQuest "the Chateau of Filth Portal Activation"
    /call killQuest "Chapterhouse of the Fallen Portal Activation"
	/call killQuest "Valley of King Xorbb Portal Activation"
	/call killQuest "Chelsith Reborn Portal Activation"
	/call killQuest "Plane of Shadow Portal Activation"
	
	
/return

