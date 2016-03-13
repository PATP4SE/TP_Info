#pragma once

#include <string>
#include "ofMain.h"
#include "windows.h"
#include "Form.h"
//#include "ofxAssimpModelLoader.h"

using namespace std;

class Modele3D : public Form
{
public:
	Modele3D(/*ofxAssimpModelLoader* p_modele,*/ string p_nom, int p_x, int p_y, int p_z, int p_width, int p_height, int p_depth);
	~Modele3D();
	Modele3D(/*ofxAssimpModelLoader* p_modele,*/ string p_nom);

	//ofxAssimpModelLoader* chargerModele();

	void SetNom(string p_nom);
	void SetHeight(int _height);
	void SetWidth(int _width);
	void SetDepth(int _depth);
	void SetDimension(int _height, int _width, int _depth);

	string GetNom();
	int GetHeight();
	int GetWidth();
	int GetDepth();

	void draw();

private:
	string m_nom;
	//ofxAssimpModelLoader *m_monModele;

	int height;
	int width;
	int depth;
};


