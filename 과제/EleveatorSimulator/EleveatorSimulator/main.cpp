#include <Windows.h>

#include "MainSystem.h"
#include "Macro.h"

int main() {
	MainSystem* mainSystem = new MainSystem();
	mainSystem->Initialize();
	while (true) {
		mainSystem->Update();
		mainSystem->Render();

		if(mainSystem->IsActive() == false)
			break;

	}
	SAFE_RELEASE(mainSystem);

	return 0;
}