//
//  Silence.h
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#ifndef __promenade_mobile_tvs__Silence__
#define __promenade_mobile_tvs__Silence__

#include "ofMain.h"

class Silence{
    
public:
    
    void update();
    void draw();
    void start();
    void stop();
    
    //constructor
    Silence(float x, float y, float w, float h);
    
    float x;
    float y;
    float w;
    float h;
    
     ofSoundPlayer  sound;
    
private:
    
    
    
    
};

#endif /* defined(__promenade_mobile_tvs__Silence__) */
