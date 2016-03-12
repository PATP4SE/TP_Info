#pragma once

#include <string>
#include "ofMain.h"
#include "windows.h"
//#include "ofxAssimpModelLoader.h"

using namespace std;

class Modele3D
{
public:
	string m_nom;
	//ofxAssimpModelLoader *m_monModele;

	Modele3D();
	//Modele3D(ofxAssimpModelLoader* m_mopele, string p_nom);
	~Modele3D();
	//ofxAssimpModelLoader* chargerModele();
};

