#pragma once

#include "Form.h"
#include <ofMain.h>

class Sphere : public Form
{
public:

	Sphere(string p_nom, int _x, int _y, int _z, int _radius);
	Sphere();
	~Sphere();

	void SetDimension(int _x, int _y, int _z) { SetRadius(_x);   SetRadius(_y);  SetRadius(_z);}
	void SetRadius(int _radius);
	int GetRadius();

	int GetWidth() { GetRadius(); }
	int GetHeight() { GetRadius(); }
	int GetHeight() { GetRadius(); }

	void draw();
	void draw(ofColor _color);
	void drawWithTexture();

private:
	int radius;
};

