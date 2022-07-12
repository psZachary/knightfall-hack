#pragma once
#include <Windows.h>

namespace uarray {
	int len(uintptr_t arrayPtr)
	{
		if (!arrayPtr)
			return -1;

		return *(int*)(arrayPtr + 0x18);
	}

	uintptr_t getaddr(uintptr_t arrayPtr, int i)
	{
		return arrayPtr + 0x20 + 0x8 * i;
	}


	uintptr_t get(uintptr_t arrayPtr, int i)
	{
		return *(uintptr_t*)(getaddr(arrayPtr, i));
	}
}