#pragma once

#include "ofMain.h"
#include "ofxCircleMenuButton.h"
#include "ofxUI/src/ofxUI.h"
#include <ofMain.h>
#include "../Cube.h"
#include "../Sphere.h"
#include "../Form.h"
#include "../Primitive.h"
#include "../_Line.h"
#include "../Triangle.h"
#include "../Group.h"
#include "../Utilities.h"
#include "../Modele3D.h"
#include "../Particule.h"

#include <list>


class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();
		
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
	list<Form*> forms;
	list<Primitive*> primitives;
	list<Group*> groups;
	list<ofImage*> images;
	list<POINT*> positionSouris;
	Utilities util;
		
	#pragma region Gestion - Interface
	//////////////////////////////////////////////////
	// Menu
	ofxCircleMenuButton m_menu;
	ofxCircleMenuButtonListener *m_listener;

	// DropDownList
	vector<string> m_dataDDL_1;
	ofxUISuperCanvas *m_guiDDL_1;
	ofxUIDropDownList *m_DDL_1;

	vector<string> m_dataDDL_2;
	ofxUISuperCanvas *m_guiDDL_2;
	ofxUIDropDownList *m_DDL_2;

	vector<string> m_dataDDL_3;
	ofxUISuperCanvas *m_guiDDL_3;
	ofxUIDropDownList *m_DDL_3;

	void guiEvent_DropDownList(ofxUIEventArgs &e);
	void guiEvent_DoAction(int p_IdButton);

	// Propriétés
	ofxUISuperCanvas *m_guiParametres;
	ofxUIDropDownList *m_DDL_4;
	vector<string> m_dataDDL_4;
	ofxUIDropDownList *m_DDL_5;
	vector<string> m_dataDDL_5;

	void guiEvent_Proprietes(ofxUIEventArgs &e);
	float m_couleurR, m_couleurG, m_couleurB, m_couleurA;
	float m_positionX, m_positionY, m_positionZ;
	float m_rotationX, m_rotationY, m_rotationZ;
	float m_maxWidthPosition, m_maxHeightPosition;
	bool m_drawFillVisible;
	string m_valeurDimension;

	POINT *m_monPoint;
	int m_creation;

	// Créer groupe
	ofxUISuperCanvas *m_guiCreerGroupe;
	void guiEvent_CreerGroupe(ofxUIEventArgs &e);
	string m_nomNouveauGroupe;
	int m_ActionCreer;

	// Autres
	HWND m_hwndDesktop;
	RECT m_rectDesktop;

	ofxUICanvas *m_guiFPS;
	//////////////////////////////////////////////////
	#pragma endregion

};
