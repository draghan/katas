
#include "external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Tests")
{
    SECTION("is_palindrome function")
    {
        REQUIRE(is_palindrome("aka"));
        REQUIRE(is_palindrome("a"));
        REQUIRE(is_palindrome("maam"));
        REQUIRE(!is_palindrome("maam."));
        REQUIRE(!is_palindrome("ma"));
    }

    SECTION("longest_palindrome")
    {
        REQUIRE(longest_palindrome("a") == 1);
        REQUIRE(longest_palindrome("aa") == 2);
        REQUIRE(longest_palindrome("baa") == 2);
        REQUIRE(longest_palindrome("aab") == 2);
        REQUIRE(longest_palindrome("zyabyz") != 6);
        REQUIRE(longest_palindrome("baabcd") == 4);
        REQUIRE(longest_palindrome("baablkj12345432133d") == 9);
    }
}

