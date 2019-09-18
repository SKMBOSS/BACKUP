#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "cScene.h"
#include <fstream>
#include <string>

class cIntro : public cScene
{
private:
	std::string introText;
	std::ifstream inFile;
	bool bEnter = false;

public:
	cIntro();
	~cIntro();

	void Init();
	void OperateInput();
	void Update();
	void Render();
	void Release();

	inline void LoadIntroText()
	{
		std::getline(inFile, introText);
	}

	inline bool FileEnd()
	{
		return inFile.eof();
	}
};

