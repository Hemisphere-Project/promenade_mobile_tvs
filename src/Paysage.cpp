//
//  Paysage.cpp
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 27/10/13.
//
//

#include "Paysage.h"

Paysage::Paysage(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
    h = _h;
	
    imgHIndex = 0;
    imgBIndex = 0;
    
    //loadingH=false;
    //loadingB=false;
    loadingHIndex=0;
    loadingBIndex=0;
    FIRST_LOAD_H=true;
    FIRST_LOAD_B=true;
    
	//ofRegisterURLNotification(this);
    
    alpha = 255;
    timestamp = ofGetUnixTime();
    ON_TRANSITION = false;
        
    loadH();
    loadB();
    
}


void Paysage::update(){
	//w = ofGetWidth();
    //h = ofGetHeight();
    
    if(ofGetUnixTime() <= (timestamp + PAYSAGE_STATIC_LENGHT) && !ON_TRANSITION){
    }else if(ofGetUnixTime() > (timestamp + PAYSAGE_STATIC_LENGHT) && !ON_TRANSITION){
        timestamp = ofGetUnixTime();//reset the counter
        trans_ts = ofGetElapsedTimeMillis();
        ON_TRANSITION = true;
    }else if (ofGetUnixTime() <= (timestamp + PAYSAGE_TRANS_LENGHT) && ON_TRANSITION){
    }else if(ofGetUnixTime() > (timestamp + PAYSAGE_TRANS_LENGHT) && ON_TRANSITION){
        timestamp = ofGetUnixTime();//reset the counter
        imgHIndex++;
        if(imgHIndex >= PAYSAGE_IMG_STACK_LENGHT)
            imgHIndex = 0;
        imgBIndex++;
        if(imgBIndex >= PAYSAGE_IMG_STACK_LENGHT)
            imgBIndex = 0;
        
        //loadH();
        //loadB();
        
        ON_TRANSITION = false;
        
    }
	
}


void Paysage::draw(){
	
    if(ON_TRANSITION)
        drawTransition();
    else
        drawStatic();
    
}

void Paysage::drawStatic(){
    
	if(imgH[imgHIndex].bAllocated()){
		ofSetColor(255);
        imgH[imgHIndex].draw(x, y);
    }
	if(imgB[imgBIndex].bAllocated()){
		ofSetColor(255);
        imgB[imgBIndex].draw(x, y+h/2);
    }
    
}
void Paysage::drawTransition(){
    
    alpha = (int)floor(255*((float)(ofGetElapsedTimeMillis() - trans_ts)/(PAYSAGE_TRANS_LENGHT*1000)));
    int nextHIndex = (imgHIndex >= PAYSAGE_IMG_STACK_LENGHT-1) ? 0 : imgHIndex+1;
    int nextBIndex = (imgBIndex >= PAYSAGE_IMG_STACK_LENGHT-1) ? 0 : imgBIndex+1;
    
    ofEnableAlphaBlending();
    
	if(imgH[imgHIndex].bAllocated() && imgH[nextHIndex].bAllocated()){
		      
        ofSetColor(255,255,255,255-alpha);
        imgH[imgHIndex].getTextureReference().draw(x,y);
        ofSetColor(255,255,255,alpha);
        imgH[nextHIndex].getTextureReference().draw(x,y);
    }
	if(imgB[imgBIndex].bAllocated() && imgB[nextBIndex].bAllocated()){
		
        ofSetColor(255,255,255,255-alpha);
        imgB[imgBIndex].getTextureReference().draw(x,y+h/2);
        ofSetColor(255,255,255,alpha);
        imgB[nextBIndex].getTextureReference().draw(x,y+h/2);
    }
    ofDisableAlphaBlending();
    
}

/*void Paysage::urlResponse(ofHttpResponse & response){
    
	if(response.status==200 && response.request.name == "imgHPaysage"){
		imgH[loadingHIndex].loadImage(response.data);
        
        //fit width
        imgH[loadingHIndex].resize(w, (int)floor(imgH[loadingHIndex].getHeight()*w/imgH[loadingHIndex].getWidth()));
        imgH[loadingHIndex].crop(0, 0, w, h/2);
        
        
		//loadingH=false;
        
        loadingHIndex++;
        if(loadingHIndex >= PAYSAGE_IMG_STACK_LENGHT)
            loadingHIndex = 0;

        if(FIRST_LOAD_H){ // in the beginning we load twice
            loadH();
            FIRST_LOAD_H = false;
        }
        
        
	}else if(response.status==200 && response.request.name == "imgBPaysage"){
		imgB[loadingBIndex].loadImage(response.data);
        

        //fit width
        imgB[loadingBIndex].resize(w, (int)floor(imgB[loadingBIndex].getHeight()*w/imgB[loadingBIndex].getWidth()));
        imgB[loadingBIndex].crop(0, imgB[loadingBIndex].getHeight() - h/2, w, h/2);
        

        loadingBIndex++;
        if(loadingBIndex >= PAYSAGE_IMG_STACK_LENGHT)
            loadingBIndex = 0;

        if(FIRST_LOAD_B){ // in the beginning we load twice
            loadB();
            FIRST_LOAD_B = false;
        }
        
	}else {
		//cout << response.status << " " << response.error << endl;
		//if(response.status!=-1) loading=false;
	}
}*/

void Paysage::loadH(){
    
    imgH[loadingHIndex].clear();
    
//    int imgNbr = (int)floor(1+ofRandom(1)*6.99);
//    ostringstream ss;
//    ss << imgNbr;
//    string imgName = "img"+ss.str();
//    string imgUrl = "http://pm.alainbarthelemy.com/paysage/"+imgName+".jpg";
//    cout << "imgH" << imgUrl << '\n';
//    ofLoadURLAsync(imgUrl,"imgHPaysage");
    
    int imgNbr = (int)floor(1+ofRandom(1)*6.99);
    loader.loadFromURL(imgH[loadingHIndex], "http://pm.alainbarthelemy.com/paysage/img" + ofToString(imgNbr) + ".jpg");
    imgNbr = (int)floor(1+ofRandom(1)*6.99);
    loader.loadFromURL(imgH[loadingHIndex+1], "http://pm.alainbarthelemy.com/paysage/img" + ofToString(imgNbr) + ".jpg");

    

}
void Paysage::loadB(){
    
    imgB[loadingBIndex].clear();
    
//    int imgNbr = (int)floor(1+ofRandom(1)*6.99);
//    ostringstream ss;
//    ss << imgNbr;
//    string imgName = "img"+ss.str();
//    string imgUrl = "http://pm.alainbarthelemy.com/paysage/"+imgName+".jpg";
//    //cout << "imgB" << imgUrl << '\n';
//    ofLoadURLAsync(imgUrl,"imgBPaysage");
    
    int imgNbr = (int)floor(1+ofRandom(1)*6.99);
    loader.loadFromURL(imgB[loadingBIndex], "http://pm.alainbarthelemy.com/paysage/img" + ofToString(imgNbr) + ".jpg");
    imgNbr = (int)floor(1+ofRandom(1)*6.99);
    loader.loadFromURL(imgB[loadingBIndex+1], "http://pm.alainbarthelemy.com/paysage/img" + ofToString(imgNbr) + ".jpg");

    
}

void Paysage::exit() {
	//ofUnregisterURLNotification(this);
    loader.stopThread();
}