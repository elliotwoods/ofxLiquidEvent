#pragma once

#include "ofxLiquidEvent.h"
#include "ofMain.h"

class GuiElement {
public:
	struct DrawArgs {
		
	};
	
	struct MouseArgs {
		enum Action {
			Pressed,
			Released,
			Dragged,
			Moved
		};
		
		int button;
		Action action;
		ofVec2f position;
	};
	
	struct KeyArgs {
		enum Action {
			Pressed,
			Released
		};
		
		int key;
		Action action;
	};
	
	ofxLiquidEvent<DrawArgs> onDraw;
	ofxLiquidEvent<MouseArgs> onMouse;
	ofxLiquidEvent<KeyArgs> onKey;
	
	ofRectangle bounds;
};