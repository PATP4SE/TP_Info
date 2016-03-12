#include "Modele3D.h"

Modele3D::Modele3D()
{

}


Modele3D::~Modele3D()
{
}
/*
Modele3D::Modele3D(ofxAssimpModelLoader* p_modele, string p_nom)
{
m_monModele = p_modele;
m_nom = p_nom;
}

ofxAssimpModelLoader* Modele3D::chargerModele()
{
ofxAssimpModelLoader* modele = new ofxAssimpModelLoader();
ofFileDialogResult dialog;
string extension;

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