#include "GridCells.h"

void GridCells::setAllCells(bool life_situation){
    for(int y = 0; y < column; y++){
        for(int x = 0; x < row; x++){
            cells[y][x] = life_situation;
            next[y][x] = life_situation;
        }
    }
}

int GridCells::neighborCount(int x, int y){
    unsigned int neighbors = 0;
    if(x == 0 && y == 0){
        if(this->cells[y][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x] == 1){
            neighbors++;
        }
    }
    else if(x == row-1 && y == 0){
        if(this->cells[y+1][x] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y][x-1] == 1){
            neighbors++;
        }
    }
    else if(x == row-1 && y == column-1){
        if(this->cells[y-1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x] == 1){
            neighbors++;
        }
        if(this->cells[y][x-1] == 1){
            neighbors++;
        }
    }
    else if(x == 0 && y == column-1){
        if(this->cells[y-1][x] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y][x+1] == 1){
            neighbors++;
        }
    }
    else if(y == 0 && (x != 0 || x != row-1)){
        if(this->cells[y+1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y][x+1] == 1){
            neighbors++;
        }
    }
    else if(y == column-1 && (x != 0 || x != row-1)){
        if(this->cells[y-1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y][x-1] == 1){
            neighbors++;
        }
    }
    else if(x == 0 && (y != 0 || y != column-1)){
        if(this->cells[y-1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x] == 1){
            neighbors++;
        }
    }
    else if(x == row-1 && (y != 0 || y != column-1)){
        if(this->cells[y-1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x] == 1){
            neighbors++;
        }
    }
    else{
        if(this->cells[y-1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x] == 1){
            neighbors++;
        }
        if(this->cells[y-1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x+1] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x] == 1){
            neighbors++;
        }
        if(this->cells[y+1][x-1] == 1){
            neighbors++;
        }
        if(this->cells[y][x-1] == 1){
            neighbors++;
        }
    }
    return neighbors;
}
