#include "Cube.h"



Cube::Cube(int _x, int _y, int _z, int _height, int _width, int _depth)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->height = _height;
	this->width = _width;
	this->depth = _depth;
}

Cube::Cube()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->height = 0;
	this->width = 0;
	this->depth = 0;
}


Cube::~Cube()
{
}

//Dessine à partir du centre du cube
void Cube::draw()
{
	int left = this->x - (this->width / 2);
	int right = this->x + (this->width / 2);
	int top = this->y + (this->height / 2);
	int bottom = this->y - (this->height / 2);
	int front = this->z - (this->depth / 2);
	int back = this->z + (this->depth / 2);

	ofPoint topFrontLeft = ofPoint(left, top, front);
	ofPoint topFrontRight = ofPoint(right, top, front);
	ofPoint bottomFrontLeft = ofPoint(left, bottom, front);
	ofPoint bottomFrontRight = ofPoint(right, bottom, front);

	ofPoint topBackLeft = ofPoint(left, top, back);
	ofPoint topBackRight = ofPoint(right, top, back);
	ofPoint bottomBackLeft = ofPoint(left, bottom, back);
	ofPoint bottomBackRight = ofPoint(right, bottom, back);

	ofDrawSphere(topFrontLeft, 10);
	ofDrawSphere(topFrontRight, 10);
	ofDrawSphere(bottomFrontLeft, 10);
	ofDrawSphere(bottomFrontRight, 10);

	ofDrawSphere(topBackLeft, 10);
	ofDrawSphere(topBackRight, 10);
	ofDrawSphere(bottomBackLeft, 10);
	ofDrawSphere(bottomBackRight, 10);

}

void Cube::SetHeight(int _height)
{
	this->height = _height;
}

void Cube::SetWidth(int _width)
{
	this->width = _width;
}

void Cube::SetDepth(int _depth)
{
	this->depth = _depth;
}

void Cube::SetDimension(int _height, int _width, int _depth)
{
	this->height = _height;
	this->width = _width;
	this->depth = _depth;
}

void Cube::SetX(int _x)
{
	this->x = _x;
}

void Cube::SetY(int _y)
{
	this->y = _y;
}

void Cube::SetZ(int _z)
{
	this->z = _z;
}

void Cube::SetPosition(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

int Cube::GetHeight()
{
	return this->height;
}

int Cube::GetWidth()
{
	return this->width;
}

int Cube::GetDepth()
{
	return this->depth;
}

int Cube::GetX()
{
	return this->x;
}

int Cube::GetY()
{
	return this->y;
}

int Cube::GetZ()
{
	return this->z;
}