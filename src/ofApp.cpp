#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);

	ofSetFrameRate(30);

	frameRate.setup("Framerate: ", 4, 1, 8, 125, 20);
	frameRate.setPosition(pixelGrid.width() / 2, pixelGrid.height() + 10);

	frameRate.addListener(this, &ofApp::frameRateChanged);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowShape(pixelGrid.width(), pixelGrid.height() + 40);
	 
	if (!gameState.getGameState()) {
		cells.update();
		ofSetFrameRate(frameSpeed);
		iteration++;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cells.draw();

	ofSetColor(0);
	ofDrawBitmapString("Iteration: " + std::to_string(iteration), pixelGrid.width() - 200, pixelGrid.height() + 20);
	ofDrawBitmapString(gameState.getText(), 200, pixelGrid.height() + 20);
	frameRate.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 114 && gameState.getGameState()) {
		cells.randomSeed();
		iteration = 0;
	}

	if (key == 99) {
		gameState.setGameState(true);
		iteration = 0;
		cells.clear();
		key = 0;
		ofSetFrameRate(30);
	}

	if (key == 32) {
		if (gameState.getGameState()) {
			gameState.setGameState(false);
		}
		else if (!gameState.getGameState()) {
			gameState.setGameState(true);
			ofSetFrameRate(30);
		}
	}
}

void ofApp::frameRateChanged(int& frameRate){
	frameSpeed = frameRate;
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
