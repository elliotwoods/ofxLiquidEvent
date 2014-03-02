#pragma once

#include "ofMain.h"
#include "ofxLiquidEvent.h"

struct LiquidEventExampleArgs {
    float time;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
        void draw();
    
        // This is the stack of handlers
        ofxLiquidEvent<LiquidEventExampleArgs> listeners;
};
