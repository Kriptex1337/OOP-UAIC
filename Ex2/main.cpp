#include <iostream>
#include <math.h>
#define MATRIX_HEIGHT 15
#define MATRIX_WIDTH 15

int Matrix[MATRIX_HEIGHT][MATRIX_WIDTH];

void Circle(int* ptr, int cx, int cy, int ray)
{
    for (int i = 0; i < MATRIX_HEIGHT; i++)
        for (int j = 0; j < MATRIX_WIDTH; j++)
            if (ray == (int)sqrt((cx - i) * (cx - i) + (cy - j) * (cy - j)))
                *(ptr + (i * MATRIX_HEIGHT + j)) = 1;
}

void WriteResult()
{
    for (int i = 0; i < MATRIX_HEIGHT; i++)
    {
        for (int j = 0; j < MATRIX_WIDTH; j++)
            std::cout << Matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}

int main()
{
    Circle(&Matrix[0][0], 7, 7, 5);
    WriteResult();
    return 0;
}
