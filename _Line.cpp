#include "_Line.h"



_Line::_Line(string p_nom, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _lineWidth): Primitive(p_nom, _x1, _y1, _z1, _lineWidth)
{
	this->point1 = ofPoint(_x1, _y1, _z1);
	this->point2 = ofPoint(_x2, _y2, _z2);
}

_Line::_Line(string p_nom, ofPoint _point1, ofPoint _point2, int _lineWidth): Primitive(p_nom, _point1.x, _point1.y, _point1.z, _lineWidth)
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
	ofPushMatrix();
	ofTranslate(this->x, this->y, this->z);
	ofRotateX(this->xRotation);
	ofRotateY(this->yRotation);
	ofRotateZ(this->zRotation);
	
	int oldWidth = GetLineWidth();
	ofSetLineWidth(this->lineWidth);
	ofSetColor(_color);

	int x = this->point2.x - this->point1.x;
	int y = this->point2.y - this->point1.y;
	int z = this->point2.z - this->point1.z;
	ofDrawLine(ofPoint(0,0,0), ofPoint(x,y,z));
	
	if (this->selected)
		ofSetColor(ofColor::red);
	else
		ofSetColor(ofColor::blue);
	ofDrawSphere(0, 0, 0, 3);
	ofDrawSphere(x, y, z, 3);

	ofSetLineWidth(oldWidth);
	ofPopMatrix();
}

