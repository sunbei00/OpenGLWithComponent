#pragma once
#include "Component.h"
#include "Vector3.h"

class Transform : public Component
{
public:
	Vector3 mPosition = {0,0,0};
	Vector3 mRotation = {0,0,0};
	Vector3 mScale = {1,1,1};

	Transform(GameObject* gameObject);
};

