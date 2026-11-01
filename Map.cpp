#include "Map.h"
#include <fstream>
#include <string>



Map::Map() {
    tileinfos[(int)E_CellType::Ground] = { '.', true,  false };
    tileinfos[(int)E_CellType::Water] = { '~', false, true };
    tileinfos[(int)E_CellType::Mountain] = { 'A', false, false };
    tileinfos[(int)E_CellType::Exit] = { 'E', true,  false };
}

void Map::LoadFromFile(const char* path) {
    std::ifstream file(path);                 // #include <fstream>, <string>
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line))
        if (!line.empty()) lines.push_back(line);

    height = (int)lines.size();
    width = height ? (int)lines[0].size() : 0;

    delete[] cells;                           // si on recharge une map
    cells = new int[width * height];

    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++) {
            int type = (int)E_CellType::Ground;   // défaut
            for (int t = 0; t < (int)E_CellType::Count; t++)
                if (tileinfos[t].symbol == lines[y][x]) type = t;
            cells[Get1DCell(x, y)] = type;
        }
}