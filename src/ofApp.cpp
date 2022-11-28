#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetFrameRate(4);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowShape(pixelGrid.width(), pixelGrid.height());

	if (!gameState.getGameState()) {
		cells.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cells.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	gameState.setGameState(false);
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
	if (gameState.getGameState()) {
		cells.seeds(x, y);
	}
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
