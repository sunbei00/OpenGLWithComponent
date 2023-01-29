#pragma once
#include "Define.h"
#include <vector>
#include "Camera.h"

class GameObject;
class Component;

class Scene abstract
{
private:
	GameObject* mRoot;
protected:
	virtual ~Scene();
public:
	Camera mCamera;
	Scene();
	void AddGameObject(GameObject* gameObject);
	void Update();
	void FixedUpdate();
	void Stop();
	void Render();
};

