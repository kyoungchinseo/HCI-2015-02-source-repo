#include "testApp.h"


const int BLENDS[] = { GL_ZERO, GL_ONE, GL_SRC_COLOR, GL_ONE_MINUS_SRC_COLOR, GL_DST_COLOR, GL_ONE_MINUS_DST_COLOR, GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_DST_ALPHA, GL_ONE_MINUS_DST_ALPHA, GL_SRC_ALPHA_SATURATE, GL_CONSTANT_COLOR, GL_ONE_MINUS_CONSTANT_COLOR, GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA };
const string BLEND_MODE[] = {"GL_ZERO", "GL_ONE", "GL_SRC_COLOR","GL_ONE_MINUS_SRC_COLOR", "GL_DST_COLOR","GL_ONE_MINUS_DST_COLOR","GL_SRC_ALPHA","GL_ONE_MINUS_SRC_ALPHA","GL_DST_ALPHA","GL_ONE_MINUS_DST_ALPHA","GL_SRC_ALPHA_SATURATE","GL_CONSTANT_COLOR","GL_ONE_MINUS_CONSTANT_COLOR","GL_CONSTANT_ALPHA","GL_ONE_MINUS_CONSTANT_ALPHA" };


//--------------------------------------------------------------
void testApp::setup(){
	
	//ofDisableArbTex();
	ofEnableNormalizedTexCoords();
	
    img.loadImage("Butterfly.tif");
    text.allocate(640, 640, GL_RGBA, true);
    ang = 0;
	glEnable(GL_DEPTH_TEST); // enable depth testing, otherwise things will
	//look really werid
    glDepthFunc(GL_LEQUAL);    // set the type of depth testing
    text.loadData(img.getPixels(), 640, 640, GL_RGBA);
	
	currentLBlend = 6;
	currentRBlend = 7;
	

	for (int i = 0; i < numPlanes; i++){
		planePos[i].set(ofRandom(ofGetWidth()/2.0-300.0, ofGetWidth()/2.0+300.0), ofRandom(ofGetHeight()/2.0-180, ofGetHeight()/2.0+180), ofRandom(100.0, 200.0));
    }

	font.loadFont("verdana.ttf", 14, true, true);
}

//--------------------------------------------------------------
void testApp::update(){
	//used to rotate the view
    ang+=0.1;
}

//--------------------------------------------------------------
void testApp::draw(){	
	ofBackgroundGradient(ofColor(0,255,0),ofColor(0,0,255),OF_GRADIENT_LINEAR);
	
	glEnable(GL_BLEND);
	text.bind();
	glBlendFunc( BLENDS[currentLBlend], BLENDS[currentRBlend] );
		
    for (int i = 0; i < numPlanes; i++) {
		ofPushMatrix();
		ofTranslate(planePos[i].x,planePos[i].y,200.0f);        
		ofDrawPlane(100,100);
		ofPopMatrix();
    }

    glDisable(GL_BLEND);
	text.unbind();
	glDisable(GL_BLEND);

	ofColor(255);
	font.drawString("Blending Mode: SRC:"+BLEND_MODE[currentLBlend] + ", DST:"+BLEND_MODE[currentRBlend], 30, 35);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch( key ){
		case 'a':
			if(currentLBlend > 13)
				currentLBlend = 0;
			else
				currentLBlend++;
			break;
		case 's':
			if(currentLBlend < 0)
				currentLBlend = 13;
			else
				currentLBlend--;
			break;
		case 'd':
			if(currentRBlend > 13)
				currentRBlend = 0;
			else
				currentRBlend++;
			break;
		case 'f':
			if(currentRBlend < 0)
				currentRBlend = 13;
			else
				currentRBlend--;
			break;
	}
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
