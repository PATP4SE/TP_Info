#pragma once

#include <string>
#include "ofMain.h"

class Group
{
public:
	template <typename T>
	std::list<std::pair<int typeObjet, string> > m_ElementGroupe;
	string m_nomGroupe;

	Group();
	Group(string p_nom);
	~Group();

	//void ajoutGroupe(int p_type, T* p_objet);
};

