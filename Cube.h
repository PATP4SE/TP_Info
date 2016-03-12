#pragma once

#include "Form.h"
#include "ofMain.h"

class Cube : public Form
{
public:
	Cube(int _x, int _y, int _z, int _height, int _width, int _depth);
	Cube();
	~Cube();

	void SetHeight(int _height);
	void SetWidth(int _width);
	void SetDepth(int _depth);
	void SetDimension(int _height, int _width, int _depth);

	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);

	int GetHeight();
	int GetWidth();
	int GetDepth();

	int GetX();
	int GetY();
	int GetZ();

	bool isSelected();
	void SetSelected(bool _selected);

	void draw(ofColor _color);
	void draw(ofImage * &_image);
	void draw();

private:
	int height;
	int width;
	int depth;
	int x;
	int y;
	int z;
	bool selected;

	ofMesh applyMesh(ofPoint _topLeft, ofPoint _topRight, ofPoint _bottomLeft, ofPoint _bottomRight, ofImage *_image);
};

