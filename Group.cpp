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

void Group::ajoutGroupePrimitive(Primitive *p_primitive)
{
	this->primitives->push_back(p_primitive);
}

void Group::ajoutGroupeForme(Form *p_form)
{
	this->forms->push_back(p_form);
}

void Group::ajoutGroupeGroupe(Group *p_group)
{
	this->groups->push_back(p_group);
}

void Group::enleverGroupePrimitive(string p_nom)
{
	list<Primitive*>::iterator it = this->primitives->begin();

	for (it = this->primitives->begin(); it!= this->primitives->end(); ++it)
	{
		if ((*it)->GetNom() == p_nom)
		{
			enleverTransformationsGroupePrimitive(*it);
			this->primitives->erase(it);
		}
	}
}

void Group::enleverGroupeForme(string p_nom)
{
	list<Form*>::iterator it = this->forms->begin();

	for (it = this->forms->begin(); it != this->forms->end(); ++it)
	{
		if ((*it)->GetNom() == p_nom)
		{
			//enleverTransformationsGroupeForme(*it);
			this->forms->erase(it);
		}
	}
}

void Group::enleverGroupeGroupe(string p_nom)
{
	list<Group*>::iterator it = this->groups->begin();

	for (it = this->groups->begin(); it != this->groups->end(); ++it)
	{
		if ((*it)->GetNom() == p_nom)
		{
			//enleverTransformationsGroupeGroupe(*it);
			this->groups->erase(it);
		}
	}
}

void Group::ajoutTransformationsGroupePrimitive(Primitive *p_primitive)
{
	// Translation
	p_primitive->SetPosition(p_primitive->GetX() + this->GetX(), p_primitive->GetY() + this->GetY(), p_primitive->GetZ() + this->GetZ());
	// Rotation 
	
}

void Group::enleverTransformationsGroupePrimitive(Primitive *p_primitive)
{
	// Translation
	p_primitive->SetPosition(p_primitive->GetX() - this->GetX(), p_primitive->GetY() - this->GetY(), p_primitive->GetZ() - this->GetZ());
}

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
