#ofxPixelsExtended

A simple extensionto ofxPixels.
Adds functions (More to come)
getTotalPixels() - returns total number of pixels, channel independent.
isNewFrame(ofPixels lastFrame)/isNewFrame(ofPixelsExtended lastFrame) - compares to sets of pixels to see if they are unique, returns true of they are.

Future versions:
Average color in the pixel set.
Most used color in pixel set.
least used color in pixel set.

##Functions

    bool isNewFrame(ofPixels last, int pxIter = 50);
    bool isNewFrame(ofxPixelsExtended last, int pxIter = 50);
    bool isNewFrame(int pxIter = 50);
    uint getTotalPixels();
    
##Details
The 3 variations of isNewFrame allow you to handle the last set of Pixels for comparison, using either ofxPixels or ofxPixelsExtended, the 3rd variation utilizes an embedded ofPixels protected object to store old px for comparison. the pxIter value defaults to 50, which moves very fast, and seems to catch even minute differences, though it can be set to whatever you need.
