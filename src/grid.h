#pragma once

class Grid {
public:
	int rows;
	int columns;
	const int& pixelSize = 20;

	Grid() {
		rows = 40;
		columns = 40;
	}

	void setColumns(int newColumns) {
		columns = newColumns;
	}

	void setRows(int newRows) {
		rows = newRows;
	}

	int height() {
		return rows * pixelSize;
	}

	int width() {
		return columns * pixelSize;
	}
};
