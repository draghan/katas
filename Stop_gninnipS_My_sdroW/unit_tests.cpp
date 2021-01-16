#include "external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"


TEST_CASE("helper functions")
{
    SECTION("split string 1-elem")
    {
        auto a = split_string_by_delimiter("abc", ' ');
        REQUIRE(a.size() == 1);
        REQUIRE(a[0] == "abc");
    }
    SECTION("split string 2-elem")
    {
        auto a = split_string_by_delimiter("abc def", ' ');
        REQUIRE(a.size() == 2);
        REQUIRE(a[0] == "abc");
        REQUIRE(a[1] == "def");
    }
    SECTION("split string 3-elem")
    {
        auto a = split_string_by_delimiter("abc def 123@#", ' ');
        REQUIRE(a.size() == 3);
        REQUIRE(a[0] == "abc");
        REQUIRE(a[1] == "def");
        REQUIRE(a[2] == "123@#");
    }
    SECTION("split string with trailing delims")
    {
        auto a = split_string_by_delimiter(" abc def ", ' ');
        REQUIRE(a.size() == 2);
        REQUIRE(a[0] == "abc");
        REQUIRE(a[1] == "def");
    }
    SECTION("split delimiter string")
    {
        auto a = split_string_by_delimiter(" ", ' ');
        REQUIRE(a.size() == 0);
    }
    SECTION("split empty string")
    {
        auto a = split_string_by_delimiter("", ' ');
        REQUIRE(a.size() == 0);
    }
}

TEST_CASE("Sample Tests")
{
    SECTION("Single word - Welcome")
    {
        REQUIRE(spinWords("Welcome") == "emocleW");
    }
    SECTION("Single word - to")
    {
        REQUIRE(spinWords("to") == "to");
    }
    SECTION("Single word - CodeWars")
    {
        REQUIRE(spinWords("CodeWars") == "sraWedoC");
    }
    SECTION("Multiple words - Hey fellow warriors")
    {
        REQUIRE(spinWords("Hey fellow warriors") == "Hey wollef sroirraw");
    }
    SECTION("Multiple words - Burgers are my favorite fruit")
    {
        REQUIRE(spinWords("Burgers are my favorite fruit") == "sregruB are my etirovaf tiurf");
    }
    SECTION("Multiple words - Pizza is the best vegetable")
    {
        REQUIRE(spinWords("Pizza is the best vegetable") == "azziP is the best elbategev");
    }
}

