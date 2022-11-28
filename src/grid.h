#pragma once

class Grid {
private:
	int rows = 50;
	int columns = 50;
	int pixelSize = 10;
	std::vector<std::vector<bool>> pixels;

public:
	Grid() {
		for (int x = 0; x < columns; x++) {
			vector<bool> temp;
			for (int y = 0; y < rows; y++) {
				temp.push_back(false);
			}
			pixels.push_back(temp);
		}
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
					if (bool pixel = pixels[y][x]) {
						pixels[y][x] = false;
					}
					else {
						pixels[y][x] = true;
					}
				}
			}
		}
	}

	void draw() {
		for (int x = 0; x < columns; x++) {
			for (int y = 0; y < rows; y++) {
				if (bool pixel = pixels[y][x]) {
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