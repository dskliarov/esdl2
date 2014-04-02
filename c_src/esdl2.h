// Copyright (c) 2014, Loïc Hoguin <essen@ninenines.eu>
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#ifndef __ESDL2_H__
#define __ESDL2_H__

#include "SDL.h"

// List of atoms used by this NIF.

#define NIF_ATOMS(A) \
	A(button) \
	A(caps) \
	A(close) \
	A(data) \
	A(enter) \
	A(error) \
	A(event) \
	A(exposed) \
	A(false) \
	A(focus_gained) \
	A(focus_lost) \
	A(h) \
	A(hidden) \
	A(key_down) \
	A(key_up) \
	A(leave) \
	A(left) \
	A(left_alt) \
	A(left_ctrl) \
	A(left_gui) \
	A(left_shift) \
	A(ok) \
	A(maximized) \
	A(middle) \
	A(minimized) \
	A(mod) \
	A(mode) \
	A(mouse_down) \
	A(mouse_motion) \
	A(mouse_up) \
	A(mouse_wheel) \
	A(moved) \
	A(num) \
	A(quit) \
	A(repeat) \
	A(resized) \
	A(restored) \
	A(right) \
	A(right_alt) \
	A(right_ctrl) \
	A(right_gui) \
	A(right_shift) \
	A(scancode) \
	A(shown) \
	A(size_changed) \
	A(state) \
	A(sym) \
	A(touch) \
	A(true) \
	A(timestamp) \
	A(type) \
	A(undefined) \
	A(w) \
	A(which) \
	A(window) \
	A(window_id) \
	A(x) \
	A(x1) \
	A(x2) \
	A(xrel) \
	A(y) \
	A(yrel) \
	A(_nif_thread_ret_)

// List of resources used by this NIF.

#define NIF_RES_TYPE(r) SDL_ ## r
#define NIF_RESOURCES(R) \
	R(Renderer) \
	R(Surface) \
	R(Texture) \
	R(Window)

// List of functions defined in this NIF.

#define NIF_FUNCTION_NAME(f) esdl2_ ## f
#define NIF_FUNCTIONS(F) \
	/* sdl */ \
	F(init, 1) \
	F(init_subsystem, 1) \
	F(quit, 0) \
	F(quit_subsystem, 1) \
	F(set_main_ready, 0) \
	F(was_init, 1) \
	/* sdl_events */ \
	F(poll_event, 0) \
	/* sdl_renderer */ \
	F(create_renderer, 3) \
	F(render_clear, 1) \
	F(render_copy, 4) \
	F(render_present, 1) \
	F(render_set_logical_size, 3) \
	F(set_render_draw_color, 5) \
	/* sdl_surface */ \
	F(img_load, 1) \
	/* sdl_texture */ \
	F(create_texture_from_surface, 2) \
	/* sdl_version */ \
	F(get_version, 0) \
	F(get_revision, 0) \
	/* sdl_window */ \
	F(create_window, 6)

// Generated declarations for the NIF.

#include "nif_helpers.h"

NIF_ATOMS(NIF_ATOM_H_DECL)
NIF_RESOURCES(NIF_RES_H_DECL)
NIF_FUNCTIONS(NIF_FUNCTION_H_DECL)

// --

#define sdl_error_tuple(env) \
	enif_make_tuple2(env, \
		atom_error, \
		enif_make_string(env, SDL_GetError(), ERL_NIF_LATIN1) \
	);

#endif