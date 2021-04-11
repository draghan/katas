
#include "../external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Tests")
{
    SECTION("Basic_Tests")
    {
        REQUIRE(duplicate_encoder("din") == "(((");
        REQUIRE(duplicate_encoder("recede") == "()()()");
        REQUIRE(duplicate_encoder("Success") == ")())())");
        REQUIRE(duplicate_encoder("CodeWarrior") == "()(((())())");
        REQUIRE(duplicate_encoder("Supralapsarian") == ")()))()))))()(");
        REQUIRE(duplicate_encoder("(( @") == "))((");
        REQUIRE(duplicate_encoder(" ( ( )") == ")))))(");
    }
}

