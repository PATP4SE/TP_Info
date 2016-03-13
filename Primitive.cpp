#include "Primitive.h"


Primitive::Primitive()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Primitive::Primitive(string p_nom, int _x, int _y, int _z, int _lineWidth)
{
	this->m_nom = p_nom;
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->lineWidth = _lineWidth;
}

Primitive::~Primitive()
{
}

string Primitive::GetNom()
{
	return this->m_nom;
}

int Primitive::GetX()
{
	return this->x;
}

int Primitive::GetY()
{
	return this->y;
}

int Primitive::GetZ()
{
	return this->z;
}

int Primitive::GetLineWidth()
{
	return this->lineWidth;
}

int Primitive::GetRotationX()
{
	return this->xRotation;
}

int Primitive::GetRotationY()
{
	return this->yRotation;
}

int Primitive::GetRotationZ()
{
	return this->zRotation;
}

bool Primitive::IsSelected()
{
	return this->selected;
}

void Primitive::SetSelected(bool _selected)
{
	this->selected = _selected;
}

void Primitive::RotateX(int _x)
{
	this->xRotation = _x;
}

void Primitive::RotateY(int _y)
{
	this->yRotation = _y;
}

void Primitive::RotateZ(int _z)
{
	this->zRotation = _z;
}

void Primitive::Rotate(int _x, int _y, int _z)
{
	this->xRotation = _x;
	this->yRotation = _y;
	this->zRotation = _z;
}


void Primitive::SetX(int _x)
{
	this->x = _x;
}

void Primitive::SetY(int _y)
{
	this->y = _y;
}

void Primitive::SetZ(int _z)
{
	this->z = _z;
}

void Primitive::SetPosition(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

void Primitive::SetLineWidth(int _width)
{
	this->lineWidth = _width;
}

void Primitive::SetNom(string p_nom)
{
	this->m_nom = p_nom;
}
