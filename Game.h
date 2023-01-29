#pragma once
#include <GL/freeglut.h>
#include <string>
#include <vector>
#include "Define.h"

class Scene;
class GameObject;
class Component;
class GameSetting;

class Game 
{
protected:
	Scene* mScene;
	static Game* mInstance;
	Game();
	static void DisplayFunc();
	static void UpdateFunc();
	static void reshapeFunc(int,int);
	static void TimerUpdateFunc(int);
	static void FixedUpdateFunc(int);

public:
	GameSetting* mGameSetting = nullptr;
	Point2i mInitWindowPoint = {0,0};
	Point2i mInitWindowSize = { 1920,1080 };
	GLuint mInitDisplayMode = GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH;
	std::string mInitWindowName = "Game";
	RGB4f mInitClearColor = { 0,0,0,0 };
	void LoadScene(Scene* scene);

	void Start(int argc, char** argv, Scene* scene);
	static Game* GetInstance();
};


