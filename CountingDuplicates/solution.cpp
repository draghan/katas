#include "solution.hpp"

size_t duplicateCount(const char *in)
{
    std::map<char, unsigned> counting_bucket;
    std::for_each(in, in + strlen(in), [&](const auto &letter)
    {
        const auto lowercase_letter = std::tolower(letter);
        counting_bucket.try_emplace(lowercase_letter, 0);
        counting_bucket[lowercase_letter]++;
    });
    const auto duplicates_count = std::count_if(counting_bucket.begin(),
                                                counting_bucket.end(),
                                                [&](const auto &letter_count)
                                                {
                                                    return letter_count.second > 1;
                                                });
    return duplicates_count;
}
