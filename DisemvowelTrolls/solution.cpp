#include "solution.hpp"

std::string disemvowel(std::string str)
{
    // If the blacklist set of letters will be
    // bigger, we could explicit specify only small
    // letters in a - for example - deque container
    // (its iterators won't be invalidated after
    // adding elements):

    // std::deque vowels{'a', 'e', 'i', 'o', 'u'};

    // and then just call:

    // std::transform(vowels.begin(), vowels.end(), std::back_inserter(vowels),
    //               [](const auto &c)
    //               {
    //                   return std::toupper(c);
    //               });

    // ...but it won't be constexpr :<

    constexpr char vowels[]{'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U'};

    std::string neutralized_sentence;
    std::copy_if(str.begin(), str.end(), std::back_inserter(neutralized_sentence), [&vowels](const auto &c)
    {
        return std::find(std::cbegin(vowels), std::cend(vowels), c) == std::cend(vowels);
    });

    return neutralized_sentence;
}

