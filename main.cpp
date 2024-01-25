// main function : The Game Of Life 

#include "TheGameOfLife1D.h"
#include "TheGameOfLife2D.h"

#include <chrono>
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    /*TheGameOfLife1D gof(0,1,0,1,1,0,1,0);
    gof.Initialize(false);
    gof.Run(100);*/

    TheGameOfLife2D gof(0, 1, 0, 0, 0, 0, 0, 0);
    gof.Initialize(true);
    gof.Run(500);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << "Time taken to process: "<< duration.count()/1000.0 << " ms" << std::endl;
    return 0;
}
