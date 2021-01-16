
#include "../external/catch/single_include/catch2/catch.hpp"
#include "solution.hpp"

TEST_CASE("Tests")
{
    SECTION("{2, 3, 4, 6, 2}")
    {
        REQUIRE(score({2, 3, 4, 6, 2}) == 0);
    }

    SECTION("{2, 4, 4, 5, 4}")
    {
        REQUIRE(score({2, 4, 4, 5, 4}) == 450);
    }

    SECTION("{5, 1, 3, 4, 1}")
    {
        REQUIRE(score({5, 1, 3, 4, 1}) == 250);
    }

    SECTION("{1, 1, 1, 3, 1}")
    {
        REQUIRE(score({1, 1, 1, 3, 1}) == 1100);
    }

    SECTION("{2, 4, 4, 5, 4}")
    {
        REQUIRE(score({2, 4, 4, 5, 4}) == 450);
    }
}

TEST_CASE("pull_out_winning_dice")
{
    SECTION("single 1 positive")
    {
        auto dice_pool = std::list<int>{1, 2, 3, 4};
        auto winning_scheme = score_template_t{{1}, 100};
        auto score = pull_out_winning_dice(&dice_pool, winning_scheme);

        REQUIRE(dice_pool == std::list<int>{2, 3, 4});
        REQUIRE(score == 100);
    }

    SECTION("single 1 repeated positive")
    {
        auto dice_pool = std::list<int>{1, 1, 1, 1};
        auto winning_scheme = score_template_t{{1}, 100};
        auto score = pull_out_winning_dice(&dice_pool, winning_scheme);

        REQUIRE(dice_pool.empty());
        REQUIRE(score == 100 * 4);
    }

    SECTION("single 1 negative")
    {
        auto dice_pool = std::list<int>{5, 5, 5, 5};
        auto winning_scheme = score_template_t{{1}, 100};
        auto score = pull_out_winning_dice(&dice_pool, winning_scheme);

        REQUIRE(dice_pool == std::list<int>{5, 5, 5, 5});
        REQUIRE(score == 0);
    }

    SECTION("empty pool")
    {
        auto dice_pool = std::list<int>();
        auto winning_scheme = score_template_t{{1}, 100};
        auto score = -500;
        REQUIRE_NOTHROW(score = pull_out_winning_dice(&dice_pool, winning_scheme));
        REQUIRE(dice_pool.empty());
        REQUIRE(score == 0);
    }

    SECTION("empty template")
    {
        auto dice_pool = std::list<int>{1, 2, 3, 4};
        auto winning_scheme = score_template_t{};
        auto score = -500;
        REQUIRE_NOTHROW(score = pull_out_winning_dice(&dice_pool, winning_scheme));
        REQUIRE(dice_pool == std::list<int>{1, 2, 3, 4});
        REQUIRE(score == 0);
    }

    SECTION("multiple 1 positive")
    {
        auto dice_pool = std::list<int>{1, 1, 1, 2};
        auto winning_scheme = score_template_t{{1, 1, 1}, 1000};
        auto score = pull_out_winning_dice(&dice_pool, winning_scheme);

        REQUIRE(dice_pool == std::list<int>{2});
        REQUIRE(score == 1000);
    }
}