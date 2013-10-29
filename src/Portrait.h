//
//  Portrait.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 27/10/13.
//
//

#ifndef promenade_mobile_tvs_Portrait_h
#define promenade_mobile_tvs_Portrait_h

#include "ofMain.h"
#include "ofxThreadedImageLoader.h"

#define PORTRAIT_IMG_STACK_LENGHT 30 // must be more than 2

#define IMG_WIDTH 60 //in pixels

#define MAX_COUNT 100 // on every 10 sec at 10 fps

class Portrait {
    
    
    
public:
    
    // methods
    void update();
    void onDrawEvent(ofEventArgs& eventArgs);
    void draw();
    
    void urlResponse(ofHttpResponse & response);
    void load();
    void exit();
    
    
    //constructor
    Portrait(float x, float y, float w, float h);
    
    // variables
    float x;
    float y;
    float w;
    float h;
    
    ofImage img[PORTRAIT_IMG_STACK_LENGHT];
    
    int imgIndex;
    
    int loadingIndex;
    bool FIRST_LOAD;
    
    int alpha;
    
    int count;
    
    //ofxThreadedImageLoader loader;
    
    
    
private:
    
    
};						//don't forget the semicolon in the end of the class definition

#endif
