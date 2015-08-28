#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();

	ofVideoGrabber 	grabber;	//Video grabber

	ofVideoPlayer 	video;		//Prerecorded video

	ofImage image;	//Resulted synthesized image

	//Synthesize image from grabber and video frames
	void synthesizeImage();	

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
private:
};
