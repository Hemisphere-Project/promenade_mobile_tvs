//
//  Nu.cpp
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 27/10/13.
//
//

#include "Nu.h"

Nu::Nu(float _x, float _y, float _w, float _h)
{
	x = _x;
	y = _y;
	w = _w;
    h = _h;
	
    imgIndex = 0;
    
    //loading=false;
    loadingIndex=0;
    FIRST_LOAD=true;
    
	//ofRegisterURLNotification(this);
    
    alpha = 255;
    timestamp = ofGetUnixTime();
    
    travelingSpeedX = TRV_SPEED;
    travelingSpeedY = TRV_SPEED;
    
    load();
    
    
	
}


void Nu::update(){
	//w = ofGetWidth();
    //h = ofGetHeight();
    
    if(ofGetUnixTime() <= (timestamp + NU_STATIC_LENGHT)){
    }else if(ofGetUnixTime() > (timestamp + NU_STATIC_LENGHT)){
        timestamp = ofGetUnixTime();//reset the counter
        imgIndex++;
        if(imgIndex >= NU_IMG_STACK_LENGHT)
            imgIndex = 0;
        
        //load();
        
    }
    x+=travelingSpeedX;
    y+=travelingSpeedY;
    if(x - w < - img[imgIndex].getWidth()){
        x = - img[imgIndex].getWidth() + w;
        travelingSpeedX*=-1;
    }
    if(y - h < - img[imgIndex].getHeight()){
        y = - img[imgIndex].getHeight() + h;
        travelingSpeedY*=-1;
    }
    if(x>0){
        x=0;
        travelingSpeedX*=-1;
    }
    if(y>0){
        y=0;
        travelingSpeedY*=-1;
    }
	
}


void Nu::draw(){
    ofSetColor(255);
    //ofRect(x,y,w,h);
    
	if(img[imgIndex].bAllocated()){
        //img[imgIndex].draw(x,y);
        img[imgIndex].drawSubsection(0, 0, w, h, -x, -y);
    }
    
}



/*void Nu::urlResponse(ofHttpResponse & response){
    
	if(response.status==200 && response.request.name == "imgNu"){
		img[loadingIndex].loadImage(response.data);
        
        
        img[loadingIndex].resize(img[loadingIndex].getWidth()*ZOOM_FACTOR, img[loadingIndex].getHeight()*ZOOM_FACTOR);
        x = ofRandom(0,- img[imgIndex].getWidth() + w);
        y = ofRandom(0,- img[imgIndex].getHeight() + h);
        
        
		loading=false;
        
        loadingIndex++;
        
        if(loadingIndex >= NU_IMG_STACK_LENGHT)
            loadingIndex = 0;
        
        if(FIRST_LOAD){ // in the beginning we load twice
            load();
            FIRST_LOAD = false;
        }
        
	}else {
		//cout << response.status << " " << response.error << endl;
		//if(response.status!=-1) loading=false;
	}
}*/

void Nu::load(){
    
    img[loadingIndex].clear();
    
//    int imgNbr = 1;
//    ostringstream ss;
//    ss << imgNbr;
//    string imgName = "img"+ss.str();
//    string imgUrl = "http://pm.alainbarthelemy.com/nu/"+imgName+".jpg";
//    //cout << "img" << imgUrl << '\n';
//    ofLoadURLAsync(imgUrl,"imgNu");

    
    int imgNbr = 1;
    loader.loadFromURL(img[loadingIndex], "http://pm.alainbarthelemy.com/nu/img" + ofToString(imgNbr) + ".jpg");
    loader.loadFromURL(img[loadingIndex+1], "http://pm.alainbarthelemy.com/nu/img" + ofToString(imgNbr) + ".jpg");
    
}


void Nu::exit() {
	//ofUnregisterURLNotification(this);
    loader.stopThread();
}