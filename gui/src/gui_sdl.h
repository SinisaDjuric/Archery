# ifndef _GUI_SDL_H
# define _GUI_SDL_H


# include "SDL/SDL.h"
# define SCREEN_HIGHT 640
# define SCREEN_WIDTH 480
# define BPP 32
//The images
    SDL_Surface* target;
	SDL_Surface* vertical;
	SDL_Surface* horizontal;
	SDL_Surface* point_vert;
	SDL_Surface* point_horiz;
	SDL_Surface* dot;
    SDL_Surface* screen;
	SDL_Surface* screen1;
	SDL_Surface* arrow;
	SDL_Surface* hit;
	SDL_Surface* tabele;
	SDL_Surface* white_target;


void setAndLoad(void);
void showAnimation(void);
//void set_positions(SDL_Rect t,SDL_Rect h);
void showStartImages(SDL_Rect t,SDL_Rect h);
void showHit(SDL_Rect d);
int takeX(SDL_Rect p);
int takeY(SDL_Rect pv);
void sdlQuit(void);

# endif
