#include "player.h"

static int isQualityInBounds(uint8_t quality)
{
	return ((quality >= QUALITY_MIN) && (quality <= QUALITY_MAX));
}

PLAYER* playerCreate()
{
	return (PLAYER*) malloc( sizeof(PLAYER) );
}

void assignPlayerName(PLAYER* player, char* name)
{
    if(strlen(name) < 1)
    {
    	strcpy (player -> name, "Player");
    }
    else
    {
    	strncpy (player -> name, name, NAME_LENGTH_MAX);
    	player -> name[NAME_LENGTH_MAX-1] = '\0';
    }
}

void assignPlayerQuality(PLAYER* player, uint8_t quality)
{
	if (isQualityInBounds (quality))
	{
		player -> quality = quality;
	}
	else
	{
		player -> quality = 1;
	}
}

void assignPlayerScore(PLAYER* player, uint8_t score)
{
	
	player -> score = score;
	
}

void increaseQuality(PLAYER* player)
{
    player->quality = player->quality >= QUALITY_MAX ? QUALITY_MAX : player->quality + 1;
}

void decreaseQuality(PLAYER* player)
{
    player->quality = player->quality <= QUALITY_MIN ? QUALITY_MIN : player->quality - 1;
}

void playerDelete (PLAYER* player)
{
    free (player);
}
