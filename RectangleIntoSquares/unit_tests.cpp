#include "external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

#include <random>

// Tester for automated tests:
// source: https://www.codewars.com/kata/55466989aeecab5aac00003e/solutions/cpp
std::vector<int> sqInRect3278(int lng, int wdth)
{
    if(lng == wdth)
    {
        return {};
    }
    std::vector<int> arr;
    while(lng > 0 && wdth > 0)
    {
        if(lng > wdth)
        {
            arr.push_back(wdth);
            lng -= wdth;
        }
        else
        {
            arr.push_back(lng);
            wdth -= lng;
        }
    }
    return arr;
}


TEST_CASE("Testing sqares")
{
    SECTION("Manual")
    {
        REQUIRE_THROWS(SqInRect::sqInRect(-5, 5));
        REQUIRE_THROWS(SqInRect::sqInRect(0, 0));
        REQUIRE(SqInRect::sqInRect(5, 5) == std::vector<int>{});
        REQUIRE(SqInRect::sqInRect(5, 3) == std::vector<int>{3, 2, 1, 1});
    }

    SECTION("Automated")
    {
        // source: https://www.codewars.com/kata/55466989aeecab5aac00003e/solutions/cpp
        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_int_distribution<int> uni1(10, 750000);

        for(int n = 0; n < 1000; ++n)
        {

            int a = uni1(rng);
            int b = uni1(rng);
            std::vector<int> sol = sqInRect3278(a, b);
            std::vector<int> ans;
            REQUIRE_NOTHROW(ans = SqInRect::sqInRect(a, b));
            REQUIRE(ans == sol);
        }
    }
}

