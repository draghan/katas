#include "solution.hpp"

bool is_palindrome(const string_view &word)
{
    auto forward_traveller = word.cbegin();
    auto backward_traveller = word.crbegin();
    for(; forward_traveller != word.cend(); ++forward_traveller, ++backward_traveller)
    {
        if(*backward_traveller != *forward_traveller)
        {
            return false;
        }
    }
    return true;
};

int longest_palindrome(const std::string &s)
{
    if(s.empty())
    {
        return 0;
    }

    for(auto current_length = s.size(); current_length > 0; --current_length)
    {
        for(auto starting_position = s.cbegin();
            starting_position != s.cend() - current_length + 1;
            ++starting_position)
        {
            string_view current_view(&*starting_position, current_length);
            if(is_palindrome(current_view))
            {
                return static_cast<int>(current_length);
            }
        }
    }

    throw std::domain_error{"Length of palindrome decremented to zero - it should never happen."};
}