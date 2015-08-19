#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    openNIDevice.setup();//FromXML("openni/config/ofxopenni_config.xml");
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
    openNIDevice.addDepthGenerator();
    openNIDevice.addImageGenerator();   // comment this out
    openNIDevice.start();
    openNIDevice.setMirror(true);
    
    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);

}

void ofApp::exit() {
    openNIDevice.stop();
}



//--------------------------------------------------------------
void ofApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255, 255, 255);
    //openNIDevice.drawDebug(); // draws all generators
    //openNIDevice.drawDepth(0, 0);
    //openNIDevice.drawImage(640, 0);
    
    ofShortPixels depthMap = openNIDevice.getDepthRawPixels();
    
    for (int i=0; i<480; i+=5) {
        for (int j=0; j<640; j+=5) {
            if (depthMap[i*640+j] > 800) {
                ofSetColor(0, 0, 100);
                ofCircle(j*2, i*2, 5);
            } else {
                ofSetColor(100, 0, 0);
                ofCircle(j*2, i*2, 10);
            }
        }
    }
    
    ofSetColor(0, 255, 0);
    string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " +
                    ofToString(ofGetFrameRate());
    verdana.drawString(msg, 20, ofGetHeight() - 26);

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
