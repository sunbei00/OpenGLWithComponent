#include "Scene.h"
#include "Component.h"
#include "GameObject.h"
#include <stdio.h>

Scene::Scene()  {
	mRoot = new GameObject("@ROOT");
}

Scene::~Scene()
{
	delete mRoot;
}

void Scene::AddGameObject(GameObject* gameObject) { 
	if (gameObject == nullptr)
		return;
	mRoot->AddGameObject(gameObject);
}
void Scene::Update() {
	mRoot->UpdateComponentWithChild();
}
void Scene::Render()
{
	mRoot->RenderComponentWithChild();
}
void Scene::FixedUpdate() {
	mRoot->FixedUpdateComponentWithChild();
}
void Scene::Stop() {
	mRoot->StopComponentWithChild();
	delete this;
}