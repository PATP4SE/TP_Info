#pragma once

#include <string>
#include "ofMain.h"

class Group
{
public:

	Group();
	Group(string p_nom);
	~Group();

	string GetNom();
	int GetX();
	int GetY();
	int GetZ();

	int GetRotationX();
	int GetRotationY();
	int GetRotationZ();

	void SetNom(string p_nom);
	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);

	void RotateX(int _x);
	void RotateY(int _y);
	void RotateZ(int _z);
	void Rotate(int _x, int _y, int _z);

	//void ajoutGroupe(int p_type, T* p_objet);
	void enleverGroupe(string p_nom);

private:
	//template <typename T>
	//std::list<std::pair<int p_typeObjet,T* p_objet> > m_ElementGroupe;
	string m_nom;

	bool selected;
	int x;
	int y;
	int z;
	int xRotation;
	int yRotation;
	int zRotation;
};

