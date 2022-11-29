#include "ofApp.h"

//CONTROLS:
//Space to play/pause
//C to clear canvas
//R to create a random seed
//Button in lower left can only be pressed when game is paused

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);

	ofSetFrameRate(30);

	gridSetup.setup("Grid Settings:");
	gridSetup.add(columns.setup("Number of Columns:", 40, 30, 80));
	gridSetup.add(rows.setup("Number of Rows:", 40, 20, 60));
	gridSetup.setSize(200, 40);

	frameSetup.setup("Frame Settings:");
	frameSetup.add(framerate.setup("Set Framerate:", 4, 1, 8));
	frameSetup.add(nextGen.setup("Next Gen"));
	gridSetup.setSize(200, 40);

	framerate.addListener(this, &ofApp::framerateChanged);
	nextGen.addListener(this, &ofApp::nextGenButton);
	columns.addListener(this, &ofApp::columnsChanged);
	rows.addListener(this, &ofApp::rowsChanged);

	gridSetup.setPosition(grid.pixelSize, settingsArea.y + 10);
	frameSetup.setPosition(frameSetup.getWidth() + grid.pixelSize * 2, settingsArea.y + 10);

	textArea = ofRectangle(gridSetup.getWidth() + frameSetup.getWidth() + grid.pixelSize * 3, grid.height() + 10, 120, 60);
}

//--------------------------------------------------------------
void ofApp::update(){
	ofSetWindowShape(grid.width(), grid.height() + settingsArea.getHeight());

	if (!gameState.getGameState()) {
		cells.update();
		ofSetFrameRate(currentFramerate);
		iteration++;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cells.draw();

	ofFill();
	ofSetColor(200);
	ofDrawRectangle(settingsArea);

	ofSetColor(255);
	ofDrawRectangle(textArea);

	std::string iterationText = "Iteration: " + std::to_string(iteration);
	std::string gameStateText = "Game State: " + gameState.getText();
	textArea.setWidth(gameStateText.length() * 10 + 10);

	ofSetColor(0);
	ofDrawBitmapString(iterationText, textArea.getX() + textArea.getWidth() / 2 - iterationText.length() * 4,  textArea.getY() + 20);
	ofDrawBitmapString(gameStateText, textArea.getX() + textArea.getWidth() / 2 - gameStateText.length() * 4, textArea.getY() + textArea.getHeight() - 20);

	frameSetup.draw();
	gridSetup.draw();
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

void ofApp::framerateChanged(int& framerate){
	currentFramerate = framerate;
}

void ofApp::nextGenButton(){
	if (gameState.getGameState()) {
		cells.update();
		iteration++;
	}
}

void ofApp::columnsChanged(int& columns) {
	grid.setColumns(columns);
	cells.columns = columns;
	cells.clear();
	settingsArea.setWidth(grid.width());
}

void ofApp::rowsChanged(int& rows) {
	grid.setRows(rows);
	cells.rows = rows;
	cells.clear();
	textArea.setY(grid.height());
	gridSetup.setPosition(gridSetup.getWidth() / 10, settingsArea.y + gridSetup.getHeight() / 4);
	frameSetup.setPosition(frameSetup.getWidth() + frameSetup.getWidth() / 10 * 2, settingsArea.y + frameSetup.getHeight() / 4);
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
