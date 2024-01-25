// TheGameOfLife.cpp 



#include "TheGameOfLife1D.h"

//_______________________________________________________________________________________
TheGameOfLife1D::TheGameOfLife1D() {

}

//_______________________________________________________________________________________
TheGameOfLife1D::TheGameOfLife1D(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)  {
    ruleset[0] = a0;
    ruleset[1] = a1;
    ruleset[2] = a2;
    ruleset[3] = a3;
    ruleset[4] = a4;
    ruleset[5] = a5;
    ruleset[6] = a6;
    ruleset[7] = a7;

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // use current time as seed for random generator

    std::cout << "____________________ The Game Of Life 1D (C++ test) ________________ " << std::endl;
    std::cout << "____________________ ______________________________ ________________ " << std::endl;
    std::cout  << std::endl;
}

//_______________________________________________________________________________________
TheGameOfLife1D::~TheGameOfLife1D() {

}


int TheGameOfLife1D::Rules(int a, int b, int c) {
    // alternative is to take input int as binary number 
    if (a == 1 && b == 1 && c == 1) return ruleset[0];
    else if (a == 1 && b == 1 && c == 0) return ruleset[1];
    else if (a == 1 && b == 0 && c == 1) return ruleset[2];
    else if (a == 1 && b == 0 && c == 0) return ruleset[3];
    else if (a == 0 && b == 1 && c == 1) return ruleset[4];
    else if (a == 0 && b == 1 && c == 0) return ruleset[5];
    else if (a == 0 && b == 0 && c == 1) return ruleset[6];
    else if (a == 0 && b == 0 && c == 0) return ruleset[7];
}


void TheGameOfLife1D::Initialize(bool isRandom=false) {
    if (isRandom) {
        for (int i = 0; i < width; i++) {
            cells[i] = 0;
            double random = std::rand();
            double random_value = random / RAND_MAX;
            if (random_value > 0.5) cells[i] = 1;
        }
    }
    else {
        for (int i = 0; i < width; i++) {
            cells[i] = 0;
        }
        cells[int(cells.size() / 2)] = 1;
    }
}

void TheGameOfLife1D::ComputeNextGen() {
    std::array<int, width> nextgen;
    //remove edges of the array
    for (int i = 1; i < cells.size() - 1; i++) {
        int left = cells[i - 1];
        int me = cells[i];
        int right = cells[i + 1];
        nextgen[i] = Rules(left, me, right);
    }
    // Compute the next generation.
    cells = nextgen;
}

void TheGameOfLife1D::Run(const int iterations = 100) {
    for (int i = 0; i < iterations; i++) {
        Draw();
        ComputeNextGen();
    }
}

void TheGameOfLife1D::Draw() {
    for (int i = 0; i < cells.size(); i++) {
        if (cells[i] == 0) std::cout << " ";
        if (cells[i] == 1) std::cout << "*";
    }
    std::cout << std::endl;
}


