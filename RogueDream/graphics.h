#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>

namespace
{
	static int kScreenWidth = 640;
	static int kScreenHeight = 480;
}

struct Graphics
{
	Graphics();
	~Graphics();

	SDL_Texture* loadImage(const std::string& file_path);
	void renderTexture(SDL_Texture* image, const SDL_Rect destination, const SDL_Rect* source) const;
	void renderTexture(SDL_Texture* image, const int x, const int y, const SDL_Rect* source) const;
	void renderFlippedTexture(SDL_Texture* image, const SDL_Rect destination, const SDL_Rect* source, const double angle, const SDL_Point* center, const SDL_RendererFlip flip) const;
	void renderFlippedTexture(SDL_Texture* image, const int x, const int y, const SDL_Rect* source, const double angle, const SDL_Point* center, const SDL_RendererFlip flip) const;
	void flip() const;
	void clear() const;

private:
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	SDL_Surface* image_;
	SDL_Texture* texture_;

	std::map<std::string, SDL_Texture*> sprite_sheets_;
};

#endif