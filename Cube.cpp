#include "Cube.h"



Cube::Cube(int _x, int _y, int _z, int _width, int _height, int _depth)
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

void Cube::draw()
{
	this->draw(ofGetBackgroundColor());
}

void Cube::draw(ofImage * & _image)
{
	ofDrawBox(this->x, this->y, this->z, this->width, this->height, this->depth);
	int left = this->x - (this->width / 2);
	int right = this->x + (this->width / 2);
	int top = this->y - (this->height / 2);
	int bottom = this->y + (this->height / 2);
	int front = this->z + (this->depth / 2);
	int back = this->z - (this->depth / 2);

	ofPoint topFrontLeft = ofPoint(left, top, front);
	ofPoint topFrontRight = ofPoint(right, top, front);
	ofPoint bottomFrontLeft = ofPoint(left, bottom, front);
	ofPoint bottomFrontRight = ofPoint(right, bottom, front);

	ofPoint topBackLeft = ofPoint(left, top, back);
	ofPoint topBackRight = ofPoint(right, top, back);
	ofPoint bottomBackLeft = ofPoint(left, bottom, back);
	ofPoint bottomBackRight = ofPoint(right, bottom, back);

	//Dessine les points
	if (this->selected)
		ofSetColor(ofColor::blue);
	else
		ofSetColor(ofColor::red);

	ofDrawSphere(topFrontLeft, 3);
	ofDrawSphere(topFrontRight, 3);
	ofDrawSphere(bottomFrontLeft, 3);
	ofDrawSphere(bottomFrontRight, 3);

	ofDrawSphere(topBackLeft, 3);
	ofDrawSphere(topBackRight, 3);
	ofDrawSphere(bottomBackLeft, 3);
	ofDrawSphere(bottomBackRight, 3);

	//Applique la texture
	ofSetColor(ofColor::white);
	applyMesh(topBackRight, topBackLeft, bottomBackRight, bottomBackLeft, _image);//Back
	applyMesh(topBackLeft, topFrontLeft, bottomBackLeft, bottomFrontLeft, _image);//Left
	applyMesh(topFrontRight, topBackRight, bottomFrontRight, bottomBackRight, _image);//Right
	applyMesh(topBackLeft, topBackRight, topFrontLeft, topFrontRight, _image);//Top
	applyMesh(bottomBackRight, bottomBackLeft, bottomFrontRight, bottomFrontLeft, _image);//Bottom
	applyMesh(topFrontLeft, topFrontRight, bottomFrontLeft, bottomFrontRight, _image);//Front

	//Dessine les lignes sur le front
	ofSetColor(ofColor::black);
	ofDrawLine(topFrontLeft, topFrontRight);
	ofDrawLine(topFrontLeft, bottomFrontLeft);
	ofDrawLine(topFrontRight, bottomFrontRight);
	ofDrawLine(bottomFrontLeft, bottomFrontRight);
	//Dessine les lignes du back
	ofDrawLine(topBackLeft, topBackRight);
	ofDrawLine(topBackLeft, bottomBackLeft);
	ofDrawLine(topBackRight, bottomBackRight);
	ofDrawLine(bottomBackLeft, bottomBackRight);
	//Dessine les lignes du dessous
	ofDrawLine(bottomFrontLeft, bottomBackLeft);
	ofDrawLine(bottomFrontRight, bottomBackRight);
	//Dessine les lignes du dessus
	ofDrawLine(topFrontLeft, topBackLeft);
	ofDrawLine(topFrontRight, topBackRight);
}

//Dessine à partir du centre du cube
void Cube::draw(ofColor _color)
{
	ofSetColor(_color);
	ofDrawBox(this->x, this->y, this->z, this->width, this->height, this->depth);
	int left = this->x - (this->width / 2);
	int right = this->x + (this->width / 2);
	int top = this->y - (this->height / 2);
	int bottom = this->y + (this->height / 2);
	int front = this->z + (this->depth / 2);
	int back = this->z - (this->depth / 2);

	ofPoint topFrontLeft = ofPoint(left, top, front);
	ofPoint topFrontRight = ofPoint(right, top, front);
	ofPoint bottomFrontLeft = ofPoint(left, bottom, front);
	ofPoint bottomFrontRight = ofPoint(right, bottom, front);

	ofPoint topBackLeft = ofPoint(left, top, back);
	ofPoint topBackRight = ofPoint(right, top, back);
	ofPoint bottomBackLeft = ofPoint(left, bottom, back);
	ofPoint bottomBackRight = ofPoint(right, bottom, back);

	ofSetColor(ofColor::blue);
	ofDrawSphere(topFrontLeft, 3);
	ofDrawSphere(topFrontRight, 3);
	ofDrawSphere(bottomFrontLeft, 3);
	ofDrawSphere(bottomFrontRight, 3);

	ofDrawSphere(topBackLeft, 3);
	ofDrawSphere(topBackRight, 3);
	ofDrawSphere(bottomBackLeft, 3);
	ofDrawSphere(bottomBackRight, 3);
	
	ofSetColor(ofColor::black);
	//Draw les lignes sur le front
	ofDrawLine(topFrontLeft, topFrontRight);
	ofDrawLine(topFrontLeft, bottomFrontLeft);
	ofDrawLine(topFrontRight, bottomFrontRight);
	ofDrawLine(bottomFrontLeft, bottomFrontRight);
	//Draw les lignes du back
	ofDrawLine(topBackLeft, topBackRight);
	ofDrawLine(topBackLeft, bottomBackLeft);
	ofDrawLine(topBackRight, bottomBackRight);
	ofDrawLine(bottomBackLeft, bottomBackRight);
	//Les lignes du dessous
	ofDrawLine(bottomFrontLeft, bottomBackLeft);
	ofDrawLine(bottomFrontRight, bottomBackRight);
	//Les lignes du dessus
	ofDrawLine(topFrontLeft, topBackLeft);
	ofDrawLine(topFrontRight, topBackRight);


}

bool Cube::isSelected()
{
	return this->selected;
}

void Cube::SetSelected(bool _selected)
{
	this->selected = _selected;
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

ofMesh Cube::applyMesh(ofPoint _topLeft, ofPoint _topRight, ofPoint _bottomLeft, ofPoint _bottomRight, ofImage *_image)
{
	ofMesh *mesh = new ofMesh();
	mesh->setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
	
	mesh->addVertex(_topLeft); //haut gauche
	mesh->addTexCoord(_image->getTextureReference().getCoordFromPercent(0, 0));
	mesh->addVertex(_topRight); //haut droit
	mesh->addTexCoord(_image->getTextureReference().getCoordFromPercent(1, 0));
	mesh->addVertex(_bottomLeft);//bas gauche
	mesh->addTexCoord(_image->getTextureReference().getCoordFromPercent(0, 1));
	mesh->addVertex(_bottomRight); //bas droit
	mesh->addTexCoord(_image->getTextureReference().getCoordFromPercent(1, 1));

	_image->getTextureReference().bind();
	mesh->draw();
	_image->getTextureReference().unbind();
	return *mesh;
}