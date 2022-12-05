#pragma once

class Grid {
public:
	int rows{ 40 };
	int columns{ 40 };
	const int& pixelSize{ 20 };

	Grid();

	void setColumns(int newColumns);

	void setRows(int newRows);

	int height();

	int width();
};
