#pragma once
#include "il2cpp.h"
#include <Windows.h>
#include "offsets.h"
namespace knightfall {
	namespace private_ {
		using p_player_is_localplayer = bool(__stdcall*)(uintptr_t);
		p_player_is_localplayer a_player_is_localplayer = (p_player_is_localplayer)(il2cpp::get_assembly() + offsets::functions::player_islocalplayer);

		using p_get_playerlist = uintptr_t* (__stdcall*)();
		p_get_playerlist a_get_playerlist = (p_get_playerlist)(il2cpp::get_assembly() + offsets::functions::photonnetwork_get_playerlist);

		using p_get_playercount = int (__stdcall*)();
		p_get_playercount a_get_playercount = (p_get_playercount)(il2cpp::get_assembly() + offsets::functions::photonnetwork_get_countofplayers);

		using p_player_get_head_position = vec3(__stdcall*)(uintptr_t);
		p_player_get_head_position a_player_get_head_position = (p_player_get_head_position)(il2cpp::get_assembly() + offsets::functions::player_getheadposition);
	}

	namespace player {
		bool is_local_player(uintptr_t player) {
			return private_::a_player_is_localplayer(player);
		}
		vec3 get_head_position(uintptr_t player) {
			return private_::a_player_get_head_position(player);
		}
	}
	namespace photonnetwork {
		uintptr_t* get_playerlist() {
			return private_::a_get_playerlist();
		}
		int get_playercount() {
			return private_::a_get_playercount();
		}
	}
}