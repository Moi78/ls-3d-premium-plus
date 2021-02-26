#include <iostream>
#include <memory>
#include <stddef.h>
#include <cstring>

#include <EXP_Game.h>

//Enabling Optimus
#ifdef _WIN32
extern "C" { _declspec(dllexport) uint32_t NvOptimusEnablement = 0x00000001; }
#else
extern "C" { uint32_t NvOptimusEnablement = 0x00000001; }
#endif //_WIN32

int main(int argc, char* argv[]) {
	const char* c = argv[0];
	const size_t s = strlen(c);
	std::string exePath;
	for(int i = 0; i < (s - 18); i++) {
		exePath += argv[0][i];
	}

	EXP_GameInfo info{};
	info.RootGameContentFolder = exePath + std::string("Content");
	info.RootEngineContentFolder = exePath + std::string("Engine");
	info.GameLib = exePath + std::string("libls-3d-premium-plus.so");
	info.RenderingPipeline = Pipeline::PBR_ENGINE;
	info.GameName = "ls 3D Premium Plus";
	info.StartupMap = "/maps/explorer.json";

	std::unique_ptr<EXP_Game> game = std::make_unique<EXP_Game>(info, vec3f(0.0f, 0.0f, 0.0f));

	while (!game->GetRenderer()->WantToClose()) {
		if (game->CheckErrors()) {
			exit(-1);
		}

		game->RenderScene();
		game->ExecCallbacks();

		game->UpdatePhysics();
		game->UpdateSound();

		game->EndFrame();
	}

	return 0;
}
