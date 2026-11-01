#pragma once
#include "Vector2.h"
#include <iostream>
#include <vector>
#include "E_CellType.h"
#include "TileInfo.h"
class Map
{

public :
	int* cells = 0;
	int width = 1;
	int height = 1;

	TileInfo tileinfos[(int)E_CellType::Count];
	Vector2 playerSpawn;
	std::vector<Vector2> enemySpawn;

	Map();
	~Map() { delete[] cells; }
	Map(const Map&) = delete;
	Map& operator=(const Map&) = delete;

	int Get1DCell(int x, int y) const { return y * width + x; };
	void LoadFromFile(const char*);

	const TileInfo& GetTileInfo(int x, int y) const {
		return tileinfos[cells[Get1DCell(x, y)]];
	}
};

