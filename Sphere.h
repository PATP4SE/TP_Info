#pragma once

#include "Form.h"

class Sphere : public Form
{
public:
	Sphere();
	~Sphere();
private:
	int radius;
	int x;
	int y;
	int z;
};

