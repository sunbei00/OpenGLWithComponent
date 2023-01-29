#pragma once
#include <string>
#include "Define.h"

class GameObject;

class Component abstract
{
private:
	ComponentList FamilyID;
	bool isStart = false;
public:
	GameObject* gameObject;
	Component(ComponentList familyID, GameObject* gameObject);
	Component() = delete;
	virtual void Update();
	virtual void FixedUpdate();
	virtual void Start();
	virtual void Stop();
	ComponentList getFamilyID();
};

