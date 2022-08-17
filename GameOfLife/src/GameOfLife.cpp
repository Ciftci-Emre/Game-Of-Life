#include "GameOfLife.h"

GameOfLife::GameOfLife(int width, int height, const char* name)
{
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), name, sf::Style::Titlebar | sf::Style::Close);
    this->winWidth = width;
    this->winHeight = height;
    this->cells.cellWidth = 5;
    this->cells.cellHeight = 5;
    this->cells.row = 100;
    this->cells.column = 100;
    this->cells.setAllCells(0);
    neighbors = 0;
    duration = 0.5f;
    fileManager.filename = "";
    fileManager.isTypingS = false;
    fileManager.isTypingL = false;
}

GameOfLife::~GameOfLife()
{
    delete this->window;
}


void GameOfLife::run(){
    while (window->isOpen())
    {
        sf::Event event;
        time = clock.getElapsedTime().asSeconds();
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                this->isRunning = !isRunning;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right){
                this->duration -= 0.1;
                if(duration < 0)
                    duration = 0.00001;
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
                this->duration += 0.07;
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C && (!fileManager.isTypingL && !fileManager.isTypingS))
                cells.setAllCells(0);
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::S && (!fileManager.isTypingS && !fileManager.isTypingL)){
                fileManager.isTypingS = true;
                std::cout << "Enter file name:\n";
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && (fileManager.isTypingS || fileManager.isTypingL)){
                if(fileManager.isTypingS)
                    fileManager.save(cells.cells);
                else if(fileManager.isTypingL)
                    fileManager.load(cells.cells);
                std::cout << "\n";
            }
            if (event.type == sf::Event::TextEntered && (fileManager.isTypingS || fileManager.isTypingL)){
                if (event.text.unicode < 128){
                    fileManager.filename += static_cast<char>(event.text.unicode);
                }
                std::cout << static_cast<char>(event.text.unicode);
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::L && (!fileManager.isTypingL && !fileManager.isTypingS)){
                fileManager.isTypingL = true;
                std::cout << "Enter file name:\n";
            }
            if (event.type == sf::Event::MouseButtonPressed){
                int mouse_x = sf::Mouse::getPosition(*window).x;
                int mouse_y = sf::Mouse::getPosition(*window).y;
                int select_x = mouse_x / cells.cellWidth;
                int select_y = mouse_y / cells.cellHeight;
                cells.cells[select_y][select_x] = !cells.cells[select_y][select_x];
            }
        }

        window->clear();
        drawGrids();
        calculateNextFrame();
        //std::cout<<time<<std::endl;
        window->display();
    }
}

void GameOfLife::drawGrids(){
    for(int y = 0; y < cells.column; y++){
        for(int x = 0; x < cells.row; x++){
            sf::RectangleShape grid(sf::Vector2f(cells.cellWidth, cells.cellHeight));
            grid.setOutlineColor(sf::Color(0,0,0));
            grid.setOutlineThickness(0.5);
            grid.setPosition(cells.cellWidth * x, cells.cellHeight * y);
            neighbors = cells.neighborCount(x, y);
            if(cells.cells[y][x] == 1 && (neighbors < 2 || neighbors > 3)){
                cells.next[y][x] = 0;
            }
            else if(cells.cells[y][x] == 0 && neighbors == 3)cells.next[y][x] = 1;
            else cells.next[y][x] = cells.cells[y][x];
            grid.setFillColor(cells.cells[y][x] ? ALIVE : DEAD);
            this->window->draw(grid);
        }
    }
}

void GameOfLife::calculateNextFrame(){
    if(isRunning && time > duration){
        for(int y = 0; y < cells.column; y++){
            for(int x = 0; x < cells.row; x++){
                cells.cells[y][x] = cells.next[y][x];
            }
        }
        clock.restart();
    }
}

void GameOfLife::transform(unsigned int x, unsigned int y, bool life_situation){
    sf::RectangleShape cell(sf::Vector2f(cells.cellWidth, cells.cellHeight));
    cell.setFillColor(life_situation ? ALIVE : DEAD);
    cell.setOutlineColor(sf::Color(0,0,0));
    cell.setOutlineThickness(0.5);
    cell.setPosition(cells.cellWidth * x, cells.cellHeight * y);
    this->window->draw(cell);
    cells.cells[y][x] = life_situation;
}
