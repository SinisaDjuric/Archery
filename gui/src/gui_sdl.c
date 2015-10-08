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
	screen1 = NULL;
	arrow = NULL;
	hit = NULL;
	tabele = NULL;
	white_target = NULL;
	
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HIGHT, BPP, SDL_SWSURFACE );
	//screen1 = SDL_SetVideoMode( 1080, 640, BPP, SDL_SWSURFACE );
	//SDL_FillRect(screen1, NULL, 0xFFFFFF);

	target = SDL_LoadBMP( "resources/target1.bmp" );
	vertical = SDL_LoadBMP( "resources/vertikala.bmp" );
	horizontal = SDL_LoadBMP( "resources/horizontala.bmp" );
	point_vert = SDL_LoadBMP( "resources/point_vertical.bmp" );
	point_horiz = SDL_LoadBMP( "resources/point.bmp" );
	dot = SDL_LoadBMP( "resources/green_dot.bmp" );
	arrow = SDL_LoadBMP( "resources/arrow.bmp" );
	hit = SDL_LoadBMP( "resources/hit.bmp" );
	tabele = SDL_LoadBMP( "resources/tabela.bmp" );
	white_target = SDL_LoadBMP( "resources/meta.bmp" );
}
/*
void showAnimation(void)
{
	SDL_Rect p[10] ={0, 0};
	SDL_Rect wt;
	wt.x = 650;
	wt.y = 50;
	
	SDL_Surface* arrow[10];
	arrow[0] = SDL_LoadBMP( "resources/1.bmp" );
	arrow[1] = SDL_LoadBMP( "resources/2.bmp" );
	arrow[2] = SDL_LoadBMP( "resources/3.bmp" );
	arrow[3] = SDL_LoadBMP( "resources/4.bmp" );
	arrow[4] = SDL_LoadBMP( "resources/5.bmp" );
	arrow[5] = SDL_LoadBMP( "resources/6.bmp" );
	arrow[6] = SDL_LoadBMP( "resources/7.bmp" );
	arrow[7] = SDL_LoadBMP( "resources/8.bmp" );
	arrow[8] = SDL_LoadBMP( "resources/9.bmp" );
	arrow[9] = SDL_LoadBMP( "resources/10.bmp" );
	int i;
	SDL_FillRect(screen1, NULL, 0xFFFFFF);
	SDL_BlitSurface( white_target, NULL, screen1, &wt );
	SDL_Flip( screen1 );
	SDL_Delay( 3000 );
	for(i=1;i<11;i++)
	{
		p[i].x = 50*i;
		p[i].y = 3*i;
		SDL_FillRect(screen1, NULL, 0xFFFFFF);
		SDL_BlitSurface( white_target, NULL, screen1, &wt );
		SDL_BlitSurface( arrow[i-1], NULL, screen1, &p[i] );

		SDL_Flip( screen1 );
		SDL_Delay( 500 );
	}
	SDL_BlitSurface( hit, NULL, screen1, NULL );

	SDL_Flip( screen1 );
	SDL_Delay( 2000 );


	SDL_FreeSurface( hit );
	SDL_FreeSurface( white_target );
	for(i=1;i<11;i++)
	{
	SDL_FreeSurface( arrow[i-1] );
	}
	//SDL_FreeSurface( screen1 );
	
}*/

void printTable(char ime[], int x, int y)
{
	SDL_Surface* message = NULL;
	
	TTF_Font *font = NULL; 
	
	SDL_Color textColor = { 255, 255, 255 };
	TTF_Init();
	 
	font = TTF_OpenFont( "resources/open-sans/OpenSans-Light.ttf", 28 );
	 
	message = TTF_RenderText_Solid( font, "Player", textColor );

	SDL_Rect offset; 
	offset.x = x; 
	offset.y = y; 
    SDL_Rect t;
    t.x = 400;
    t.y = 50;
	SDL_BlitSurface( tabele, NULL, screen, &t );
	SDL_BlitSurface( message, NULL, screen, &offset );
	SDL_Flip( screen );
	SDL_Delay( 5000 );

	SDL_FreeSurface( message ); 
	
	TTF_CloseFont( font ); 
	
	TTF_Quit(); 
	
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


