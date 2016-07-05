#pragma once

#include "ofMain.h"
#include "ofxPixelsExtended.h"
#include "ofFbo.h"

class ofApp : public ofBaseApp{

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
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofFbo fbo;
    ofImage testImg;
    ofxPixelsExtended px;
    ofxPixelsExtended lastPx;
    ofTrueTypeFont font;
    bool isNewFrame;
    vector<string> imgStr;
    int imgIter;
    string lastChange;
    bool drawFBO;
};
