#pragma once

#include <stdexcept>
#include <string>
#include <algorithm>

#if __cplusplus < 201703L
using string_view = std::string;
#else
using string_view = std::string_view;
#endif

int longest_palindrome(const std::string &s);
bool is_palindrome(const string_view &word);
