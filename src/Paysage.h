//
//  Paysage.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 27/10/13.
//
//

#ifndef promenade_mobile_tvs_Paysage_h
#define promenade_mobile_tvs_Paysage_h

#include "ofMain.h"


#define PAYSAGE_IMG_STACK_LENGHT 2 // must be more than 2
#define PAYSAGE_STATIC_LENGHT 10 // in sec
#define PAYSAGE_TRANS_LENGHT 10 // in sec

class Paysage {
    
    
    
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
    Paysage(float x, float y, float w, float h);
    
    // variables
    float x;
    float y;
    float w;
    float h;
    
    ofImage imgH[PAYSAGE_IMG_STACK_LENGHT];
    ofImage imgB[PAYSAGE_IMG_STACK_LENGHT];
    
    int imgHIndex;
    int imgBIndex;
    
    //bool loadingH;
    //bool loadingB;
    int loadingHIndex;
    int loadingBIndex;
    bool FIRST_LOAD_H;
    bool FIRST_LOAD_B;
    
    int alpha;
    
    int timestamp;
    long trans_ts;
    bool ON_TRANSITION;
    
    //ofxThreadedImageLoader loader;
    
    
    
private:
    
    
};						//don't forget the semicolon in the end of the class definition

#endif
