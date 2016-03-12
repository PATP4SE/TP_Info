#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor(ofColor(224, 224, 224));
	this->cube = new Cube(500, 500, 200, 200, 100, 100);

	listener = new ofxCircleMenuButtonListener();

	m.setup();
	m.setRadius(60, 180);

	m.addMenuItem("Creation diverse");	// 0
	m.addMenuItem("Creation 3D");		// 1
	m.addMenuItem("Creation 2D");		// 2
	m.addMenuItem("Importer");			// 3
	m.addMenuItem("Quitter");			// 4
	m.addMenuItem("Exporter");			// 5

	m.enableMouseControl();

	m.setListener(listener);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw() {
	m.draw();
	this->cube->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	ofImage *image = util.ImportImage();
	image->draw(0, 0, 0, 100, 100);

	ofTexture *texture = new ofTexture();
	//texture->loadData()
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofxCircleMenuButtonListener::buttonClicked(int p_button)
{
	if (p_button == 0)
	{
		cout << "TEST_0" << endl;
	}
	else if (p_button == 1)
	{
		cout << "TEST_1" << endl;
	}
	else if (p_button == 2)
	{
		cout << "TEST_2" << endl;
	}
	else if (p_button == 3)
	{
		cout << "TEST_3" << endl;
	}
	else if (p_button == 4)
	{
		cout << "TEST_4" << endl;
	}
	else if (p_button == 5)
	{
		cout << "TEST_5" << endl;
	}
}
	