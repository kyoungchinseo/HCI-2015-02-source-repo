#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	camWidth 		= 320;
	camHeight 		= 240;

	vector<ofVideoDevice> devices = videoIn.listDevices();
	 for(int i = 0; i < devices.size(); i++){
		cout << devices[i].id << ": " << devices[i].deviceName; 
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl; 
        }
	}
	videoIn.setDeviceID(0);
	videoIn.setDesiredFrameRate(60);
	videoIn.initGrabber(camWidth,camHeight);

	
	videoInverted 	= new unsigned char[camWidth*camHeight*3];
	videoTexture.allocate(camWidth,camHeight, GL_RGB);	
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){
	float sobelHorizontal[3][3];
	sobelHorizontal[0][0] = -1; sobelHorizontal[0][1] = 0; sobelHorizontal[0][2]= 1;
    sobelHorizontal[1][0] = -2; sobelHorizontal[1][1] = 0; sobelHorizontal[1][2] = 2;
    sobelHorizontal[2][0] = -1; sobelHorizontal[2][1]= 0; sobelHorizontal[2][2] = 1;

    videoIn.update();
	
    int brightest = 0;
    int index = 0;
	
    if (videoIn.isFrameNew()) { //check to make sure the frame is new
        drawingPixels = videoIn.getPixels();
        int length  = camWidth*camHeight*3;
        for (int i = 0; i < length; i+=3) {
            unsigned char r = drawingPixels[i];
            unsigned char g = drawingPixels[i+1];
            unsigned char b = drawingPixels[i+2];
			
            if(int(r+g+b) > brightest) {
                brightest = int(r+g+b);
                brightestLoc[0] = (i/3) % camWidth;
                brightestLoc[1] = (i/3) / camWidth;
            }
        }

		for (int i = 0; i < length; i++){
			videoInverted[i] = 255 - drawingPixels[i];
		}
		videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0xffffff);
    videoIn.draw(0, 0);

	videoTexture.draw(camWidth,0,camWidth,camHeight);

    ofEllipse(brightestLoc[0],brightestLoc[1], 10, 10);
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
