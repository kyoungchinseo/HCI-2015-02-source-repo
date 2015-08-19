#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(60);
	ofBackground(255,255,255);
	ofSetVerticalSync(true);
	ofEnableSmoothing();

	for(int i=0;i<10;i++) {
		planet p;
		p.radius = ofRandom(40) + 5.f;
		p.pos.x  = ofRandom(400);
		p.pos.y  = ofRandom(400);
		p.orbitSize = ofRandom( 2.0 ) + 0.5;
		
		p.color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
		planets.push_back(p);
	}

}

//--------------------------------------------------------------
void testApp::update(){
	float amplitude = 200.0;
	int i=0;
	while (i < planets.size()) {
		float wavelength = 20.f * planets.at(i).orbitSize;
		planets.at(i).pos.x = amplitude * planets.at(i).orbitSize * cos(ofGetFrameNum()/wavelength) + mouseX;
		planets.at(i).pos.y = amplitude * planets.at(i).orbitSize * sin(ofGetFrameNum()/wavelength) + mouseY;

		i++;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofFill();
	int i=0;
	while(i<planets.size()) {
		ofSetColor(planets.at(i).color);
		ofCircle(planets.at(i).pos.x, planets.at(i).pos.y, planets.at(i).radius);
		i++;
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
	planet p;
	p.radius = ofRandom(40) + 5.f;
	p.pos.x  = ofRandom(400);
	p.pos.y  = ofRandom(400);
	p.orbitSize = ofRandom( 2.0 ) + 0.5;
		
	p.color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
	planets.push_back(p);
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
