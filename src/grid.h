#pragma once

class Grid : public Cells {
private:

public:
	Grid() {
	}

	int height() {
		return rows * pixelSize;
	}

	int width() {
		return columns * pixelSize;
	}

	void update(int mouseX, int mouseY) {
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
