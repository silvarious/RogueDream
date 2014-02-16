#include "graphics.h"

Graphics::Graphics()
{
	window_ = SDL_CreateWindow("RogueDream", 200, 200, kScreenWidth, kScreenHeight, 0);
	if (window_ == nullptr)
        SDL_ShowSimpleMessageBox(0, "Window init error", SDL_GetError(), window_);
	renderer_ = SDL_CreateRenderer(window_, -1, 0);
	if (renderer_ == nullptr)
        SDL_ShowSimpleMessageBox(0, "Renderer init error", SDL_GetError(), window_);
}

Graphics::~Graphics()
{
	SDL_FreeSurface(image_);
	SDL_DestroyTexture(texture_);
	SDL_DestroyWindow(window_);
	SDL_DestroyRenderer(renderer_);
}

SDL_Texture* Graphics::loadImage(const std::string& file_path)
{
	image_ = IMG_Load(file_path.c_str());
	if (image_ == nullptr)
        SDL_ShowSimpleMessageBox(0, "Image init error", SDL_GetError(), window_);

	texture_ = SDL_CreateTextureFromSurface(renderer_, image_);
	if (texture_ == nullptr)
        SDL_ShowSimpleMessageBox(0, "Texture init error", SDL_GetError(), window_);

	SDL_FreeSurface(image_);
	sprite_sheets_[file_path] = texture_;
	return sprite_sheets_[file_path];
}

void Graphics::renderTexture(SDL_Texture* image, const SDL_Rect destination, const SDL_Rect* source) const
{
	SDL_RenderCopy(renderer_, image, source, &destination);
}

void Graphics::renderTexture(SDL_Texture* image, const int x, const int y, const SDL_Rect* source) const
{
	SDL_Rect destination;

	destination.x = x;
	destination.y = y;

	if (source != nullptr)
	{
		destination.w = source->w;
		destination.h = source->h;
	}
	else
	{
		SDL_QueryTexture(image, nullptr, nullptr, &destination.w, &destination.h);
	}

	renderTexture(image, destination, source);
}

void Graphics::renderFlippedTexture(SDL_Texture* image, const SDL_Rect destination, const SDL_Rect* source, const double angle, const SDL_Point* center, const SDL_RendererFlip flip) const
{
	SDL_RenderCopyEx(renderer_, image, source, &destination, angle, center, flip);
}

void Graphics::renderFlippedTexture(SDL_Texture* image, const int x, const int y, const SDL_Rect* source, const double angle, const SDL_Point* center, const SDL_RendererFlip flip) const
{
	SDL_Rect destination;

	destination.x = x;
	destination.y = y;

	if (source != nullptr)
	{
		destination.w = source->w;
		destination.h = source->h;
	}
	else
	{
		SDL_QueryTexture(image, nullptr, nullptr, &destination.w, &destination.h);
	}

	renderFlippedTexture(image, destination, source, angle, center, flip);
}

void Graphics::flip() const
{
	SDL_RenderPresent(renderer_);
}

void Graphics::clear() const
{
	SDL_RenderClear(renderer_);
}