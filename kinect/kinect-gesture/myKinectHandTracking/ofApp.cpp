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
    
    openNIDevice.setMaxNumHands(MAX_NUMBER_OF_HAND);
    
    openNIDevice.start();

    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
    
    for(int i=0;i<MAX_NUMBER_OF_HAND; i++) {
        effectList.push_back(DetectingEffect());
        prevPoint.push_back(ofPoint(0.0f,0.0f,0.0f));
        currPoint.push_back(ofPoint(0.0f,0.0f,0.0f));
    }
    
    ofAddListener(openNIDevice.handEvent, this, &ofApp::handEvent);
    
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
    //openNIDevice.drawDebug();
    openNIDevice.drawImage(0,0);
    openNIDevice.drawDepth(640, 0);
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
        
        currPoint[i] = handPosition;
        if ((prevPoint[i].z - currPoint[i].z) > 50) {
            effectList[i].startEffect(handPosition.x, handPosition.y);
        }
        prevPoint[i] = handPosition;
        
        msg += "hand " + ofToString(i)  + ":" + "(x:" + ofToString(handPosition.x) + ", y:" + ofToString(handPosition.y) + ", z:" + ofToString(handPosition.z) + ")\n";
        
        ofSetColor(255,0,0);
        ofRect(handPosition.x, handPosition.y, 10, 10);
    }
    ofPopMatrix();
    
    ofPushMatrix();
    for(int i=0;i<MAX_NUMBER_OF_HAND;i++) {
        effectList[i].display();
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
