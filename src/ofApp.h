#pragma once

#include "ofMain.h"

#include "ofxGui.h"
#include "gamestate.h"

#include "grid.h"
#include "cells.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void settingsSetup();
		void update();
		void draw();
		void drawSettings();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void framerateChanged(int& framerate);
		void nextGenButton();
		void columnsChanged(int& columns);
		void rowsChanged(int& rows);

		//gui variables -- used gui groups so user can't move them
		ofxGuiGroup gridSetup;
		ofxIntSlider columns;
		ofxIntSlider rows;
		ofxGuiGroup frameSetup;
		ofxIntSlider framerate;
		ofxButton nextGen;

		//framerate variables
		int currentFramerate{ 4 };
		int defaultFramerate{ 30 };

		//creating grid, cells, and gamestate
		Grid grid = Grid();
		Cells cells = Cells();
		GameState gameState = GameState();

		//creating setting area and text area
		ofRectangle settingsArea = ofRectangle(0, grid.height(), grid.width(), 80);
		ofRectangle textArea;
};
