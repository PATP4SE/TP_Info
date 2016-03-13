#include "Light.h"



Light::Light(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

Light::Light(int _x, int _y, int _z, ofColor _color)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->color = _color;
}

Light::Light()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}


Light::~Light()
{
}

int Light::GetX()
{
	return this->x;
}

int Light::GetY()
{
	return this->y;
}

int Light::GetZ()
{
	return this->z;
}

void Light::SetX(int _x)
{
	this->x = _x;
}

void Light::SetY(int _y)
{
	this->y = _y;
}

void Light::SetZ(int _z)
{
	this->z = _z;
}

void Light::SetPosition(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}
