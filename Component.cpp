#include "Component.h"
#include "GameObject.h"
#include <stdio.h>

Component::Component(ComponentList familyID, GameObject* gameObject) : FamilyID(familyID), gameObject(gameObject) {
	gameObject->AddComponent(this);
}
void Component::Update() {}
void Component::FixedUpdate() {}
void Component::Start() {}
void Component::Stop() {}
ComponentList Component::getFamilyID() { return FamilyID; }