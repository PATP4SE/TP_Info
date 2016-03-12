#pragma once

<<<<<<< HEAD
#include "ofMain.h"
#include "ofxCircleMenuButton.h"
=======
#include <ofMain.h>
#include "../Cube.h"
#include "../Sphere.h"
#include "../Form.h"
#include "../Primitive.h"
#include "../_Line.h"
#include "../Triangle.h"
#include "../Transformation.h"
#include "../Group.h"
#include "../renderer.h"
#include "../Utilities.h"
>>>>>>> refs/remotes/origin/master

#include <list>

<<<<<<< HEAD
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
		ofxCircleMenuButton m;
		ofxCircleMenuButtonListener *listener;
=======
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
	Cube *cube;
	list<Form> *forms;
	list<Primitive> *primitives;
	list<Group> *groups;
	Utilities util;
		
>>>>>>> refs/remotes/origin/master
};
