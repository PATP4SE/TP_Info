#pragma once

#include "Triangle.h"

Triangle::Triangle(ofPoint _point1, ofPoint _point2, ofPoint _point3, int _lineWidth = 1):
	Primitive((_point1.x + _point2.x + _point3.x) / 3, (_point1.y + _point2.y + _point3.y) / 3, (_point1.z + _point2.z + _point3.z) / 3, _lineWidth)
{
	this->point1 = _point1;
	this->point2 = _point2;
	this->point3 = _point3;
}

Triangle::Triangle(int _positionX, int _positionY, int _positionZ, int _width, int _height, int _lineWidth = 1): 
	Primitive(_positionX, _positionY, _positionZ, _lineWidth)
{
	this->point1 = ofPoint(_positionX - (_width/2), _positionY, _positionZ);
	this->point2 = ofPoint(_positionX + (_width / 2), _positionY, _positionZ);
	this->point3 = ofPoint(_positionX, _positionY - (_width / 2), _positionZ);
}

void Triangle::draw(bool fill = false)
{
	this->draw(ofColor::black, fill);
}

void Triangle::draw(ofColor _color, bool fill = false)
{
	ofSetColor(_color);
	if (fill)
		ofFill();
	else
		ofNoFill();
	ofDrawTriangle(this->point1, this->point2, this->point3);
}

void Triangle::SetPoint1(ofPoint _point)
{
	this->point1 = _point;
}

void Triangle::SetPoint2(ofPoint _point)
{
	this->point1 = _point;
}

void Triangle::SetPoint3(ofPoint _point)
{
	this->point1 = _point;
}

void Triangle::SetPoints(ofPoint _point1, ofPoint _point2, ofPoint _point3)
{
	this->point1 = _point1;
	this->point2 = _point2;
	this->point3 = _point3;
}

ofPoint Triangle::GetPoint1()
{
	return this->point1;
}

ofPoint Triangle::GetPoint2()
{
	return this->point2;
}

ofPoint Triangle::GetPoint3()
{
	return this->point3;
}


