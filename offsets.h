#pragma once
#include <Windows.h>

namespace offsets {
	namespace functions {
		static const uintptr_t player_update = 0x80C2A0;
		// internal bool IsLocalPlayer() { }
		static const uintptr_t player_islocalplayer = 0x80AEF0;
		// public Vector3 GetHeadPos() { }
		static const uintptr_t player_getheadposition = 0x80ACD0;

		// public static Player[] get_PlayerList() { }
		static const uintptr_t photonnetwork_get_playerlist = 0xB78C10;
		// public static int get_CountOfPlayers() { }
		static const uintptr_t photonnetwork_get_countofplayers = 0xB773F0;
		

		static const uintptr_t playerhandler_typeinfo = 0x1CA29E8;
	}
	namespace typeinfos {
		//      "Name": "PlayerHandler_TypeInfo",
		//		"Signature": "PlayerHandler_c*"
		static const uintptr_t playerhandler_typeinfo = 0x1CA29E8;
	}
}