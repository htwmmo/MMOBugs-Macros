Sub Housing
    /if (!${EverQuest.Foreground}) {
        /while (!${EverQuest.Foreground}) {
            /popup *** This has to be run manually ***
			/popup Requried: 1 and 3 Room versions of Stone, Stucco and Wood Interiors
            /beep
            /delay 15
        }
        /call MQP
		
		/delay 2s		
		/ini "${RouteIniFileName}" "CompletedRoutes" "Housing" "1"
		/delay 1s
/return