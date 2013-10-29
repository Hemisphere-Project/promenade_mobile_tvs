//
//  Autoportrait.cpp
//  promenade_mobile_tvs
//
//  Created by Alain Barthelemy on 27/10/13.
//
//

#include "Autoportrait.h"

Autoportrait::Autoportrait(float _x, float _y, float _w, float _h)
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
    
    timestamp = ofGetUnixTime();
    
    loadH();
    loadB();
    
    // plus besoin car ici on charge à la volée, l'arrivee d'une image entraine le
    // chargement d'un nouvelle
    //ofAddListener(ofEvents().draw, this, &Autoportrait::onDrawEvent);
	
}


void Autoportrait::update(){
	//w = ofGetWidth();
    //h = ofGetHeight();
	
}


void Autoportrait::draw(){
	
    drawStatic();
    
}

void Autoportrait::drawStatic(){
    //cout << "imgHIndex  " << imgHIndex << "  loadingHIndex  "<<loadingHIndex<<"\n";
    //cout << "imgBIndex  " << imgBIndex << "  loadingBIndex  "<<loadingBIndex<<"\n";
    

		

    
	if(imgH[imgHIndex].bAllocated()){
		ofSetColor(255);
        imgH[imgHIndex].draw(x, y);
        
        /*for(int y = 0; y < imgH[imgHIndex].getHeight(); y+= PIXEL_SIZE){
			for(int x = 0; x < imgH[imgHIndex].getWidth(); x+=PIXEL_SIZE){
				ofColor c = imgH[imgHIndex].getColor(x, y);
				
				ofSetColor( c.r, c.g, c.b );
				ofRect( x, y, PIXEL_SIZE,PIXEL_SIZE );
			}
		}*/
    }
	if(imgB[imgBIndex].bAllocated()){
        ofSetColor(255);
        imgB[imgBIndex].draw(x+w/2,y);
        /*for(int y = 0; y < imgH[imgHIndex].getHeight(); y+= PIXEL_SIZE){
            for(int x = 0; x < imgB[imgBIndex].getWidth(); x+=PIXEL_SIZE){
                ofColor c = imgB[imgBIndex].getColor(x, y);
                
                ofSetColor( c.r, c.g, c.b );
                ofRect( x+w/2, y, PIXEL_SIZE,PIXEL_SIZE );
            }
        }*/
    }
    
}
/*
void Autoportrait::urlResponse(ofHttpResponse & response){

//cout << "response  "<< response.request.name << "\n";
    
	if(response.status==200 && response.request.name == "imgHAutoportrait"){
        //imgH[loadingHIndex].setCompression(OF_COMPRESS_NONE);
		imgH[loadingHIndex].loadImage(response.data);
        

        imgH[loadingHIndex].resize((int)floor(imgH[loadingHIndex].getWidth()*h/imgH[loadingHIndex].getHeight()),h);
        imgH[loadingHIndex].crop(0, 0, w/2, h);
        
        imgH[loadingHIndex].resize(imgH[loadingHIndex].getWidth()/PIXEL_SIZE, imgH[loadingHIndex].getHeight()/PIXEL_SIZE);
        imgH[loadingHIndex].resize(imgH[loadingHIndex].getWidth()*PIXEL_SIZE, imgH[loadingHIndex].getHeight()*PIXEL_SIZE);
        
        
		loadingH=false;
        
        loadingHIndex++;
        
        if(loadingHIndex >= Autoportrait_IMG_STACK_LENGHT)
            loadingHIndex = 0;
        
        if(FIRST_LOAD_H){ // in the beginning we load twice
            loadH();
            FIRST_LOAD_H = false;
        }else{
            imgHIndex++;
            if(imgHIndex >= Autoportrait_IMG_STACK_LENGHT)
                imgHIndex = 0;
            //loadH();
        }
        
        
	}else if(response.status==200 && response.request.name == "imgBAutoportrait"){
		imgB[loadingBIndex].loadImage(response.data);
        

        imgB[loadingBIndex].resize((int)floor(imgB[loadingBIndex].getWidth()*h/imgB[loadingBIndex].getHeight()),h);
        imgB[loadingBIndex].crop(0, 0, w/2, h);
        
        imgB[loadingBIndex].resize(imgB[loadingBIndex].getWidth()/PIXEL_SIZE, imgB[loadingBIndex].getHeight()/PIXEL_SIZE);
        imgB[loadingBIndex].resize(imgB[loadingBIndex].getWidth()*PIXEL_SIZE, imgB[loadingBIndex].getHeight()*PIXEL_SIZE);
        
		//loadingB=false;
        
        loadingBIndex++;
        
        if(loadingBIndex >= Autoportrait_IMG_STACK_LENGHT)
            loadingBIndex = 0;
        
        if(FIRST_LOAD_B){ // in the beginning we load twice
            loadB();
            FIRST_LOAD_B = false;
        }else{
            imgBIndex++;
            if(imgBIndex >= Autoportrait_IMG_STACK_LENGHT)
                imgBIndex = 0;
            //loadB();
        }
        
	}else {
		//cout << response.status << " " << response.error << endl;
		//if(response.status!=-1) loading=false;
	}
}
*/
void Autoportrait::loadH(){
    
    imgH[loadingHIndex].clear();
    
//    int imgNbr = (int)floor(1+ofRandom(1)*44.99);
//    ostringstream ss;
//    ss << imgNbr;
//    string imgName = "img"+ss.str();
//    string imgUrl = "http://pm.alainbarthelemy.com/portrait/"+imgName+".jpg";
//    //cout << "imgH  " << imgUrl << '\n';
//    ofLoadURLAsync(imgUrl,"imgHAutoportrait");
    
    int imgNbr = (int)floor(1+ofRandom(1)*44.99);
    loader.loadFromURL(imgH[loadingHIndex], "http://pm.alainbarthelemy.com/portrait/img" + ofToString(imgNbr) + ".jpg");
    imgNbr = (int)floor(1+ofRandom(1)*44.99);
    loader.loadFromURL(imgH[loadingHIndex+1], "http://pm.alainbarthelemy.com/portrait/img" + ofToString(imgNbr) + ".jpg");

    
}
void Autoportrait::loadB(){
    
    imgB[loadingBIndex].clear();
    
//    int imgNbr = (int)floor(1+ofRandom(1)*44.99);
//    ostringstream ss;
//    ss << imgNbr;
//    string imgName = "img"+ss.str();
//    string imgUrl = "http://pm.alainbarthelemy.com/portrait/"+imgName+".jpg";
//    //cout << "imgB  " << imgUrl << '\n';
//    ofLoadURLAsync(imgUrl,"imgBAutoportrait");

    int imgNbr = (int)floor(1+ofRandom(1)*44.99);
    loader.loadFromURL(imgB[loadingBIndex], "http://pm.alainbarthelemy.com/portrait/img" + ofToString(imgNbr) + ".jpg");
    imgNbr = (int)floor(1+ofRandom(1)*44.99);
    loader.loadFromURL(imgB[loadingBIndex+1], "http://pm.alainbarthelemy.com/portrait/img" + ofToString(imgNbr) + ".jpg");

}

void Autoportrait::exit() {
	//ofUnregisterURLNotification(this);
    loader.stopThread();
}