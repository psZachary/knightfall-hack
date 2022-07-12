#pragma once
#include "il2cpp.h"

namespace screen {
	namespace private_ {
		using p_screen_size = int(__cdecl*)();
		static p_screen_size p_screen_size_x = (p_screen_size)il2cpp::resolve_icall("UnityEngine.Screen::get_width()");
		static p_screen_size p_screen_size_y = (p_screen_size)il2cpp::resolve_icall("UnityEngine.Screen::get_height()");
	}
	int screen_size_x() {
		return private_::p_screen_size_x();
	}
	int screen_size_y() {
		return private_::p_screen_size_y();
	}
}