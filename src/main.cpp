#include <array>
#include <iostream>
#include <fstream>
#include <vector>

#include "cmatrix2.h"

using namespace std;

// Table 1. 10x10 matrix
const std::array<std::array<int, 10>, 10> example1 = {
    {
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
    }
};

// Simple function to save a matrix as a csv file
template <size_t lineCount, size_t colCount>
void saveMatrixAsCsv(const std::string& filename, const std::array<std::array<int, colCount>, lineCount>& matrix)
{
    std::ofstream out("ex1.csv");
    for (size_t y = 0; y < lineCount; ++y)
    {
        for (size_t x = 0; x < colCount - 1; ++x)
        {
            out << matrix[y][x] << ",";
        }
        out << matrix[y][colCount - 1] << std::endl;
    }
}

// Simple function to print the content of a vector
template <typename iter_t>
void printVector(iter_t beginIter, iter_t endIter)
{
    std::cout << '{';
    for (iter_t iter = beginIter; iter != endIter - 1; ++iter)
        std::cout << *iter << ", ";

    std::cout << *(endIter - 1) << '}' << std::endl;
}

int main()
{
    // Save the Table 1. matrix to a file
    saveMatrixAsCsv<10, 10>("ex1.csv", example1);

    // Exercise 2
    cmatrix2 cm2("ex1.csv");

    // Question 2.1
    std::vector<int> f = cm2.getVectorAtLine(5);
    printVector(f.begin(), f.end());

    return 0;
}