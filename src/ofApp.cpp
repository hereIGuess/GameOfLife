#include "ofApp.h"

//CONTROLS:
//Space to play/pause
//C to clear canvas
//R to create a random seed
//Next Gen button can only be pressed when game is paused

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(grid.width(), grid.height() + settingsArea.getHeight());
	ofBackground(255);
	ofSetLineWidth(2);

	settingsSetup();
}

//--------------------------------------------------------------
void ofApp::settingsSetup() {
	//grid settings
	gridSetup.setup("Grid Settings:");
	gridSetup.add(columns.setup("Number of Columns:", 40, 30, 80));
	gridSetup.add(rows.setup("Number of Rows:", 40, 20, 60));
	gridSetup.setSize(180, 40);

	//frame settings
	frameSetup.setup("Frame Settings:");
	frameSetup.add(framerate.setup("Set Framerate:", 4, 1, 8));
	frameSetup.add(nextGen.setup("Next Gen"));
	frameSetup.setSize(160, 40);

	//set listeners
	framerate.addListener(this, &ofApp::framerateChanged);
	nextGen.addListener(this, &ofApp::nextGenButton);
	columns.addListener(this, &ofApp::columnsChanged);
	rows.addListener(this, &ofApp::rowsChanged);

	//set positions
	gridSetup.setPosition(grid.pixelSize, settingsArea.y + 10);
	frameSetup.setPosition(gridSetup.getWidth() + grid.pixelSize * 2, settingsArea.y + 10);

	//text area setup
	textArea = ofRectangle(gridSetup.getWidth() + frameSetup.getWidth() + grid.pixelSize * 3, settingsArea.getY() + settingsArea.getHeight() / 2 - 30, 180, 60);
}

//--------------------------------------------------------------
void ofApp::update(){
	//only update if game is playing
	if (!gameState.getGameState()) {
		cells.update();

		//lower framerate
		ofSetFrameRate(currentFramerate);
	} else {
		//reset framerate to default
		ofSetFrameRate(defaultFramerate);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	cells.draw();

	drawSettings();
}

void ofApp::drawSettings() {
	//draw setting area
	ofFill();
	ofSetColor(200);
	ofDrawRectangle(settingsArea);

	//draw text area
	ofSetColor(255);
	ofDrawRectangle(textArea);

	//setup texts
	std::string iterationText = "Iteration: " + std::to_string(cells.getIteration());
	std::string gameStateText = "Game State: " + gameState.getText();

	//draw strings
	ofSetColor(0);
	ofDrawBitmapString(iterationText, textArea.getX() + textArea.getWidth() / 2 - iterationText.length() * 4, textArea.getY() + 20);
	ofDrawBitmapString(gameStateText, textArea.getX() + textArea.getWidth() / 2 - gameStateText.length() * 4, textArea.getY() + textArea.getHeight() - 20);

	//draw GUIs
	frameSetup.draw();
	gridSetup.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//if user presses r while game is paused, create a random seed
	if (key == 114 && gameState.getGameState()) {
		cells.randomSeed();
	}

	//if user presses c, empty grid
	if (key == 99) {
		ofSetFrameRate(defaultFramerate);
		gameState.setGameState(true);
		cells.reset();
	}

	//if user pressed space, set gameState
	if (key == 32) {
		gameState.setGameState(!gameState.getGameState());
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//check what cell should be changed
	if (gameState.getGameState()) {
		cells.changeState(x, y);
	}
}

void ofApp::framerateChanged(int& framerate){
	currentFramerate = framerate;
}

void ofApp::nextGenButton(){
	if (gameState.getGameState()) {
		cells.update();
	}
}

void ofApp::columnsChanged(int& columns) {
	//when columns are changed:
	//pause game, setup columns, reset cells...
	//change settings, and resize window

	gameState.setGameState(true);

	grid.setColumns(columns);

	cells.columns = columns;
	cells.reset();

	settingsArea.setWidth(grid.width());

	ofSetWindowShape(grid.width(), grid.height() + settingsArea.getHeight());
}

void ofApp::rowsChanged(int& rows) {
	//when rows are changed:
	//pause game, setup rows, reset cells...
	//change settings, and resize window

	gameState.setGameState(true);

	grid.setRows(rows);

	cells.rows = rows;
	cells.reset();

	settingsArea.setY(grid.height());
	textArea.setY(settingsArea.getY() + settingsArea.getHeight() / 2 - 30);
	gridSetup.setPosition(grid.pixelSize, settingsArea.y + 10);
	frameSetup.setPosition(gridSetup.getWidth() + grid.pixelSize * 2, settingsArea.y + 10);

	ofSetWindowShape(grid.width(), grid.height() + settingsArea.getHeight());
}
