#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    listeners += [] (LiquidEventExampleArgs args) {
        ofCircle( ofGetWidth()/2.0f , ofGetHeight()/2.0f * sin(args.time) + ofGetHeight()/2.0f, 20.0f);
    };
    
    listeners += [] (LiquidEventExampleArgs args) {
        ofCircle( ofGetWidth()/2.0f * sin(args.time) + ofGetWidth()/2.0f, ofGetHeight()/2, 20.0f);
    };
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Create the arguments which are passed to the listeners
    LiquidEventExampleArgs args;
    
    // Add the time
    args.time = ofGetElapsedTimef();
    
    // Trigger the listeners
    listeners.notifyListeners(args);


}
