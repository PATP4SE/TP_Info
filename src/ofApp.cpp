#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofEnableDepthTest();
	glShadeModel(GL_SMOOTH);

	#pragma region Gestion - Interface
	//////////////////////////////////////////////////
	ofSetBackgroundColor(ofColor(224, 224, 224));

	// Autres
	m_hwndDesktop = GetDesktopWindow();
	GetWindowRect(m_hwndDesktop, &m_rectDesktop);

	m_guiFPS = new ofxUICanvas((ofGetWidth() - 211), (ofGetHeight() - 30), 211, 211);
	m_guiFPS->addFPSSlider("FPS");
	m_guiFPS->autoSizeToFitWidgets();
	m_guiFPS->setVisible(true);

	// Menu
	m_listener = new ofxCircleMenuButtonListener();
	m_menu.setup();
	m_menu.setRadius(80, 240);
	m_menu.addMenuItem("Creer groupe");		// 0
	m_menu.addMenuItem("Creation 3D");		// 1
	m_menu.addMenuItem("Creation 2D");		// 2
	m_menu.addMenuItem("Importer");			// 3
	m_menu.addMenuItem("Quitter");			// 4
	m_menu.addMenuItem("Exporter");			// 5
	m_menu.enableMouseControl();
	m_menu.setListener(m_listener);

	// DropDownList
	m_guiDDL_1 = new ofxUISuperCanvas("Liste d'elements 2D", 0, 0, 200, 211);
	m_guiDDL_1->addSpacer();
	m_DDL_1 = m_guiDDL_1->addDropDownList("Elements 2D", m_dataDDL_1);
	m_DDL_1->setAllowMultiple(true);
	m_DDL_1->setAutoClose(false);
	m_guiDDL_1->autoSizeToFitWidgets();
	ofAddListener(m_guiDDL_1->newGUIEvent, this, &ofApp::guiEvent_DropDownList);

	m_guiDDL_2 = new ofxUISuperCanvas("Liste d'elements 3D", 201, 0, 200, 211);
	m_guiDDL_2->addSpacer();
	m_DDL_2 = m_guiDDL_2->addDropDownList("Elements 3D", m_dataDDL_2);
	m_DDL_2->setAllowMultiple(true);
	m_DDL_2->setAutoClose(false);
	m_guiDDL_2->autoSizeToFitWidgets();
	ofAddListener(m_guiDDL_2->newGUIEvent, this, &ofApp::guiEvent_DropDownList);

	m_guiDDL_3 = new ofxUISuperCanvas("Liste de groupes", 402, 0, 200, 211);
	m_guiDDL_3->addSpacer();
	m_DDL_3 = m_guiDDL_3->addDropDownList("Groupes", m_dataDDL_3);
	m_DDL_3->setAllowMultiple(false);
	m_DDL_3->setAutoClose(true);
	m_guiDDL_3->autoSizeToFitWidgets();
	ofAddListener(m_guiDDL_3->newGUIEvent, this, &ofApp::guiEvent_DropDownList);

	// Parametres
	m_couleurR = 0, m_couleurB = 0, m_couleurG = 0, m_couleurA = 255;
	m_positionX = (m_rectDesktop.right / 2), m_positionY = (m_rectDesktop.bottom / 2), m_positionZ = 0;
	m_rotationX = 0, m_rotationY = 0, m_rotationZ = 0;
	m_maxWidthPosition = m_rectDesktop.right, m_maxHeightPosition = m_rectDesktop.bottom;
	m_drawFillVisible = true;
	m_valeurDimension = "0.0";

	m_guiParametres = new ofxUISuperCanvas("Parametres", ofGetWidth() - 211, 0, 211, 211);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabel("Dimension");
	m_guiParametres->addTextInput("m_valeurDimension", m_valeurDimension);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabel("Position XYZ");
	m_guiParametres->addSlider("X", 0.0, (m_maxWidthPosition), &m_positionX);
	m_guiParametres->addSlider("Y", 0.0, (m_maxHeightPosition), &m_positionY);
	m_guiParametres->addSlider("Z", 0.0, (m_maxWidthPosition), &m_positionZ);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabel("Rotation XYZ");
	m_guiParametres->addSlider("X", 0.0, (360), &m_rotationX);
	m_guiParametres->addSlider("Y", 0.0, (360), &m_rotationY);
	m_guiParametres->addSlider("Z", 0.0, (360), &m_rotationZ);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabel("Couleur RGBA");
	m_guiParametres->addSlider("RED", 0.0, 255.0, &m_couleurR);
	m_guiParametres->addSlider("GREEN", 0.0, 255.0, &m_couleurG);
	m_guiParametres->addSlider("BLUE", 0.0, 255.0, &m_couleurB);
	m_guiParametres->addSlider("ALPHA", 0.0, 255.0, &m_couleurA);
	m_guiParametres->addSpacer();
	m_DDL_4 = m_guiParametres->addDropDownList("Selection Groupe", m_dataDDL_4);
	m_DDL_4->setAllowMultiple(false);
	m_DDL_4->setAutoClose(true);
	m_guiParametres->addSpacer();
	m_DDL_5 = m_guiParametres->addDropDownList("Selection Image", m_dataDDL_5);
	m_DDL_5->setAllowMultiple(false);
	m_DDL_5->setAutoClose(true);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabelToggle("VISIBLE", &m_drawFillVisible);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabelButton("Valider", false);
	m_guiParametres->addLabelButton("Annuler", false);
	m_guiParametres->autoSizeToFitWidgets();
	ofAddListener(m_guiParametres->newGUIEvent, this, &ofApp::guiEvent_Proprietes);
	m_guiParametres->setVisible(true);

	// Créer groupe - Autres créer
	m_nomNouveauGroupe = "";
	m_ActionCreer = -1;
	//////////////////////////////////////////////////
	#pragma endregion
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	#pragma region Gestion - Interface
	//////////////////////////////////////////////////
	if (m_ActionCreer == -1)
	{
		m_menu.draw();
	}

	ofSetColor(0, 0, 0);
	ofDrawBitmapString("F1 - Afficher l'interface", 10, (ofGetHeight() - 35));
	ofDrawBitmapString("Clic droit - Afficher le menu", 10, (ofGetHeight() - 15));
	//////////////////////////////////////////////////
	#pragma endregion

	//Primitives
	list<Primitive*>::iterator it = this->primitives.begin();

	for (it = this->primitives.begin(); it != this->primitives.end(); ++it)
	{
		string nomClasse = typeid(*it).name();

		if(nomClasse == "_Line")
			(dynamic_cast<_Line*>(*it))->draw();
		else if(nomClasse == "Triangle")
			(dynamic_cast<Triangle*>(*it))->draw();
		else
			cout << "Mauvais typage sur Primitive";
	}

	//Formes
	list<Form*>::iterator it2 = this->forms.begin();

	for (it2 = this->forms.begin(); it2 != this->forms.end(); ++it2)
	{
		string nomClasse = typeid(*it2).name();

		if (nomClasse == "Cube")
			(dynamic_cast<Cube*>(*it))->draw();
		else if (nomClasse == "Sphere")
			(dynamic_cast<Sphere*>(*it))->draw();
		else if (nomClasse == "Modele3D")
			(dynamic_cast<Modele3D*>(*it))->draw();
		else
			cout << "Mauvais typage sur Forme";
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	switch (key)
	{
	case 257:
	{
		m_guiDDL_1->toggleVisible();
		m_guiDDL_2->toggleVisible();
		m_guiDDL_3->toggleVisible();
		m_guiParametres->toggleVisible();
	}
	break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	guiEvent_DoAction(m_menu.hitTest());
<<<<<<< HEAD
=======

	switch(m_creation)
	{
	case 0 : //Rien à créer
		if(positionSouris.size() > 0)
			positionSouris.clear();
		break;
	case 1 : //En création de ligne
		m_monPoint = new POINT();
		m_monPoint->x = x;
		m_monPoint->y = y;

		positionSouris.push_back(m_monPoint);
		
		if (positionSouris.size() == 2) {}
			//Créer ligne + réinitialiser liste positionSouris
		break;
	case 2 : //En création de triangle
		m_monPoint = new POINT();
		m_monPoint->x = x;
		m_monPoint->y = y;

		positionSouris.push_back(m_monPoint);
		
		if (positionSouris.size() == 3) {}
			//Créer triangle + réinitialiser liste positionSouris
		break;
	}
>>>>>>> origin/master
}	

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	#pragma region Gestion - Interface
	//////////////////////////////////////////////////
	m_guiParametres->setPosition(ofGetWidth() - 211, 0);
	m_guiFPS->setPosition((ofGetWidth() - 211), (ofGetHeight() - 35));
	//////////////////////////////////////////////////
	#pragma endregion
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::guiEvent_DoAction(int p_IdButton)
{
	if (p_IdButton != -1)
	{
		if (p_IdButton == 0)
		{
			if (m_ActionCreer == -1)
			{
				// Créer groupe
				m_ActionCreer = 0;

				m_guiCreerGroupe = new ofxUISuperCanvas("Nouveau groupe", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
				m_guiCreerGroupe->addSpacer();
				m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
				m_guiCreerGroupe->addSpacer();
				m_guiCreerGroupe->addLabelButton("Valider", false);
				m_guiCreerGroupe->addLabelButton("Annuler", false);
				m_guiCreerGroupe->autoSizeToFitWidgets();
				ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
				m_guiCreerGroupe->setVisible(true);
			}
		}
		else if (p_IdButton == 1)
		{
			// Création 3D

			/*
			INSERT CODE HERE
			*/
		}
		else if (p_IdButton == 2)
		{
			// Création 2D

			/*
			INSERT CODE HERE
			*/
		}
		else if (p_IdButton == 3)
		{
			// Importer

			/*
			INSERT CODE HERE
			*/
		}
		else if (p_IdButton == 4)
		{
			// Quitter l'application
			exit();
		}
		else if (p_IdButton == 5)
		{
			if (m_ActionCreer == -1)
			{
				// Exporter
				m_ActionCreer = 1;

				m_guiCreerGroupe = new ofxUISuperCanvas("Exporter un fichier", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
				m_guiCreerGroupe->addSpacer();
				m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
				m_guiCreerGroupe->addSpacer();
				m_guiCreerGroupe->addLabelButton("Valider", false);
				m_guiCreerGroupe->addLabelButton("Annuler", false);
				m_guiCreerGroupe->autoSizeToFitWidgets();
				ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
				m_guiCreerGroupe->setVisible(true);
			}
		}
	}
}

void ofApp::guiEvent_DropDownList(ofxUIEventArgs &e)
{
	string m_nomWidget = e.widget->getName();
	int m_kindWidget = e.widget->getKind();

	if (m_kindWidget == OFX_UI_WIDGET_DROPDOWNLIST)
	{
		if (m_nomWidget == "Elements 2D")
		{
			ofxUIToggle *toggle = (ofxUIToggle*)e.widget;
			m_DDL_1->setShowCurrentSelected(toggle->getValue());

			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();
			for (int i = 0; i < m_selectedDDL.size(); i++)
			{
			}
		}
		else if (m_nomWidget == "Elements 3D")
		{
			ofxUIToggle *toggle = (ofxUIToggle*)e.widget;
			m_DDL_2->setShowCurrentSelected(toggle->getValue());

			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();
			for (int i = 0; i < m_selectedDDL.size(); i++)
			{
			}
		}
		else if (m_nomWidget == "Groupes")
		{
			ofxUIToggle *toggle = (ofxUIToggle*)e.widget;
			m_DDL_3->setShowCurrentSelected(toggle->getValue());

			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();
			for (int i = 0; i < m_selectedDDL.size(); i++)
			{
			}
		}
	}
}

void ofApp::guiEvent_Proprietes(ofxUIEventArgs &e)
{
	string m_nomWidget = e.widget->getName();
	int m_kindWidget = e.widget->getKind();

	if (m_kindWidget == OFX_UI_WIDGET_TEXTINPUT)
	{
		ofxUITextInput *txtinput = (ofxUITextInput*)e.widget;
		m_valeurDimension = txtinput->getTextString();

		cout << m_valeurDimension << endl;

		txtinput->setAutoClear(false);
	}
}

void ofApp::guiEvent_CreerGroupe(ofxUIEventArgs &e)
{
	string m_nomWidget = e.widget->getName();
	int m_kindWidget = e.widget->getKind();

	if (m_kindWidget == OFX_UI_WIDGET_TEXTINPUT)
	{
		ofxUITextInput *txtinput = (ofxUITextInput*)e.widget;
		m_nomNouveauGroupe = txtinput->getTextString();
		txtinput->setAutoClear(false);
	}
	else if (m_kindWidget == OFX_UI_WIDGET_LABELBUTTON)
	{
		if (m_nomWidget == "Valider")
		{
			if (m_ActionCreer == 0)
			{
				cout << m_nomNouveauGroupe << endl;

				Group * m_nouveauGroupe = new Group(m_nomNouveauGroupe);
				groups.push_back(m_nouveauGroupe);

				m_DDL_3->addToggle(m_nomNouveauGroupe);
			}
			else if (m_ActionCreer == 1)
			{

			}

			m_ActionCreer = -1;
			ofxUITextInput *txtinput = (ofxUITextInput*)m_guiCreerGroupe->getWidget("m_ti_CreerGroupe");
			txtinput->setTextString("");
			m_guiCreerGroupe->clearEmbeddedWidgets();
			m_guiCreerGroupe->setVisible(false);
		}
		else if (m_nomWidget == "Annuler")
		{
			m_ActionCreer = -1;

			cout << "ANNULER" << endl;

			ofxUITextInput *txtinput = (ofxUITextInput*)m_guiCreerGroupe->getWidget("m_ti_CreerGroupe");
			txtinput->setTextString("");

			m_guiCreerGroupe->clearEmbeddedWidgets();
			m_guiCreerGroupe->setVisible(false);
		}
	}
}