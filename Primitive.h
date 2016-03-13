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

	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);
	void SetLineWidth(int _width);

protected:
	int x;
	int y;
	int z;
	int lineWidth;
};

