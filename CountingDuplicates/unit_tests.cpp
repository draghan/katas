
#include "../external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Tests")
{
    SECTION("[space]")
    {
        REQUIRE(duplicateCount(" ") == 0);
    }
    SECTION("[empty]")
    {
        REQUIRE(duplicateCount("") == 0);
    }
    SECTION("aabbcde")
    {
        REQUIRE(duplicateCount("aabbcde") == 2);
    }
    SECTION("aabBcde")
    {
        REQUIRE(duplicateCount("aabBcde") == 2);
    }
    SECTION("Indivisibility")
    {
        REQUIRE(duplicateCount("Indivisibility") == 1);
    }
    SECTION("Indivisibilities")
    {
        REQUIRE(duplicateCount("Indivisibilities") == 2);
    }
    SECTION("ABBA")
    {
        REQUIRE(duplicateCount("ABBA") == 2);
    }
}

