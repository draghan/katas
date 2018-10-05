#include "solution.hpp"

std::vector<int> SqInRect::sqInRect(int length, int width)
{
    if(length <= 0 || width <= 0)
    {
        throw std::invalid_argument("Dimension cannot be zero or negative!");
    }

    std::vector<int> squares;

    // not doing early exit because of NRVO -
    // when is single return path, it's easier for compiler to do elision
    if(length != width)
    {
        while(length > 0 && width > 0)
        {
            auto shorter = std::min(length, width);
            auto longer = std::max(length, width);
            length = shorter;
            width = longer - shorter;
            squares.push_back(shorter);
        }
    }
    return squares;
}
