#pragma once

#include "ofMain.h"


#include "Paysage.h"
#include "Silence.h"
#include "Portrait.h"
#include "Nu.h"
#include "Autoportrait.h"

#include "ofxThreadedImageLoader.h"

#define PAYSAGE 1
#define SILENCE 2
#define PORTRAIT 3
#define NU 4 // c'est bien si c'est sur la 4...
#define AUTOPORTRAIT 5

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
        void stopAll();
        void startCurrentChannel();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
       
   
        Paysage* paysage;
        Silence* silence;
        Portrait* portrait;
        Nu* nu;
        Autoportrait* autoportrait;
    
        ofxThreadedImageLoader loader;
    
        int currentChannel;

		
};
