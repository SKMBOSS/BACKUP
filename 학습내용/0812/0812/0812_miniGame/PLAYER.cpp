#include "PLAYER.h"

PLAYER::PLAYER()
{
	PosX = 0;
	PosY = 0;
}


PLAYER::~PLAYER()
{
}

void PLAYER::initPlayer()
{
	PosX = MAP_SIZE / 2;
	PosY = MAP_SIZE / 2;
}
