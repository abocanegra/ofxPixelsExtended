/*Developed by Aaron Bocanegra of Nontrivial Studio
 * to extend ofPixels as needed.
 * new Functionality:
 * isNewFrame(ofPixels/ofPixelsExtended, int)
 * Current functions include a comparison to find
 * whether or not the pixels are equal to another set of ofPixels
 * or ofPixelsExtended. Depending on speed needs you can iterate through
 * the pixels individually or by any number you like. The default is to check every
 * 10th pixel.
 *
 * getTotalPixels()
 * returns the total numbe of pixels.
 *
 * Creative Commons Share-Alike Version 4.0
 * July 2016 - Aaron Bocanegra
 */
#pragma once
#include "ofMain.h"

class ofxPixelsExtended : public ofPixels
{
public:
    ofxPixelsExtended();
    ~ofxPixelsExtended();
    bool isNewFrame(ofPixels last, int pxIter = 10);
    bool isNewFrame(ofxPixelsExtended last, int pxIter = 10);

    uint getTotalPixels();

protected:

private:
};
