#include "BlueCubeMesh.h"

BlueCubeMesh::BlueCubeMesh(GameObject* gameObject) : RenderComponent(gameObject){}

void BlueCubeMesh::Update()
{
	gameObject->mTransform->mRotation.y += Time::getDeltaTime() * 500;
}

void BlueCubeMesh::OnRender()
{
	glColor3f(0, 0, 1);
	glutSolidCube(1);
}
