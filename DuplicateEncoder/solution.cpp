#include "solution.hpp"

std::string duplicate_encoder(const std::string &word)
{
    const auto lower_word = to_lower(word);
    std::string result;
    std::for_each(lower_word.cbegin(), lower_word.cend(), [&lower_word, &result](const auto &character)
    {
        const auto how_many = std::count_if(lower_word.cbegin(), lower_word.cend(), [&character](const auto &c)
        {
            return c == character;
        });
        result += (how_many > 1) ? ")" : "(";
    });
    return result;
}

std::string to_lower(const std::string &input)
{
    std::string output;
    std::for_each(input.cbegin(), input.cend(), [&output](const auto &character)
    {
        output += std::tolower(character);
    });
    return output;
}
