#pragma once

#include "ofMain.h"

#include "ofxGui.h"
#include "gamestate.h"

#include "grid.h"
#include "cells.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void framerateChanged(int& framerate);
		void nextGenButton();
		void columnsChanged(int& columns);
		void rowsChanged(int& rows);

		//GUI VARIABLES
		//used gui groups so they aren't moveable
		ofxGuiGroup gridSetup;
		ofxIntSlider columns;
		ofxIntSlider rows;
		ofxGuiGroup frameSetup;
		ofxIntSlider framerate;
		ofxButton nextGen;

		int currentFramerate = 4;

		Grid grid = Grid();
		Cells cells = Cells();
		GameState gameState = GameState();

		ofRectangle settingsArea = ofRectangle(0, grid.height(), grid.width(), 80);
		ofRectangle textArea;
};
