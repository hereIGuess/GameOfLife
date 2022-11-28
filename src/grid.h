#pragma once

class Grid {
private:

public:
	const int& rows = 20;
	const int& columns = 20;
	const int& pixelSize = 30;

	Grid() {

	}

	int height() {
		return rows * pixelSize;
	}

	int width() {
		return columns * pixelSize;
	}
};
