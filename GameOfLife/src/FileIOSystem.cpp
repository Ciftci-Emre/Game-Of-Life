#include "FileIOSystem.h"

void FileIOSystem::save(bool cells[GRID_HEIGHT][GRID_WIDTH]){
    std::ofstream file;
    file.open(filename + ".gol");
    for(int y = 0; y < GRID_HEIGHT; y++){
        for(int x = 0; x < GRID_WIDTH; x++){
            file << cells[y][x];
        }
        file << "\n";
    }
    file.close();
    std::cout << "\n" + filename + ".gol saved!\n";
    filename = "";
    isTypingS = false;
}

void FileIOSystem::load(bool cells[GRID_HEIGHT][GRID_WIDTH]){
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        int index = 0;
        while (std::getline(file, line)) {
            for(int x = 0; x < line.length(); x++){
                cells[index][x] = (line[x] == '0') ? 0 : 1;
            }
            index++;
        }
    }else std::cout << "\nFailed!\n";
    file.close();
    filename = "";
    isTypingL = false;
}
