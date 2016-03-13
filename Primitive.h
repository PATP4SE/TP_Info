#pragma once

#include "ofMain.h"
#include <string>

class Primitive
{
public:
	Primitive(int _x, int _y, int _z, int _lineWidth = 1);
	Primitive();
	~Primitive();

	string GetNom();
	int GetX();
	int GetY();
	int GetZ();
	int GetLineWidth();

<<<<<<< HEAD
	void SetNom(string p_nom);
=======
	int GetRotationX();
	int GetRotationY();
	int GetRotationZ();

>>>>>>> 4864c66a8370929d907a7662274cd97939aa7181
	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);
	void SetLineWidth(int _width);

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
};

