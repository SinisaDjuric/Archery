# include "gui_sdl.h"


     //Start SDL
void set_and_load(void)
{
	SDL_Init( SDL_INIT_EVERYTHING );

	//Set up screen
	screen = SDL_SetVideoMode( 1080, 1080, 32, SDL_SWSURFACE );
	//Load image
	target = SDL_LoadBMP( "resources/target1.bmp" );
	vertical = SDL_LoadBMP( "resources/vertikala.bmp" );
	horizontal = SDL_LoadBMP( "resources/horizontala.bmp" );
	point_vert = SDL_LoadBMP( "resources/point_vertical.bmp" );
	point_horiz = SDL_LoadBMP( "resources/point.bmp" );
}

void show_start_images(SDL_Rect t,SDL_Rect h)
{
    //Apply image to screen
    SDL_BlitSurface( target, NULL, screen, &t);
	SDL_BlitSurface( vertical, NULL, screen, NULL );
	SDL_BlitSurface( horizontal, NULL, screen, &h );
	
    //Update Screen
    SDL_Flip( screen );
	SDL_Delay( 4000 );
}

int take_x(SDL_Rect p)
{
	SDL_Event event;
	int i, direction = 1;
	p.y=327;
	while (direction != 0)
	{
		if (direction == 1)
		{
			for(i=106;i<335;i++)
			{
				p.x=i;
				SDL_BlitSurface( point_horiz, NULL, screen, &p );
				SDL_Flip( screen );
				SDL_Delay( 10 );
				if (i == 334)
					direction = -1;
				if( SDL_PollEvent( &event ) )
        		{
          		  //If a key was pressed
          		  if( event.type == SDL_KEYDOWN )
          		  {
					if (event.key.keysym.sym == SDLK_SPACE)
					{
						direction = 0;
						return p.x;
					}
				  }
				}	
			}
		}
		else if (direction == -1)
		{
			for(i=334;i>105;i--)
			{
				p.x=i;
				SDL_BlitSurface( point_horiz, NULL, screen, &p );
				SDL_Flip( screen );
				SDL_Delay( 10 );
				if (i == 106)
					direction = 1;
				if( SDL_PollEvent( &event ) )
        		{
          		  //If a key was pressed
          		  if( event.type == SDL_KEYDOWN )
          		  {
					if (event.key.keysym.sym == SDLK_SPACE)
					{
						direction = 0;
						return p.x;
					}
				  }
				}	
			}
		}
	}
}

int take_y(SDL_Rect pv)
{
	SDL_Event event;
	int i, direction = 1;
	pv.x=18;
	while (direction != 0)
	{
		if (direction == 1)
		{
			for(i=29;i<228;i++)
			{
				pv.y=i;
				SDL_BlitSurface( point_vert, NULL, screen, &pv );
				SDL_Flip( screen );
				SDL_Delay( 10 );
				if (i == 227)
					direction = -1;
				if( SDL_PollEvent( &event ) )
        		{
          		  //If a key was pressed
          		  if( event.type == SDL_KEYDOWN )
          		  {
						if (event.key.keysym.sym == SDLK_SPACE)
						{
							direction = 0;
							return pv.y;
						}
				  }
				}
			}
		}
		else if (direction == -1)
		{
			for(i=227;i>28;i--)
			{
				pv.y=i;
				SDL_BlitSurface( point_vert, NULL, screen, &pv );
				SDL_Flip( screen );
				SDL_Delay( 10 );
				if (i == 29)
					direction = 1;
				if( SDL_PollEvent( &event ) )
        		{
          		  //If a key was pressed
          		  if( event.type == SDL_KEYDOWN )
          		  {
						if (event.key.keysym.sym == SDLK_SPACE)
						{
							direction = 0;
							return pv.y;
						}
				  }
				}
			}
		}
	}
}
	
void sdl_quit(void)
{
	//Pause
    SDL_Delay( 3000 );
    //Free the loaded image
    SDL_FreeSurface( target );
	SDL_FreeSurface( vertical );
	SDL_FreeSurface( horizontal );
	SDL_FreeSurface( point_vert );
	SDL_FreeSurface( point_horiz );
    //Quit SDL
    SDL_Quit();
}


