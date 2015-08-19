#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openNIDevice.setup();
    openNIDevice.addImageGenerator();
    openNIDevice.addDepthGenerator();
    openNIDevice.setRegister(true);
    openNIDevice.setMirror(true);
    
    // setup the hand generator
    openNIDevice.addHandsGenerator();
    
    // add all focus gestures (ie., wave, click, raise arm)
    openNIDevice.addAllHandFocusGestures();
    
    openNIDevice.setMaxNumHands(4);
    
    openNIDevice.start();

    
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
}

//--------------------------------------------------------------
void ofApp::update(){
    openNIDevice.update();
}

void ofApp::exit() {
    openNIDevice.stop();
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    
    ofPushMatrix();
    openNIDevice.drawDebug();
    //openNIDevice.drawImage(0,0);
    ofPopMatrix();
    
    ofPushMatrix();
    int numHands = openNIDevice.getNumTrackedHands();
    
    string msg = "";
    // iterate through users
    for (int i = 0; i < numHands; i++){
        // get a reference to this user
        ofxOpenNIHand & hand = openNIDevice.getTrackedHand(i);
        // get hand position
        ofPoint & handPosition = hand.getPosition();
        
        msg += "hand " + ofToString(i)  + ":" + "(" + ofToString(handPosition.x) + "," + ofToString(handPosition.y) + ")\n";
        
        ofSetColor(255,0,0);
        ofRect(handPosition.x, handPosition.y, 10, 10);
    }
    ofPopMatrix();
    
    ofSetColor(0, 255, 0);
    
    verdana.drawString(msg, 20, 480 + 20);
}

//--------------------------------------------------------------
void ofApp::handEvent(ofxOpenNIHandEvent & event){
    // show hand event messages in the console
    ofLogNotice() << getHandStatusAsString(event.handStatus) << "for hand"
        << event.id << "from device" << event.deviceID;
    
    if (event.handStatus == HAND_TRACKING_STARTED) {
        cout << "hand tracking started!" << endl;
    }
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
