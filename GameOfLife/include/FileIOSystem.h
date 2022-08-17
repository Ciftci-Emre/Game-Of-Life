#ifndef FILEIOSYSTEM_H
#define FILEIOSYSTEM_H

#include <iostream>
#include <fstream>
#include <string>
#include "GridCells.h"

class FileIOSystem
{
    public:
        FileIOSystem() = default;
        virtual ~FileIOSystem() = default;

        std::string filename;
        bool isTypingS;
        bool isTypingL;
        void save(bool cells[GRID_HEIGHT][GRID_WIDTH]);
        void load(bool cells[GRID_HEIGHT][GRID_WIDTH]);

    protected:

    private:
};

#endif // FILEIOSYSTEM_H
