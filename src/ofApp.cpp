#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    vec = {0,0.2,0.4,0.6};
    
    nn = new NeuralNetwork(5,2,1);
    
    for(int i=0; i<50000; i++){
        nn->train({0,0,1,0,0}, {0});
        nn->train({1,1,1,0,1}, {1});
        nn->train({1,0,1,0,1}, {0});
        nn->train({0,1,1,1,1}, {1});
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofDrawBitmapString(ofToString(guess), 10, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
   
    switch(key){
        case '1' :
            ofLogNotice("ff1") << ofToString(nn->feedforward({1,1,0,0,0})); // 1
            break;
        case '2' :
            ofLogNotice("ff2") << ofToString(nn->feedforward({0,1,1,0,1})); // 1
            break;
        case '3' :
            ofLogNotice("ff3") << ofToString(nn->feedforward({0,0,0,1,0})); // 0
            break;
        case '4' :
            ofLogNotice("ff4") << ofToString(nn->feedforward({0,0,0,0,0})); // 0
            break;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
   
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
