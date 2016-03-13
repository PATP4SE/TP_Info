#pragma once

#include "Primitive.h"
#include "ofMain.h"

class _Line : public Primitive
{
public:
	_Line(string p_nom, ofPoint _point1, ofPoint _point2, int _lineWidth = 1);
	_Line(string p_nom, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _lineWidth = 1);
	_Line();
	~_Line();

	void draw();
	void draw(ofColor _color);
	void SetDimension(int _x, int _y, int _z) 
	{
		this->point1.x *= _x;
		this->point1.y *= _y;
		this->point1.z *= _z;
		this->point2.x *= _x;
		this->point2.y *= _y;
		this->point2.z *= _z;
	}
private:
	ofPoint point1;
	ofPoint point2;
};

