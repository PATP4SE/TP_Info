#pragma once

#include "Form.h"
#include <ofMain.h>

class Sphere : public Form
{
public:

	Sphere(int _x, int _y, int _z, int _radius);
	Sphere();
	~Sphere();

	void SetRadius(int _raidus);
	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);

	int GetRadius();
	int GetX();
	int GetY();
	int GetZ();

	void draw();
	void draw(ofColor _color);
	void draw(ofImage * & _image);

private:
	int radius;
	int x;
	int y;
	int z;
};

