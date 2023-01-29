#include "Game.h"
#include "ExampleScene.h"
#include "ExampleGameSetting.h"

int main(int argc, char* argv[]) {
	Game::GetInstance()->mGameSetting = (GameSetting*) new ExampleGameSetting();
	Game::GetInstance()->mInitWindowName = "Example Game";
	Game::GetInstance()->mInitClearColor = { 1,1,1,1 };
	Game::GetInstance()->Start(argc, argv, new ExampleScene());
}