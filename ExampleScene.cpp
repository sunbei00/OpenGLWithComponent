#include "ExampleScene.h"
#include "GameObject.h"
#include "TestComponent.h"
#include "TestObjectRender.h"

ExampleScene::ExampleScene() {
	InitScene();
}

void ExampleScene::InitScene() {
	GameObject* go = new GameObject("TEST01");
	GameObject* go2 = new GameObject("TEST02");
	new TestComponent(go2);
	new TestObjectRender(go2);
	go->AddGameObject(go2);
	AddGameObject(go);
}

