#pragma once
#include "config.h"

class Ball
{
public:
	Ball(float x, float y);
	~Ball(void);

    void init();

    void setVelocity();

    void update();

    void draw();

	void checkBoundary();

    void changeBallProperties();

    void stopIncreasing();

	// get / set functions
	void	setRadius(float radius)		{ m_Radius = radius; }
	float	getRadius()					{ return m_Radius; }
	ofVec3f getPosition()				{ return m_Position; }
	ofVec3f getVelocity()				{ return m_Velocity; }
	void    setVelocity(ofVec3f change)	{ m_Velocity = change; }

private:
    
	float m_ColorIdx;

	bool m_IsChanging;

	ofVec3f m_Position;
	float m_Radius;

	ofVec3f m_Velocity;

	vector<ofColor> m_colorList;
};

