#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(800,600,OF_WINDOW);			// <-------- setup the GL context 1024x768

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    ofSetVerticalSync(false);
    ofSetFrameRate(10);
    ofSetLogLevel(OF_LOG_VERBOSE);
    
    
	ofRunApp(new testApp());

}
