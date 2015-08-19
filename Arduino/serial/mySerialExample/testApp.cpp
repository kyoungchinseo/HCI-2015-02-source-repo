#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
	
	ofBackground(255);	
	font.loadFont("DIN.otf", 64);
	
	serial.listDevices();
	vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
	
	// this should be set to whatever com port your serial device is connected to.
	// (ie, COM4 on a pc, /dev/tty.... on linux, /dev/tty... on a mac)
	// arduino users check in arduino app....
	int baud = 9600;
	serial.setup("COM7", baud); //open the first device
	//serial.setup("COM4", baud); // windows example
	//serial.setup("/dev/tty.usbserial-A4001JEC", baud); // mac osx example
	//serial.setup("/dev/ttyUSB0", baud); //linux example

	recvData.clear();
}

//--------------------------------------------------------------
void testApp::update(){
	char ch;
	if (serial.available()) {
		while((ch = serial.readByte())>0) {
			if (ch == ' ') {
				rotationValue = ofToFloat(recvData);
				cout << "Received: " << rotationValue << endl;
				recvData.clear();
				//break;
			} else {
				recvData += ch;
			}
		}		
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(20,20,20);
	ofSetColor(220);
	string msg;
	msg += "Rotating " + ofToString(rotationValue);
	font.drawString(msg,50,100);

	ofSetColor(200,200,200,70);
	
	ofTranslate(ofGetWindowWidth()/2.0f,ofGetWindowHeight()/2.0f);	
	ofRotate(rotationValue);
	ofTranslate(-200,-100);	
	ofRect(0,0,400,200);

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
