#include "ofMain.h"
#include "Ball.h"
#include <stdlib.h>
#include <math.h>

Ball::Ball(float x, float y)
{
	m_Position.x = x * WINDOW_WIDTH;
	m_Position.y = y * WINDOW_HEIGHT;

	m_Radius = 50.0f;

	m_Velocity.x = 0.0f;
	m_Velocity.y = 0.0f;
  
    m_colorList.push_back(ofColor(30,153,197));
    m_colorList.push_back(ofColor(196,15,132));
    m_colorList.push_back(ofColor(204,232,36));
    m_colorList.push_back(ofColor(78,183,153));
    m_colorList.push_back(ofColor(255,102,0));

	m_ColorIdx = 0;
	m_IsChanging = false;
}


Ball::~Ball(void)
{
}

void Ball::init()
{
    m_IsChanging = true;
}

void Ball::setVelocity()
{
	m_Velocity.x = static_cast<float>(rand() ) / (RAND_MAX / 2) - 1.0f;
	m_Velocity.y = static_cast<float>(rand() ) / (RAND_MAX / 2) - 1.0f;
}

void Ball::update()
{
    if (m_IsChanging)
		changeBallProperties();

    m_Position += m_Velocity;
}

void Ball::draw()
{
	//ofSetColor(m_colorList[static_cast<unsigned int>(m_ColorIdx) % COLOR_NUMBER]);
    ofSetColor(m_colorList[(unsigned int)(m_ColorIdx) % COLOR_NUMBER]);
    ofCircle(m_Position.x, m_Position.y, m_Radius);
}

void Ball::changeBallProperties()
{
    m_Radius += 0.5;

    m_ColorIdx += 0.1f;
}

void Ball::stopIncreasing()
{
	m_IsChanging = false;
}

void Ball::checkBoundary()
{
	if (m_Position.x - m_Radius < 0) {
		m_Velocity.x *= -1;
		m_Position.x = m_Radius;
	} else if (m_Position.x + m_Radius > WINDOW_WIDTH) {
		m_Velocity.x *= -1;
		m_Position.x = WINDOW_WIDTH - m_Radius;
	}

	if (m_Position.y - m_Radius < 0) {
		m_Velocity.y *= -1;
		m_Position.y = m_Radius;
	} else if (m_Position.y + m_Radius > WINDOW_HEIGHT){
		m_Velocity.y *= -1;
		m_Position.y = WINDOW_HEIGHT - m_Radius;
	}
}