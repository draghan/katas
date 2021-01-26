
#include "../external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Tests")
{
    SECTION("10 10 10")
    {
        REQUIRE(Evaporator::evaporator(10, 10, 10) == 22);
    }
    SECTION("10 10 5")
    {
        REQUIRE(Evaporator::evaporator(10, 10, 5) == 29);
    }
}

