#pragma once
#include <string>
#include <vector>
#include "Define.h"


class Transform;
class Component;

class GameObject
{
private:
	std::string mName;
	std::vector<Component*> mComponents;
	std::vector<GameObject*> mGameObjects;
public:
	Transform* mTransform;
	bool mIsActive = true;

	GameObject(std::string name);
	~GameObject();
	std::string GetName() const;
	bool AddComponent(Component* component);
	bool AddGameObject(GameObject* gameObject) ;
	Component* GetComponent(ComponentList componentList) const;
	GameObject* GetGameObject(std::string name) const;
	std::vector<GameObject*> GetGameObjects() const;
	void UpdateComponentWithChild();
	void FixedUpdateComponentWithChild();
	void StopComponentWithChild();
	void RenderComponentWithChild();
};

