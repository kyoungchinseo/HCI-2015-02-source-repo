#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	//Load and set up the sound samples
	for ( int i=0; i<N; i++) {
		sound[i].loadSound(
			"vox" + ofToString( i + 1 ) + ".wav" );
		sound[i].setLoop( true );

		//Do some stereo panoraming of the sounds
		sound[i].setPan( ofMap( i, 0, N-1, -0.5, 0.5 ) );

		sound[i].setVolume( 0 );
		sound[i].play();		//Start a sample to play
	}
	//Decrease overall volume to eliminate volume overload
	//(audio clipping)
	ofSoundSetVolume( 0.2 );	
}

//--------------------------------------------------------------
void testApp::update(){
	float time = ofGetElapsedTimef();	//Get current time

	//Update volumes
	float tx = time*0.1 + 50;	 //Value, smoothly changed over time
	for (int i=0; i<N; i++) {
		//Calculate the sample volume as 2D Perlin noise,
		//depending on tx and ty = i * 0.2
		float ty = i * 0.2;
		vol[i] = ofNoise( tx, ty );	//Perlin noise

		sound[i].setVolume( vol[i] );	//Set sample's volume
	}	

	//Update sound engine
	ofSoundUpdate();
}

//--------------------------------------------------------------
void testApp::draw(){	
	ofBackground( 255, 255, 255 );	//Set the background color

	//Draw volumes as vertical lines
	ofSetColor( 0, 0, 0 );
	for (int i=0; i<N; i++) {
		ofRect( i * 20 + 100, 400, 5, -vol[i] * 300 );
	}
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