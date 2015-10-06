# include "gui_sdl.h"

int main( int argc, char* args[] )
{

    set_and_load();
    SDL_Rect h, t, p, pv, d;
    show_start_images(t, h);
    d.x = take_x(p) - 4;
    d.y = take_y(pv) + 4;
	show_hit(d);
    sdl_quit();

    return 0; 
}
