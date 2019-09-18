#include "cPlayer.h"
#include <fstream>
#include <iostream>

cPlayer::cPlayer()
{
}

cPlayer::~cPlayer()
{
}

void cPlayer::SaveStatus()
{
	std::ofstream outFile("playerStatus.txt");
	
	outFile << playerX << " " << playerY << std::endl;
	outFile << playerName << std::endl;
	outFile << hp << " " << mp << " " << atk << " " << def << " " << exp<<std::endl;
}

void cPlayer::LoadStatus()
{
	std::ifstream inFile("playerStatus.txt");

	std::string sBuffer;

	inFile >> sBuffer;
	playerX = atoi(sBuffer.c_str());

	inFile >> sBuffer;
	playerY = atoi(sBuffer.c_str());

	inFile >> playerName;

	inFile >> sBuffer;
	hp = atoi(sBuffer.c_str());

	inFile >> sBuffer;
	mp = atoi(sBuffer.c_str());

	inFile >> sBuffer;
	atk = atoi(sBuffer.c_str());

	inFile >> sBuffer;
	def = atoi(sBuffer.c_str());

	inFile >> sBuffer;
	exp = atoi(sBuffer.c_str());
}
