| -------------------------------------------------------------------------------------
| SUB: Prep
| -------------------------------------------------------------------------------------
Sub Prep
	/mqclear

	/declare MacroName				    string	outer       Explorer
	/declare RouteIniFileName			string	outer       Explorer\${EverQuest.Server}_${Me.CleanName}_Route.ini
    /declare PotionIniFileName        	string  outer       Explorer\${EverQuest.Server}_${Me.CleanName}_Potions.ini	
	
|- Set up Evac Options
	/declare blnHasStein 			    bool	outer       ${FindItemCount[=Drunkard's Stein]}
    /declare blnHasBrick                bool    outer       ${FindItemCount[=Brick of Knowledge]}
    /declare intBulwarkCount            int     outer       ${FindItemCount[=Bulwark of Many Portals]}
    /declare intEthBrewCount		    int	    outer       ${FindItemCount[=Ethernere Travel Brew]}
    /declare blnHasBinden               bool    outer       ${FindItemCount[=The Binden Concerrentia]}
    /declare blnHasFabledBinden         bool    outer       ${FindItemCount[=The Fabled Binden Concerrentia]}
	
	/declare FailedToZone              	bool    outer      	0
    /declare envirofall   				int 	outer 	 	0
    /declare InvisOff               	bool    outer       0
	/declare PortalAttuned            	bool    outer       0
    /declare IgnoreCombat           	bool    outer       0	
	
    /declare blnPorted                  bool    outer       0
    /declare blnSkipIVU                 bool    outer       0
    /declare blnSkipAhead               bool    outer       0
	
    /declare intMaxPlatPerPotion        int     outer
    /declare gateAbility	            int	    outer       0
    /declare gatePotionCount		    int	    outer		${FindItemCount[=Philter of Major Translocation]}
    /declare intMinGateCount            int     outer       10
    /declare invisAbility	            int	    outer       0
    /declare invisPotionCount		    int	    outer		${FindItemCount[=Cloudy Potion]}
    /declare intMinCloudyCount          int     outer
    /declare shrinkAbility	            int	    outer       0
    /declare shrinkPotionCount		    int	    outer		${FindItemCount[=Philter of the Ant]}
    /declare intMinAntCount             int     outer
    /declare levAbility                 int     outer       0
    /declare levPotionCount             int     outer       ${FindItemCount[=Philter of Gulon's Impunity]}
    /declare intMinLevCount             int     outer       10
    /declare ivuAbility                 int     outer       0
    /declare ivuPotionCount             int     outer       ${FindItemCount[=Philter of Unlife Awareness]}
    /declare intMinIVUCount             int     outer       20
		
	/declare completed                  int     outer       0
		
|- Routes
    /declare Antonica         			bool    outer       0
    /declare Faydwer            		bool    outer       0
    /declare Odus               		bool    outer       0
    /declare ThePlanes             		bool    outer       0
    /declare SpecialEvents      		bool    outer       0
    /declare Housing            		bool    outer       0
    /declare Guilds             		bool    outer       0
    /declare RoK                		bool    outer       0
    /declare SoV                		bool    outer       0
    /declare SoL                		bool    outer       0
    /declare PoP                		bool    outer       0
    /declare LoY                		bool    outer       0
    /declare LDoN               		bool    outer       0
    /declare GoD                		bool    outer       0
    /declare OoW                		bool    outer       0
    /declare DoN                		bool    outer       0
    /declare DoDH               		bool    outer       0
    /declare PoR                		bool    outer       0
    /declare TSS                		bool    outer       0
    /declare TBS                		bool    outer       0
    /declare SoF                		bool    outer       0
    /declare SoD                		bool    outer       0
    /declare Underfoot          		bool    outer       0
    /declare HoT                		bool    outer       0
    /declare VoA                		bool    outer       0
    /declare RoF                		bool    outer       0
    /declare CotF              			bool    outer       0
    /declare TDS                		bool    outer       0
    /declare TBM                		bool    outer       0
    /declare EoK                		bool    outer       0
    /declare RoS               	 		bool    outer       0

|-RoF Portals	
|---------------
    /declare PortaltoEastWastes       	int    outer       	0
    /declare PortaltoBreedingGround   	int    outer       	0
    /declare PortaltoVileOak          	int    outer      	0
    /declare PortaltoGrelleth         	int    outer      	0
    /declare PortaltoChapterhouse     	int    outer     	0
    /declare PortaltoKingXorbb        	int    outer       	0
    /declare PortaltoChelsith         	int    outer       	0
    /declare PortaltoPoShadow         	int    outer       	0
	
|-LDON	
|---------------
	/declare LDoN-MM                	bool    outer       0
    /declare LDoN-MM-Wastes         	bool    outer       0
    /declare LDoN-MM-FrostHalls     	bool    outer       0
    /declare LDoN-MM-Library        	bool    outer       0
    /declare LDoN-MM-Heart          	bool    outer       0
    /declare LDoN-MM-Banquet        	bool    outer       0	
    /declare LDoN-MM-Menagerie      	bool    outer       0
    /declare LDoN-MM-Laboratory     	bool    outer       0
    /declare LDoN-MM-Gallery        	bool    outer       0
    /declare LDoN-MM-SpiderDen      	bool    outer       0
    /declare LDoN-MM-Theater       		bool    outer       0
	
    /declare LDoN-MC                	bool    outer       0
    /declare LDoN-MC-Aisles         	bool    outer       0
    /declare LDoN-MC-Asylum         	bool    outer       0
    /declare LDoN-MC-Cesspit        	bool    outer       0
    /declare LDoN-MC-Chamber        	bool    outer       0
    /declare LDoN-MC-Grotto         	bool    outer       0
    /declare LDoN-MC-Cavern         	bool    outer       0
    /declare LDoN-MC-Halls          	bool    outer       0
    /declare LDoN-MC-Sanctuary      	bool    outer       0
    /declare LDoN-MC-SummGround     	bool    outer       0
    /declare LDoN-MC-Sepulcher      	bool    outer       0
	
    /declare LDoN-DG                	bool    outer       0
    /declare LDoN-DG-Sanctuary      	bool    outer       0
    /declare LDoN-DG-Aquaduct       	bool    outer       0	
    /declare LDoN-DG-Cauldron       	bool    outer       0
    /declare LDoN-DG-Chapel         	bool    outer       0
    /declare LDoN-DG-Crypt          	bool    outer       0
    /declare LDoN-DG-Prison         	bool    outer       0	
    /declare LDoN-DG-Mushroom       	bool    outer       0
    /declare LDoN-DG-Garden         	bool    outer       0

    /declare LDoN-TH                	bool    outer       0
    /declare LDoN-TH-Palace         	bool    outer       0
    /declare LDoN-TH-Chamber        	bool    outer       0
    /declare LDoN-TH-Temple         	bool    outer       0
    /declare LDoN-TH-Prismatic      	bool    outer       0
    /declare LDoN-TH-River          	bool    outer       0
    /declare LDoN-TH-Observatory    	bool    outer       0
    /declare LDoN-TH-Sandfall       	bool    outer       0
    /declare LDoN-TH-Tower          	bool    outer       0
    /declare LDoN-TH-Library        	bool    outer       0
    /declare LDoN-TH-Tides          	bool    outer       0
 
	/declare LDoN-RH                	bool    outer       0
    /declare LDoN-RH-Arena          	bool    outer       0
    /declare LDoN-RH-Barracks       	bool    outer       0
    /declare LDoN-RH-Forge          	bool    outer       0
    /declare LDoN-RH-Quarries       	bool    outer       0	
    /declare LDoN-RH-Hollows        	bool    outer       0
    /declare LDoN-RH-Fort           	bool    outer       0	
    /declare LDoN-RH-GladPit        	bool    outer       0
    /declare LDoN-RH-Halls          	bool    outer       0
    /declare LDoN-RH-Vale           	bool    outer       0
    /declare LDoN-RH-Bridges        	bool    outer       0
	
	/declare AdventureNavigation		bool		outer	0
	/declare MagusName					string		outer
	/declare AdvRecruiter				string		outer
	/declare EverfrostNPC				string		outer	Mannis_McGuyett
	/declare EverfrostMagus				string		outer	Magus_Delin
	/declare ButcherNPC					string		outer	Xyzelauna_Tu`Valzir
	/declare ButcherMagus				string		outer	Magus_Tira
	/declare CommonlandsNPC				string		outer	Periac_Windfell
	/declare CommonlandsMagus			string		outer	Magus_Zeir
	/declare SRoNPC						string		outer	Kallei_Ribblok
	/declare SRoMagus					string		outer	Magus_Jerira
	/declare NRoNPC						string		outer	Escon_Quickbow
	/declare NRoMagus					string		outer	Magus_Arindri
	/declare AdventureText				string		outer
	/declare lstBosses					string		outer
	/declare BossName					string		outer
	/declare iniBossZoneLookups			string		outer	Explorer\Routes\LDoN.ini
	/declare lstBossZones				string		outer
	/declare CampComplete				bool		outer	0
	/declare AdventureNeeded			bool 		outer	0
	/declare strLDONName				string		outer
	/declare lstAdventureZIs			string		outer
	/declare TaskEntrance				string		outer
	/declare strZonePrefix				string		outer	0
	/declare strZoneSuffix				string		outer   0
	
	
    /declare Black         				string outer \ab
    /declare Blue       				string outer \au
    /declare Brown      				string outer \a-o
    /declare Cyan       				string outer \at
    /declare Gray        				string outer \a-w
    /declare Green        				string outer \ag
    /declare Pink       				string outer \am
    /declare Orange       				string outer \ao
    /declare Purple       				string outer \ap
    /declare Red           				string outer \ar
    /declare Teal       				string outer \at
    /declare White       				string outer \aw
    /declare Yellow      				string outer \ay
    /declare DarkGreen     				string outer \a-g
    /declare DarkMaroon    				string outer \a-m
    /declare DarkPurple    				string outer \a-p
    /declare DarkRed    				string outer \a-r
    /declare DarkCyan    				string outer \a-t
    /declare DarkBlue    				string outer \a-u
    /declare DarkYellow    				string outer \a-y
	
|- Plugins
    /declare blnDoCrackLoaded        	bool    outer       ${Bool[${Plugin[MQ2DoCrack].Name.Equal[MQ2DoCrack]}]}
    /declare blnEasyfindLoaded          bool    outer       ${Bool[${Plugin[MQ2LazyFind].Name.Equal[MQ2LazyFind]}]}
    /declare blnNavLoaded               bool    outer       ${Bool[${Plugin[MQ2Nav].Name.Equal[MQ2Nav]}]}
    /declare blnEQBCSLoaded             bool    outer       ${Bool[${Plugin[MQ2EQBC].Name.Equal[MQ2EQBC]}]}
	
	
	/call loadPlugin MQ2Nav
    /call loadPlugin MQ2LazyFind
    /call loadPlugin MQ2DoCrack
	
	/mqclear
	
	/echo ${Black}--------------------------------------------------------------------------
	/echo ${Red}Explorer Ver 1.0.1
	/echo ${White}Written by 
	/echo ${Blue}Fizz
	/echo ${Black}--------------------------------------------------------------------------
	/echo ${White}Special Thanks of code assistance: ${Yellow}Fry, HTW, 
	/echo ${Yellow}PeteSampras, Chatwiththisname ${Orange}and ${Yellow}Dewey2461 
	/echo 
	/echo ${White}Beta Testing by: ${Yellow}Fry ${Orange}and ${Yellow}Spin	
	/echo ${Black}--------------------------------------------------------------------------
	/echo ${Cyan}Start point: ${Green}Plane of Knowledge
	/echo ${Black}--------------------------------------------------------------------------
	/delay 1s

    /call createPotionINI
    /call createRouteINI

|- Find invis and shrink ability
    /declare invisClickie           string  outer       ${Ini[${PotionIniFileName},General,invisClickie]}
    /declare invisClickie2          string  outer       ${Ini[${PotionIniFileName},General,invisClickie2]}
    /declare ivuClickie             string  outer       ${Ini[${PotionIniFileName},General,ivuClickie]}
    /declare shrinkClickie          string  outer       ${Ini[${PotionIniFileName},General,shrinkClickie]}
    /declare levClickie             string  outer       ${Ini[${PotionIniFileName},General,levClickie]}
	/varset invisAbility ${Select[TRUE,${Me.AltAbilityReady[Cloak of Shadows]},${Me.AltAbilityReady[Shauri's Sonorous Clouding]},${Me.AltAbilityReady[Group Perfected Invisibility]},${Me.AltAbilityReady[Perfected Invisibility]},${Me.AltAbilityReady[Natural Invisibility]}]},${Me.AltAbilityReady[Improved Natural Invisibility]}]},${Me.AltAbilityReady[Shared Camouflage]},${Me.AltAbilityReady[Camouflage]},${Me.AltAbilityReady[Group Silent Presence]},${Me.AltAbilityReady[Silent Presence]}]}

    /varset ivuAbility ${Select[TRUE,${Me.AltAbilityReady[Cloak of Light]},${Me.AltAbilityReady[Shauri's Sonorous Clouding]},${Me.AltAbilityReady[Perfected Invisibility to Undead]},${Me.AltAbilityReady[Group Perfected Invisibility to Undead]},${Me.AltAbilityReady[Innate Invis to Undead]}]}
    /varset shrinkAbility ${Select[TRUE,${Me.AltAbilityReady[Group Shrink]},${Me.AltAbilityReady[Shrink]},${Me.AltAbilityReady[Cunning Disguise: Goblin]}]}
    /varset levAbility ${Select[TRUE,${Me.AltAbilityReady[Group Perfected Levitation]},${Me.AltAbilityReady[Dead Man Floating]},${Me.AltAbilityReady[Perfected Dead Men Floating]},${Me.AltAbilityReady[Shauri's Sonorous Clouding]},${Me.AltAbilityReady[Perfected Levitation]},${Me.AltAbilityReady[Bobbing Corse]},${Me.AltAbilityReady[Elemental Form: Air]},${Me.AltAbilityReady[Noteworthy Disguise: Blue Drake II]},${Me.AltAbilityReady[Divine Steed]},${Me.AltAbilityReady[Steed of Souls]}]}
    /varset intMinCloudyCount ${Ini[${PotionIniFileName},General,minimumInvisPots]}
    /varset intMinAntCount ${Ini[${PotionIniFileName},General,minimumShrinkPots]}
    /varset intMaxPlatPerPotion ${Ini[${PotionIniFileName},General,maxPlatPerPotion]}

|- Prep invisClickie, shrinkClickie, & levClickie for use
    /if ((!${FindItem[=${invisClickie}].Name.Length} || !${FindItem[=${invisClickie2}].Name.Length}) && !${invisAbility}) {
        /call findInvisClickies
    }
    /if ((${FindItem[=${ivuClickie}].Name.Length}  && !${ivuAbility})) {
        /call findIVUClickies
    } 
    /if (${shrinkClickie.Equal[Anizok's Minimizing Device]}) {
        /varset shrinkClickie
        /ini "${PotionIniFileName}" "General" "shrinkClickie" ""
        /echo No longer able to use Anizok's Minimizing Device for shrinking.  Removing it from INI.
    }
    /if (!${FindItem[=${shrinkClickie}].Name.Length} && !${shrinkAbility}) {
        /call findShrinkClickie
    }
    /if (!${FindItem[=${levClickie}].Name.Length} && !${levAbility}) {
        /call findLevClickie
    }
/return


| -------------------------------------------------------------------------------------
| SUB: createRouteINI
| ------------------------------------------------------------------------------------- 
Sub createRouteINI
    /if (${Ini[${RouteIniFileName},General].Length}) {
        /ini "${RouteIniFileName}" "General" "invisClickie" NULL
        /ini "${RouteIniFileName}" "General" "invisClickie2" NULL
        /ini "${RouteIniFileName}" "General" "shrinkClickie" NULL
        /ini "${RouteIniFileName}" "General" "levClickie" NULL
        /ini "${RouteIniFileName}" "General" "minimumInvisPots" NULL
        /ini "${RouteIniFileName}" "General" "minimumShrinkPots" NULL
        /ini "${RouteIniFileName}" "General" "maxPlatPerPotion" NULL
        /if (${Ini[${RouteIniFileName},General,ivuClickie].Length}) {
            /ini "${RouteIniFileName}" "General" "ivuClickie" NULL
        }
        /if (${Ini[${RouteIniFileName},General,maxPlatPerPotion].Length}) {
            /ini "${RouteIniFileName}" "General" "maxPlatPerPotion" NULL
        }
        /ini "${RouteIniFileName}" "General" NULL
    }
    /if (!${Ini[${RouteIniFileName},CompletedRoutes].Length}) {
        /ini "${RouteIniFileName}" "CompletedRoutes" "Antonica" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "Faydwer" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "Odus" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "ThePlanes" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "SpecialEvents" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "Housing" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "Guilds" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "RoK" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "SoV" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "SoL" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "PoP" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "LoY" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "LDoN" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "GoD" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "OoW" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "DoN" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "DoDH" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "PoR" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "TSS" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "TBS" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "SoF" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "SoD" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "Underfoot" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "HoT" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "VoA" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "RoF" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "CotF" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "TDS" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "TBM" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "EoK" 0
        /ini "${RouteIniFileName}" "CompletedRoutes" "RoS" 0
    }
    /if (!${Ini[${RouteIniFileName},CompletedQuests].Length}) {
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoEastWastes" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoBreedingGround" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoVileOak" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoGrelleth" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoChapterhouse" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoKingXorbb" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoChelsith" 0
        /ini "${RouteIniFileName}" "CompletedQuests" "PortaltoPoShadow" 0

    }
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs].Length}) {
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Wastes" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-FrostHalls" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Library" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Heart" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Banquet" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Menagerie" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Laboratory" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Gallery" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-SpiderDen" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Miragul-Theater" 0
		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Aisles" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Asylum" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Cesspit" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Chamber" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Grotto" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Cavern" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Halls" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Sanctuary" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-SummGround" 0		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Mistmoore-Sepulcher" 0
		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Sanctuary" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Aquaduct" 0		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Cauldron" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Chapel" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Crypt" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Prison" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Mushroom" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "DeepGuk-Garden" 0
		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Palace" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Chamber" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Temple" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Prismatic" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-River" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Observatory" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Sandfall" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Tower" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Library" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "TakHiz-Tides" 0
		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Arena" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Barracks" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Forge" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Quarries" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Hollows" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Fort" 0		
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-GladPit" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Halls" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Vale" 0
        /ini "${RouteIniFileName}" "CompletedLDoNs" "Rujark-Bridges" 0
    }
/return

| -------------------------------------------------------------------------------------
| SUB: Help
| ------------------------------------------------------------------------------------- 
Sub Help
    /echo ${Teal}--------------------------------------------------------------------------------------
    /echo ${Teal}                   Help Information
    /echo ${Teal}--------------------------------------------------------------------------------------
    /echo ${Teal}Macro can be started with '/mac Explorer All'
    /echo ${Teal}It will look for an INI file (Server_CharName_Route.ini) and continue.
    /echo ${Teal}If no such file exists, it will create a new one, and
    /echo ${Teal}assume you wish to explore all available routes.
    /echo
    /echo ${Teal}Use one of the command line parameters to instruct the macro to
    /echo ${Teal}run that specific route. Example: ${Green}'/mac Explorer PoP'
    /echo
    /echo ${Orange}Valid command line parameters include:
    /echo ${Green}     All${Orange} - Will run all available routes not completed in the INI settings
    /echo ${Green}     Faydwer${Orange} - Faydwer
    /echo ${Green}     Antonica${Orange} - Antonica includes TSS Routes
    /echo ${Green}     Odus${Orange} - Odus
    /echo ${Green}     ThePlanes${Orange} - Planes ${Yellow}(old school Places)
    /echo ${Green}     SpecialEvents${Orange} - Special Events
    /echo ${Green}     Housing${Orange} - Housing
    /echo ${Green}     Guilds${Orange} - Guilds
    /echo ${Green}     RoK${Orange} - Ruins of Kunark 
    /echo ${Green}     SoV${Orange} - Scars of Velious Route
    /echo ${Green}     SoL${Orange} - Shadows of Luclin
    /echo ${Green}     PoP${Orange} - Planes of Power
    /echo ${Green}     LoY${Orange} - Legacy of Ykesha
    /echo ${Green}     LDoN${Orange} - Lost Dungeons of Norrath
    /echo ${Green}     GoD${Orange} - Gates of Discord
    /echo ${Green}     OoW${Orange} - Omens of War
    /echo ${Green}     DoN${Orange} - Dragons of Norrath
    /echo ${Green}     DoDH${Orange} - Depths of Darkhallow
    /echo ${Green}     PoR${Orange} - Prophecy of Ro
    /echo ${Green}     TSS${Orange} - The Serpent's Spine
    /echo ${Green}     TBS${Orange} - The Buried Sea
    /echo ${Green}     SoF${Orange} - Secrets of Faydwer
    /echo ${Green}     SoD${Orange} - Seeds of Destruction
    /echo ${Green}     Underfoot${Orange} - Underfoot
    /echo ${Green}     HoT${Orange} - House of Thule
    /echo ${Green}     VoA${Orange} - Veil of Alaris
    /echo ${Green}     RoF${Orange} - Rain of Fear
    /echo ${Green}     CotF${Orange} - Call of the Forsaken
    /echo ${Green}     TDS${Orange} - The Darkedend Sea 
    /echo ${Green}     TBM${Orange} - The Broken Mirror
    /echo ${Green}     EoK${Orange} - Empires of Kunark
    /echo ${Green}     RoS${Orange} - Ring of Scale	
	/endm
/return

| -------------------------------------------------------------------------------------
| SUB: load LDoN ini file
| ------------------------------------------------------------------------------------- 
Sub loadLDoNinis

    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk]}) 				/varset LDoN-DG 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Cauldron]}) 		/varset LDoN-DG-Cauldron 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Chapel]}) 		/varset LDoN-DG-Chapel 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Mushroom]}) 		/varset LDoN-DG-Mushroom 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Sanctuary]}) 	/varset LDoN-DG-Sanctuary 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Crypt]}) 		/varset LDoN-DG-Crypt 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Aquaduct]}) 		/varset LDoN-DG-Aquaduct 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Prison]}) 		/varset LDoN-DG-Prison 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,DeepGuk-Garden]}) 		/varset LDoN-DG-Garden 1
	
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul]}) 				/varset LDoN-MM 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Menagerie]}) 	/varset LDoN-MM-Menagerie 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Laboratory]}) 	/varset LDoN-MM-Laboratory 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-SpiderDen]}) 	/varset LDoN-MM-SpiderDen 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Theater]}) 		/varset LDoN-MM-Theater 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Wastes]}) 		/varset LDoN-MM-Wastes 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Heart]}) 		/varset LDoN-MM-Heart 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Banquet]}) 		/varset LDoN-MM-Banquet 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Library]}) 		/varset LDoN-MM-Library 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-Gallery]}) 		/varset LDoN-MM-Gallery 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Miragul-FrostHalls]}) 	/varset LDoN-MM-FrostHalls 1
	
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore]}) 			/varset LDoN-MC 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Cavern]}) 		/varset LDoN-MC-Cavern 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Grotto]}) 		/varset LDoN-MC-Grotto 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Asylum]}) 		/varset LDoN-MC-Asylum 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Chamber]}) 	/varset LDoN-MC-Chamber 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Sepulcher]}) 	/varset LDoN-MC-Sepulcher 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-SummGround]}) 	/varset LDoN-MC-SummGround 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Cesspit]}) 	/varset LDoN-MC-Cesspit 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Aisles]}) 		/varset LDoN-MC-Aisles 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Halls]}) 		/varset LDoN-MC-Halls 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Mistmoore-Sanctuary]}) 	/varset LDoN-MC-Sanctuary 1
	
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz]}) 				/varset LDoN-TH 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Tower]}) 			/varset LDoN-TH-Tower 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Observatory]}) 	/varset LDoN-TH-Observatory 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Palace]}) 		/varset LDoN-TH-Palace 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Chamber]}) 		/varset LDoN-TH-Chamber 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Prismatic]}) 		/varset LDoN-TH-Prismatic 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Library]}) 		/varset LDoN-TH-Library 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-River]}) 			/varset LDoN-TH-River 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Tides]}) 			/varset LDoN-TH-Tides 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Sandfall]}) 		/varset LDoN-TH-Sandfall 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,TakHiz-Temple]}) 		/varset LDoN-TH-Temple 1
	
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark]}) 				/varset LDoN-RH 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Hollows]}) 		/varset LDoN-RH-Hollows 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Forge]}) 			/varset LDoN-RH-Forge 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Arena]}) 			/varset LDoN-RH-Arena 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Quarries]}) 		/varset LDoN-RH-Quarries 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Fort]}) 			/varset LDoN-RH-Fort 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-GladPit]}) 		/varset LDoN-RH-GladPit 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Barracks]}) 		/varset LDoN-RH-Barracks 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Halls]}) 			/varset LDoN-RH-Halls 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Vale]}) 			/varset LDoN-RH-Vale 1
    /if (!${Ini[${RouteIniFileName},CompletedLDoNs,Rujark-Bridges]}) 		/varset LDoN-RH-Bridges 1


/return

| -------------------------------------------------------------------------------------
| SUB: ShardPortalQuests
| ------------------------------------------------------------------------------------- 
Sub ShardPortalQuests
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoEastWastes]}) 		/varset PortaltoEastWastes 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoBreedingGround]}) 	/varset PortaltoBreedingGround 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoVileOak]}) 			/varset PortaltoVileOak 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoGrelleth]}) 			/varset PortaltoGrelleth 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoChapterhouse]})		/varset PortaltoChapterhouse 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoKingXorbb]}) 		/varset PortaltoKingXorbb 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoChelsith]}) 			/varset PortaltoChelsith 1
   /if (!${Ini[${RouteIniFileName},CompletedQuests,PortaltoPoShadow]}) 			/varset PortaltoPoShadow 1
/return


| -------------------------------------------------------------------------------------
| SUB: loadRoutes
| ------------------------------------------------------------------------------------- 
Sub loadRoutes

    /if (!${Ini[${RouteIniFileName},CompletedRoutes,Antonica]}) 		/varset Antonica 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,Faydwer]}) 			/varset Faydwer 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,Odus]}) 			/varset Odus 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,ThePlanes]}) 		/varset ThePlanes 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,SpecialEvents]}) 	/varset SpecialEvents 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,Housing]})  		/varset Housing 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,Guilds]}) 			/varset Guilds 1	
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,RoK]}) 				/varset RoK 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,SoV]}) 				/varset SoV 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,SoL]}) 				/varset SoL 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,PoP]}) 				/varset PoP 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,LoY]}) 				/varset LoY 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,LDoN]}) 			/varset LDoN 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,GoD]}) 				/varset GoD 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,OoW]}) 				/varset OoW 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,DoN]}) 				/varset DoN 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,DoDH]}) 			/varset DoDH 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,PoR]}) 				/varset PoR 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,TSS]}) 				/varset TSS 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,TBS]}) 				/varset TBS 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,SoF]}) 				/varset SoF 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,SoD]}) 				/varset SoD 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,Underfoot]}) 		/varset Underfoot 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,HoT]}) 				/varset HoT 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,VoA]}) 				/varset VoA 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,RoF]}) 				/varset RoF 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,CotF]}) 			/varset CotF 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,TDS]}) 				/varset TDS 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,TBM]}) 				/varset TBM 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,EoK]}) 				/varset EoK 1
    /if (!${Ini[${RouteIniFileName},CompletedRoutes,RoS]}) 				/varset RoS 1
/return

| -------------------------------------------------------------------------------------
| SUB: createPotionINI
| ------------------------------------------------------------------------------------- 
Sub createPotionINI
    |- Adding invisClickie Support
    /if (!${Ini[${PotionIniFileName},General,invisClickie].Length}) {
        /ini "${PotionIniFileName}" "General" "invisClickie"
    }
    |- Adding invisClickie2 Support
    /if (!${Ini[${PotionIniFileName},General,invisClickie2].Length}) {
        /ini "${PotionIniFileName}" "General" "invisClickie2"
    }

    |- Adding IVU Clickie Support
    /if (!${Ini[${PotionIniFileName},General,ivuClickie].Length}) {
        /ini "${PotionIniFileName}" "General" "ivuClickie"
    }

    |- Adding shrinkClickie Support
    /if (!${Ini[${PotionIniFileName},General,shrinkClickie].Length}) {
        /ini "${PotionIniFileName}" "General" "shrinkClickie"
    }

    |- Adding levClickie Support
    /if (!${Ini[${PotionIniFileName},General,levClickie].Length}) {
        /ini "${PotionIniFileName}" "General" "levClickie"
    }

    |- Adding minimumInvisPots Support
    /if (!${Ini[${PotionIniFileName},General,minimumInvisPots].Length}) {
        /ini "${PotionIniFileName}" "General" "minimumInvisPots" 60
    }

    |- Adding minimumShrinkPots Support
    /if (!${Ini[${PotionIniFileName},General,minimumShrinkPots].Length}) {
        /ini "${PotionIniFileName}" "General" "minimumShrinkPots" 60
    }

    |- Adding control mechanism to protect plat spend
    /if (!${Ini[${PotionIniFileName},General,MaxPlatPerPotion].Length}) {
        /ini "${PotionIniFileName}" "General" "MaxPlatPerPotion" 1200
    }
/return

| -------------------------------------------------------------------------------------
| SUB: checkPotionStock - Check quantity of potions on hand
| ------------------------------------------------------------------------------------- 
Sub checkPotionStock (string specialRequirement)
    /if (!${Zone.ShortName.Equal[poknowledge]}) /return
    |- Special handler for: indoor Levitation
    /if (${specialRequirement.Equal[Levi]}) {
        /echo The route you are going to run through requires indoor levitation, buying lev potions
        /call restockPotions levi
    }
    |- Special handler for: Invis to Undead
    /if (${specialRequirement.Equal[ivu]}) {
        /if (!${ivuClickie.Equal[Philter of Unlife Awareness]} && ${ivuAbility}) {
            /return
        } else {
            /echo The route you are going to run requires Invis vs. Undead, buying IVU potions because you don't have an ability nor an item.
            /call restockPotions ivu
        }
    }
	
    /if (!${invisClickie.Equal[Cloudy Potion]} && !${FindItemCount[=${invisClickie}]} && !${invisAbility} && ${Me.Class.ShortName.NotEqual[ROG]}) {
        /echo Searching your inventories for Invis-Clickies.  Storing the two fastest casting in my INI.
        /call findInvisClickies
    }
    /if (!${shrinkClickie.Equal[Philter of the Ant]} && !${FindItemCount[=${shrinkClickie}]} && !${shrinkAbility}) {
        /echo Searching your inventory for Shrink-Clickies.  Adding the fastest-cast in my INI.
        /call findShrinkClickie
    }
    /if (!${levClickie.Equal[Philter of Gulon's Impunity]} && !${FindItemCount[=${levClickie}]} && !${levAbility}) {
        /echo Searching your inventory for Levitation Clickies.  Adding the fastest-cast in my INI.
        /call findLevClickie
    }
    /if (!${invisAbility} && ${Me.Class.ShortName.NotEqual[ROG]}) {
        /if ((${invisClickie.Equal[Cloudy Potion]} || ${invisClickie2.Equal[Cloudy Potion]}) && ${FindItemCount[Cloudy Potion]}<${intMinCloudyCount}) /call restockPotions cloudy
    }
    /if (!${shrinkAbility} && ${Me.Height}>2.85) {
        /if (${shrinkClickie.Equal[Philter of the Ant]} && ${FindItemCount[=${shrinkClickie}]}<${intMinAntCount}) /call restockPotions ant
    }
    /if (!${levAbility}) {
        /if (${levClickie.Equal[Philter of Gulon's Impunity]} && ${FindItemCount[=${levClickie}]}<${intMinLevCount}) /call restockPotions levi
    }
    /if (!${Me.AltAbility[Gate]} && ${FindItemCount[=Philter of Major Translocation]}<${intMinGateCount}) {
        /call restockPotions gate
    }
/return


| -------------------------------------------------------------------------------------
| Sub: restockPotions
| -------------------------------------------------------------------------------------
Sub restockPotions(string strPotionType)
    /if (${Zone.ShortName.NotEqual[poknowledge]}) /return
    /declare        intMyCash               int         local       ${Math.Calc[ (${Me.Platinum}*1000) + (${Me.Gold}*100) + (${Me.Silver}*10) + ${Me.Copper} ]}
    /declare        index                   int         local       1
    /declare        indexCount              int         local       0
    /declare        indexPrice              int         local       0
    /declare        indexPlat               int         local       0
    /declare        indexGold               int         local       0
    /declare        indexSilver             int         local       0
    /declare        indexCopper             int         local       0
    /declare        cheapestIndex           int         local       0
    /declare        cheapestIndexPrice      int         local       0
    /declare        cheapestIndexQty        int         local       0
    /declare        buyPrice                float       local       0
    /declare        parcelFee               int         local       0
    /declare        buyAmount               int         local
    /declare        stillNeed               int         local
    /declare        strPotionName           string      local
    /declare        intMinQty               int         local

    /if (${strPotionType.Equal[cloudy]}) {
        /declare        intQtyToBuy            int      local       ${Math.Calc[${intMinCloudyCount}-${FindItemCount[=Cloudy Potion]}]}
        /declare        intPurchasePrice       int      local       ${Math.Calc[${intQtyToBuy}*12000]}
        :NotEnoughPlatCloudy
        /if (${intMyCash}<${intPurchasePrice}) {
            /call MQP needMoney
        }
        /varset intMyCash ${Math.Calc[ (${Me.Platinum}*1000) + (${Me.Gold}*100) + (${Me.Silver}*10) + ${Me.Copper} ]}
        /if (${intMyCash}<${intPurchasePrice}) /goto :NotEnoughPlatCloudy
        /target clear
        /nav spawn npc Toxicologist_Huey
        /call Navigating
        /target npc Toxicologist_Huey
        /delay 3s ${Target.ID}
        /click right target
        |Wait on inventory
        /delay 10s ${Merchant.ItemsReceived}
        /if (${Merchant.Open}) {
            /invoke ${Merchant.SelectItem[=Cloudy Potion]}
            /while (${FindItemCount[=Cloudy Potion]} < ${intMinCloudyCount}) {
                /invoke ${Merchant.Buy[${Math.Calc[${intMinCloudyCount}-${FindItemCount[=Cloudy Potion]}]}]}
                /delay 10
            }

        }
        /deletevar intMyCash
        /deletevar intQtyToBuy
        /deletevar intPurchasePrice
        /cleanup
    } else {
    |- Player Made/auctioned Potions
        |- Populate variables with potion-type specifics
        /if (${strPotionType.Equal[ant]}) {
            /varset strPotionName Philter of the Ant
            /varset intMinQty ${intMinAntCount}
        } else /if (${strPotionType.Equal[levi]}) {
            /varset strPotionName Philter of Gulon's Impunity
            /varset intMinQty ${intMinLevCount}
        } else /if (${strPotionType.Equal[ivu]}) {
            /varset strPotionName Philter of Unlife Awareness
            /varset intMinQty ${intMinIVUCount}
        } else /if (${strPotionType.Equal[gate]}) {
            /varset strPotionName Philter of Major Translocation
            /varset intMinQty ${intMinGateCount}
        } else {
            /return badArgument
        }

        /varcalc buyAmount ${intMinQty}-${FindItemCount[=${strPotionName}]}
        /varcalc stillNeed ${intMinQty}-${FindItemCount[=${strPotionName}]}

        |- Checking if we actually need to buy aything
        /if (${stillNeed}<=0) {
            /echo Found poitions in our bags. Let's explore!
            /return
        }

        |- Opening bazaar and adding check if it failed.
        /if (!${Window[BazaarSearchWnd].DoOpen}) {
            /echo \arBazaar didnt open, we cant restock shrink pots without it.
            /return bazaarfailed
        }
        
        |- Populate bazaarwindow.
        /delay 5s ${Window[BazaarSearchWnd].Open}
        :buymore
        |- Clearing previous searches.
        /notify BazaarSearchWnd BZR_Default leftmouseup
        /delay 8
        /delay 1s ${Window[BazaarSearchWnd].Child[BZR_Default].Enabled}
        /delay 1s 

        |-Typing in the name we looking for.
        /notify BazaarSearchWnd BZR_ItemNameInput leftmouseup
        /delay 5
        /call inputItemSearch "${strPotionName}"

        |- Hitting the search button and waiting for the search to be done
		
        /notify BazaarSearchWnd BZR_QueryButton leftmouseup
        /delay 60s ${Window[BazaarSearchWnd].Child[BZR_QueryButton].Enabled}
        /varset indexCount ${Window[BazaarSearchWnd].Child[BZR_ItemList].Items}
        /if (${indexCount}<1) {
		
            /beep
            /echo ${Red} ERROR -  Cannot find ${strPotionName} for sale, and you don't have an appropriate Clickie or AA.  ${White}Don't log a bug if you have problems!
            /echo ${Red} ERROR -  Make / Buy some potions and unpause the macro.
            /call MQP
            /return noPotionsForSale
        }
        
        /for index 1 to ${indexCount}
            /varcalc indexPlat ${Window[BazaarSearchWnd].Child[BZR_ItemList].List[${index},4]}*1000
            /if (${indexPlat} > ${intMaxPlatPerPotion}*1000) {
                /varset cheapestIndex -1
                /continue
            }
            /varcalc indexGold ${Window[BazaarSearchWnd].Child[BZR_ItemList].List[${index},5]}*100
            /varcalc indexSilver ${Window[BazaarSearchWnd].Child[BZR_ItemList].List[${index},6]}*10
            /varcalc indexCopper ${Window[BazaarSearchWnd].Child[BZR_ItemList].List[${index},7]}
            /varcalc indexPrice ${indexPlat}+${indexGold}+${indexSilver}+${indexCopper}
            /if (${indexPrice} > 0) {
                /if (${index} == 1) {
                    /varset cheapestIndex ${index}
                    /varset cheapestIndexPrice ${indexPrice}
                } else /if (${indexPrice} <=  ${cheapestIndexPrice}) {
                    /varset cheapestIndex ${index}
                    /varset cheapestIndexPrice ${indexPrice}
                }
            }
        /next index
        /if (${cheapestIndex}<0) {
            /echo ${Orange}Warning Potions available but above your max price of ${intMaxPlatPerPotion}pp per potion (in the INI as MaxPlatPerPotion)
            /echo ${Red} ERROR -  Pausing macro. Either buy potions or end macro manually.
            /call MQP
            /cleanup
            /return
        }
        /notify BazaarSearchWnd BZR_ItemList listselect ${cheapestIndex} leftmouseup
        /varset cheapestIndexQty ${Window[BazaarSearchWnd].Child[BZR_ItemList].List[${cheapestIndex},3]}    
        /delay 5
        
|       /echo ${White} Debug -  We wish to buy ${buyAmount} and the selected trader has ${cheapestIndexQty}
        /if (${buyAmount} > ${cheapestIndexQty}) {
            /varset buyAmount ${cheapestIndexQty}
        }

        /varcalc buyPrice ${buyAmount}*(${cheapestIndexPrice}/1000)
        /varcalc parcelFee ${buyPrice}*0.10
        :CheckCashForParcel
        /if (${Math.Calc[${buyPrice}+${parcelFee}]} > ${Math.Calc[${intMyCash}/1000]})  {
            /echo We have ${Math.Calc[${intMyCash}/1000]}pp, which is not enough we need a total of ${buyPrice}+ ${parcelFee}(Parcel fee)
            /call MQP needMoney
        } 
        /varset intMyCash ${Math.Calc[ (${Me.Platinum}*1000) + (${Me.Gold}*100) + (${Me.Silver}*10) + ${Me.Copper} ]}
        /if (${Math.Calc[${buyPrice}+${parcelFee}]} > ${Math.Calc[${intMyCash}/1000]}) /goto :CheckCashForParcel

|       /echo ${White} Debug -  Let's buy ${buyAmount} for a total of ${Math.Calc[${buyPrice}+${parcelFee}]}
|       /echo ${White} Debug -  We have ${Math.Calc[${intMyCash}/1000]}pp
                
        /notify BazaarSearchWnd BZR_BuyButton leftmouseup
        /delay 5s ${Window[QuantityWnd].Open}
        /notify QuantityWnd QTYW_slider newvalue ${Math.Calc[${buyAmount}].Int}
        /delay 5
        /notify QuantityWnd QTYW_Accept_Button leftmouseup
        /delay 5
        /notify BazaarConfirmationWnd BZC_UsePlatButton leftmouseup
        /delay 60s !${Window[BazaarConfirmationWnd].Open}
        
        /varcalc stillNeed ${stillNeed} - ${buyAmount}
        /if (${stillNeed}) {
            /echo The trader only had ${buyAmount} and we wanted ${intMinQty} so we still need to buy ${stillNeed}
            /varset buyAmount ${stillNeed}
            /goto :buymore
        } else /if (${stillNeed} == 0) {
            /windowstate BazaarSearchWnd close
            /delay 5s                
            :pickup
            |- lets nav to near the gnome parcel dude in pok so we can pick up potions.
            /echo Lets go pick up our potions!
            /nav spawn npc caden | dist=12
            /while (${Navigation.Active}) {
                /delay 5
            }
            /target npc caden
            /delay 5s ${Target.CleanName.Find[Caden]}
            /while (!${Window[MerchantWnd].Open}) {
                /click right target
                /delay 25 ${Window[MerchantWnd].Open}
            }

            /delay 5s ${Window[MerchantWnd].Open}
            /delay 5s ${Merchant.ItemsReceived}
            /if (${Window[MerchantWnd].Open}) {
                /notify MerchantWnd MW_MerchantSubWindows tabselect 3
                /delay 15s ${Merchant.ItemsReceived}
                /echo Waiting for Parcel items to be ready
                /while (${Window[MerchantWnd].Child[MW_ItemListMail].Items}<=1) {
					/delay 1s
				}
                /delay 10
                /while (${Window[MerchantWnd].Child[MW_ItemListMail].List[philter of,2]}) {
                    /notify MerchantWnd MW_ItemListMail listselect ${Window[MerchantWnd].Child[MW_ItemListMail].List[philter of,2]} leftmouseup   
                    /delay 5
                    /notify MerchantWnd MW_Retrieve_Button leftmouseup
                    /delay 10
                }
                /echo Retrieved all philters out of waiting parcels
                /cleanup                 
            } else {
                /echo Something went wrong and Caden didnt open his trading window.  Pausing Macro.  Pick up the parcels and then unpause.
                /call MQP
            }
        }
        /cleanup
    }
/return

