# ifndef _GUI_SDL_H
# define _GUI_SDL_H


# include "SDL/SDL.h"
//The images
    SDL_Surface* target;
	SDL_Surface* vertical;
	SDL_Surface* horizontal;
	SDL_Surface* point_vert;
	SDL_Surface* point_horiz;
    SDL_Surface* screen;

void set_and_load(void);
//void set_positions(void);
void show_start_images(SDL_Rect t,SDL_Rect h);
int take_x(SDL_Rect p);
int take_y(SDL_Rect pv);
void sdl_quit(void);

# endif
