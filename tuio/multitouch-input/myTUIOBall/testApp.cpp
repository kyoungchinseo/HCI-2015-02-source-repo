#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(100, 100, 100);
	ofSetVerticalSync(true);
	
	//Connect to Port
	myTuio.connect(3333);
	
    
    ballMap.clear();
    
	//Assign Global TUIO Callback Functions
	ofAddListener(ofEvents().touchDown, this, &testApp::touchDown);
	ofAddListener(ofEvents().touchUp, this, &testApp::touchUp);
	ofAddListener(ofEvents().touchMoved, this, &testApp::touchMoved);

}

//--------------------------------------------------------------
void testApp::update(){
    
    map<int, Ball>::iterator iter_Pos;
    for(iter_Pos = ballMap.begin(); iter_Pos != ballMap.end(); ++iter_Pos) {
        iter_Pos->second.checkBoundary();
        iter_Pos->second.update();
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//render TUIO Cursors and Objects
	myTuio.drawCursors();
	myTuio.drawObjects();

    map<int, Ball>::iterator iter_Pos;
    for(iter_Pos = ballMap.begin(); iter_Pos != ballMap.end(); ++iter_Pos) {
        iter_Pos->second.draw();
    }
    
    cout << "Number of Balls: " << ballMap.size() << endl;
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


void testApp::touchDown(ofTouchEventArgs & touch){
    
    ballMap.insert(make_pair((int)touch.id, Ball(touch.x,touch.y)));
    ballMap.find(touch.id)->second.init();
    
    
}

void testApp::touchUp(ofTouchEventArgs & touch){
    
    ballMap.find(touch.id)->second.stopIncreasing();
    ballMap.find(touch.id)->second.setVelocity();
    
}

void testApp::touchMoved(ofTouchEventArgs & touch){
	
}

