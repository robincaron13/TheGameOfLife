// TheGameOfLife.cpp 



#include "TheGameOfLife2D.h"

//_______________________________________________________________________________________
TheGameOfLife2D::TheGameOfLife2D(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    ruleset[0] = a0;
    ruleset[1] = a1;
    ruleset[2] = a2;
    ruleset[3] = a3;
    ruleset[4] = a4;
    ruleset[5] = a5;
    ruleset[6] = a6;
    ruleset[7] = a7;

    std::srand(static_cast<unsigned int>(std::time(nullptr))); // use current time as seed for random generator

    std::cout << "____________________ The Game Of Life 2D (C++ test) ________________ " << std::endl;
    std::cout << "____________________ ______________________________ ________________ " << std::endl;
    std::cout << std::endl;
}

//_______________________________________________________________________________________
TheGameOfLife2D::~TheGameOfLife2D() {

}


int TheGameOfLife2D::Rules(int value, int sum) {
    if ((value == 1) && (sum <2) ) return ruleset[0]; // the cells dies
    else if ((value == 0) && (sum == 3)) return ruleset[1];  // cells is born
    else if ((value == 1) && (sum > 3)) return ruleset[2];  // the cells dies
    else { 
        return value; // remains unchanged 
    }
}


void TheGameOfLife2D::Initialize(bool isRandom = false) {
    if (isRandom) {
        for (int column = 0; column < width; column++) {
            for (int row = 0; row < width; row++) {
                cells2D[column][row] = 0;
                double random = std::rand();
                double random_value = random / RAND_MAX;
                if (random_value > 0.5) cells2D[column][row] = 1;
            }
        }
    }
    else {
        for (int column = 0; column < width; column++) {
            for (int row = 0; row < width; row++) {
                cells2D[column][row] = 0;
            }
        }
        for (int column = width / 4; column < width/2; column++) {
            for (int row = width / 4; row < width/2; row++) {
                cells2D[column][row] = 1;
            }
        }
    }
}

void TheGameOfLife2D::ComputeNextGen() {
    std::array< std::array<int, width>, width> nextgen2D;
    // keep the old infos
    old_cells2D = cells2D;

    for (int column = 1; column < width-1; column++) {
        for (int row = 1; row < width - 1; row++) {
            int top_left = cells2D[column - 1][row - 1];
            int top_me = cells2D[column][row-1];
            int top_right = cells2D[column + 1][row-1];

            int med_left = cells2D[column - 1][row];
            int med_me = cells2D[column][row];
            int med_right = cells2D[column + 1][row];

            int bottom_left = cells2D[column - 1][row + 1];
            int bottom_me = cells2D[column][row + 1];
            int bottom_right = cells2D[column + 1][row + 1];

            int sum = top_left + top_me + top_right + med_left + med_right + bottom_left + bottom_me + bottom_right; // without med_me content 
            nextgen2D[column][row] = Rules(med_me, sum);
        }
    }

    // Compute the next generation.
    cells2D = nextgen2D;
}

void TheGameOfLife2D::Run(const int iterations = 100) {
    for (int i = 0; i < iterations; i++) {
        Draw(i);
        ComputeNextGen();
    }
}

void TheGameOfLife2D::DrawStandard(int iteration) {
    for (int column = 0; column < width ; column++) {
        for (int row = 0; row < width ; row++) {
            if (cells2D[column][row] == 1) { 
                std::cout << "*"; 
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "\n ________ iteration: "<< iteration<<" ________ \n\n" << std::endl;
}

void TheGameOfLife2D::Draw(int iteration) {

    CreateImage(iteration, width, 255);
}

int TheGameOfLife2D::GetCellInfo(int col, int row) {
    int diff =  cells2D[col][row] - old_cells2D[col][row];
    return diff;
}

void TheGameOfLife2D::CreateImage(int iteration, int side, int colorBkg) {
    int factor = 4;
    cv::Mat Canvas(side* factor, side * factor, CV_8UC3);
    Canvas.setTo(colorBkg);

    float radiusCell = 1* factor;
    int c_blue = 0;
    int c_red = 0;
    int c_green = 0;

    for (int column = 0; column < width; column++) {
        for (int row = 0; row < width; row++) {
            int value_cell = cells2D[column][row];
            cv::Point topleftCellPoint(column * factor, row * factor);
            cv::Point bottomleftCellPoint(column * factor+ factor, row * factor+ factor);
            cellInfo = GetCellInfo(column, row);
            if ((cellInfo < 0) && (value_cell == 0)) c_red = 250;
            if ((cellInfo == 0) && (value_cell == 1)) c_blue = 250;
            if ((cellInfo > 0) && (value_cell == 1) ) c_green = 250;

            if( (c_red != 0) || (c_blue != 0) || (c_green != 0)) cv::rectangle(Canvas, topleftCellPoint, bottomleftCellPoint, cv::Scalar(c_blue, c_red, c_red), 2);
            c_blue = 0;
            c_red = 0;
            c_green = 0;
        }
    }
    std::string s = std::to_string(iteration);
    std::string name_img = "images/TheGameOfLife2D_" + s + ".png";
    cv::imwrite(name_img, Canvas);

}

