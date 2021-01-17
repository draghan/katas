
#include "../external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Tests")
{
    SECTION("\"foefet\", \"toffee\"")
    {
        REQUIRE(isAnagram("foefet", "toffee") == true);
    }
    SECTION("\"Buckethead\", \"DeathCubeK\"")
    {
        REQUIRE(isAnagram("Buckethead", "DeathCubeK") == true);
    }
    SECTION("\"Twoo\", \"WooT\"")
    {
        REQUIRE(isAnagram("Twoo", "WooT") == true);
    }
    SECTION("\"dumble\", \"bumble\"")
    {
        REQUIRE(isAnagram("dumble", "bumble") == false);
    }
    SECTION("\"around\", \"round\"")
    {
        REQUIRE(isAnagram("around", "round") == false);
    }
    SECTION("\"ound\", \"round\"")
    {
        REQUIRE(isAnagram("ound", "round") == false);
    }
    SECTION("\"apple\", \"pale\"")
    {
        REQUIRE(isAnagram("apple", "pale") == false);
    }
    SECTION("\"apple\", \"appeal\"")
    {
        REQUIRE(isAnagram("apple", "appeal") == false);
    }
    SECTION("\"apple\", \"appeal\"")
    {
        REQUIRE(isAnagram("apple", "appeal") == false);
    }
    SECTION("\"\", \"\"")
    {
        REQUIRE(isAnagram("", "") == true);
    }
}

