# include "../../gui/src/gui_sdl.h"
# include "../../player/src/player.h"
# include "../../score/src/score.h"

void intToString(int num, char points[])
{
	char sym[2];
	int i = 0, j = 0;
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
	//return points;
}


int main( int argc, char* args[] )
{
    setAndLoad();
    SDL_Rect h, ta, po, pv, d;
    showStartImages(ta, h);
    d.x = takeX(po);
    d.y = takeY(pv);
	showHit(d);
	//showAnimation();
	PLAYER* pl = playerCreate();
	assignPlayerName(pl, "Sinisa");
	//assignPlayerScore(pl, totalScore(printScore(d.x, d.y)));
	//printf("%s\t%d \n", pl->name, pl->score);
	printf("%s\n", pl->name);
	assignPlayerScore(pl, totalScore(printScore(d.x, d.y)));
	//int skor = totalScore(printScore(d.x, d.y));
	showStartImages(ta, h);
	d.x = takeX(po);
    d.y = takeY(pv);
	showHit(d);
	assignPlayerScore(pl, totalScore(printScore(d.x, d.y)));
	//skor = totalScore(printScore(d.x, d.y));
	printf("%d \n", pl->score);
	char p1[3], t1[3];
	intToString(pl->score,p1);
	intToString(pl->score+10,t1);
	printTable(pl->name, p1, t1, "Bojan", "5", "17", "Asim", "5", "17" );
	
   sdlQuit();

    return 0; 
}
