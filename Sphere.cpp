#include "Sphere.h"

Sphere::Sphere(): Form()
{
	this->radius = 0;
}

Sphere::Sphere(string p_nom, int _x, int _y, int _z, int _radius):Form(p_nom, _x, _y, _z)
{
	this->radius = _radius;
	this->color = ofColor::black;
}

Sphere::~Sphere()
{
}

void Sphere::draw()
{
	this->draw(this->color);
}

void Sphere::draw(ofColor _color)
{
	ofPushMatrix();
	ofTranslate(this->x, this->y, this->z);
	ofRotateX(this->xRotation);
	ofRotateY(this->yRotation);
	ofRotateZ(this->zRotation);
	//Dessine les points
	if(this->selected)
		ofSetColor(ofColor::red);
	else
		ofSetColor(ofColor::blue);

	ofDrawSphere(0, 0 - this->radius, 0, 3);
	ofDrawSphere(0, 0 + this->radius, 0, 3);
	ofDrawSphere(0 + this->radius, 0, 0, 3);
	ofDrawSphere(0 - this->radius, 0, 0, 3);
	//ofDrawSphere(this->x, this->y, this->z, 3);
	
	ofNoFill();
	ofSetColor(_color);
	ofDrawSphere(0, 0, 0, this->radius);
	ofPopMatrix();
}

void Sphere::drawWithTexture()
{
	ofImage image;
	ofMesh mesh;

	ofDisableArbTex();
	image = *this->texture;
	mesh.clear();
	mesh = ofMesh::sphere(this->radius);
	ofSetColor(ofColor::white);

	ofPushMatrix();
	ofTranslate(this->x, this->y, this->z);
	ofRotateX(this->xRotation);
	ofRotateY(this->yRotation);
	ofRotateZ(this->zRotation);
	image.getTextureReference().bind();
	mesh.draw();
	image.getTextureReference().unbind();
	ofPopMatrix();

	//Dessine les points
	if (this->selected)
		ofSetColor(ofColor::blue);
	else
		ofSetColor(ofColor::red);
	ofDrawSphere(this->x, this->y - this->radius, this->z, 5);
	ofDrawSphere(this->x, this->y + this->radius, this->z, 5);
	ofDrawSphere(this->x + this->radius, this->y, this->z, 5);
	ofDrawSphere(this->x - this->radius, this->y, this->z, 5);
	//ofDrawSphere(this->x, this->y, this->z, 3);
}

/******************************************************************************
***************                 GET ET SET            *************************
*******************************************************************************/

void Sphere::SetRadius(int _radius)
{
	this->radius = _radius;
}

int Sphere::GetRadius()
{
	return this->radius;
}



