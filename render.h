#pragma once
#include "menu.h"
#include "mathn.h"
#include "il2cpp.h"
#include "w2s.h"
#include "pointer.h"
#include "knightfall.h"
#include "uarray.h"
static void render() {
	menu();

	if (config::esp) {

		printf("%p\n", *(uintptr_t*)(il2cpp::get_assembly() + offsets::typeinfos::playerhandler_typeinfo) + 0xB8);
		
	}
}
