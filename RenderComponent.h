#pragma once
#include "Component.h"

class RenderComponent : public Component
{
private:
	void Render();
	friend class GameObject;
public:
	RenderComponent(GameObject* gameObject);
	
	virtual void OnRender() = 0;

};

