#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    
    TCP.setup(8001);
    
    TCP.setMessageDelimiter("\n");
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(20, 20, 20);
    
    for(int i = 0; i < TCP.getLastID(); i++){
        if( !TCP.isClientConnected(i) )continue;
        
        if(i >= storeText.size() ){
            storeText.push_back( string() );
            storeFlag.push_back(false);
        }
        
        string str = TCP.receive(i);
        
        if(str.length() > 0){
            if (storeFlag[i]) {          
                storeFlag[i] = false;
                storeText[i] = "id: "+ofToString(i)+" Turn OFF by button from Arduino";
                TCP.send(i, ofToString(0) );
            } else {
                
                storeFlag[i] = true;
                storeText[i] = "id: "+ofToString(i)+" Turn ON by button from Arduino";
                TCP.send(i, ofToString(1));
            }
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetHexColor(0xDDDDDD);
    ofDrawBitmapString("TCP SERVER Example \n\nconnect on port: "+ofToString(TCP.getPort()), 10, 20);
    
    ofSetHexColor(0x000000);
    ofRect(10, 60, ofGetWidth()-24, ofGetHeight() - 65 - 15);
    
    ofSetHexColor(0xDDDDDD);
    
    for(unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++){
        
        if( !TCP.isClientConnected(i) )continue;
        
        //calculate where to draw the text
        int xPos = 60;
        int yPos = 80 + (12 * i * 4);
        
        
        if (storeFlag[i]) {
            ofSetColor(0, 255, 0);
            
        } else {
            ofSetColor(255, 0, 0);
        }
        ofRect(xPos-50, yPos-10, 40, 30);
        
        //give each client its own color
        ofSetColor(255 - i*30, 255 - i * 20, 100 + i*40);
        
        //get the ip and port of the client
        string port = ofToString( TCP.getClientPort(i) );
        string ip   = TCP.getClientIP(i);
        string info = "client "+ofToString(i)+" -connected from "+ip+" on port: "+port;
        
        ofDrawBitmapString(info, xPos, yPos);
        ofDrawBitmapString(storeText[i], xPos, yPos + 20);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(unsigned int i = 0; i < (unsigned int)TCP.getLastID(); i++){
        
        if( !TCP.isClientConnected(i) )continue;

        if (storeFlag[i]) {
            storeFlag[i] = false;
            storeText[i] = "id: "+ofToString(i)+" Turn OFF by keyboard from PC";
            TCP.send(i, ofToString(0) );
        } else {
            storeFlag[i] = true;
            storeText[i] = "id: "+ofToString(i)+" Turn ON by keyboard from PC";
            TCP.send(i, ofToString(1));
        }
    }
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
