#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "cSceneManager.h"

using namespace std;
const int FPS = 60;
int main()
{
	cSceneManager *sceneManager;

	sceneManager = cSceneManager::GetInstance();

	sceneManager->Init();

	while (true)
	{
		sceneManager->OperateInput();

		if (sceneManager->GetSceneEnd())
		{
			if (sceneManager->GetCurrentScene() == TITLE)
			{
				if (sceneManager->GetSceneLoad())
					sceneManager->SetNextScene(MENU);

				else
					sceneManager->SetNextScene(INTRO);
			}
			else if (sceneManager->GetCurrentScene() == INTRO)
			{
					sceneManager->SetNextScene(TOWNHALL);
					
			}

			else if (sceneManager->GetCurrentScene() == TOWNHALL)
			{
				if(sceneManager->GetCallMenu())
					sceneManager->SetNextScene(MENU);
			}

			else if (sceneManager->GetCurrentScene() == MENU)
			{
					sceneManager->SetNextScene(TOWNHALL);
			}
		}

		sceneManager->Update();
		sceneManager->Render();

		if (sceneManager->GetSceneChange())
		{
			sceneManager->SceneChange(sceneManager->GetNextScene());
		}
		Sleep(1000 / FPS);
	}
	

	system("pause");
	return 0;
}