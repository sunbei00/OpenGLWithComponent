#include "ExampleScene2.h"
#include "HeaderHelper.h"
#include "BlueCubeMesh.h"

ExampleScene2::ExampleScene2() {
	GameObject* go = new GameObject("BlueCube");
	new BlueCubeMesh(go);
	AddGameObject(go);
}
