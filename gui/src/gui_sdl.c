# include "gui_sdl.h"


void setAndLoad(void)
{
	SDL_Init( SDL_INIT_EVERYTHING );
	target = NULL;
	vertical = NULL;
	horizontal = NULL;
	point_vert = NULL;
	point_horiz = NULL;
	dot = NULL;
    screen = NULL;
	
	screen = SDL_SetVideoMode( SCREEN_HIGHT, SCREEN_WIDTH, BPP, SDL_SWSURFACE );
	
	target = SDL_LoadBMP( "resources/target1.bmp" );
	vertical = SDL_LoadBMP( "resources/vertikala.bmp" );
	horizontal = SDL_LoadBMP( "resources/horizontala.bmp" );
	point_vert = SDL_LoadBMP( "resources/point_vertical.bmp" );
	point_horiz = SDL_LoadBMP( "resources/point.bmp" );
	dot = SDL_LoadBMP( "resources/green_dot.bmp" );
}

void showStartImages(SDL_Rect t,SDL_Rect h)
{
	h.x = 75;
    h.y = 275;  
	t.x = 95;
	t.y = 25;
    
    SDL_BlitSurface( target, NULL, screen, &t);
	SDL_BlitSurface( vertical, NULL, screen, NULL );
	SDL_BlitSurface( horizontal, NULL, screen, &h );
	
    
    SDL_Flip( screen );
	SDL_Delay( 4000 );
}

void showHit(SDL_Rect d)
{
	d.x += 4;
	d.y += 4;
    SDL_BlitSurface( dot, NULL, screen, &d );
    SDL_Flip( screen );
	SDL_Delay( 4000 );
}

static void blituj(SDL_Surface* source, SDL_Surface* destination, SDL_Rect p)
{
	SDL_BlitSurface( source, NULL, destination, &p );
	SDL_Flip( destination );
	SDL_Delay( 10 );
}

int takeX(SDL_Rect p)
{
	SDL_Event event;
	int i, direction = 1;
	p.y=327;
	while (direction != 0)
	{
		if (direction == 1)
		{
			for(i=106;i<333;i++)
			{
				p.x=i;
				blituj(point_horiz, screen, p );			
				if (i == 332)
					direction = -1;					
				if( SDL_PollEvent( &event ) &&  event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
				{
						direction = 0;
						return p.x;
				}
			}
		}
		else if (direction == -1)
		{
			for(i=332;i>105;i--)
			{
				p.x=i;
				blituj(point_horiz, screen, p );				
				if (i == 106)
					direction = 1;				
				if( SDL_PollEvent( &event ) &&  event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
				{
						direction = 0;
						return p.x;
				}	
			}
		}
	}
}

int takeY(SDL_Rect pv)
{
	SDL_Event event;
	int i, direction = 1;
	pv.x=18;
	while (direction != 0)
	{
		if (direction == 1)
		{
			for(i=29;i<226;i++)
			{
				pv.y=i;
				blituj( point_vert, screen, pv);
				if (i == 225)
					direction = -1;		
				if( SDL_PollEvent( &event ) &&  event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
				{
						direction = 0;
						return pv.y;
				}
			}
		}
		else if (direction == -1)
		{
			for(i=225;i>28;i--)
			{
				pv.y=i;
				blituj( point_vert, screen, pv);
				if (i == 29)
					direction = 1;
				if( SDL_PollEvent( &event ) &&  event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
				{
						direction = 0;
						return pv.y;
				}
			}
		}
	}
}
	
void sdlQuit(void)
{
    SDL_Delay( 3000 );
    
    SDL_FreeSurface( target );
	SDL_FreeSurface( vertical );
	SDL_FreeSurface( horizontal );
	SDL_FreeSurface( point_vert );
	SDL_FreeSurface( point_horiz );
	SDL_FreeSurface( dot );
    
    SDL_Quit();
}


