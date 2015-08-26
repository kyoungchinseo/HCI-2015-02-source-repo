#include "ImageExample.h"

//--------------------------------------------------------------
void ImageExample::setup(){
	ofSetFrameRate(60);
	// Connect
	myTuio.connect(3333);

	ofAddListener(ofEvents().touchDown, this, &ImageExample::touchDown);
	ofAddListener(ofEvents().touchMoved, this, &ImageExample::touchMoved);
	ofAddListener(ofEvents().touchUp, this, &ImageExample::touchUp);

	m_MyImage.loadImage("test.jpg");

	m_OpenGLRenderer = new ofGLRenderer();

	m_ImgPositionX = 100.0;
	m_ImgPositionY = 100.0;
	m_ImgWidth = 200.0;
	m_ImgHeight = 200.0;
	m_ImgRotateAngle = 120.0;
}

//--------------------------------------------------------------
void ImageExample::update(){
    
    vector<TuioCursor> cursorList;
    cursorList.clear();
    
    for(TuioCursor *iter : myTuio.client->getTuioCursors())
    {
        cursorList.push_back(iter);
    }
    
    int numPoint = cursorList.size();
    switch (numPoint) {
        case 1:
        {
            int movedPositionX = cursorList[0].getX() * WINDOW_WIDTH * 2;
            int movedPositionY = cursorList[0].getY() * WINDOW_HEIGHT * 2;
            
            // if imaged moved too far, return;
            if ( (m_ImgPositionX - movedPositionX) > 10.0 || m_ImgPositionY - movedPositionY > 10.0 )
            {
                break;
            }
            m_ImgPositionX = cursorList[0].getX() * WINDOW_WIDTH;
            m_ImgPositionY = cursorList[0].getY() * WINDOW_HEIGHT;
            break;
        }
        case 2:
            m_ImgWidth = abs( cursorList[0].getX() - cursorList[1].getX() ) * WINDOW_WIDTH;
            m_ImgHeight = abs( cursorList[0].getY() - cursorList[1].getY() ) * WINDOW_HEIGHT;
            break;
        case 3:
        {
            double tempAngle = ( cursorList[0].getY() - cursorList[1].getY() ) /
                               ( cursorList[0].getX() - cursorList[1].getX() );
            m_ImgRotateAngle = 180.0 * atan(tempAngle) / PI;
            break;
        }
        default:
            break;
    }
}

//--------------------------------------------------------------
void ImageExample::draw(){

// 	myTuio.drawCursors();
// 	myTuio.drawObjects();

    m_OpenGLRenderer.pushMatrix();
    m_OpenGLRenderer.translate(m_ImgPositionX, m_ImgPositionY);
    m_OpenGLRenderer.rotateZ(m_ImgRotateAngle);
    
    m_OpenGLRenderer.draw(m_MyImage, -m_ImgWidth / 2, -m_ImgHeight / 2, 0.0,
                          m_ImgWidth, m_ImgHeight,
                          0.0, 0.0,
                          m_MyImage.getWidth(), m_MyImage.getHeight());
    
    m_OpenGLRenderer.popMatrix();
}

//--------------------------------------------------------------
void ImageExample::keyPressed(int key){

}

//--------------------------------------------------------------
void ImageExample::keyReleased(int key){

}

//--------------------------------------------------------------
void ImageExample::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ImageExample::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ImageExample::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void ImageExample::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ImageExample::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ImageExample::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ImageExample::dragEvent(ofDragInfo dragInfo){ 
	
}

void ImageExample::touchDown( ofTouchEventArgs & touch )
{
}

void ImageExample::touchMoved( ofTouchEventArgs & touch )
{
}

void ImageExample::touchUp( ofTouchEventArgs & touch )
{

}
