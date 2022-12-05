#include "cells.h"

int Cells::getIteration() { return iteration; }

Cells::Cells() { reset(); }

void Cells::reset() {
	cells.clear();
	cells.resize(rows, std::vector<State>(columns, State::Dead));

	newGen.clear();
	newGen.resize(rows, std::vector<State>(columns, State::Dead));

	iteration = 0;
}

void Cells::randomSeed() {
	reset();

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			int random = floor(ofRandom(0, 2));

			if (random == 1) newGen[y][x] = State::Alive;
			else newGen[y][x] = State::Dead;
		}
	}

	cells = newGen;
}

void Cells::changeState(int mouseX, int mouseY) {
	for (int x = 0; x < columns; x++) {
		for (int y = 0; y < rows; y++) {
			if (mouseX > x * pixelSize && mouseX < (x * pixelSize) + pixelSize &&
				mouseY > y * pixelSize && mouseY < (y * pixelSize) + pixelSize) {
				if (cells[y][x] == State::Alive) {
					cells[y][x] = State::Dead;
				} else {
					cells[y][x] = State::Alive;
				}
			}
		}
	}
}

void Cells::update() {
	newGen.clear();
	newGen.resize(rows, std::vector<State>(columns, State::Dead));

	for (int x = 0; x < columns; x++) {
		for (int y = 0; y < rows; y++) {
			checkLife(x, y);
		}
	}

	cells = newGen;

	iteration++;
}

void Cells::checkLife(int x, int y) {
	int aliveNeighbours = 0;

	//keeps tally of how many surrounding cells are alive
	if (x > 0 && y > 0 && cells[y - 1][x - 1] == State::Alive) aliveNeighbours++;
	if (y > 0 && cells[y - 1][x] == State::Alive) aliveNeighbours++;
	if (y > 0 && x < columns - 1 && cells[y - 1][x + 1] == State::Alive) aliveNeighbours++;
	if (x > 0 && cells[y][x - 1] == State::Alive) aliveNeighbours++;
	if (x < columns - 1 && cells[y][x + 1] == State::Alive) aliveNeighbours++;
	if (x > 0 && y < rows - 1 && cells[y + 1][x - 1] == State::Alive) aliveNeighbours++;
	if (x < columns - 1 && y < rows - 1 && cells[y + 1][x + 1] == State::Alive) aliveNeighbours++;
	if (y < rows - 1 && cells[y + 1][x] == State::Alive) aliveNeighbours++;

	if (cells[y][x] == State::Alive) {
		if (aliveNeighbours > 3) newGen[y][x] = State::Dead;
		else if (aliveNeighbours < 2) newGen[y][x] = State::Dead;
		else newGen[y][x] = State::Alive;
	} else {
		if (aliveNeighbours == 3) newGen[y][x] = State::Alive;
	}
}

void Cells::draw() {
	for (int x = 0; x < columns; x++) {
		for (int y = 0; y < rows; y++) {
			if (cells[y][x] == State::Alive) {
				ofSetColor(0);
				ofFill();
				ofDrawRectangle(pixelSize * x, pixelSize * y, pixelSize, pixelSize);
			} else {
				ofSetColor(200);
				ofNoFill();
				ofDrawRectangle(pixelSize * x, pixelSize * y, pixelSize, pixelSize);
			}
		}
	}
}
