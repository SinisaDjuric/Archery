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
	PLAYER* pl;
	//assignPlayerName(pl, "Sinisa");
	//assignPlayerScore(pl, totalScore(printScore(d.x, d.y)));
	int skor = totalScore(printScore(d.x, d.y));
	showStartImages(ta, h);
	d.x = takeX(po);
    d.y = takeY(pv);
	showHit(d);
	skor = totalScore(printScore(d.x, d.y));
	printf("%d \n", skor);
	char p1[3], t1[3];
	intToString(4,p1);
	intToString(12,t1);
	printTable("Bojan", 1, p1, t1 );
	printTable("Sinisa", 2, "5", "17" );
    sdlQuit();

    return 0; 
}
