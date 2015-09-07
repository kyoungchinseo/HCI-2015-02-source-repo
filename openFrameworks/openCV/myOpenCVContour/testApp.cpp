#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	bLearnBackground = false;
	
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320,240);
	
    colorImg.allocate(320,240);
    grayImage.allocate(320,240);
    grayBg.allocate(320,240);
    grayDiff.allocate(320,240);
}

//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.update();
    //do we have a new frame?
    if (vidGrabber.isFrameNew()){
		colorImg.setFromPixels(vidGrabber.getPixelsRef());
        grayImage = colorImg; // convert our color image to a grayscale image
        if (bLearnBackground == true) {
            grayBg = grayImage; // update the background image
            bLearnBackground = false;
        }
		grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(30);
		contourFinder.findContours(grayDiff, 5, (340*240)/4, 4, false, true);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xffffff);
    colorImg.draw(0, 0, 320, 240);
	grayDiff.draw(0, 240, 320, 240);
    ofRect(320, 0, 320, 240);
    contourFinder.draw(320, 0, 320, 240);
	ofColor c(255, 255, 255);
	for(int i = 0; i < contourFinder.nBlobs; i++) {
		ofRectangle r = contourFinder.blobs.at(i).boundingRect;
		r.x += 320; r.y += 240;
		c.setHsb(i * 64, 255, 255);
		ofSetColor(c);
		ofRect(r);
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	bLearnBackground = true;
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
