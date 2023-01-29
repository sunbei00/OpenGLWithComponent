#include "GameObject.h"
#include "Component.h"
#include "RenderComponent.h"
#include "Transform.h"
#include <GL/freeglut.h>
#include <stdio.h>

GameObject::GameObject(std::string name) : mName(name) {
	mTransform = new Transform(this);
	
}

GameObject::~GameObject() {
	for (Component* comp : mComponents) {
		delete comp;
	}
	for (GameObject* go : mGameObjects) {
		delete go;
	}
}
bool GameObject::AddComponent(Component* component) {
	if (component == nullptr)
		return false;

	if (component->getFamilyID() != ComponentList::CUSTOM && GetComponent(component->getFamilyID()) != nullptr) {
		delete component;
		return false;
	}
	mComponents.push_back(component);
	return true;
}

Component* GameObject::GetComponent(ComponentList componentList) const {
	for (Component* comp : mComponents) {
		if (comp->getFamilyID() == componentList)
			return comp;
	}
	return nullptr;
}

bool GameObject::AddGameObject(GameObject* gameObject) {
	if (gameObject == nullptr)
		return false;

	mGameObjects.push_back(gameObject);
	return true;

}
GameObject* GameObject::GetGameObject(std::string name) const {
	for (GameObject* go : mGameObjects) {
		if (go->GetName() == name || go->GetGameObject(name) != nullptr)
			return go;
	}
	return nullptr;
}
void GameObject::UpdateComponentWithChild()
{
	if (mIsActive == false)
		return;
	for (Component* comp : mComponents) {
		comp->Update();
	}
	for (GameObject* go : mGameObjects) {
		go->UpdateComponentWithChild();
	}
}

void GameObject::FixedUpdateComponentWithChild() {
	if (mIsActive == false)
		return;
	for (Component* comp : mComponents) {
		comp->FixedUpdate();
	}
	for (GameObject* go : mGameObjects) {
		go->FixedUpdateComponentWithChild();
	}
}
void GameObject::StopComponentWithChild() {
	for (Component* comp : mComponents) {
		comp->Stop();
	}
	for (GameObject* go : mGameObjects) {
		go->StopComponentWithChild();
	}
}
void GameObject::RenderComponentWithChild() {
	glPushMatrix();
		glTranslatef(mTransform->mPosition.x, mTransform->mPosition.y, mTransform->mPosition.z );
		glRotatef(mTransform->mRotation.z,0,0,1);
		glRotatef(mTransform->mRotation.y,0,1,0);
		glRotatef(mTransform->mRotation.x,1,0,0);
		glScalef(mTransform->mScale.x, mTransform->mScale.y, mTransform->mScale.z);
		for (Component* comp : mComponents) 
			if (comp->getFamilyID() == ComponentList::RENDER) 
				((RenderComponent*)comp)->Render();
		for (GameObject* go : mGameObjects)
			go->RenderComponentWithChild();
	glPopMatrix();
}

std::vector<GameObject*> GameObject::GetGameObjects() const {
	return mGameObjects;
}


std::string GameObject::GetName() const
{
	return mName;
}


