#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	glEnable(GL_DEPTH_TEST);
	ofColor color(255, 0, 0);
	float hue = 254.f;
	ang=0.0;
	
	for (int i = 0; i<12; ++i)
	{
		mesh.addVertex( ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
		
		mesh.addColor(color);
		color.setHue( hue );
		hue -= 20.f;
	}
	
	for (int i = 0; i<20; ++i) 
	{
		mesh.addIndex(tindices[i][0]);
		mesh.addIndex(tindices[i][1]);
		mesh.addIndex(tindices[i][2]);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	ang+=0.1;
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(122,122,122);
	
	ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0,ofGetHeight()/2.0, 0);
    ofRotate(ang, 1.0, 1.0, 1.0);

	mesh.drawFaces();
	
	ofPopMatrix();
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
