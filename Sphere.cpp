#include "Sphere.h"



Sphere::Sphere()
{
}

Sphere::Sphere(int _x, int _y, int _z, int _radius)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->radius = _radius;
}

Sphere::~Sphere()
{
}


void Sphere::draw()
{
	this->draw(ofGetBackgroundColor());
}

void Sphere::draw(ofColor _color)
{
	//Dessine les points
	if(this->selected)
		ofSetColor(ofColor::blue);
	else
		ofSetColor(ofColor::red);
	ofDrawSphere(this->x, this->y - this->radius, this->z, 3);
	ofDrawSphere(this->x, this->y + this->radius, this->z, 3);
	ofDrawSphere(this->x + this->radius, this->y, this->z, 3);
	ofDrawSphere(this->x - this->radius, this->y, this->z, 3);
	ofDrawSphere(this->x, this->y, this->z, 3);

	ofNoFill();
	ofSetColor(_color);
	ofDrawSphere(this->x, this->y, this->z, this->radius);

	
}

void Sphere::draw(ofImage * & _image)
{
	/*glBindTexture(GL_TEXTURE_RECTANGLE_ARB, (GLuint)_image->getTextureReference());
	ofSetColor(ofColor::white);
	ofDrawSphere(this->x, this->y, this->z, this->radius);
	gluQuadricTexture();

	//Dessine les points
	if (this->selected)
		ofSetColor(ofColor::blue);
	else
		ofSetColor(ofColor::red);
	ofDrawSphere(this->x, this->y - this->radius, this->z, 3);
	ofDrawSphere(this->x, this->y + this->radius, this->z, 3);
	ofDrawSphere(this->x + this->radius, this->y, this->z, 3);
	ofDrawSphere(this->x - this->radius, this->y, this->z, 3);
	ofDrawSphere(this->x, this->y, this->z, 3);*/

	
}


void Sphere::SetRadius(int _radius)
{
	this->radius = _radius;
}

void Sphere::SetX(int _x)
{
	this->x = _x;
}

void Sphere::SetY(int _y)
{
	this->y = _y;
}

void Sphere::SetZ(int _z)
{
	this->z = _z;
}

int Sphere::GetRadius()
{
	return this->radius;
}

int Sphere::GetX()
{
	return this->x;
}

int Sphere::GetY()
{
	return this->y;
}

int Sphere::GetZ()
{
	return this->z;
}
