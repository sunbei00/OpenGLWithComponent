#pragma once


typedef struct {
	int x;
	int y;
} Point2i;

typedef struct {
	float r;
	float g;
	float b;
	float a;
} RGB4f;


enum class ComponentList {
	CUSTOM,
	TRANSFORM,
	RENDER
};

