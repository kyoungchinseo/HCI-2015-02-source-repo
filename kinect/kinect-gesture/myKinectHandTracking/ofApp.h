#pragma once

#include "ofxOpenNI.h"
#include "ofMain.h"
#include "DetectingEffect.h"

#define MAX_DEVICES 2
#define MAX_NUMBER_OF_HAND 4

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
        void handEvent(ofxOpenNIHandEvent & event);
    
        ofxOpenNI openNIDevice;
        ofTrueTypeFont verdana;
        string logMessage;
    
        vector<DetectingEffect> effectList;
        vector<ofPoint> prevPoint;
        vector<ofPoint> currPoint;
    
};
