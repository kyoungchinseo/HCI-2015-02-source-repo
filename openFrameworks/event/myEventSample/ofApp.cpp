#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	fontMessage.loadFont("vag.ttf",16);
	ofBackground(50,50,50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(200,200,200);
	fontMessage.drawString(eventMessage,20,20);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	cout << "key press: " << key << endl;
	sprintf(eventMessage, "key press: %d", key);

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
	cout << "X: " << x << " Y: " << y << " button: " << button << endl;
	switch(button) {
	case 0:
		sprintf(eventMessage,"left mouse pressed at (%d,%d)",x,y);
		break;
	case 1:
		sprintf(eventMessage,"middle mouse pressed at (%d,%d)",x,y);
		break;
	case 2:
		sprintf(eventMessage,"right mouse pressed at (%d,%d)",x,y);
		break;
	default:
		sprintf(eventMessage,"mouse pressed at (%d,%d)",x,y);
		break;
	}	

	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
