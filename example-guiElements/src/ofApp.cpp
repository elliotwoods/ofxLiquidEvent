#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	//--
	//First button
	//--
	//
	auto button = new GuiElement();
	
	button->onDraw += [this, button] (GuiElement::DrawArgs&) {
		auto & bounds = button->bounds;
		ofPushStyle();
		ofNoFill();
		ofRect(bounds);
		ofDrawBitmapString("button 1", bounds.x + 20, bounds.y + 10);
		ofPopStyle();
	};

	button->bounds = ofRectangle(300, 300, 100, 20);
	//
	//--
	
	
	//--
	//Second button
	//--
	//
	auto button2 = new GuiElement();
	
	//copy everything from first button (behaviours and all)
	*button2 = *button;
	
	button2->onDraw += [this, button2] (GuiElement::DrawArgs&) {
		auto & bounds = button2->bounds;
		ofPushStyle();
		ofNoFill();
		ofRect(bounds);
		ofDrawBitmapString("button 2", bounds.x + 20, bounds.y + 10);
		ofPopStyle();
	};
	
	button->bounds = ofRectangle(300, 300, 100, 20);
	//
	//--
	
	
	this->guiElements.push_back(button);
	this->guiElements.push_back(button2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(50, 0);
	GuiElement::DrawArgs drawArgs; // empty argument set
	
	for(auto element : this->guiElements) {
		element->onDraw(drawArgs);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	this->keyAction(key, GuiElement::KeyArgs::Action::Pressed);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	this->keyAction(key, GuiElement::KeyArgs::Action::Released);
}

//--------------------------------------------------------------
void ofApp::keyAction(int key, GuiElement::KeyArgs::Action action) {
	GuiElement::KeyArgs keyArgs;
	
	keyArgs.action = action;
	keyArgs.key = key;
	
	for(auto element : this->guiElements) {
		element->onKey(keyArgs);
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	this->mouseAction(x, y, GuiElement::MouseArgs::Action::Moved);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	this->mouseAction(x, y, GuiElement::MouseArgs::Action::Dragged);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	this->mouseAction(x, y, GuiElement::MouseArgs::Action::Pressed);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	this->mouseAction(x, y, GuiElement::MouseArgs::Action::Released);
}

//--------------------------------------------------------------
void ofApp::mouseAction(int x, int y, GuiElement::MouseArgs::Action action) {
	GuiElement::MouseArgs mouseArgs;
	
	mouseArgs.action = GuiElement::MouseArgs::Pressed;
	mouseArgs.position = ofVec2f(x, y);
	
	for(auto element : this->guiElements) {
		element->onMouse(mouseArgs);
	}
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
