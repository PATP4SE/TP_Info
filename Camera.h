#pragma once

#include "ofMain.h"

class Camera
{
public:
	Camera();
	~Camera();
	void Zoom();

	void SetPosition(int _x, int _y, int _z);
	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);

	void draw();


private:
	ofEasyCam* camera;

};

