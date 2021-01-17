#include "solution.hpp"

bool isAnagram(std::string test, std::string original)
{
    if (test.size() != original.size())
    {
        return false;
    }
    to_lower_in_place(test);
    to_lower_in_place(original);
    return test.find_first_not_of(original) == std::string::npos;
}

void to_lower_in_place(std::string &s)
{
    std::transform(s.begin(), s.end(), s.begin(), [](auto &c)
    {
        return std::tolower(c);
    });
}