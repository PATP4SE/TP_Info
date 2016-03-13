#include "Sphere.h"

Sphere::Sphere(): Form()
{
	this->radius = 0;
}

Sphere::Sphere(string p_nom, int _x, int _y, int _z, int _radius):Form(p_nom, _x, _y, _z)
{
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
	ofPushMatrix();
	//Dessine les points
	if(this->selected)
		ofSetColor(ofColor::red);
	else
		ofSetColor(ofColor::blue);
	ofDrawSphere(this->x, this->y - this->radius, this->z, 3);
	ofDrawSphere(this->x, this->y + this->radius, this->z, 3);
	ofDrawSphere(this->x + this->radius, this->y, this->z, 3);
	ofDrawSphere(this->x - this->radius, this->y, this->z, 3);
	//ofDrawSphere(this->x, this->y, this->z, 3);

	ofRotateX(this->xRotation);
	ofRotateY(this->xRotation);
	ofRotateZ(this->xRotation);
	ofNoFill();
	ofSetColor(_color);
	ofDrawSphere(this->x, this->y, this->z, this->radius);
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




