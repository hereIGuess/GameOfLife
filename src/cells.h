#pragma once

class Cells : public Grid {
private:
	std::vector<std::vector<bool>> cells;
	std::vector<std::vector<bool>> newGen;

	bool isUpdating = false;

public:
	Cells() {
		for (int x = 0; x < columns; x++) {
			vector<bool> temp;
			for (int y = 0; y < rows; y++) {
				temp.push_back(false);
			}
			cells.push_back(temp);
		}
	}

	void seeds(int mouseX, int mouseY) {
		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				if (mouseX > x * pixelSize && mouseX < (x * pixelSize) + pixelSize &&
					mouseY > y * pixelSize && mouseY < (y * pixelSize) + pixelSize) {
					if (bool pixel = cells[y][x]) {
						cells[y][x] = false;
					}
					else {
						cells[y][x] = true;
					}
				}
			}
		}
	}

	void update() {
		if (isUpdating) return;

		isUpdating = true;

		newGen.resize(rows, std::vector<bool>(columns, false));

		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				checkLife(x, y);
			}
		}

		cells = newGen;
		isUpdating = false;
	}

	void checkLife(int x, int y) {
		if (x == 0 || x == columns - 1 || y == 0 || y == rows - 1) return;

		int aliveNeighbours = 0;
		bool alive = cells[y][x];

		if (alive) {
			if (cells[y - 1][x - 1]) aliveNeighbours++;
			if (cells[y - 1][x]) aliveNeighbours++;
			if (cells[y - 1][x + 1]) aliveNeighbours++;
			if (cells[y][x - 1]) aliveNeighbours++;
			if (cells[y][x + 1]) aliveNeighbours++;
			if (cells[y + 1][x - 1]) aliveNeighbours++;
			if (cells[y + 1][x]) aliveNeighbours++;
			if (cells[y + 1][x + 1]) aliveNeighbours++;

			if (aliveNeighbours > 3) newGen[y][x] = false;
			else if (aliveNeighbours < 2) newGen[y][x] = false;
			else newGen[y][x] = true;
		}
		else if (!alive) {
			if (cells[y - 1][x - 1]) aliveNeighbours++;
			if (cells[y - 1][x]) aliveNeighbours++;
			if (cells[y - 1][x + 1]) aliveNeighbours++;
			if (cells[y][x - 1]) aliveNeighbours++;
			if (cells[y][x + 1]) aliveNeighbours++;
			if (cells[y + 1][x - 1]) aliveNeighbours++;
			if (cells[y + 1][x]) aliveNeighbours++;
			if (cells[y + 1][x + 1]) aliveNeighbours++;

			if (aliveNeighbours == 3) newGen[y][x] = true;
			else newGen[y][x] = false;
		}
	}

	void draw() {
		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				if (bool pixel = cells[y][x]) {
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