#include "Form.h"

Form::Form()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->xRotation = 0;
	this->yRotation = 0;
	this->zRotation = 0;
	this->selected = false;
	this->texture = NULL;
	this->color = ofGetBackgroundColor();
}

Form::Form(string p_nom, int _x, int _y, int _z)
{
	this->m_nom = p_nom;
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->xRotation = 0;
	this->yRotation = 0;
	this->zRotation = 0;
	this->selected = false;
	this->texture = NULL;
	this->color = ofGetBackgroundColor();
}

Form::~Form()
{
	delete this->texture;
}

/******************************************************************************
***************                 GET ET SET            *************************
*******************************************************************************/

string Form::GetNom()
{
	return this->m_nom;
}

int Form::GetX()
{
	return this->x;
}

int Form::GetY()
{
	return this->y;
}

int Form::GetZ()
{
	return this->z;
}

int Form::GetRotationX()
{
	return this->xRotation;
}

int Form::GetRotationY()
{
	return this->yRotation;
}

int Form::GetRotationZ()
{
	return this->zRotation;
}

ofImage* Form::GetTexture()
{
	return this->texture;
}

ofColor Form::GetColor()
{
	return this->color;
}

void Form::SetColor(ofColor _color)
{
	this->color = _color;
}

bool Form::IsSelected()
{
	return this->selected;
}

void Form::SetSelected(bool _selected)
{
	this->selected = _selected;
}

void Form::SetNom(string p_nom)
{
	this->m_nom = p_nom;
}

void Form::SetTexture(ofImage *_image)
{
	this->texture = _image;
}

void Form::SetX(int _x)
{
	this->x = _x;
}

void Form::SetY(int _y)
{
	this->y = _y;
}

void Form::SetZ(int _z)
{
	this->z = _z;
}

void Form::SetPosition(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

void Form::RotateX(int _x)
{
	this->xRotation = _x;
}

void Form::RotateY(int _y)
{
	this->yRotation = _y;
}

void Form::RotateZ(int _z)
{
	this->zRotation = _z;
}

void Form::Rotate(int _x, int _y, int _z)
{
	this->xRotation = _x;
	this->yRotation = _y;
	this->zRotation = _z;
}