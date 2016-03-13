#pragma once

#include "Form.h"
#include <ofMain.h>

class Sphere : public Form
{
public:

	Sphere(string p_nom, int _x, int _y, int _z, int _radius);
	Sphere();
	~Sphere();

	void SetRadius(int _raidus);
	int GetRadius();

	void draw();
	void draw(ofColor _color);
	void drawWithTexture();

private:
	int radius;
};

