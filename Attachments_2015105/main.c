//# include "gui_sdl.h"
# include "../player/src/player.h"
//# include "../score/src/score.h"


int main( int argc, char* args[] )
{

  /* setAndLoad();
    SDL_Rect h, t, p, pv, d;
    showStartImages(t, h);
    d.x = takeX(p);
    d.y = takeY(pv);
	showAnimation();
	showHit(d);*/
	PLAYER* pl;
	assignPlayerName(pl, "Sinisa");
	printf("%s\n", pl->name);
	//assignPlayerScore(pl, totalScore(printScore(d.x, d.y)));
	/*int skor = totalScore(printScore(d.x, d.y));
	showStartImages(t, h);
	d.x = takeX(p);
    d.y = takeY(pv);
	showHit(d);
	skor = totalScore(printScore(d.x, d.y));
	printf("%d \n", skor);
    sdlQuit();*/

    return 0; 
}
