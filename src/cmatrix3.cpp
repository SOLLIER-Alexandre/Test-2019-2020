#include <fstream>
#include <string>
#include <sstream>

#include "cmatrix3.h"

cmatrix3::cmatrix3(const std::string& filename)
{
    // Open the file
    std::ifstream in(filename);
    while (true)
    {
        // Get a line from the csv
        std::string line;
        std::getline(in, line);
        if (in.fail()) break;

        // Parse the line
        std::stringstream lineStream(line);
        size_t x = 0;
        matrix.emplace_back();
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
                matrix.back().push_back(std::make_pair(x, n));
            }

            ++x;
        }
    }
}

// Question 3.1
std::vector<int> cmatrix3::getVectorAtLine(const size_t& line) const
{
    // Instantiate return vector, filled with 0
    std::vector<int> ret(matrix.size(), 0);

    // Start looking for values in the specified line
    std::shared_ptr<CNode<pairColVal>> node = matrix[line].getFictionalHead()->GetNextNode();
    while (node != nullptr)
    {
        // Actual node is != 0, set its value to the return vector
        ret[node->GetData().first] = node->GetData().second;

        // Get the next node, exit if we got to the fictional tail
        node = node->GetNextNode();
        if (node == matrix[line].getFictionalTail()) break;
    }

    return ret;
}

// Question 3.2
std::vector<int> cmatrix3::getVectorAtColumn(const size_t& column) const
{
    // Instantiate return vector, filled with 0
    std::vector<int> ret(matrix.size(), 0);

    // Start looking in every line
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        // Start looking for values in the actual line
        std::shared_ptr<CNode<pairColVal>> node = matrix[i].getFictionalHead()->GetNextNode();
        while (node != nullptr)
        {
            // Actual node is != 0, set its value to the return vector
            if (node->GetData().first == column)
                ret[i] = node->GetData().second;

            // Get the next node, exit if we got to the fictional tail
            node = node->GetNextNode();
            if (node == matrix[i].getFictionalTail()) break;
        }
    }

    return ret;
}
