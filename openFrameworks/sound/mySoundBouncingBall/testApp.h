#pragma once

#include "ofMain.h"


class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	ofSoundPlayer sound;		//Sound sample
	bool updateBall();			//Move ball function

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
    
    float mass = 0.007;    //Mass of point
    float g = 9.8;         //Gravity force
    float time0;           //Time value, used for time step computing
    ofPoint pos, vel;      //Ball position and velocity
};
