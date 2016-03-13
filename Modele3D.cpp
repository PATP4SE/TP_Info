#include "Modele3D.h"

Modele3D::Modele3D(/*ofxAssimpModelLoader* p_modele,*/ string p_nom) :Form()
{
	//this->m_monModele = p_modele;
	this->m_nom = p_nom;

	this->height = 0;
	this->width = 0;
	this->depth = 0;
}

Modele3D::~Modele3D()
{

}

Modele3D::Modele3D(/*ofxAssimpModelLoader* p_modele,*/ string p_nom, int p_x, int p_y, int p_z, int p_width, int p_height, int p_depth) :Form(p_nom, p_x, p_y, p_z)
{
	//this->m_monModele = p_modele;
	this->m_nom = p_nom;

	this->height = p_height;
	this->width = p_width;
	this->depth = p_depth;

	//this->m_monModele.setRotation(this->xRotation, this->yRotation, this->zRotation, 0, 0);
	//this->m_monModele.setScale(1, 1, 1);
	//this->m_monModele.setPosition(this->x, this->y, this->z);
}

/*
ofxAssimpModelLoader* Modele3D::chargerModele()
{
	ofxAssimpModelLoader* modele = new ofxAssimpModelLoader();
	ofFileDialogResult dialog;
	string extension;
	d
	dialog = ofSystemLoadDialog("Importer un modèle 3D");

	if (dialog.bSuccess)
	{
		extension = dialog.fileName.substr(dialog.fileName.find_last_of(".") + 1);
		if (extension == "obj" || extension == "3ds")
		{
			modele->loadModel(dialog.filePath);
		}
		else
		{
			wstring s(L"Le fichier doit avoir des formats qui suit : obj ou 3ds");
			wstring s2(L"Erreur");
			MessageBox(NULL, (LPCWSTR)s.c_str(), (LPCWSTR)s2.c_str(), MB_OK | MB_ICONERROR);
		}
	}

	return modele;
}
*/

void Modele3D::draw()
{
	ofPushMatrix();
		//this->m_monModele.setRotation(this->xRotation, this->yRotation, this->zRotation, 0, 0);
		//this->m_monModele.setScale(1, 1, 1);
		//this->m_monModele.setPosition(this->x, this->y, this->z);
		//this->m_monModele.drawFaces();
	ofPopMatrix();
}

/******************************************************************************
***************                 GET ET SET            *************************
*******************************************************************************/

void Modele3D::SetHeight(int _height)
{
	this->height = _height;
}

void Modele3D::SetWidth(int _width)
{
	this->width = _width;
}

void Modele3D::SetDepth(int _depth)
{
	this->depth = _depth;
}

void Modele3D::SetDimension(int _height, int _width, int _depth)
{
	this->height = _height;
	this->width = _width;
	this->depth = _depth;
}

int Modele3D::GetHeight()
{
	return this->height;
}

int Modele3D::GetWidth()
{
	return this->width;
}

int Modele3D::GetDepth()
{
	return this->depth;
}
