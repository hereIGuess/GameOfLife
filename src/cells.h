#pragma once

class Cells : public Grid {
private:
	enum class State { Dead, Alive };

	std::vector<std::vector<State>> cells;
	std::vector<std::vector<State>> newGen;

	int iteration;

public:
	int getIteration() {
		return iteration;
	}

	Cells() {
		clear();
	}

	void clear() {
		cells.resize(0);
		cells.resize(rows, std::vector<State>(columns, State::Dead));
		newGen.resize(0);
		newGen.resize(rows, std::vector<State>(columns, State::Dead));

		iteration = 0;
	}

	void randomSeed() {
		for (int y = 0; y < rows; y++) {
			for (int x = 0; x < columns; x++) {
				int random = floor(ofRandom(0, 2));

				if (random == 1) cells[y][x] = State::Alive;
				else cells[y][x] = State::Dead;
			}
		}
	}

	void seeds(int mouseX, int mouseY) {
		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				if (mouseX > x * pixelSize && mouseX < (x * pixelSize) + pixelSize &&
					mouseY > y * pixelSize && mouseY < (y * pixelSize) + pixelSize) {
					if (cells[y][x] == State::Alive) {
						cells[y][x] = State::Dead;
					}
					else {
						cells[y][x] = State::Alive;
					}
				}
			}
		}
	}

	void update() {
		newGen.resize(rows, std::vector<State>(columns, State::Dead));

		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				checkLife(x, y);
			}
		}

		cells = newGen;
		iteration++;
	}

	void checkLife(int x, int y) {
		int aliveNeighbours = 0;

		if (cells[y][x] == State::Alive) {
			if (x > 0 && y > 0 && cells[y - 1][x - 1] == State::Alive) aliveNeighbours++;
			if (y > 0 && cells[y - 1][x] == State::Alive) aliveNeighbours++;
			if (y > 0 && x < columns - 1 && cells[y - 1][x + 1] == State::Alive) aliveNeighbours++;
			if (x > 0 && cells[y][x - 1] == State::Alive) aliveNeighbours++;
			if (x < columns - 1 && cells[y][x + 1] == State::Alive) aliveNeighbours++;
			if (x > 0 && y < rows - 1 && cells[y + 1][x - 1] == State::Alive) aliveNeighbours++;
			if (x < columns - 1 && y < rows - 1 && cells[y + 1][x + 1] == State::Alive) aliveNeighbours++;
			if (y < rows - 1 && cells[y + 1][x] == State::Alive) aliveNeighbours++;

			if (aliveNeighbours > 3) newGen[y][x] = State::Dead;
			else if (aliveNeighbours < 2) newGen[y][x] = State::Dead;
			else newGen[y][x] = State::Alive;
		}
		else if (cells[y][x] == State::Dead) {
			if (x > 0 && y > 0 && cells[y - 1][x - 1] == State::Alive) aliveNeighbours++;
			if (y > 0 && cells[y - 1][x] == State::Alive) aliveNeighbours++;
			if (y > 0 && x < columns - 1 && cells[y - 1][x + 1] == State::Alive) aliveNeighbours++;
			if (x > 0 && cells[y][x - 1] == State::Alive) aliveNeighbours++;
			if (x < columns - 1 && cells[y][x + 1] == State::Alive) aliveNeighbours++;
			if (x > 0 && y < rows - 1 && cells[y + 1][x - 1] == State::Alive) aliveNeighbours++;
			if (x < columns - 1 && y < rows - 1 && cells[y + 1][x + 1] == State::Alive) aliveNeighbours++;
			if (y < rows - 1 && cells[y + 1][x] == State::Alive) aliveNeighbours++;

			if (aliveNeighbours == 3) newGen[y][x] = State::Alive;
		}
	}

	void draw() {
		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				if (cells[y][x] == State::Alive) {
					ofSetColor(0);
					ofFill();
					ofSetLineWidth(0);
					ofDrawRectangle(pixelSize * x, pixelSize * y, pixelSize, pixelSize);
				}
				else {
					ofSetColor(200);
					ofNoFill();
					ofSetLineWidth(2);
					ofDrawRectangle(pixelSize * x, pixelSize * y, pixelSize, pixelSize);
				}
			}
		}
	}
};