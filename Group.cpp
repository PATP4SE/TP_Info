#include "Group.h"



Group::Group()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->xRotation = 0;
	this->yRotation = 0;
	this->zRotation = 0;
	this->selected = false;
}


Group::~Group()
{
}

Group::Group(string p_nom)
{
	this->m_nom = p_nom;

	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->xRotation = 0;
	this->yRotation = 0;
	this->zRotation = 0;
	this->selected = false;
}
/*
void ajoutGroupe(int p_type, T* p_objet)
{
	this->m_ElementGroupe.push_back(std::make_pair(p_type,p_objet));
}

void enleverGroupe(string p_nom)
{
	std::list<pair> mylist;
	std::list<int>::iterator it1;

	for (it=m_ElementGroupe.begin(); it!=m_ElementGroupe.end(); ++it)
	{
		if ((it->second)->GetName() == p_nom) then
			
		end if
	}
}
*/

/******************************************************************************
***************                 GET ET SET            *************************
*******************************************************************************/


string Group::GetNom()
{
	return this->m_nom;
}

int Group::GetX()
{
	return this->x;
}

int Group::GetY()
{
	return this->y;
}

int Group::GetZ()
{
	return this->z;
}

int Group::GetRotationX()
{
	return this->xRotation;
}

int Group::GetRotationY()
{
	return this->yRotation;
}

int Group::GetRotationZ()
{
	return this->zRotation;
}

void Group::SetNom(string p_nom)
{
	this->m_nom = p_nom;
}

void Group::SetX(int _x)
{
	this->x = _x;
}

void Group::SetY(int _y)
{
	this->y = _y;
}

void Group::SetZ(int _z)
{
	this->z = _z;
}

void Group::SetPosition(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}

void Group::RotateX(int _x)
{
	this->xRotation += _x;
}

void Group::RotateY(int _y)
{
	this->yRotation += _y;
}

void Group::RotateZ(int _z)
{
	this->zRotation += _z;
}

void Group::Rotate(int _x, int _y, int _z)
{
	this->xRotation = _x;
	this->yRotation = _y;
	this->zRotation = _z;
}
