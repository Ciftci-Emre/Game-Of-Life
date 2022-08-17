#ifndef GRIDCELLS_H
#define GRIDCELLS_H

#define GRID_WIDTH 100
#define GRID_HEIGHT 100

class GridCells
{
    public:
        int row, column;
        int cellWidth, cellHeight;
        bool cells[GRID_HEIGHT][GRID_WIDTH];

        GridCells() = default;
        virtual ~GridCells() = default;

        void setAllCells(bool life_situation);

    protected:

    private:
};

#endif // GRIDCELLS_H
