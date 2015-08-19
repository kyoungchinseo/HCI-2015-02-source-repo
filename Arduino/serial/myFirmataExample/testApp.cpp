#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	ofBackground(255,0,130);
    
    buttonState = "digital pin:";
    potValue = "analog pin:";

	font.loadFont("franklinGothic.otf", 48);    

    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
	//ard.connect("/dev/tty.usbmodemfd121", 57600);
	arduino.connect("COM7", 57600);
	
	// listen for EInitialized notification. this indicates that
	// the arduino is ready to receive commands and it is safe to
	// call setupArduino()
	ofAddListener(arduino.EInitialized, this, &testApp::setupArduino);
	bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void testApp::update(){
	updateArduino();
}

//--------------------------------------------------------------
void testApp::draw(){
	    
    ofEnableAlphaBlending();    
	ofSetColor(0, 0, 0, 127);
    ofRect(15, 15, 770, 65);
	ofSetColor(0, 0, 0, 127);
    ofRect(15, 95, 770, 270);
    ofDisableAlphaBlending();
    
    ofSetColor(255, 255, 255);
	if (!bSetupArduino){
		font.drawString("arduino not ready...\n", 20, 65);
	} else {
		font.drawString("arduino-oF communication\n", 20, 65);
		font.drawString(potValue + "\n" + buttonState +
						"\nsending pwm: " + ofToString((int)(128 + 128 * sin(ofGetElapsedTimef()))), 20, 165);
        
        ofSetColor(255, 255, 255);
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
	// turn on the onboard LED when the application window is clicked
	arduino.sendDigital(13, ARD_HIGH);
	digitalPinChanged(13);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	// turn off the onboard LED when the application window is clicked
	arduino.sendDigital(13, ARD_LOW);
	digitalPinChanged(13);
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

void testApp::setupArduino(const int & version) {
	
	// remove listener because we don't need it anymore
	ofRemoveListener(arduino.EInitialized, this, &testApp::setupArduino);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
    
    // print firmware name and version to the console
    ofLogNotice() << arduino.getFirmwareName(); 
    ofLogNotice() << "firmata v" << arduino.getMajorFirmwareVersion() << "." << arduino.getMinorFirmwareVersion();
        
    // Note: pins A0 - A5 can be used as digital input and output.
    // Refer to them as pins 14 - 19 if using StandardFirmata from Arduino 1.0.
    // If using Arduino 0022 or older, then use 16 - 21.
    // Firmata pin numbering changed in version 2.3 (which is included in Arduino 1.0)
    
    // set pin A0 to analog input
    arduino.sendAnalogPinReporting(0, ARD_ANALOG);
    
    // set pin D13 as digital output
	arduino.sendDigitalPinMode(13, ARD_OUTPUT);
    
    // set pin D11 as PWM (analog output)
	arduino.sendDigitalPinMode(9, ARD_PWM);

    // Listen for changes on the digital and analog pins
    ofAddListener(arduino.EDigitalPinChanged, this, &testApp::digitalPinChanged);
    ofAddListener(arduino.EAnalogPinChanged, this, &testApp::analogPinChanged);    
}

//--------------------------------------------------------------
void testApp::updateArduino(){

	// update the arduino, get any data or messages.
    // the call to ard.update() is required
	arduino.update();
	
	// do not send anything until the arduino has been set up
	if (bSetupArduino) {
        // fade the led connected to pin D11
		arduino.sendPwm(9, (int)(128 + 128 * sin(ofGetElapsedTimef())));   // pwm...
	}

}

// digital pin event handler, called whenever a digital pin value has changed
// note: if an analog pin has been set as a digital pin, it will be handled
// by the digitalPinChanged function rather than the analogPinChanged function.

//--------------------------------------------------------------
void testApp::digitalPinChanged(const int & pinNum) {
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(arduino.getDigital(pinNum));	
}

// analog pin event handler, called whenever an analog pin value has changed

//--------------------------------------------------------------
void testApp::analogPinChanged(const int & pinNum) {
    // do something with the analog input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    potValue = "analog pin: " + ofToString(pinNum) + " = " + ofToString(arduino.getAnalog(pinNum));
}
