#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetCircleResolution(100);
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

	m_bkMenu.setup();
	m_bkMenu.setRadius(80, 240);
	m_bkMenu.addMenuItem("Creer groupe");		// 0
	m_bkMenu.addMenuItem("Creation 3D");		// 1
	m_bkMenu.addMenuItem("Creation 2D");		// 2
	m_bkMenu.addMenuItem("Importer");			// 3
	m_bkMenu.addMenuItem("Quitter");			// 4
	m_bkMenu.addMenuItem("Exporter");			// 5
	m_bkMenu.enableMouseControl();
	
	m_bkMenu2D.setup();
	m_bkMenu2D.setRadius(50, 150);
	m_bkMenu2D.addMenuItem("Ligne");			// 0
	m_bkMenu2D.addMenuItem("Triangle");			// 1
	m_bkMenu2D.addMenuItem("Annuler");			// 2
	m_bkMenu2D.enableMouseControl();

	m_bkMenu3D.setup();
	m_bkMenu3D.setRadius(50, 150);
	m_bkMenu3D.addMenuItem("Cube");				// 0
	m_bkMenu3D.addMenuItem("Sphere");			// 1
	m_bkMenu3D.addMenuItem("Annuler");			// 2
	m_bkMenu3D.enableMouseControl();
	
	m_selectedMenu.setup();
	m_selectedMenu = m_bkMenu;
	m_selectedMenu.setListener(m_listener);

	m_sousMenuInt = -1;
	m_sousMenuBool = false;

	// DropDownList
	m_guiDDL_1 = new ofxUISuperCanvas("Liste d'elements 2D", 0, 0, 200, 211);
	m_guiDDL_1->addSpacer();
	m_DDL_1 = m_guiDDL_1->addDropDownList("Elements 2D", m_dataDDL_1);
	m_DDL_1->setAllowMultiple(false);
	m_DDL_1->setAutoClose(true);
	m_guiDDL_1->autoSizeToFitWidgets();
	ofAddListener(m_guiDDL_1->newGUIEvent, this, &ofApp::guiEvent_DropDownList);

	m_guiDDL_2 = new ofxUISuperCanvas("Liste d'elements 3D", 201, 0, 200, 211);
	m_guiDDL_2->addSpacer();
	m_DDL_2 = m_guiDDL_2->addDropDownList("Elements 3D", m_dataDDL_2);
	m_DDL_2->setAllowMultiple(false);
	m_DDL_2->setAutoClose(true);
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
	
	//slider = new ofxUISlider("Position X",0,500,300,0,0);
	
	m_guiParametres = new ofxUISuperCanvas("Parametres", ofGetWidth() - 211, 0, 211, 211);
	m_guiParametres->addSpacer();
	m_guiParametres->addLabel("Dimension");
	m_guiParametres->addTextInput("m_valeurDimension", m_valeurDimension);
	m_guiParametres->addSpacer();
	m_sliderXPosition = m_guiParametres->addSlider("Position X", 0.0, (m_maxWidthPosition), &m_positionX);
	m_sliderYPosition = m_guiParametres->addSlider("Position Y", 0.0, (m_maxHeightPosition), &m_positionY);
	m_sliderZPosition = m_guiParametres->addSlider("Position Z", 0.0, (m_maxWidthPosition), &m_positionZ);
	m_guiParametres->addSpacer();
	m_sliderXRotation = m_guiParametres->addSlider("Rotation X", 0.0, (360), &m_rotationX);
	m_sliderYRotation = m_guiParametres->addSlider("Rotation Y", 0.0, (360), &m_rotationY);
	m_sliderZRotation = m_guiParametres->addSlider("Rotation Z", 0.0, (360), &m_rotationZ);
	m_guiParametres->addSpacer();
	m_sliderRed = m_guiParametres->addSlider("RED", 0.0, 255.0, &m_couleurR);
	m_sliderGreen = m_guiParametres->addSlider("GREEN", 0.0, 255.0, &m_couleurG);
	m_sliderBlue = m_guiParametres->addSlider("BLUE", 0.0, 255.0, &m_couleurB);
	m_sliderAlpha = m_guiParametres->addSlider("ALPHA", 0.0, 255.0, &m_couleurA);
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

	// Cr�er groupe - Autres cr�er
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
	m_selectedMenu.draw();

	ofSetColor(0, 0, 0);
	ofDrawBitmapString("F1 - Afficher l'interface", 10, (ofGetHeight() - 35));
	ofDrawBitmapString("Clic droit - Afficher le menu (et sous-menu)", 10, (ofGetHeight() - 15));
	//////////////////////////////////////////////////
	#pragma endregion

	//Primitives
	list<Primitive*>::iterator it = this->primitives.begin();

	for (it = this->primitives.begin(); it != this->primitives.end(); ++it)
	{
		string nomClasse = typeid(**it).name();

		if(nomClasse == "class _Line")
		{
			Primitive *Lparent = (*it);
			_Line *Lenfant = (dynamic_cast<_Line *>(Lparent));
			Lenfant->draw();
		}
		else if(nomClasse == "class Triangle")
		{
			Primitive *Tparent = (*it);
			Triangle *Tenfant = (dynamic_cast<Triangle *>(Tparent));
			Tenfant->draw();
		}
		else
			cout << "Mauvais typage sur Primitive";
	}

	//Formes
	list<Form*>::iterator it2 = this->forms.begin();

	for (it2 = this->forms.begin(); it2 != this->forms.end(); ++it2)
	{
		string nomClasse = typeid(**it2).name();

		if (nomClasse == "class Cube")
		{
			Form *Cparent = (*it2);
			Cube *Cenfant = (dynamic_cast<Cube *>(Cparent));
			if (Cenfant->GetTexture() != NULL)
			{
				Cenfant->drawOnCube();
			}
			else
			{
				Cenfant->draw();
			}
			
		}
		else if (nomClasse == "class Sphere")
		{
			Form *Sparent = (*it2);
			Sphere *Senfant = (dynamic_cast<Sphere *>(Sparent));
			if (Senfant->GetTexture() != NULL)
			{
				Senfant->drawWithTexture();
			}
			else
			{
				Senfant->draw();
			}
		}
		else if (nomClasse == "class Modele3D")
		{
			Form *Mparent = (*it2);
			Modele3D *Menfant = (dynamic_cast<Modele3D *>(Mparent));
			Menfant->draw();
		}
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

	guiEvent_DoAction(m_selectedMenu.hitTest());

	switch(m_creation)
	{
	case 0 : //Rien � cr�er
		if(positionSouris.size() > 0)
			positionSouris.clear();
		break;
	case 1 : //En cr�ation de ligne
		m_monPoint = new POINT();
		m_monPoint->x = x;
		m_monPoint->y = y;

		positionSouris.push_back(m_monPoint);
		
		if (positionSouris.size() == 2) {}
			//Cr�er ligne + r�initialiser liste positionSouris
		break;
	case 2 : //En cr�ation de triangle
		m_monPoint = new POINT();
		m_monPoint->x = x;
		m_monPoint->y = y;

		positionSouris.push_back(m_monPoint);
		
		if (positionSouris.size() == 3) {}
			//Cr�er triangle + r�initialiser liste positionSouris
		break;
	}
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
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}

void ofApp::guiEvent_DoAction(int p_IdButton)
{
	if (p_IdButton != -1)
	{
		if (m_sousMenuBool == false)
		{
			if (p_IdButton == 0)
			{
				if (m_ActionCreer == -1)
				{
					// Cr�er groupe
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

					m_selectedMenu.setup();
					m_selectedMenu = m_bkMenu;
					m_selectedMenu.setListener(m_listener);
				}
			}
			else if (p_IdButton == 1)
			{
				// Cr�ation 3D
				//m_selectedMenu = m_bkMenu3D;
				m_sousMenuInt = 1;
				m_sousMenuBool = true;

				m_selectedMenu.setup();
				m_selectedMenu = m_bkMenu3D;
				m_selectedMenu.setListener(m_listener);
			}
			else if (p_IdButton == 2)
			{
				// Cr�ation 2D
				m_sousMenuInt = 0;
				m_sousMenuBool = true;

				m_selectedMenu.setup();
				m_selectedMenu = m_bkMenu2D;
				m_selectedMenu.setListener(m_listener);

			}
			else if (p_IdButton == 3)
			{
				// Importer
				if (m_ActionCreer == -1)
				{
					ofImage* image = util.ImportImage();
					if (image != NULL)
					{
						this->images.push_back(image);
						m_ActionCreer = 2;

						m_guiCreerGroupe = new ofxUISuperCanvas("Nom de l'image", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
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

				m_selectedMenu.setup();
				m_selectedMenu = m_bkMenu;
				m_selectedMenu.setListener(m_listener);
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

					m_guiCreerGroupe = new ofxUISuperCanvas("Nom de l'image", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 300, 211);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addLabelButton("Valider", false);
					m_guiCreerGroupe->addLabelButton("Annuler", false);
					m_guiCreerGroupe->autoSizeToFitWidgets();
					ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
					m_guiCreerGroupe->setVisible(true);
				}

				m_selectedMenu.setup();
				m_selectedMenu = m_bkMenu;
				m_selectedMenu.setListener(m_listener);
			}
		}
		else
		{
			if (m_sousMenuInt == 0)
			{
				if (p_IdButton == 0)
				{
					// Ligne
					m_ActionCreer = 3;
					m_guiCreerGroupe = new ofxUISuperCanvas("Nom de la ligne", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addLabelButton("Valider", false);
					m_guiCreerGroupe->addLabelButton("Annuler", false);
					m_guiCreerGroupe->autoSizeToFitWidgets();
					ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
					m_guiCreerGroupe->setVisible(true);
					
					m_selectedMenu.setup();
					m_selectedMenu = m_bkMenu;
					m_selectedMenu.setListener(m_listener);
					m_sousMenuBool = false;
					m_sousMenuInt = -1;
				}
				else if (p_IdButton == 1)
				{
					// Triangle
					m_ActionCreer = 4;
					m_guiCreerGroupe = new ofxUISuperCanvas("Nom du triangle", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addLabelButton("Valider", false);
					m_guiCreerGroupe->addLabelButton("Annuler", false);
					m_guiCreerGroupe->autoSizeToFitWidgets();
					ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
					m_guiCreerGroupe->setVisible(true);

					m_selectedMenu.setup();
					m_selectedMenu = m_bkMenu;
					m_selectedMenu.setListener(m_listener);
					m_sousMenuBool = false;
					m_sousMenuInt = -1;
				}
				else
				{
					m_selectedMenu.setup();
					m_selectedMenu = m_bkMenu;
					m_selectedMenu.setListener(m_listener);
					m_sousMenuBool = false;
					m_sousMenuInt = -1;
				}
			}
			else if (m_sousMenuInt == 1)
			{
				if (p_IdButton == 0)
				{
					// Cube
					m_ActionCreer = 5;
					m_guiCreerGroupe = new ofxUISuperCanvas("Nom du cube", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addLabelButton("Valider", false);
					m_guiCreerGroupe->addLabelButton("Annuler", false);
					m_guiCreerGroupe->autoSizeToFitWidgets();
					ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
					m_guiCreerGroupe->setVisible(true);
					
					m_selectedMenu.setup();
					m_selectedMenu = m_bkMenu;
					m_selectedMenu.setListener(m_listener);
					m_sousMenuBool = false;
					m_sousMenuInt = -1;
				}
				else if (p_IdButton == 1)
				{
					// Sphere

					m_guiCreerGroupe = new ofxUISuperCanvas("Nom de la sphere", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 200, 211);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addTextInput("m_ti_CreerGroupe", m_nomNouveauGroupe);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addLabelButton("Valider", false);
					m_guiCreerGroupe->addLabelButton("Annuler", false);
					m_guiCreerGroupe->autoSizeToFitWidgets();
					ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
					m_guiCreerGroupe->setVisible(true);
					
					m_selectedMenu.setup();
					m_selectedMenu = m_bkMenu;
					m_selectedMenu.setListener(m_listener);
					m_ActionCreer = 6;
					m_sousMenuBool = false;
					m_sousMenuInt = -1;
				}
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

			list<Primitive*>::iterator it = this->primitives.begin();

			for (it; it != this->primitives.end(); it++)
			{
				(*it)->SetSelected(false);
			}
			
			if (m_selectedDDL.size() > 0)
			{
				unselectAll(m_nomWidget);
				it = this->primitives.begin();
				for (it; it != this->primitives.end(); it++)
				{
					if (m_selectedDDL.at(0)->getName() == (*it)->GetNom())
					{
						(*it)->SetSelected(true);
						m_positionX = (*it)->GetX();
						m_positionY = (*it)->GetY();
						m_positionZ = (*it)->GetZ();
						m_rotationX = (*it)->GetRotationX();
						m_rotationY = (*it)->GetRotationY();
						m_rotationZ = (*it)->GetRotationZ();
						m_couleurR = (float)(*it)->GetColor().r;
						m_couleurG = (float)(*it)->GetColor().g;
						m_couleurB = (float)(*it)->GetColor().b;
						m_couleurA = (float)(*it)->GetColor().a;
					}
				}
			}
			/*for (int i = 0; i < m_selectedDDL.size(); i++)
			{
			if (m_selectedDDL.at(i)->getName() == (*it)->GetNom())
			{
			(*it)->SetSelected(true);
			}
			it++;
			}*/
		}
		else if (m_nomWidget == "Elements 3D")
		{

			ofxUIToggle *toggle = (ofxUIToggle*)e.widget;
			m_DDL_2->setShowCurrentSelected(toggle->getValue());
			
			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();

			list<Form*>::iterator it = this->forms.begin();

			for (it; it != this->forms.end(); it++)
			{
				(*it)->SetSelected(false);
			}

			if (m_selectedDDL.size() > 0)
			{
				unselectAll(m_nomWidget);
				it = this->forms.begin();
				for (it; it != this->forms.end(); it++)
				{
					if (m_selectedDDL.at(0)->getName() == (*it)->GetNom())
					{
						(*it)->SetSelected(true);
						m_positionX = (*it)->GetX();
						m_positionY = (*it)->GetY();
						m_positionZ = (*it)->GetZ();
						m_rotationX = (*it)->GetRotationX();
						m_rotationY = (*it)->GetRotationY();
						m_rotationZ = (*it)->GetRotationZ();
						m_couleurR = (float)(*it)->GetColor().r;
						m_couleurG = (float)(*it)->GetColor().g;
						m_couleurB = (float)(*it)->GetColor().b;
						m_couleurA = (float)(*it)->GetColor().a;
					}
				}
			}
			/*for (int i = 0; i < m_selectedDDL.size(); i++)
			{
				if (m_selectedDDL.at(i)->getName() == (*it)->GetNom())
				{
					(*it)->SetSelected(true);
				}
				it++;
			}*/

		}
		else if (m_nomWidget == "Groupes")
		{
			ofxUIToggle *toggle = (ofxUIToggle*)e.widget;
			m_DDL_3->setShowCurrentSelected(toggle->getValue());

			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();
			list<Group*>::iterator it = this->groups.begin();

			if (m_selectedDDL.size() >  0)
				unselectAll(m_nomWidget);

			for (it; it != this->groups.end(); it++)
			{
				(*it)->SetSelected(false);
			}
			
			if (m_selectedDDL.size() > 0)
			{
				unselectAll(m_nomWidget);
				it = this->groups.begin();
				for (it; it != this->groups.end(); it++)
				{
					if (m_selectedDDL.at(0)->getName() == (*it)->GetNom())
					{
						(*it)->SetSelected(true);
						m_positionX = (*it)->GetX();
						m_positionY = (*it)->GetY();
						m_positionZ = (*it)->GetZ();
						m_rotationX = (*it)->GetRotationX();
						m_rotationY = (*it)->GetRotationY();
						m_rotationZ = (*it)->GetRotationZ();
						m_couleurR = (float)(*it)->GetColor().r;
						m_couleurG = (float)(*it)->GetColor().g;
						m_couleurB = (float)(*it)->GetColor().b;
						m_couleurA = (float)(*it)->GetColor().a;
					}
				}
			}
			/*for (int i = 0; i < m_selectedDDL.size(); i++)
			{
			if (m_selectedDDL.at(i)->getName() == (*it)->GetNom())
			{
			(*it)->SetSelected(true);
			}
			it++;
			}*/
		}
	}
}

void ofApp::guiEvent_Proprietes(ofxUIEventArgs &e)
{
	string m_nomWidget = e.widget->getName();
	int m_kindWidget = e.widget->getKind();

	if (m_kindWidget == OFX_UI_WIDGET_TEXTINPUT)
	{
		ofxUITextInput *m_texteInput = (ofxUITextInput*)e.widget;

		if (m_nomWidget == "Dimension")
		{
			m_valeurDimension = m_texteInput->getTextString();
			m_texteInput->setAutoClear(false);
		}
	}
	else if (m_kindWidget == OFX_UI_WIDGET_SLIDER_H)
	{
		ofxUIIntSlider *m_slider = (ofxUIIntSlider*)e.widget;

		m_positionX = m_sliderXPosition->getValue();
		m_positionY = m_sliderYPosition->getValue();
		m_positionZ = m_sliderZPosition->getValue();

		m_rotationX = m_sliderXRotation->getValue();
		m_rotationY = m_sliderYRotation->getValue();
		m_rotationZ = m_sliderZRotation->getValue();

		m_couleurR = m_sliderRed->getValue();
		m_couleurG = m_sliderGreen->getValue();
		m_couleurB = m_sliderBlue->getValue();
		m_couleurA = m_sliderAlpha->getValue();

		list<Group*>::iterator itGroup = this->groups.begin();
		for (itGroup; itGroup != this->groups.end(); itGroup++)
		{
			if ((*itGroup)->IsSelected())
			{
				(*itGroup)->SetPosition(m_positionX, m_positionY, m_positionZ);
				(*itGroup)->Rotate(m_rotationX, m_rotationY, m_rotationZ);
				(*itGroup)->SetColor(ofColor(m_couleurR, m_couleurG, m_couleurB, m_couleurA));
			}
		}

		list<Form*>::iterator itFrom = this->forms.begin();
		for (itFrom; itFrom != this->forms.end(); itFrom++)
		{
			if ((*itFrom)->IsSelected())
			{
				(*itFrom)->SetPosition(m_positionX, m_positionY, m_positionZ);
				(*itFrom)->Rotate(m_rotationX, m_rotationY, m_rotationZ);
				(*itFrom)->SetColor(ofColor(m_couleurR, m_couleurG, m_couleurB, m_couleurA));
			}
		}

		list<Primitive*>::iterator itPrimitive = this->primitives.begin();
		for (itPrimitive; itPrimitive != this->primitives.end(); itPrimitive++)
		{
			if ((*itPrimitive)->IsSelected())
			{
				(*itPrimitive)->SetPosition(m_positionX, m_positionY, m_positionZ);
				(*itPrimitive)->Rotate(m_rotationX, m_rotationY, m_rotationZ);
				(*itPrimitive)->SetColor(ofColor(m_couleurR, m_couleurG, m_couleurB, m_couleurA));
			}
		}
	}
	else if (m_kindWidget == OFX_UI_WIDGET_DROPDOWNLIST)
	{
		if (m_nomWidget == "Selection Groupe")
		{
			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();


		}
		else if (m_nomWidget == "Selection Image")
		{
			ofxUIDropDownList *m_DDL_Temp = (ofxUIDropDownList*)e.widget;
			vector<ofxUIWidget *> &m_selectedDDL = m_DDL_Temp->getSelected();
			
			if (m_selectedDDL.size() != 0)
			{
				list<ofImage*>::iterator it = this->images.begin();

				for (int i = 0; i < this->noms_images.size(); i++)
				{
					if (*noms_images.at(i) == m_selectedDDL.at(0)->getName())
					{
						this->imageSelected = *it;
						break;
					}
					it++;
				}
				
				list<Form*>::iterator it2 = this->forms.begin();
				bool formsSelected = false;

				for (it2 ; it2 != this->forms.end(); it2++)
				{
					if ((*it2)->IsSelected())
					{
						formsSelected = true;
						break;
					}
				}

				if (formsSelected)
				{
					m_guiCreerGroupe = new ofxUISuperCanvas("Application de l'image", ((ofGetWidth() / 2) - (100)), ((ofGetHeight() / 2) - (100)), 300, 211);
					m_guiCreerGroupe->addSpacer();
					m_guiCreerGroupe->addLabel("Voulez-vous appliquer");
					m_guiCreerGroupe->addLabel("cette texture a");
					m_guiCreerGroupe->addLabel("l'objet selectionne?");
					m_guiCreerGroupe->addLabelButton("Oui", false);
					m_guiCreerGroupe->addLabelButton("Non", false);
					m_guiCreerGroupe->autoSizeToFitWidgets();
					ofAddListener(m_guiCreerGroupe->newGUIEvent, this, &ofApp::guiEvent_CreerGroupe);
					m_guiCreerGroupe->setVisible(true);

					m_sousMenuBool = false;
					m_sousMenuInt = -1;
				}
			}
			m_DDL_Temp->clearSelected();

		}
	}
	else if (m_kindWidget == OFX_UI_WIDGET_LABELTOGGLE)
	{

		if (m_nomWidget == "VISIBLE")
		{
		}
	}
	else if (m_kindWidget == OFX_UI_WIDGET_LABELBUTTON)
	{
		if (m_nomWidget == "Valider")
		{

		}
		else if (m_nomWidget == "Annuler")
		{

		}
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
				Group * m_nouveauGroupe = new Group(m_nomNouveauGroupe);
				groups.push_back(m_nouveauGroupe);

				m_DDL_3->addToggle(m_nomNouveauGroupe);
			}
			else if (m_ActionCreer == 1)
			{
				// Exporter
				string nomImage = m_nomNouveauGroupe;
				cout << nomImage << endl;

				list<ofImage*>::iterator it = this->images.begin();
				bool trouvee = false;

				for (int i = 0 ; i < this->noms_images.size(); ++i)
				{
					if (nomImage == *(this->noms_images.at(i)))
					{
						util.ExportImage(*it);
						trouvee = true;
						break;
					}
					it++;
				}
				if (!trouvee)
				{
					wstring s(L"Cette image n'existe pas");
					wstring s2(L"Image inexistante");
					MessageBox(NULL, (LPCWSTR)s.c_str(), (LPCWSTR)s2.c_str(), MB_OK);
				}

			}
			else if (m_ActionCreer == 2)
			{
				// Importer
				string* nomImage = &(m_nomNouveauGroupe);
				m_DDL_5->addToggle(*nomImage);
				this->noms_images.push_back(nomImage);

			}
			else if (m_ActionCreer == 3)
			{
				// Ligne
				string nomLine = m_nomNouveauGroupe;
				this->primitives.push_back(new _Line(nomLine, ofPoint(300, 300, 0), ofPoint(400, 300, 0)));
				m_DDL_1->addToggle(nomLine);
				m_dataDDL_1.push_back(nomLine);
			}
			else if (m_ActionCreer == 4)
			{
				// Triangle
				string nomTriangle = m_nomNouveauGroupe;
				this->primitives.push_back(new Triangle(nomTriangle, ofPoint(300, 300, 0), ofPoint(400, 300, 0), ofPoint(350, 400, 0)));
				m_DDL_1->addToggle(nomTriangle);
				m_dataDDL_1.push_back(nomTriangle);
			}
			else if (m_ActionCreer == 5)
			{
				// Cube
				string nomCube = m_nomNouveauGroupe;
				this->forms.push_back(new Cube(nomCube, 500, 500, 0, 100, 100, 100));
				m_DDL_2->addToggle(nomCube);
				m_dataDDL_2.push_back(nomCube);
			}
			else if (m_ActionCreer == 6)
			{
				// Sphere
				string nomSphere = m_nomNouveauGroupe;
				this->forms.push_back(new Sphere(nomSphere, 500, 500, 0, 100));
				m_DDL_2->addToggle(nomSphere);
				m_dataDDL_2.push_back(nomSphere);
			}
		}
		else if (m_nomWidget == "Annuler")
		{
			if (m_ActionCreer == 2)
			{
				this->images.pop_back();
			}
		}
		else if (m_nomWidget == "Oui")
		{
			list<Form*>::iterator it = this->forms.begin();

			for (it; it != this->forms.end(); it++)
			{
				if ((*it)->IsSelected())
				{
					(*it)->SetTexture(this->imageSelected);
				}
			}
		}
		else if (m_nomWidget == "Non")
		{
		}
		hideMessageBox();
	}
}

void ofApp::hideMessageBox()
{
	m_ActionCreer = -1;
	ofxUITextInput *txtinput = (ofxUITextInput*)m_guiCreerGroupe->getWidget("m_ti_CreerGroupe");
	txtinput->setTextString("");
	m_guiCreerGroupe->clearEmbeddedWidgets();
	m_guiCreerGroupe->setPosition(-100, -100);
	m_guiCreerGroupe->setVisible(false);
	m_guiCreerGroupe = NULL;
}

void ofApp::unselectAll(string _expception)
{
	list<Group*>::iterator itGroup = this->groups.begin();
	list<Form*>::iterator itFrom = this->forms.begin();
	list<Primitive*>::iterator itPrimitive = this->primitives.begin();
	if (_expception == "Elements 2D")
	{
		for (itFrom; itFrom != this->forms.end(); itFrom++)
		{
			(*itFrom)->SetSelected(false);
		}
		m_DDL_2->clearSelected();
		m_dataDDL_2.clear();

		for (itGroup; itGroup != this->groups.end(); itGroup++)
		{
			(*itGroup)->SetSelected(false);
		}
		m_DDL_3->clearSelected();
		m_dataDDL_3.clear();
	}
	else if (_expception == "Elements 3D")
	{
		for (itGroup; itGroup != this->groups.end(); itGroup++)
		{
			(*itGroup)->SetSelected(false);
		}
		m_DDL_3->clearSelected();
		m_dataDDL_3.clear();

		for (itPrimitive; itPrimitive != this->primitives.end(); itPrimitive++)
		{
			(*itPrimitive)->SetSelected(false);
		}
		m_DDL_1->clearSelected();
		m_dataDDL_1.clear();
	}
	else if (_expception == "Groupes")
	{
		for (itPrimitive; itPrimitive != this->primitives.end(); itPrimitive++)
		{
			(*itPrimitive)->SetSelected(false);
		}
		m_DDL_1->clearSelected();
		m_dataDDL_1.clear();

		for (itFrom; itFrom != this->forms.end(); itFrom++)
		{
			(*itFrom)->SetSelected(false);
		}
		m_DDL_2->clearSelected();
		m_dataDDL_2.clear();
	}
}