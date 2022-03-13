#include<SDL.h>
#include<iostream>

const int w = 1024;
const int h = 768;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void DeInit(int error)
{
	if (renderer != NULL) SDL_DestroyRenderer(renderer);
	if (window != NULL) SDL_DestroyWindow(window);
	SDL_Quit();
	exit(error);
}

void Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
	window = SDL_CreateWindow("HELP PLS ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		printf("SDL_CreateWindow error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf("SDL_CreateRenderer error: %s", SDL_GetError());
		system("pause");
		DeInit(1);
	}
}

void circle(int x_circle, int y_circle, int radius)
{
	int x_point, y_point;
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	for (double i = 0; i < 360; i+=0.5)
	{
		x_point = x_circle + radius * cos(i * M_PI / 180);
		y_point = y_circle + radius * sin(i * M_PI / 180);
		SDL_RenderDrawPoint(renderer, x_point, y_point);
	}
}

int main(int argc, char* argv[])
{
	system("chcp 1251 > nul");
	int r = 160;
	Init();

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	while (r > 0)
	{
		circle(w / 2, h / 2, r);
		r -= 5;
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(100000);
	DeInit(1);
	return 0;
}