#pragma once
#include "RenderComponent.h"

class TestObjectRender : RenderComponent
{
public:
	void OnRender() override;
	TestObjectRender(GameObject* gameObject);
};

