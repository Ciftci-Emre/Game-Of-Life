#include <SFML/Graphics.hpp>
#include "GameOfLife.h"
int main()
{
    GameOfLife gameOfLife(500, 500, "Conway's Game of Life");
    gameOfLife.run();
    return 0;
}
