#pragma once
#include <Windows.h>

static bool isbad(uintptr_t ptr)
{
    if (ptr == NULL) return false;
    if (!ptr) return false;
    auto minimum_application_address = uintptr_t(0x0001000);
    auto maximum_application_address = uintptr_t((sizeof(uintptr_t*) == 4u) ? 0x7FFEFFFF : 0x7FFFFFFEFFFF);
    return (uintptr_t)(ptr) < minimum_application_address || (uintptr_t)(ptr) > maximum_application_address;
}
