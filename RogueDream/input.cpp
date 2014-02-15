#include"input.h"

void Input::beginNewFrame()
{
	pressed_keys_.clear();
	released_keys_.clear();
}

void Input::keyDownEvent(const SDL_Event& sdl_event)
{
	pressed_keys_[sdl_event.key.keysym.sym] = true;
	held_keys_[sdl_event.key.keysym.sym] = true;
}

void Input::keyUpEvent(const SDL_Event& sdl_event)
{
	released_keys_[sdl_event.key.keysym.sym] = true;
	held_keys_[sdl_event.key.keysym.sym] = false;
}

bool Input::wasKeyPressed(SDL_Keycode key)
{
	return pressed_keys_[key];
}

bool Input::wasKeyReleased(SDL_Keycode key)
{
	return released_keys_[key];
}

bool Input::isKeyHeld(SDL_Keycode key)
{
	return held_keys_[key];
}