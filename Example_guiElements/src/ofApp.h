#pragma once

#include "ofMain.h"
#include "GuiElement.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
	
		void keyAction(int key, GuiElement::KeyArgs::Action action);
	
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

		void mouseAction(int x, int y, GuiElement::MouseArgs::Action action);
	
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		vector<GuiElement*> guiElements;
};
