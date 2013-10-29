#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //paysage = new Paysage(0,0,ofGetWidth(),ofGetHeight());
    //silence = new Silence(0,0,ofGetWidth(),ofGetHeight());
    portrait = new Portrait(0,0,ofGetWidth(),ofGetHeight());
    nu = new Nu(0,0,ofGetWidth(),ofGetHeight());
    //autoportrait = new Autoportrait(0,0,ofGetWidth(),ofGetHeight());
    
    currentChannel = NU;
    startCurrentChannel();
    
}



//--------------------------------------------------------------
void testApp::update(){
	
    
    /*switch (currentChannel) {
        case PAYSAGE:
            paysage->update();
            break;
        case SILENCE:
            silence->update();
            break;
        case PORTRAIT:
            portrait->update();
            break;
        case NU:
            nu->update();
            break;
        case AUTOPORTRAIT:
            autoportrait->update();
            break;
            
        default:
            break;
    }*/
    //paysage->update();
    //silence->update();
    portrait->update();
    nu->update();
    //autoportrait->update();
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    switch (currentChannel) {
        case PAYSAGE:
            //paysage->draw();
            break;
        case SILENCE:
            //silence->draw();
            break;
        case PORTRAIT:
            portrait->draw();
            break;
        case NU:
            nu->draw();
            break;
        case AUTOPORTRAIT:
            //autoportrait->draw();
            break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::exit() {

    paysage->exit();
    portrait->exit();
    nu->exit();
    autoportrait->exit();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //paysage->load();
    cout << key << '\n';
    
    
    switch (key) {
        case 49:// 1
            currentChannel = 1;
            break;
        case 50:// 2
            currentChannel = 2;
            break;
        case 51:// 3
            currentChannel = 3;
            break;
        case 52:// 4
            currentChannel = 4;
            break;
        case 53:// 5
            currentChannel = 5;
            break;
        case 54:// 6
            currentChannel = 6;
            break;
            
        default:
            return;
    }
    
    stopAll();
    startCurrentChannel();
}

void testApp::stopAll(){
    silence->stop();
}

void testApp::startCurrentChannel(){
    switch (currentChannel) {
        case PAYSAGE:break;
        case SILENCE:
            silence->start();
            break;
        case PORTRAIT:break;
        case NU:break;
            
        default:
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    //sound.play();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
