# include "../../gui/src/gui_sdl.h"
//# include "../../player/src/player.h"
# include "../../score/src/score.h"

void intToString(int num, char points[])
{
	char sym[2];
	int i = 0, j = 0;
    if(num == 0)
    {
        points[0] = '0';
        points[1] = '\0';
    }
    else
    {
	    while(num)
	    {
		    sym[i] = (num % 10) + '0';
		    i++;
		    num /=10;
	    }
	    while(i>0)
	    {
		    points[j] = sym[i-1];
		    j++;
		    i--;
	    }
	    points[j] =  '\0';
    }
	
}

SDL_Rect shoot(SDL_Rect ta, SDL_Rect h, SDL_Rect po, SDL_Rect pv, SDL_Rect d )
{
    showStartImages(ta, h);
    d.x = takeX(po);
    d.y = takeY(pv);
	showHit(d);
	return d;
}

void result(PLAYER* pl, int skor, char p1[3],char t1[3], SDL_Rect d )
{
    skor = printScore(d.x, d.y);
    pl->score = totalScore(skor, pl->score);
    intToString(skor,p1);
	intToString(pl->score,t1);
}

int main( int argc, char* args[] )
{
    setAndLoad();
    SDL_Rect h;
	SDL_Rect ta;
	SDL_Rect po;
	SDL_Rect pv;
	SDL_Rect da;

    char p[3][3];
	char t[3][3];
	
    PLAYER* pl[3];
	int i;

	for (i = 0; i < 3; i++)
	{
		pl[i] = playerCreate();
	}
	
	assignPlayerName(pl[0], "Sinisa");
    assignPlayerName(pl[1], "Seka");
	assignPlayerName(pl[2], "Bojan");

	for (i = 0; i < 3; i++)
	{
		assignPlayerScore(pl[i], 0);
	}
    
    int skor = 0;
	int j;
	
	for (i = 0; i < 3; i++)
	{
		intToString(skor, p[i]);
		intToString(pl[i]->score, t[i]);
    }
    
	//printf("%s\n", pl->name);
	//printf("%d\n", pl1->score);
	//showAnimation();

	for (i = 0; i < 6; i++)
	{
		j = i % 3;
		da = shoot(ta, h, po, pv, da);
		result(pl[j], skor, p[j], t[j], da);
		printTable(pl, p, t);
		
	}
  
	
    sdlQuit();

    return 0; 
}
