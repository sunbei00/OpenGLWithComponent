#include "TestObjectRender.h"
#include "HeaderHelper.h"


void TestObjectRender::OnRender()
{
	glColor3f(1, 0, 0);
	glutSolidCube(1);
}

TestObjectRender::TestObjectRender(GameObject * gameObject) : RenderComponent(gameObject)
{

}
