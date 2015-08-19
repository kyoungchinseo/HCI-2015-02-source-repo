#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	xPosition = ofGetWindowWidth()/2.0;
	yPosition = ofGetWindowHeight()/2.0;

	radius = 60;

	xSpeed = 2.8;
	ySpeed = 2.2;

	xDirection = 1;
	yDirection = 1;

	ofSetFrameRate(30);

	ofSetCircleResolution(36);
}

//--------------------------------------------------------------
void testApp::update(){
	xPosition += xSpeed * xDirection;
	yPosition += ySpeed * yDirection;

	if (xPosition > (ofGetWindowWidth() - radius) || xPosition < radius) {
		xDirection *= -1;
	}
	if (yPosition > (ofGetWindowHeight() - radius) || yPosition < radius) {
		yDirection *= -1;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(102);	

	ofSetColor(200,0,0,80);
	ofCircle(xPosition, yPosition, radius);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
