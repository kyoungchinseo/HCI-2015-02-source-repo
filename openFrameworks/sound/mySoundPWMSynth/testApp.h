#pragma once

#include "ofMain.h"



class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void mousePressed(int x, int y, int button);

	//Function for generating audio
	void audioOut( float * input, int bufferSize, int nChannels );

	ofSoundStream soundStream;	//Object for sound output setup

	//User-changing parameters
	float userFreq;				//Frequency
	float userPwm;				//PWM-value

	//Parameters, used during synthesis
	float freq;					//Current frequency
	float pwm;					//Current PWM-value
	float phase;				//Phase of the wave

	//Buffer for rendering last generated audio buffer
	vector<float> buf;

    int bufSize = 512;		//Sound card buffer size
    int sampleRate = 44100;	//Sound sample rate
    float volume = 0.1;		//Output volume

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
};
