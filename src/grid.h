#pragma once

class Grid {
private:

public:
	const int& rows = 40;
	const int& columns = 40;
	const int& pixelSize = 20;

	Grid() {

	}

	int height() {
		return rows * pixelSize;
	}

	int width() {
		return columns * pixelSize;
	}
};
