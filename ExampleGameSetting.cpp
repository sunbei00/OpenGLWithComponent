#include "ExampleGameSetting.h"
#include "Game.h"
#include "ExampleScene2.h"

void ExampleGameSetting::InitSet()
{
	glutTimerFunc(1000, LoadExampleScene2,0);
}

void ExampleGameSetting::LoadExampleScene2(int)
{
	Game::GetInstance()->LoadScene(new ExampleScene2());
}

