#pragma once

class Cells {
private:

public:
	const int& rows = 50;
	const int& columns = 50;
	const int& pixelSize = 10;
	std::vector<std::vector<bool>> cells;

	Cells() {
		for (int x = 0; x < columns; x++) {
			vector<bool> temp;
			for (int y = 0; y < rows; y++) {
				temp.push_back(false);
			}
			cells.push_back(temp);
		}
	}
};