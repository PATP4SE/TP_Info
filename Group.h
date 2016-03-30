#pragma once

#include <string>
#include "ofMain.h"
#include "Primitive.h"
#include "Form.h"

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
	bool IsSelected();

	int GetRotationX();
	int GetRotationY();
	int GetRotationZ();

	int GetDimensionX();
	int GetDimensionY();
	int GetDimensionZ();
	ofColor GetColor();

	void SetColor(ofColor _color);
	void SetNom(string p_nom);
	void SetX(int _x);
	void SetY(int _y);
	void SetZ(int _z);
	void SetPosition(int _x, int _y, int _z);
	void SetSelected(bool _selected);

	void RotateX(int _x);
	void RotateY(int _y);
	void RotateZ(int _z);
	void Rotate(int _x, int _y, int _z);

	void DimensionX(int _x);
	void DimensionY(int _y);
	void DimensionZ(int _z);
	void SetDimension(int _x, int _y, int _z);

	void ajoutGroupePrimitive(Primitive *p_primitive);
	void ajoutGroupeForme(Form *p_form);
	void ajoutGroupeGroupe(Group *p_group);

	void enleverGroupePrimitive(string p_nom);
	void enleverGroupeForme(string p_nom);
	void enleverGroupeGroupe(string p_nom);

	void ajoutTransformationsGroupePrimitive(Primitive *p_primitive);
	void ajoutTransformationsGroupeForme(Form *p_form);
	void ajoutTransformationsGroupeGroupe(Group *p_group);

	void ajoutTransformationsGroupeEnsemble();

	void enleverTransformationsGroupePrimitive(Primitive *p_primitive);
	void enleverTransformationsGroupeForme(Form *p_form);
	void enleverTransformationsGroupeGroupe(Group *p_group);

	void enleverTransformationsGroupeEnsemble();
private:
	
	list<Form*> forms;
	list<Primitive*> primitives;
	list<Group*> groups;

	string m_nom;

	bool selected;
	int x;
	int y;
	int z;
	int xRotation;
	int yRotation;
	int zRotation;
	int xDimension;
	int yDimension;
	int zDimension;
	ofColor color;

};

