#include "_Line.h"



_Line::_Line(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _lineWidth): Primitive(_x1, _y1, _z1, _lineWidth)
{
	this->point1 = ofPoint(_x1, _y1, _z1);
	this->point2 = ofPoint(_x2, _y2, _z2);
}

_Line::_Line(ofPoint _point1, ofPoint _point2, int _lineWidth): Primitive(_point1.x, _point1.y, _point1.z, _lineWidth)
{
	this->point1 = _point1;
	this->point2 = _point2;
}

_Line::_Line()
{
	this->point1 = ofPoint(0, 0, 0);
	this->point2 = ofPoint(0, 0, 0);
}

_Line::~_Line()
{
}

void _Line::draw()
{
	this->draw(ofColor::black);
}

void _Line::draw(ofColor _color)
{
	ofSetLineWidth(this->lineWidth);
	ofSetColor(_color);
	ofDrawLine(this->point1, this->point2);
}

