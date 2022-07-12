#pragma once
#include "kiero/minhook/include/MinHook.h"
#include "il2cpp.h"
#include <iostream>
#include "offsets.h"
#include "knightfall.h"
#include "pointer.h"

static bool tryhook(uintptr_t address, LPVOID detour, LPVOID* original) {
	if (MH_CreateHook(reinterpret_cast<LPVOID>(address), detour, original) == MH_STATUS::MH_OK) {
		if (MH_EnableHook(reinterpret_cast<LPVOID>(address)) == MH_STATUS::MH_OK) {
			return true;
		}
		return false;
	}
	return false;
}

using p_player_update = void(__stdcall*)(uintptr_t);
static p_player_update player_update = 0;
static void hk_player_update(uintptr_t instance) {
	if (isbad(instance)) return player_update(instance);

	printf("actual player: %p\n", instance);


	/*
	if (!std::count(player_entities.begin(), player_entities.end(), instance)) {
		if (!knightfall::player::is_local_player(instance)) {
			player_entities.push_back(instance);
		}
	}
	*/

	if (knightfall::player::is_local_player(instance)) {

		auto data = *(uintptr_t*)(instance + 0x68);
		if (data) {
			auto refs = *(uintptr_t*)(instance + 0x70);
			if (refs) {
				auto stats = *(uintptr_t*)(instance + 0x18);
				if (stats) {
					auto gun = *(uintptr_t*)(refs + 0x78);
					if (gun) {
						if (config::no_spread) {
							auto spreadentry = *(uintptr_t*)(stats + 0x40);
							if (spreadentry) {
								*(float*)(spreadentry + 0x10) = 0;
							}
						}
						auto reloadspeedentry = *(uintptr_t*)(stats + 0x48);
						*(float*)(reloadspeedentry + 0x10) = config::reload_time;
					}
				}
			}
		}
	}
	return player_update(instance);

}



namespace gamehook {
	static void init() {
		player_update = (p_player_update)(il2cpp::get_assembly() + offsets::functions::player_update);

		if (!tryhook(il2cpp::get_assembly() + offsets::functions::player_update, &hk_player_update, reinterpret_cast<LPVOID*>(&player_update))) {
			printf("hook failed: player_update");
		}


	}
}

