#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "GridCells.h"
#include "FileIOSystem.h"

#define DEAD sf::Color(40, 40, 40)
#define ALIVE sf::Color(255, 255, 255)

class GameOfLife
{
    public:
        GameOfLife() = default;
        GameOfLife(int width, int height, const char*name);
        virtual ~GameOfLife();

        void run();
        void drawGrids();
        void calculateNextFrame();
        void transform(unsigned int x, unsigned int y, bool life_situation);

    protected:

    private:
        sf::RenderWindow* window;
        FileIOSystem fileManager;
        int winWidth, winHeight;
        bool isRunning;
        float duration;
        GridCells cells;
        int neighbors;
        sf::Clock clock;
        float time;
};

#endif // GAMEOFLIFE_H
