#ifndef CMATRIX3_H
#define CMATRIX3_H

#include <utility>
#include <string>
#include <vector>

#include "list.hpp"

typedef std::pair<size_t, int> pairColVal;

class cmatrix3
{

public:
    cmatrix3(const std::string& filename);

    // Question 3.1
    std::vector<int> getVectorAtLine(const size_t& line) const;

private:
    std::vector<CList<pairColVal>> matrix;

};

#endif // CMATRIX3_H
