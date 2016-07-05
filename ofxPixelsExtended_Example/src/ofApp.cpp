#include "ofApp.h"

/*
 * This example shows a couple manners where
 * being ablet o know when an ofxPixelsExtended
 * object is a new frame. The example works for fbo
 * generated pixels or through changing images.
 * pressing:
 * f - switches between fbo object and slideshow.
 * left arrow/right arrow - switches images
 */

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowTitle("ofPixels Extended Example");
    ofSetVerticalSync(false);
    ofSetFrameRate(30);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(0);
    drawFBO = true;
    imgIter = 0;
    imgStr.push_back("publicdomainarchive.png");
    imgStr.push_back("audio_banner_corporate_2.jpg");
    testImg.load(imgStr.at(0));
    px.allocate(
                testImg.getWidth(),
                testImg.getHeight(),
                testImg.getImageType()
                );
    px.setFromPixels(
                testImg.getPixels().getData(),
                testImg.getWidth(),
                testImg.getHeight(),
                testImg.getImageType()
                );
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
    font.load("arial.ttf", 20);
}

//--------------------------------------------------------------
void ofApp::update(){
    //Checkfor new frame
    if((isNewFrame = px.isNewFrame(lastPx))){
        lastPx.operator =(px);
        lastChange = ofGetTimestampString();
    }

    //Update FBO
    if(drawFBO){
        fbo.begin();
        ofClear(0, 0);
        float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 100, 255);
        ofSetColor(255, alpha);
        testImg.draw(
                    (ofGetWidth()/2)-(testImg.getWidth()/2),
                    (ofGetHeight()/2)-(testImg.getHeight()/2)
                    );
        ofSetColor(50,100,200,alpha);
        ofDrawCircle(ofVec2f(ofGetMouseX(), ofGetMouseY()),100);
        fbo.end();
        fbo.readToPixels(px);
    }else{
        px.setFromPixels(testImg.getPixels().getData(),
                         testImg.getWidth(),
                         testImg.getHeight(),
                         testImg.getImageType()
                         );
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Draw FBO to Screen
    if(drawFBO){
        fbo.draw(0,0);
    }else{
        testImg.draw(
                    (ofGetWidth()/2)-(testImg.getWidth()/2),
                    (ofGetHeight()/2)-(testImg.getHeight()/2)
                    );
    }

    string str = "Pixels: " +
            ofToString(px.getTotalPixels()) +
            " | Last Change: " +
            lastChange +
            " | " +
            ofToString(ofGetFrameRate(),0) +
            "fps" ;
    // in draw:
    ofSetColor(0,128,200,200);
    font.drawString(str, 10, ofGetHeight() - 30);
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_LEFT){
        if(imgIter >0){
            imgIter--;
        }else{
            imgIter = imgStr.size()-1;
        }
        testImg.load(imgStr.at(imgIter));
    }
    if(key == OF_KEY_RIGHT){
        imgIter=(imgIter+1)%imgStr.size();
        testImg.load(imgStr.at(imgIter));
    }
    if(key == 'f'){
        drawFBO ^=true;
    }
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
