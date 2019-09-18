#pragma once
#include "cScene.h"
#include "cTitle.h"
#include "cIntro.h"
#include "cMenu.h"
#include "cTownHall.h"

enum SCENE_STATE
{
	TITLE,
	INTRO,
	TOWNHALL,
	MENU
};

class cSceneManager
{
private:
	cSceneManager();

	static cSceneManager* cSceneManagerInstance; //¾À¸Å´ÏÁ® ½Ì±ÛÅæÀ» À§ÇÑ Å¬·¡½º Æ÷ÀÎÅÍ º¯¼ö
	cScene* pcScene;
	SCENE_STATE nextScene; //´ÙÀ½ ¾À
	SCENE_STATE currentScene; //ÇöÀç ¾À
	bool bSceneChange; //¾À º¯°æ À¯¹«
	bool bGameEnd; 

public:
	~cSceneManager();
	static cSceneManager* GetInstance();
	void Init();
	void ReleaseInstance();
	void SceneChange(SCENE_STATE state);
	void OperateInput();
	void Update();
	void Render();

	inline bool GetCallMenu()
	{
		return pcScene->bCallMenu;
	}

	inline void SetCallMenu()
	{
		pcScene->bCallMenu = true;
	}

	inline bool GetSceneEnd()
	{
		return pcScene->bSceneEnd;
	}

	inline bool GetSceneLoad()
	{
		return pcScene->bSceneLoad;
	}

	inline void SetSceneLoad()
	{
		pcScene->bSceneLoad = false;
	}

	inline void SetNextScene(SCENE_STATE state)
	{
		nextScene = state;
		bSceneChange = true;
	}

	inline SCENE_STATE GetNextScene()
	{
		return nextScene;
	}

	inline SCENE_STATE GetCurrentScene()
	{
		return currentScene;
	}

	inline bool GetSceneChange()
	{
		return bSceneChange;
	}

	inline void SetGameEnd(bool bEnd)
	{
		bGameEnd = bEnd;
	}

	inline bool GetGameEnd()
	{
		return bGameEnd;
	}


};

