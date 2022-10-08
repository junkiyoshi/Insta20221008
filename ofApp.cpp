#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255, 25, 25);
	ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {

	this->mesh.clear();

	int size = 1;
	for (int x = 10; x <= ofGetWidth() - 10; x += size) {

		for (int y = 10; y <= ofGetHeight() - 10; y += size) {

			float deg = ofMap(ofNoise(x * 0.01, y * 0.01, ofGetFrameNum() * 0.03), 0, 1, -360, 360);
			this->mesh.addVertex(glm::vec3(x + size * 3 * cos(deg * DEG_TO_RAD), y + size * 3 * sin(deg * DEG_TO_RAD), 0));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofTranslate(ofGetWindowSize() * -0.5);

	this->mesh.drawVertices();

	this->cam.end();
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}