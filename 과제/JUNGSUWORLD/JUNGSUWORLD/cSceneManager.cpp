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
	pcScene = new cTitle; //ù��° ���� ��Ʈ�η�
	currentScene = TITLE;

	pcScene->Init(); //��ĳ���ù���
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
			pcScene->Release(); //���� �ı����ϱ����� �ش�� �Ҵ�����
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
		pcScene = new cIntro; //new �� ������ ���� �ѱ�� ������
		currentScene = INTRO;
		break;

	case MENU:
		pcScene = new cMenu;
		currentScene = MENU;
		break;

	case TOWNHALL:
		pcScene = new cTownHall; //new �� ������ ���� �ѱ�� ������ -> ü����;;
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