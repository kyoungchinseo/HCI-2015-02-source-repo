#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	faceFinder.setup("haarcascade_frontalface_default.xml");
	eyeFinder.setup("haarcascade_eye.xml");
	
    grab.setVerbose(true);
    grab.initGrabber(320,240);
}

//--------------------------------------------------------------
void testApp::update(){
	grab.update();
	
	if(grab.isFrameNew())
	{
		img.setFromPixels(grab.getPixelsRef());
		faceFinder.findHaarObjects(img);
		
		for(int i = 0; i < faceFinder.blobs.size(); i++) {
			ofRectangle cur = faceFinder.blobs[i].boundingRect;
			origin.x = cur.x;
			origin.y = cur.y;
			faceImg.cropFrom(img, cur.x, cur.y, cur.width, cur.height);
			eyeFinder.findHaarObjects(faceImg);						
		}
		
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	img.draw(0, 0);
	ofNoFill();
	for(int i = 0; i < eyeFinder.blobs.size(); i++) {
		ofRectangle cur = eyeFinder.blobs[i].boundingRect;
		ofRect(cur.x + origin.x, cur.y + origin.y, cur.width, cur.height);
	}
	faceImg.draw(320,0);
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
