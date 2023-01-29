#pragma once
#include "HeaderHelper.h"

class BlueCubeMesh : RenderComponent
{
public:
	BlueCubeMesh(GameObject * gameObject);

	void Update() override;
	void OnRender() override;
};

