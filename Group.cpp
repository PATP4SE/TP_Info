#include "Group.h"

Group::Group()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->xRotation = 0;
	this->yRotation = 0;
	this->zRotation = 0;
	this->xDimension = 1;
	this->yDimension = 1;
	this->zDimension = 1;
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
	this->xDimension = 1;
	this->yDimension = 1;
	this->zDimension = 1;
	this->selected = false;
}

void Group::ajoutGroupePrimitive(Primitive *p_primitive)
{
	this->primitives.push_back(p_primitive);
}

void Group::ajoutGroupeForme(Form *p_form)
{
	this->forms.push_back(p_form);
}
 
void Group::ajoutGroupeGroupe(Group *p_group)
{
	this->groups.push_back(p_group);
}

void Group::enleverGroupePrimitive(string p_nom)
{
	list<Primitive*>::iterator it = this->primitives.begin();

	for (it = this->primitives.begin(); it!= this->primitives.end(); ++it)
	{
		if ((*it)->GetNom() == p_nom)
		{
			enleverTransformationsGroupePrimitive(*it);
			this->primitives.erase(it);
		}
	}
}

void Group::enleverGroupeForme(string p_nom)
{
	list<Form*>::iterator it = this->forms.begin();

	for (it = this->forms.begin(); it != this->forms.end(); ++it)
	{
		if ((*it)->GetNom() == p_nom)
		{
			enleverTransformationsGroupeForme(*it);
			this->forms.erase(it);
		}
	}
}

void Group::enleverGroupeGroupe(string p_nom)
{
	list<Group*>::iterator it = this->groups.begin();

	for (it = this->groups.begin(); it != this->groups.end(); ++it)
	{
		if ((*it)->GetNom() == p_nom)
		{
			enleverTransformationsGroupeGroupe(*it);
			this->groups.erase(it);
		}
	}
}

void Group::ajoutTransformationsGroupePrimitive(Primitive *p_primitive)
{
	// Translation
	p_primitive->SetPosition(p_primitive->GetX() + this->GetX(), p_primitive->GetY() + this->GetY(), p_primitive->GetZ() + this->GetZ());
	// Rotation 
	p_primitive->Rotate(p_primitive->GetRotationX() + this->xRotation, p_primitive->GetRotationY() + this->yRotation, p_primitive->GetRotationZ() + this->zRotation);
	// Dimension
	//p_primitive->SetDimension(p_primitive->GetWidth()*this->xDimension, p_primitive->GetHeight()*this->yDimension, p_primitive->GetDepth()*this->zDimension);
}

void Group::ajoutTransformationsGroupeForme(Form *p_form)
{
	// Translation
	p_form->SetPosition(p_form->GetX() + this->GetX(), p_form->GetY() + this->GetY(), p_form->GetZ() + this->GetZ());
	// Rotation 
	p_form->Rotate(p_form->GetRotationX() + this->xRotation, p_form->GetRotationY() + this->yRotation, p_form->GetRotationZ() + this->zRotation);
	// Dimension
	p_form->SetDimension(p_form->GetWidth()*this->xDimension, p_form->GetHeight()*this->yDimension, p_form->GetDepth()*this->zDimension);
}

void Group::ajoutTransformationsGroupeGroupe(Group *p_group)
{
	// Translation
	p_group->SetPosition(p_group->GetX() + this->GetX(), p_group->GetY() + this->GetY(), p_group->GetZ() + this->GetZ());
	// Rotation 
	p_group->Rotate(p_group->GetRotationX() + this->xRotation, p_group->GetRotationY() + this->yRotation, p_group->GetRotationZ() + this->zRotation);
	// Dimension
	p_group->SetDimension(p_group->GetDimensionX()*this->xDimension, p_group->GetDimensionY()*this->yDimension, p_group->GetDimensionZ()*this->zDimension);
}

void Group::ajoutTransformationsGroupeEnsemble()
{
	//Primitives
	list<Primitive*>::iterator it = this->primitives.begin();

	for (it = this->primitives.begin(); it != this->primitives.end(); ++it)
	{
		ajoutTransformationsGroupePrimitive(*it);
	}

	//Formes
	list<Form*>::iterator it2 = this->forms.begin();

	for (it2 = this->forms.begin(); it2 != this->forms.end(); ++it2)
	{
		ajoutTransformationsGroupeForme(*it2);
	}

	//Groupes
	list<Group*>::iterator it3 = this->groups.begin();

	for (it3 = this->groups.begin(); it3 != this->groups.end(); ++it3)
	{
		ajoutTransformationsGroupeGroupe(*it3);
	}
}

void Group::enleverTransformationsGroupePrimitive(Primitive *p_primitive)
{
	// Translation
	p_primitive->SetPosition(p_primitive->GetX() - this->GetX(), p_primitive->GetY() - this->GetY(), p_primitive->GetZ() - this->GetZ());
	// Rotation 
	p_primitive->Rotate(p_primitive->GetRotationX() - this->xRotation, p_primitive->GetRotationY() - this->yRotation, p_primitive->GetRotationZ() - this->zRotation);
	// Dimension
	//p_primitive->SetDimension(p_primitive->GetWidth()/this->xDimension, p_primitive->GetHeight()/this->yDimension, p_primitive->GetDepth()/this->zDimension);
}

void Group::enleverTransformationsGroupeForme(Form *p_form)
{
	// Translation
	p_form->SetPosition(p_form->GetX() - this->GetX(), p_form->GetY() - this->GetY(), p_form->GetZ() - this->GetZ());
	// Rotation 
	p_form->Rotate(p_form->GetRotationX() - this->xRotation, p_form->GetRotationY() - this->yRotation, p_form->GetRotationZ() - this->zRotation);
	// Dimension
	p_form->SetDimension(p_form->GetWidth()/this->xDimension, p_form->GetHeight()/this->yDimension, p_form->GetDepth()/this->zDimension);
}

void Group::enleverTransformationsGroupeEnsemble()
{
	//Primitives
	list<Primitive*>::iterator it = this->primitives.begin();

	for (it = this->primitives.begin(); it != this->primitives.end(); ++it)
	{
		enleverTransformationsGroupePrimitive(*it);
	}

	//Formes
	list<Form*>::iterator it2 = this->forms.begin();

	for (it2 = this->forms.begin(); it2 != this->forms.end(); ++it2)
	{
		enleverTransformationsGroupeForme(*it2);
	}

	//Groupes
	list<Group*>::iterator it3 = this->groups.begin();

	for (it3 = this->groups.begin(); it3 != this->groups.end(); ++it3)
	{
		enleverTransformationsGroupeGroupe(*it3);
	}
}

void Group::enleverTransformationsGroupeGroupe(Group *p_group)
{
	// Translation
	p_group->SetPosition(p_group->GetX() - this->GetX(), p_group->GetY() - this->GetY(), p_group->GetZ() - this->GetZ());
	// Rotation 
	p_group->Rotate(p_group->GetRotationX() - this->xRotation, p_group->GetRotationY() - this->yRotation, p_group->GetRotationZ() - this->zRotation);
	// Dimension
	p_group->SetDimension(p_group->GetDimensionX()/this->xDimension, p_group->GetDimensionY()/this->yDimension, p_group->GetDimensionZ()/this->zDimension);
}

/******************************************************************************
*****************                 GET ET SET            ***********************
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

int Group::GetDimensionX()
{
	return this->xDimension;
}

int Group::GetDimensionY()
{
	return this->yDimension;
}

int Group::GetDimensionZ()
{
	return this->zDimension;
}

ofColor Group::GetColor()
{
	return this->color;
}

void Group::SetColor(ofColor _color)
{
	this->color = _color;
}

bool Group::IsSelected()
{
	return this->selected;
}

void Group::SetSelected(bool _selected)
{
	this->selected = _selected;

	/*list<Form*>::iterator itForms = forms.begin();
	list<Primitive*>::iterator itPrimitives = primitives.begin();
	list<Group*>::iterator itGroups = groups.begin();

	for (itForms; itForms != forms.end(); itForms++)
	{
		(*itForms)->SetSelected(_selected);
	}

	for (itPrimitives; itPrimitives != primitives.end(); itPrimitives++)
	{
		(*itPrimitives)->SetSelected(_selected);
	}

	for (itGroups; itGroups != groups.end(); itGroups++)
	{
		(*itGroups)->SetSelected(_selected);
	}*/
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

void Group::DimensionX(int _x)
{
	this->xDimension = _x;
}

void Group::DimensionY(int _y)
{
	this->yDimension = _y;
}

void Group::DimensionZ(int _z)
{
	this->zDimension = _z;
}

void Group::SetDimension(int _x, int _y, int _z)
{
	this->xDimension = _x;
	this->yDimension = _y;
	this->zDimension = _z;
}