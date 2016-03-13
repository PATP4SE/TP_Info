#pragma once

#include "Primitive.h"
#include "ofMain.h"

class Triangle : public Primitive
{
public:
	Triangle(string p_nom, ofPoint _point1, ofPoint _point2, ofPoint _point3, int _lineWidth = 1);
	Triangle(string p_nom, int _positionX, int _positionY, int _positionZ, int _width, int _height, int _lineWidth = 1);
	Triangle();
	~Triangle();

	void SetPoint1(ofPoint _point);
	void SetPoint2(ofPoint _point);
	void SetPoint3(ofPoint _point);
	void SetPoints(ofPoint _point1, ofPoint _point2, ofPoint _point3);

	ofPoint GetPoint1();
	ofPoint GetPoint2();
	ofPoint GetPoint3();

	void draw(ofColor _color, bool fill = false);
	void draw(bool fill = false);

private:
	ofPoint point1;
	ofPoint point2;
	ofPoint point3;
};

