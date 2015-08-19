#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	numBalls = 12;
	spring = 0.05;
	gravity = 0.03;
	friction = -0.9;

	width = ofGetWidth();
	height= ofGetHeight();
	
	balls = new Ball[numBalls];
	
	for(int i=0;i<numBalls;i++) {		
		balls[i].setup(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),ofRandom(30,70), i, spring, gravity, friction);
	}
	
	ofSetFrameRate(60);
	ofBackground(100,100,100);
	ofSetVerticalSync(true);
	ofEnableSmoothing();
}

//--------------------------------------------------------------
void testApp::update(){
	for(int i=0;i<numBalls;i++) {
		
		balls[i].move();
	}
	checkCollision();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(100,100,100);
	for(int i=0;i<numBalls;i++) {
		ofColor(255,255,255,100);
		
		balls[i].display();
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


//
void testApp::checkCollision(void) {
	for(int i=0;i<numBalls;i++) {
		for(int j=i+1;j<numBalls;j++) {
			float dx = balls[j].x - balls[i].x;
			float dy = balls[j].y - balls[i].y;
			float distance = ofDist(balls[i].x,balls[i].y,balls[j].x,balls[j].y);
			float minDist = balls[j].diameter/2 + balls[i].diameter/2;
			if (distance < minDist) {
				float angle = atan2(dy,dx);
				float targetX = balls[i].x + cos(angle) * minDist;
				float targetY = balls[i].y + sin(angle) * minDist;
				float ax = (targetX - balls[j].x) * spring;
				float ay = (targetY - balls[j].y) * spring;
				balls[i].vx -= ax;
				balls[i].vy -= ay;
				balls[j].vx += ax;
				balls[j].vy += ay;

			}
		}
	}
}