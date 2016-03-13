#pragma once

#include <ofMain.h>

class Light
{
public:
	Light(int _x, int _y, int _z);
	Light(int _x, int _y, int _z, ofColor _color);
	Light();
	~Light();

	int GetX();
	int GetY();
	int GetZ();

	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);

private:
	int x;
	int y;
	int z;
	ofColor color;
};

