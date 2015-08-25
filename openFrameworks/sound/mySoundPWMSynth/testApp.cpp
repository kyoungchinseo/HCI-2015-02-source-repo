#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	userFreq = 100.0;		//Some initial frequency
	userPwm = 0.5;			//Some initial PWM-value


	freq = userFreq;
	pwm = userPwm;
	phase = 0;
	buf.resize( bufSize );

	//Start the sound output	
	soundStream.setup( this, 2, 0, sampleRate, bufSize, 4 );
}

//--------------------------------------------------------------
void testApp::update(){
	//Nothing is here
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground( 255, 255, 255 );	//Set the background color	
	//Draw the buffer values
	ofSetColor( 0, 0, 0 );
	for (int i=0; i<bufSize-1; i++) {
		ofLine( i, 100 - buf[i]*50, (i+1), 100 - buf[i+1]*50 );
	}
}

//--------------------------------------------------------------
void testApp::audioOut( float * output, int bufferSize, int nChannels ){
	//Fill output buffer,
	//and also move freq to userFreq and pwm to userPWM slowly
	for (int i=0; i<bufferSize; i++) {
		//freq smoothly reaches userFreq
		freq += ( userFreq - freq ) * 0.001;
		//pwm smoothly reaches userPwm
		pwm += ( userPwm - pwm ) * 0.001;

		//Change phase, and push it into [0, 1] range
		phase += freq / sampleRate;
		phase = fmodf( phase, 1.0 );

		//Calculate the output audio sample value
		//Instead of 1 and 0 we use 1 and -1 output values
		//for the sound wave to be symmetrical along y-axe
		float v = ( phase < pwm ) ? 1.0 : -1.0;

		//Set the computed value to the left and the right
		//channels of output buffer,
		//also using global volume value defined above
		output[ i*2 ] = output[ i*2 + 1 ] = v * volume;

		//Set the value to buffer buf, used for rendering
		//on the screen
		//Note: bufferSize can occasionally differ from bufSize
		if ( i < bufSize ) {
			buf[ i ] = v;
		}
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
	userFreq = ofMap( x, 0, ofGetWidth(), 1, 2000 );
	userPwm = ofMap( y, 0, ofGetHeight(), 0, 1 );
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