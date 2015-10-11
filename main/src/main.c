# include "../../gui/src/gui_sdl.h"
# include "../../player/src/player.h"
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
	//return points;
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
    SDL_Rect h, ta, po, pv, da;
    char p1[3], t1[3], p2[3], t2[3];
    PLAYER* pl = playerCreate();
    PLAYER* pl1 = playerCreate();
	assignPlayerName(pl, "Sinisa");
    assignPlayerName(pl1, "Seka");

    assignPlayerScore(pl, 0);
    assignPlayerScore(pl1, 0);
    int skor = 0, skor1 = 0;
    intToString(skor,p1);
	intToString(pl1->score,t1);
    intToString(skor1,p2);
	intToString(pl1->score,t2);
    
	//printf("%s\n", pl->name);
	//printf("%d\n", pl1->score);
	//showAnimation();

    da = shoot(ta, h, po, pv, da);
    result(pl, skor, p1, t1, da);
    printTable(pl->name, p1, t1, "Bojan", "5", "17", pl1->name, p2, t2);

    da = shoot(ta, h, po, pv, da);
    result(pl1, skor1, p2, t2, da);
    printTable(pl->name, p1, t1, "Bojan", "5", "17", pl1->name, p2, t2);

    da = shoot(ta, h, po, pv, da);
    result(pl1, skor1, p2, t2, da);
    printTable(pl->name, p1, t1, "Bojan", "5", "17", pl1->name, p2, t2);
	
    sdlQuit();

    return 0; 
}
