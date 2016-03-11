#pragma once

#include <string>
#include "ofMain.h"
#include "windows.h"

using namespace std;

class Utilities
{

public:
	Utilities();
	~Utilities();

	ofImage* ImportImage();
	void ExportImage(ofImage *_image);

};

