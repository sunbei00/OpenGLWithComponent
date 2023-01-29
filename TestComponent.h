#pragma once
#include "CustomComponent.h"

class TestComponent : public CustomComponent
{
public:
	TestComponent(GameObject* gameObject);
	void Update() override;
	void Start() override;
	void FixedUpdate() override;
	void Stop() override;
};

