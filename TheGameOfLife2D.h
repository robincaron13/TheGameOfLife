#pragma once

#include "TheGameOfLife1D.h"
#include <opencv2/opencv.hpp>

// Class  TheGameOfLife2D
class TheGameOfLife2D : public TheGameOfLife1D {
private:


public:
    TheGameOfLife2D(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);

    // default destructor
    ~TheGameOfLife2D();

    void Initialize(bool isRandom);
    int Rules(int value, int sum);
    void ComputeNextGen();
    void Draw(int iteration);
    void Run(const int iterations);

    void DrawStandard(int iteration);
    void CreateImage(int iteration, int side, int colorBkg);
    int GetCellInfo(int col, int row);

    int cellInfo;
    std::array< std::array<int, width>, width> old_cells2D;
    std::array< std::array<int, width>, width> cells2D;

};
