//
//  Silence.cpp
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 28/10/13.
//
//

#include "Silence.h"

Silence::Silence(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
    h = _h;
    
    sound.loadSound("sounds/01 Boring Angel.mp3");
	sound.setVolume(0.0f);
	sound.setMultiPlay(false);
    sound.setLoop(true);
    
    sound.play();
}

void Silence::update(){
	//w = ofGetWidth();
    //h = ofGetHeight();
    
    ofSoundUpdate();
	
}

void Silence::draw(){
    ofSetColor(0,0,255);
    ofRect(x,y,w,h);
}

void Silence::start(){
    sound.setVolume(1.0f);
}

void Silence::stop(){
    sound.setVolume(0.0f);
}