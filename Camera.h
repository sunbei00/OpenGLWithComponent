#pragma once
#include "Vector3.h"

class Camera
{
public:
	Vector3 mEye = {0,1,3};
	Vector3 mCenter = { 0,0,0 };
	Vector3 mUp = { 0,1,0 };
	double mNear = 0.1;
	double mFar = 50;
	int mAngle = 60;
};

