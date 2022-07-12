#pragma once
#include "config.h"
#include "screen.h"
#include "gamehook.h"
static bool is_menu_open = true;

static void menu() {
	if (GetAsyncKeyState(VK_INSERT) & 1) is_menu_open = !is_menu_open;
	if (!is_menu_open) return;

	ImGui::Begin("Knightfall Internal", 0, ImGuiWindowFlags_NoCollapse);
	
	ImGui::Checkbox("Player ESP", &config::esp);
	if (ImGui::Button("No Spread")) {
		config::no_spread = true;
	}
	if (ImGui::Button("Print Playerlist Addr")) {
		printf("%p\n", knightfall::photonnetwork::get_playerlist());
	}
	if (ImGui::Button("Print Playercount")) {
		printf("%i\n", knightfall::photonnetwork::get_playercount());
	}
	ImGui::SliderFloat("Reload Time", &config::reload_time, 0, 3.0f);
	ImGui::End();
}