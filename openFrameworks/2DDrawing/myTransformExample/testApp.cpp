#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(122,122,122);	
	ofSetFrameRate(60);

	rotateAmt = 0.0;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofPushMatrix();
		ofTranslate(100,100,0);		
		ofSetColor(255,0,0,100);
		ofFill();				
		ofRect(250,250,200,200);		
		ofPushMatrix();
			ofSetColor(0,255,0,100);
			ofFill();
			ofTranslate(mouseX - 350, 100);
			ofRect(100,100,200,200);
			ofPushMatrix();
				ofSetColor(0,0,255,100);
				ofFill();
				ofTranslate(100,mouseY - 350);				
				ofRect(100,100,200,200);
				ofPushMatrix();
					ofSetColor(255,255,255,100);
					ofFill();
					ofRotate(PI*rotateAmt);
					ofTranslate(-25,-25);
					ofRect(0,0,50,50);
				ofPopMatrix();
			ofPopMatrix();
		ofPopMatrix();
	ofPopMatrix();

	rotateAmt++;
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
