#pragma once

#include "Triangle.h"

Triangle::Triangle(string p_nom, ofPoint _point1, ofPoint _point2, ofPoint _point3, int _lineWidth):
	Primitive(p_nom, (_point1.x + _point2.x + _point3.x) / 3, (_point1.y + _point2.y + _point3.y) / 3, (_point1.z + _point2.z + _point3.z) / 3, _lineWidth)
{
	this->point1 = _point1;
	this->point2 = _point2;
	this->point3 = _point3;
}

Triangle::Triangle(string p_nom, int _positionX, int _positionY, int _positionZ, int _width, int _height, int _lineWidth): 
	Primitive(p_nom, _positionX, _positionY, _positionZ, _lineWidth)
{
	this->point1 = ofPoint(_positionX - (_width/2), _positionY, _positionZ);
	this->point2 = ofPoint(_positionX + (_width / 2), _positionY, _positionZ);
	this->point3 = ofPoint(_positionX, _positionY - (_width / 2), _positionZ);
}

void Triangle::draw(bool fill)
{
	this->draw(ofColor::black, fill);
}

void Triangle::draw(ofColor _color, bool fill)
{
	ofPushMatrix();
	ofTranslate(this->point1.x, this->point1.y, this->point1.z);
	ofRotateX(this->xRotation);
	ofRotateY(this->yRotation);
	ofRotateZ(this->zRotation);

	int x2 = this->point2.x - this->point1.x;
	int y2 = this->point2.y - this->point1.y;
	int z2 = this->point2.z - this->point1.z;

	int x3 = this->point3.x - this->point1.x;
	int y3 = this->point3.y - this->point1.y;
	int z3 = this->point3.z - this->point1.z;

	ofSetLineWidth(this->lineWidth);
	ofSetColor(_color);
	if (fill)
		ofFill();
	else
		ofNoFill();
	ofDrawTriangle(ofPoint(0,0,0), ofPoint(x2,y2,z2), ofPoint(x3, y3, z3));
	ofPopMatrix();
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


