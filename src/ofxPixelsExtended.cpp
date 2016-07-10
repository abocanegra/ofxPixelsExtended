#include "ofxPixelsExtended.h"

ofxPixelsExtended::ofxPixelsExtended(){
}

ofxPixelsExtended::~ofxPixelsExtended(){

}

bool ofxPixelsExtended::isNewFrame(ofPixels last, int pxIter)
{
    if(this->getTotalPixels() != (last.getTotalBytes() / this->getNumChannels())){
        return true;
    }
    for(int i = 0; i < this->getTotalBytes(); i+=pxIter){
        if(this->getColor(i) != last.getColor(i)){
            return true;
        }
    }
    return false;
}

bool ofxPixelsExtended::isNewFrame(ofxPixelsExtended last, int pxIter)
{
    if(this->getTotalPixels() != last.getTotalPixels()){
        return true;
    }
    for(int i = 0; i < this->getTotalBytes(); i+=pxIter){
        if(this->getColor(i) != last.getColor(i)){
            return true;
        }
    }
    return false;
}

bool ofxPixelsExtended::isNewFrame(int pxIter)
{
    for(int i = 0; i < this->getTotalBytes(); i+=pxIter){
        if(this->getColor(i) != this->lastPx.getColor(i)){
            this->lastPx.setFromPixels(this->getData(),this->getWidth(), this->getHeight(), this->getImageType());
            return true;
        }
    }
    return false;
}

uint ofxPixelsExtended::getTotalPixels(){
    return this->getTotalBytes() / this->getNumChannels();
}
