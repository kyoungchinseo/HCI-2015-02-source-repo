#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
	//Set up sound sample
	sound.loadSound( "bounce.wav" );  //Load sound sample
	sound.setMultiPlay( true );       //Set multiplay mode

	//Model setup
	time0 = ofGetElapsedTimef();    //Get current time
	pos = ofPoint( ofGetWidth() / 2, 100 ); //Ball's initial position
	vel = ofPoint( 0, 0 );  //Initial velocity

	//Set up background to not clear each frame
	ofSetBackgroundAuto( false );
	ofBackground( 255, 255, 255 );    //Clear background to white
}

//--------------------------------------------------------------
void testApp::update(){
	//Update ball position and check if it is bounced
	bool bounced = updateBall();
	if ( bounced ) {
		//Start sample playing
		sound.play();
		//Set play speed, in dependence of x
		float speed = ofMap( pos.x, 0, ofGetWidth(), 0.2, 2 );
		sound.setSpeed( speed );
	}
	//Update sound engine
	ofSoundUpdate();
}

//--------------------------------------------------------------
void testApp::draw(){
	float bottom = 300.0; //The floor position on the screen
	//Draw the floor line in black color
	ofSetColor( 0, 0, 0 );
	ofLine( 0, bottom, ofGetWidth(), bottom );
	//Draw the ball in red color
	ofSetColor( 255, 0, 0 );
	ofFill();
	ofCircle( pos.x, bottom - pos.y, 3 );
}

//--------------------------------------------------------------
bool testApp::updateBall() {
	bool bounced = false;

	//Compute dt
	float time = ofGetElapsedTimef();
	float dt = ofClamp( time - time0, 0, 0.1 );
	time0 = time;

	//Compute gravity force acceleration
	//using the second Newton's law
	ofPoint acc( 0, -g/mass );

	//Change velocity and position using Euler's method
	vel += acc * dt;		
	pos += vel * dt;

	//Check if the ball bounced off floor
	if ( pos.y < 0 ) {
		//Elastic bounce with momentum conservation
		pos.y = -pos.y;		
		vel.y = -vel.y;
		//Set random velocity by x axe in range [-300, 500]
		vel.x = ofRandom( -300, 500 );
		bounced = true;	
	}

	//Check if the ball is out of screen
	if ( pos.x < 0 ) { pos.x += ofGetWidth(); }
	if ( pos.x > ofGetWidth() ) { pos.x -= ofGetWidth(); }
	return bounced;
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

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