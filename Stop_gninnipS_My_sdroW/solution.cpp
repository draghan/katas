#include "solution.hpp"

std::string spinWords(const std::string &str)
{
    const auto words = split_string_by_delimiter(str, ' ');
    std::string result;
    for (auto i = 0u; i < words.size(); ++i)
    {
        if (words[i].size() < 5)
        {
            result += words[i];
        }
        else
        {
            std::copy(words[i].crbegin(), words[i].crend(), std::back_inserter(result));
        }

        if (i < words.size() - 1)
        {
            result += " ";
        }
    }
    return result;
}// spinWords

std::vector<std::string_view> split_string_by_delimiter(std::string_view string_to_split, char delimiter)
{
    std::vector<std::string_view> slices;
    auto found_delimiter_position = string_to_split.find(delimiter);

    size_t starting_position = 0;
    while (found_delimiter_position != std::string::npos)
    {
        auto current_slice = std::string_view(string_to_split.cbegin() + starting_position,
                                              found_delimiter_position - starting_position);
        if (current_slice.size() != 0)
        {
            slices.emplace_back(current_slice);
        }
        starting_position = found_delimiter_position + 1;
        found_delimiter_position = string_to_split.find(delimiter, starting_position);
    }
    if (starting_position < string_to_split.size())
    {
        slices.emplace_back(std::string_view(string_to_split.cbegin() + starting_position,
                                             string_to_split.size() - starting_position));
    }
    return slices;
}