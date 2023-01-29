#include "TestComponent.h"
#include "HeaderHelper.h"


void TestComponent::Update()
{
	printf("Delta Time : %f\n",Time::getDeltaTime()); 
	gameObject->mTransform->mRotation.y += Time::getDeltaTime() * 100;
}

void TestComponent::Start()
{
	printf("start\n");
	throw new std::exception("test");
}

void TestComponent::FixedUpdate()
{
	printf("fixed update\n");
}

void TestComponent::Stop()
{
	printf("stop");
}

TestComponent::TestComponent(GameObject* gameObject) : CustomComponent(gameObject){}