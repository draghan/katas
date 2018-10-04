
#include "external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Testing disemovel function")
{
    using namespace std;
    using test_strings_t = vector<string>;

    SECTION("Empty case")
    {
        REQUIRE(disemvowel("") == "");
    }

    SECTION("Vowels only")
    {
        const string string_empty;
        const test_strings_t test_strings
                {
                        "a",
                        "aeiou",
                        "AEIOU",
                        "aeiouAEIOU",
                };

        for(const auto &test_string : test_strings)
        {
            REQUIRE(disemvowel(test_string) == string_empty);
        }
    }

    SECTION("Consonants only")
    {
        const test_strings_t test_strings
                {
                        "b",
                        "qwrtypsdfghjklzxcvbnm",
                        "QWRTYPSDFGHJKLZXCVBNM"
                };

        for(const auto &test_string : test_strings)
        {
            REQUIRE(disemvowel(test_string) == test_string);
        }
    }

    SECTION("Non letters only")
    {
        const test_strings_t test_strings
                {
                        ".1234567890",
                        "!@#$%^&*()_+[]{};:,./<>?\\\'\"",
                        " \t\a\n\r"
                };

        for(const auto &test_string : test_strings)
        {
            REQUIRE(disemvowel(test_string) == test_string);
        }
    }

    SECTION("Mixed")
    {
        using test_strings_t = vector<pair<string, string>>;
        const test_strings_t test_strings
                {
                        {"Abba",         "bb"},
                        {"bad",          "bd"},
                        {"test strings", "tst strngs"}
                };

        for(const auto &pair : test_strings)
        {
            REQUIRE(disemvowel(pair.first) == pair.second);
        }
    }
}

