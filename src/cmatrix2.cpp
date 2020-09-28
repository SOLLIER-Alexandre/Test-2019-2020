#include <fstream>
#include <string>
#include <sstream>

#include "cmatrix2.h"

cmatrix2::cmatrix2(const std::string& filename)
{
    // Open the file
    std::ifstream in(filename);
    size_t y = 0;
    while (true)
    {
        // Get a line from the csv
        std::string line;
        std::getline(in, line);
        if (in.fail()) break;

        // Parse the line
        std::stringstream lineStream(line);
        size_t x = 0;
        while (true)
        {
            // Get a value from the line
            std::string val;
            std::getline(lineStream, val, ',');
            if (lineStream.fail()) break;

            // Try to parse it into an int
            int n = 0;
            try {
                n = std::stoi(val);
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
            }

            // Add to the list if != 0
            if (n != 0)
            {
                matrix.push_back({y, x, n});
            }

            ++x;
        }

        ++y;
    }

    // Remember matrix size
    _size = y;

//    std::cout << _size << std::endl;
//    for (std::shared_ptr<CNode<triplet>> pgp = matrix.getFictionalHead(); pgp->GetNextNode() != nullptr; pgp = pgp->GetNextNode())
//    {
//        std::cout << pgp->GetData().val << " at [" << pgp->GetData().colNum << ", " << pgp->GetData().lineNum << "]" << std::endl;
//    }
}

// Question 2.1
std::vector<int> cmatrix2::getVectorAtLine(const size_t& line) const
{
    // Instantiate return vector, filled with 0
    std::vector<int> ret(_size, 0);

    // Start looking for values in the specified line
    std::shared_ptr<CNode<triplet>> node = matrix.getFictionalHead()->GetNextNode();
    while (node != nullptr)
    {
        // If the actual node is on the specified line, update the vector accordingly
        if (node->GetData().lineNum == line)
            ret[node->GetData().colNum] = node->GetData().val;

        // Get the next node, exit if we got to the fictional tail or we passed the specified line
        node = node->GetNextNode();
        if (node == matrix.getFictionalTail() || node->GetData().lineNum > line) break;
    }

    return ret;
}

// Question 2.2
std::vector<int> cmatrix2::getVectorAtColumn(const size_t& column) const
{
    // Instantiate return vector, filled with 0
    std::vector<int> ret(_size, 0);

    // Start looking for values in the specified column
    std::shared_ptr<CNode<triplet>> node = matrix.getFictionalHead()->GetNextNode();
    while (node != nullptr)
    {
        // If the actual node is on the specified line, update the vector accordingly
        if (node->GetData().colNum == column)
            ret[node->GetData().lineNum] = node->GetData().val;

        // Get the next node, exit if we got to the fictional tail
        node = node->GetNextNode();
        if (node == matrix.getFictionalTail()) break;
    }

    return ret;
}

// Question 2.3
const int& cmatrix2::getValue(const size_t& line, const size_t& column) const
{
    // Start checking if the specified coordinates are leading to a stored value
    std::shared_ptr<CNode<triplet>> node = matrix.getFictionalHead()->GetNextNode();
    while (node != nullptr)
    {
        // If the actual node is on the specified line, update the vector accordingly
        if (node->GetData().colNum == column && node->GetData().lineNum == line) return node->GetData().val;

        // Get the next node, exit if we got to the fictional tail or we passed the specified line
        node = node->GetNextNode();
        if (node == matrix.getFictionalTail() || node->GetData().lineNum > line) break;
    }

    return 0;
}
