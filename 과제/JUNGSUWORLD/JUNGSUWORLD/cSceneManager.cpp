#include "cSceneManager.h"

cSceneManager* cSceneManager::cSceneManagerInstance = nullptr;

cSceneManager::cSceneManager()
{
}

cSceneManager::~cSceneManager()
{
}

void cSceneManager::Init()
{
	bSceneChange = false;
	bGameEnd = false;
	pcScene = new cTitle; //첫번째 씬을 인트로로
	currentScene = TITLE;

	pcScene->Init(); //업캐스팅배운거
}

void cSceneManager::OperateInput()
{
	pcScene->OperateInput();
}

cSceneManager* cSceneManager::GetInstance()
{
	if (cSceneManagerInstance == nullptr)
	{
		cSceneManagerInstance = new cSceneManager;
	}
	return cSceneManagerInstance;
}

void cSceneManager::ReleaseInstance()
{
	if (cSceneManagerInstance != nullptr)
	{
		if (pcScene != nullptr)
		{
			pcScene->Release(); //씬이 파괴당하기전에 해당씬 할당해제
			delete pcScene;
			pcScene = nullptr;
		}
		delete cSceneManagerInstance;
		cSceneManagerInstance = nullptr;
	}
}

void cSceneManager::SceneChange(SCENE_STATE state)
{
	if (pcScene != nullptr)
	{
		pcScene->Release();
		delete pcScene;
		pcScene = nullptr;
	}

	switch (state)
	{
	case INTRO:
		pcScene = new cIntro; //new 로 받으면 상태 넘기기 귀찮음
		currentScene = INTRO;
		break;

	case MENU:
		pcScene = new cMenu;
		currentScene = MENU;
		break;

	case TOWNHALL:
		pcScene = new cTownHall; //new 로 받으면 상태 넘기기 귀찮음 -> 체험중;;
		if (currentScene == MENU)
		{
			SetCallMenu();
		}
		currentScene = TOWNHALL;
		break;
	}
	pcScene->Init();
	bSceneChange = false;
}

void cSceneManager::Update()
{
	pcScene->Update();
}

void cSceneManager::Render()
{
	pcScene->Render();
}