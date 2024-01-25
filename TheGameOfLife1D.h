#pragma once

#include <iostream>
#include <cmath>
//#include <vector>
#include <array>
//#include <algorithm>

#include <cstdlib>
#include <ctime>


// Class  TheGameOfLife1D
class TheGameOfLife1D {
private:



public:
    // default constructor
    TheGameOfLife1D();
    TheGameOfLife1D(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);

    // default destructor
    ~TheGameOfLife1D();

    
    void Initialize(bool isRandom);
    int Rules(int a, int b, int c);   
    void ComputeNextGen();
    void Draw();
    void Run(const int iterations);

    static constexpr int nbit =2*2*2;
    //Arbitrarily start with rule 90.
    int ruleset[nbit];

    static constexpr int width = 292;
    std::array<int, width> cells;

};
