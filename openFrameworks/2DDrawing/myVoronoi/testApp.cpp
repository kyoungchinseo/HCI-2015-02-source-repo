#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	needRedraw = false;
	ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	if (!needRedraw ) return;


	ofBackground(255,255,255);
	float w = ofGetWidth();
	float h = ofGetHeight();
	int step = 1;

	for(int x = 0; x < w && (xs.size() > 0); x+=step) {
		for(int y = 0; y<h; y+=step) {
			int idx = 0;
			float dd;
			dd = ofDist(xs[0], ys[0], x, y);
			for(int i=1; i<d.size(); i++) {
				float d0 = ofDist(xs[i],ys[i],x,y);
				if (dd > d0) {
					dd = d0;
					idx = i;
				}
			}
			ofSetColor(c[idx]);
			ofRect(x,y,step,step);
		}
	}
	ofSetColor(255);
	for(int i=0;i<xs.size();i++) {
		ofEllipse(xs[i],ys[i],10,10);
	}
	needRedraw = false;
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
	xs.push_back(x);
	ys.push_back(y);
	d.push_back(0);
	ofColor cl(ofRandom(255),ofRandom(255),ofRandom(255));
	c.push_back(cl);

	needRedraw = true;
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
