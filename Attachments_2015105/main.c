# include "gui_sdl.h"

int main( int argc, char* args[] )
{

    set_and_load();
    //set_positions();
    SDL_Rect h;
    h.x = 75;
    h.y = 275;  
	SDL_Rect t;
	t.x = 95;
	t.y = 25;
    SDL_Rect p, pv;
    SDL_Rect d;
    show_start_images(t, h);
    d.x = take_x(p) + 4;
    d.y = take_y(pv) + 4;
	//printf("%d, %d\n", d.x, d.y);
    SDL_Surface* dot = NULL;
    dot = SDL_LoadBMP( "green_dot.bmp" );
    SDL_BlitSurface( dot, NULL, screen, &d );
    SDL_Flip( screen );
	SDL_Delay( 4000 );
    sdl_quit();

    return 0; 
}
