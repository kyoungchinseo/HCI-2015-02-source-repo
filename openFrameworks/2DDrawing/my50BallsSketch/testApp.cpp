#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	centerX = ofGetWindowWidth()/2.0f;
	centerY = ofGetWindowHeight()/2.0f;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0,0,0,100);

	for(int i=0;i<50;i++) {
		ofSetColor(200,200,200,50);
		ofCircle(centerX-(centerX - mouseX)/50.0 * i, 
				 centerY-(centerY - mouseY)/50.0 * i,
				 i*2);

	}
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
