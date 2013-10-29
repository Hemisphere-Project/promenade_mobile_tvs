//
//  Autoportrait.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 27/10/13.
//
//

#ifndef promenade_mobile_tvs_Autoportrait_h
#define promenade_mobile_tvs_Autoportrait_h

#include "ofMain.h"
#include "ofxThreadedImageLoader.h"

#define Autoportrait_IMG_STACK_LENGHT 2 // must be more than 2

#define PIXEL_SIZE 20 //10
class Autoportrait {
    
    
    
public:
    
    // methods
    void update();
    void onDrawEvent(ofEventArgs& eventArgs);
    void draw();
    void drawStatic();
    void drawTransition();
    
    void urlResponse(ofHttpResponse & response);
    void loadH();
    void loadB();
    void exit();
    
    
    //constructor
    Autoportrait(float x, float y, float w, float h);
    
    // variables
    float x;
    float y;
    float w;
    float h;
    
    ofImage imgH[Autoportrait_IMG_STACK_LENGHT];
    ofImage imgB[Autoportrait_IMG_STACK_LENGHT];
    
    int imgHIndex;
    int imgBIndex;
    
    //bool loadingH;
    //bool loadingB;
    int loadingHIndex;
    int loadingBIndex;
    bool FIRST_LOAD_H;
    bool FIRST_LOAD_B;
        
    int timestamp;
    
    ofxThreadedImageLoader loader;
    
    
    
private:
    
    
};						//don't forget the semicolon in the end of the class definition

#endif
