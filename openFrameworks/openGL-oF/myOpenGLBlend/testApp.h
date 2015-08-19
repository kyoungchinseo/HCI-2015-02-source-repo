#pragma once

#include "ofMain.h"

#define numPlanes 20

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		float ang;
		int currentLBlend, currentRBlend; // indexes to store the current blending value
		ofImage img; // an image to load a picture for a texture
		ofTexture text; // a texture to use
		ofVec3f planePos[numPlanes]; // an array to store all the text values	

		ofTrueTypeFont	font;

};
