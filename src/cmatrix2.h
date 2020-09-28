#ifndef CMATRIX2_H
#define CMATRIX2_H

#include <string>
#include <vector>

#include "list.hpp"

struct triplet {
    size_t lineNum;
    size_t colNum;
    int val;
};

class cmatrix2
{

public:
    cmatrix2(const std::string& filename);

    // Question 2.1
    std::vector<int> getVectorAtLine(const size_t& line);

private:
    CList<triplet> matrix;
    size_t _size;

};

#endif // CMATRIX2_H
