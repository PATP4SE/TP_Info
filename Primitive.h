#pragma once

#include "ofMain.h"
#include <string>

class Primitive
{
public:
	Primitive(string p_nom, int _x, int _y, int _z, int _lineWidth = 1);
	Primitive();
	~Primitive();

	string GetNom();
	int GetX();
	int GetY();
	int GetZ();
	int GetLineWidth();
	bool IsSelected();

	void SetNom(string p_nom);

	int GetRotationX();
	int GetRotationY();
	int GetRotationZ();

	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);
	void SetLineWidth(int _width);
	void SetSelected(bool _selected);

	void RotateX(int _x);
	void RotateY(int _y);
	void RotateZ(int _z);
	void Rotate(int _x, int _y, int _z);

protected:
	string m_nom;
	int x;
	int y;
	int z;
	int xRotation;
	int yRotation;
	int zRotation;
	int lineWidth;
	bool selected;
};

