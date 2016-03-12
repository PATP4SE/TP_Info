#include "Cube.h"



Cube::Cube(int _x, int _y, int _z, int _width, int _height, int _depth)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
	this->height = _height;
	this->width = _width;
	this->depth = _depth;
	this->selected = false;
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

void Cube::drawOnCube(ofImage * & _image)
{
	float left = this->x - (this->width / 2);
	float right = this->x + (this->width / 2);
	float top = this->y - (this->height / 2);
	float bottom = this->y + (this->height / 2);
	float front = this->z + (this->depth / 2);
	float back = this->z - (this->depth / 2);

	ofPoint topFrontLeft = ofPoint(left, top, front);
	ofPoint topFrontRight = ofPoint(right, top, front);
	ofPoint bottomFrontLeft = ofPoint(left, bottom, front);
	ofPoint bottomFrontRight = ofPoint(right, bottom, front);

	ofPoint topBackLeft = ofPoint(left, top, back);
	ofPoint topBackRight = ofPoint(right, top, back);
	ofPoint bottomBackLeft = ofPoint(left, bottom, back);
	ofPoint bottomBackRight = ofPoint(right, bottom, back);
	
	float verts[] = {

		//front
		left, top, front, //haut gauche front
		right, top, front, //haut droit front
		left, bottom, front, //bas gauche front
		right, bottom, front, //bas droit front

		//right
		right, top, front, //haut droit front
		right, top, back,//haut droit back
		right, bottom, front, //bas droit front
		right, bottom, back,//bas droit back

		//back
		right, top, back,//haut droit back
		left, top, back,//haut gauche back
		right, bottom, back,//bas droit back
		left, bottom, back,//bas gauche back

		//left
		left, top, back,//haut gauche back
		left, top, front, //haut gauche front
		left, bottom, back,//bas gauche back
		left, bottom, front, //bas gauche front

		//top
		left, top, back,//haut gauche back
		right, top, back,//haut droit back
		left, top, front, //haut gauche front
		right, top, front, //haut droit front

		//bottom
		left, bottom, back,//bas gauche back
		right, bottom, back,//bas droit back
		left, bottom, front, //bas gauche front
		right, bottom, front, //bas droit front
	};

	int indicies[] = {
		0,1,2,
		1,2,3,

		4,5,6,
		5,6,7,

		8,9,10,
		10,11,12,

		12,13,14,
		13,14,15,

		16,17,18,
		17,18,19,

		20,21,22,
		21,22,23
	};
	ofMesh mesh;
	mesh.clear();

	ofVec3f points[24];

	mesh.setMode(OF_PRIMITIVE_TRIANGLES);

	for (int i = 0; i < 24; i++) 
	{
		points[i].x = verts[i * 3];
		points[i].y = verts[i * 3 + 1];
		points[i].z = verts[i * 3 + 2];

		mesh.addVertex(points[i]);
		//mesh.addTexCoord(ofVec2f(points[i].x,points[i].y));
		//mesh.addColor(ofColor::white);
	}
	float tcoords[] = {
		//front
		0,0,
		0.33,0,
		0,0.5,
		0.33,0.5,

		//right
		0.33,0,
		0.67,0,
		0.33,0.5,
		0.67,0.5,

		//back
		0.67,0,
		1.0,0,
		0.67,0.5,
		1.0,0.5,

		//left
		0,0.5,
		0.33,0.5,
		0,1.0,
		0.33,1.0,

		//top
		0.33,0.5,
		0.67,0.5,
		0.33,1.0,
		0.67,1.0,

		//bottom
		0.67,0.5,
		1.0,0.5,
		0.67,1.0,
		1.0,1.0
	};

	ofVec2f tcrds[24];
	for (int i = 0; i < 24; i++) 
	{
		tcrds[i].x = tcoords[i * 2];
		tcrds[i].y = tcoords[i * 2 + 1];
		mesh.addTexCoord(tcrds[i]);
	}

	for (int i = 0; i < 6; i++) 
	{
		int fI = 4 * i;

		mesh.addIndex(fI);  
		mesh.addIndex(fI + 1);
		mesh.addIndex(fI + 2);
		mesh.addIndex(fI + 1); 
		mesh.addIndex(fI + 2);
		mesh.addIndex(fI + 3);
	}

	ofDisableArbTex();
	ofDisableBlendMode();
	ofEnableDepthTest();

	ofSetColor(ofColor::white);
	_image->getTextureReference().bind();
	//mesh.drawWireframe();
	mesh.draw();
	_image->getTextureReference().unbind();
}

void Cube::drawOnFaces(ofImage * & _image)
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