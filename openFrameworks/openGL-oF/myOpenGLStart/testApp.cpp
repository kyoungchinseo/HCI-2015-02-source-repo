#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableNormalizedTexCoords();
	
	ofImage img;
    img.loadImage("hci.png");
	img.mirror(false, true);
    text.allocate(640, 640, GL_RGB, true);
    ang = 0;
	
	glEnable(GL_DEPTH_TEST); // enable depth testing, otherwise things will
    text.loadData(img.getPixels(), 640, 640, GL_RGB);
}

//--------------------------------------------------------------
void testApp::update(){
	 ang += 0.1;
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(122,122,122);


	//glPushMatrix();
	//glColor3f(1.0f,1.0f,1.0f);
	text.bind(); 
	ofTranslate(ofGetWidth() * .5, ofGetHeight() * .5, 0);
	ofRotate(ang, 1.0, 1.0, 1.0);
	ofBox(200);
	text.unbind();
	//glPopMatrix();

	/*
	glPushMatrix();
	glTranslatef(100,100,0);
	glColor3f(1.0f,0.0f,0.0f);
	glBegin(GL_POLYGON);
	glVertex3f(0.0f,0.0f,0.0f);
	glVertex3f(0.0f,200.0f,0.0f);
	glVertex3f(200.0f,200.0f,0.0f);
	glVertex3f(200.0f,0.0f,0.0f);
	glEnd();
	glPopMatrix();
	*/
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
