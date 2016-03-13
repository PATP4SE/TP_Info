#pragma once
class Primitive
{
public:
	Primitive(int _x, int _y, int _z, int _lineWidth = 1);
	Primitive();
	~Primitive();

	int GetX();
	int GetY();
	int GetZ();
	int GetLineWidth();

	int GetRotationX();
	int GetRotationY();
	int GetRotationZ();

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
	int x;
	int y;
	int z;
	int xRotation;
	int yRotation;
	int zRotation;
	int lineWidth;
};

