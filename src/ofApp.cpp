#include "ofApp.h"

int count_rotate;
int count_rotate2;
int count_time;


//--------------------------------------------------------------
void ofApp::setup(){
    mImageBG.load("oldtvwebcam.png");
    mImageBGWeb.load("oldtvwebcamOn.png");
    mImageDial.load("dial.png");
    mImageDial2.load("dial.png");
    mFuzz.load("chanelchange.mp4");
    mTrix.load("trix.mov");
    count_rotate=0;
    count_rotate2=0;
    count_time=0;

}

//--------------------------------------------------------------
void ofApp::update(){
    mTrix.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    count_time++;
    ofBackground(0);
    //mImageBG.draw(0, 0);
    
    if (count_time > 600){
        count_time = 0;
    }
    
    //play movie on channel 1 & 6
    
    if (count_rotate==0 || count_rotate==6){
    mTrix.play();
    mTrix.draw(200,225);
    }
    else{
             mTrix.stop();
    }
    
    //alternate BG image to show blinking light
    
    if (count_time < 300){
        mImageBG.draw(0, 0);
       }
    else {
        mImageBGWeb.draw(0, 0);
        }
    
    
    
    //rotate first dial

  
        ofPushMatrix();
        ofTranslate(815+(mImageDial.getWidth()/2),200+(mImageDial.getHeight()/2));
        ofRotate(30*count_rotate, 0, 0, 1);
        mImageDial.draw(-mImageDial.getHeight()/2, -mImageDial.getHeight()/2);
        ofPopMatrix();
        ofLog(OF_LOG_NOTICE, "Click count is" + ofToString(count_rotate));

    
    //rotate second dial

   
        ofPushMatrix();
        ofTranslate(815+(mImageDial2.getWidth()/2),300+(mImageDial2.getHeight()/2));
        ofRotate(30*count_rotate2, 0, 0, 1);
        mImageDial2.draw(-mImageDial2.getHeight()/2, -mImageDial2.getHeight()/2);
        ofPopMatrix();
        ofLog(OF_LOG_NOTICE, "Click count2 is" + ofToString(count_rotate2));

    
    

//ofLog(OF_LOG_NOTICE, "Click count2 is" + ofToString(count_time));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    int mDialOneX = 815+(mImageDial.getWidth()/2);
    int mDialOneY = 200+(mImageDial.getHeight()/2);
    int mDialTwoX = 815+(mImageDial2.getWidth()/2);
    int mDialTwoY = 300+(mImageDial2.getHeight()/2);
    
    
    //Finding the center point of the first dial and adding to the rotate count with each click
    if (abs(mouseX-mDialOneX) < (mImageDial.getWidth()/2) && abs(mouseY-mDialOneY) < (mImageDial.getHeight()/2)){
    count_rotate++;
    if(count_rotate>11){
        count_rotate = 0;
        }
    }
    
    //Finding the center point of the second dial and adding to the rotate count with each click
    if (abs(mouseX-mDialTwoX) < (mImageDial2.getWidth()/2) && abs(mouseY-mDialTwoY) < (mImageDial2.getHeight()/2)){
        count_rotate2++;
        if(count_rotate2>11){
            count_rotate2 = 0;
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
   
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

