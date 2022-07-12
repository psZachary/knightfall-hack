#pragma once
#include <Windows.h>
#include "mathn.h"
namespace il2cpp {
	static uintptr_t get_assembly() {
		return (uintptr_t)GetModuleHandleA("GameAssembly.dll");
	}
	static void* resolve_icall(const char* icall) {
		using p_resolve_icall = void* (__cdecl*)(const char*);
		printf("icall: %p\n", GetProcAddress((HMODULE)get_assembly(), "il2cpp_resolve_icall"));
		return ((p_resolve_icall)GetProcAddress((HMODULE)get_assembly(), "il2cpp_resolve_icall"))(icall);
		
	}

	namespace private_ {
		using p_get_game_object = uintptr_t(__cdecl*)(uintptr_t component);
		auto a_get_game_object = resolve_icall("UnityEngine.Component::get_gameObject()");

		using p_gameobject_get_transform = uintptr_t*(__cdecl*)(uintptr_t gameobject);
		auto a_gameobject_get_transform = resolve_icall("UnityEngine.GameObject::get_transform(System.IntPtr)");

		using p_transform_get_vector = uintptr_t* (__cdecl*)(uintptr_t*, vec3*);		
		auto a_transform_get_vector = resolve_icall("UnityEngine.Transform::get_position_Injected(UnityEngine.Vector3&)");

		using p_camera_get_main = uintptr_t(__cdecl*)();
		auto a_camera_get_main = resolve_icall("UnityEngine.Camera::get_main()");
	}

	namespace component {
		static uintptr_t get_game_object(uintptr_t component) {
			auto f = ((private_::p_get_game_object)(private_::a_get_game_object));
			return f(component);
		}
	}

	namespace gameobject {
		static uintptr_t* get_transform(uintptr_t game_object) {
			auto f = ((private_::p_gameobject_get_transform)(private_::a_gameobject_get_transform));
			return f(game_object);
		}	
	}

	namespace transform {
		static uintptr_t* get_vector(uintptr_t* transform, vec3* output) {
			auto f = ((private_::p_transform_get_vector)(private_::a_transform_get_vector));
			return f(transform, output);
		}
	}

	namespace camera {
		static uintptr_t get_main() {
			auto f = ((private_::p_camera_get_main)(private_::a_camera_get_main));
			return f();
		}
		static matrix4x4 get_matrix(uintptr_t camera) {
			if (camera) {
				camera = *(uintptr_t*)(camera + 0x10);
				return *(matrix4x4*)(camera + 0xDC);
			}

		}
	}

}