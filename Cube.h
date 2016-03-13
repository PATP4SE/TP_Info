#pragma once

#include "Form.h"
#include "ofMain.h"

class Cube : public Form
{
public:
	Cube(string p_nom, int _x, int _y, int _z, int _height, int _width, int _depth);
	Cube();
	~Cube();

	void SetHeight(int _height);
	void SetWidth(int _width);
	void SetDepth(int _depth);
	void SetDimension(int _height, int _width, int _depth);

	int GetHeight();
	int GetWidth();
	int GetDepth();

	void draw(ofColor _color);
	void drawOnFaces();
	void drawOnCube();
	void draw();

private:
	int height;
	int width;
	int depth;

	ofMesh applyMesh(ofPoint _topLeft, ofPoint _topRight, ofPoint _bottomLeft, ofPoint _bottomRight);
};

