#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	position.set(100,100);
	velocity.set(1.5,2.1);
	gravity.set(0,0.2);

	radius = 60;

	ofSetFrameRate(30);
	ofSetCircleResolution(36);
}

//--------------------------------------------------------------
void testApp::update(){
	position = position + velocity;
	velocity = velocity + gravity;

	if (position.x > (ofGetWindowWidth() - radius) || position.x < radius){
		velocity.x *= -1.0f;
	}

	if (position.y > (ofGetWindowHeight() - radius)) {
		velocity.y = velocity.y * -0.95f;
		position.y = ofGetWindowHeight() - radius;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(102);	

	ofSetColor(200,0,0,80);
	ofCircle(position.x, position.y, radius);
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
