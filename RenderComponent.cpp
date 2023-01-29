#include "RenderComponent.h"
#include "Define.h"

void RenderComponent::Render()
{
	OnRender();
}

RenderComponent::RenderComponent(GameObject* gameObject) : Component(ComponentList::RENDER, gameObject){}
