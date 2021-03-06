#pragma once

#include "ofMain.h"
#include <string>

class Form
{
public:
	Form();
	Form(string p_nom, int _x, int _y, int _z);
	~Form();

	string GetNom();
	int GetX();
	int GetY();
	int GetZ();

	int GetRotationX();
	int GetRotationY();
	int GetRotationZ();
	bool IsSelected();
	ofColor GetColor();

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual int GetDepth() = 0;

	ofImage* GetTexture();
	void SetTexture(ofImage *_image);
	void SetColor(ofColor _color);

	void SetNom(string p_nom);
	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);
	virtual void SetDimension(int _x, int _y, int _z) = 0;
	void SetSelected(bool _selected);

	void RotateX(int _x);
	void RotateY(int _y);
	void RotateZ(int _z);
	void Rotate(int _x, int _y, int _z);
protected:
	string m_nom;

	bool selected;
	int x;
	int y;
	int z;
	int xRotation;
	int yRotation;
	int zRotation;
	ofImage *texture;
	ofColor color;
};

