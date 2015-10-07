# include "score.h"
//# include <math.h>


static int delta(int a, int b)
{
	return abs(a - b);
}

static int kvadrat(int a)
{
	return a*a;
}

static double radius(int x, int y)
{
	return sqrt(kvadrat(delta(x,CENTAR_X)) + kvadrat(delta(y, CENTAR_Y)));
}

int printScore(int x, int y)
{
	if(radius(x, y) < RADIUS_FIVE)
		return FIVE;
	else if(radius(x, y) < RADIUS_FOUR)
		return FOUR;
	else if(radius(x, y) < RADIUS_THREE)
		return THREE;
	else if(radius(x, y) < RADIUS_TWO)
		return TWO;
	else if(radius(x, y) < RADIUS_ONE)
		return ONE;
	else
		return ZERO;
}

int totalScore(int score)
{
	tot_score += score;
	return tot_score;
}
