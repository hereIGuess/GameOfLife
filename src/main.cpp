#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//stop users from being able to resize window
	ofGLFWWindowSettings window;
	window.setSize(500, 500);
	window.resizable = false;
	ofCreateWindow(window);
	ofRunApp(new ofApp());
}
