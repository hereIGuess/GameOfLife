#include "grid.h"

Grid::Grid() { }

void Grid::setColumns(int newColumns) { columns = newColumns; }

void Grid::setRows(int newRows) { rows = newRows; }

int Grid::height() { return rows * pixelSize; }

int Grid::width() { return columns * pixelSize; }
