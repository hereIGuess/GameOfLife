#pragma once
#include <vector>
#include "grid.h"
#include "ofxColorPicker.h"

class Cells : public Grid {
private:
	enum class State { Dead, Alive };

	std::vector<std::vector<State>> cells;
	std::vector<std::vector<State>> newGen;

	int iteration;

public:
	int getIteration();

	Cells();

	void reset();

	void randomSeed();

	void changeState(int mouseX, int mouseY);

	void update();

	void checkLife(int x, int y);

	void draw();
};
