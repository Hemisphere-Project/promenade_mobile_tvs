//
//  Nu.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#ifndef promenade_mobile_tvs_Nu_h
#define promenade_mobile_tvs_Nu_h

#include "ofMain.h"
#include "ofxThreadedImageLoader.h"

#define NU_IMG_STACK_LENGHT 2 // must be more than 2
#define NU_STATIC_LENGHT 100 // in sec

#define ZOOM_FACTOR 1 //in pixels
#define TRV_SPEED -0.1


class Nu {
    
    
    
public:
    
    // methods
    void update();
    void onDrawEvent(ofEventArgs& eventArgs);
    void draw();
    
    void urlResponse(ofHttpResponse & response);
    void load();
    void exit();
    
    
    //constructor
    Nu(float x, float y, float w, float h);
    
    // variables
    float x;
    float y;
    float w;
    float h;
    
    ofImage img[NU_IMG_STACK_LENGHT];
    
    int imgIndex;
    
    int loadingIndex;
    bool FIRST_LOAD;
    
    int alpha;
    
    int timestamp;
    
    float travelingSpeedX;
    float travelingSpeedY;
    
    ofxThreadedImageLoader loader;
    
    
private:
    
    
};						//don't forget the semicolon in the end of the class definition

#endif
