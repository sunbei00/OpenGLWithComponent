#include "Game.h"
#include "GameObject.h"
#include "Scene.h"
#include "ExampleScene.h"
#include "ExampleScene2.h"
#include "Time.h"
#include "GameSetting.h"


void Game::DisplayFunc() {
	Camera* camera = &GetInstance()->mScene->mCamera;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	// 카메라로 Wrapping하기.
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera->mEye.x , camera->mEye.y, camera->mEye.z,
		camera->mCenter.x, camera->mCenter.z, camera->mCenter.z,
		camera->mUp.x, camera->mUp.y, camera->mUp.z);

	GetInstance()->mScene->Render();

	glutSwapBuffers();
}

void Game::LoadScene(Scene* scene)
{
	mScene->Stop();
	mScene = scene;
}

void Game::reshapeFunc(int x, int y) {
	Camera* camera = & GetInstance()->mScene->mCamera;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(camera->mAngle, (double)x/y, camera->mNear, camera->mFar);
	glViewport(0, 0, x, y);
}

void Game::UpdateFunc()
{
	Time::GetInstance()->setTime();
	GetInstance()->mScene->Update();
	glutPostRedisplay();
}

void Game::TimerUpdateFunc(int)
{
	UpdateFunc();
	glutTimerFunc(1, TimerUpdateFunc, 0);
}

void Game::FixedUpdateFunc(int) {
	while(Time::GetInstance()->isFixedTime())
		GetInstance()->mScene->FixedUpdate();
	glutTimerFunc(1, FixedUpdateFunc, 0);
}
Game::Game() : mScene(nullptr){}

void Game::Start(int argc, char** argv, Scene* scene) {
	mScene = scene;
	glutInit(&argc, argv);

	glutInitDisplayMode(mInitDisplayMode | GLUT_DOUBLE);
	glutInitWindowPosition(mInitWindowPoint.x, mInitWindowPoint.y);
	glutInitWindowSize(mInitWindowSize.x, mInitWindowSize.y);

	glutCreateWindow(mInitWindowName.c_str());

	glClearColor(mInitClearColor.r, mInitClearColor.g, mInitClearColor.b, mInitClearColor.a);

	if (mGameSetting != nullptr)
		mGameSetting->InitSet();

	glutDisplayFunc(DisplayFunc);
	glutReshapeFunc(reshapeFunc);
	//glutIdleFunc(UpdateFunc);
	glutTimerFunc(1, TimerUpdateFunc, 0);
	glutTimerFunc(1, FixedUpdateFunc, 0);

	glutMainLoop();
}

Game* Game::GetInstance()
{
	if (mInstance == nullptr)
		mInstance = new Game();
	return mInstance;
}

Game* Game::mInstance = nullptr;
