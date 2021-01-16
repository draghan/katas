#pragma once

#include <string>
#include <string_view>
#include <algorithm>

std::vector<std::string_view> split_string_by_delimiter(std::string_view string_to_split, char delimiter);
std::string spinWords(const std::string &str);