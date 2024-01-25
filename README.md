In the 2D case, libraries from OpenCV are needed to run the game

See in main.cpp:

e.g. launch the 2D game with rule 01000000 for 100 iterations (or images):
    TheGameOfLife2D gof(0, 1, 0, 0, 0, 0, 0, 0);
    gof.Initialize(true);
    gof.Run(100);
