#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableNormalizedTexCoords();
	
	ofImage img;
	img.loadImage("hci.png");
	img.mirror(false, true);
    text.allocate(640, 640, GL_RGB, true);
    ang = 0;
	glEnable(GL_DEPTH_TEST); // enable depth testing, otherwise things will look really weird
    text.loadData(img.getPixels(), 640, 640, GL_RGB);
	
	light1.setPointLight();
	light2.setPointLight();
}

//--------------------------------------------------------------
void testApp::update(){
	light1.setPosition( cos(ofGetElapsedTimef()) * 400 + ofGetWidth()/2.0, 200, sin(ofGetElapsedTimef()) * 400);
	light2.setPosition( cos(ofGetElapsedTimef()) * 400 + ofGetWidth()/2.0, sin(ofGetElapsedTimef()) * 400 +ofGetHeight()/2.0, 0);
	
	ang+=0.1;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(122,122,122);
	ofEnableLighting();
	
	light1.enable();
	light2.enable();
	
	light1.draw();
	light2.draw();
	
	text.bind();
	ofBox(400, 600, 0, 200);
	ofBox(800, 400, -400, 200);
	ofBox(400, 200, 0, 200);
	ofBox(800, 800, -400, 200);
	text.unbind();
	
	ofDisableLighting();
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
