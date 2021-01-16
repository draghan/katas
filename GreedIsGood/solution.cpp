#include "solution.hpp"

int score(const std::vector<int> &dice)
{
    const std::array winning_score_templates = {
            score_template_t{{1, 1, 1}, 1000},
            score_template_t{{6, 6, 6}, 600},
            score_template_t{{5, 5, 5}, 500},
            score_template_t{{4, 4, 4}, 400},
            score_template_t{{3, 3, 3}, 300},
            score_template_t{{2, 2, 2}, 200},
            score_template_t{{1}, 100},
            score_template_t{{5}, 50},
    };
    std::list<int> dice_pool{dice.begin(), dice.end()};
    int current_score = 0;
    for (const auto &winning_score_template : winning_score_templates)
    {
        current_score += pull_out_winning_dice(&dice_pool, winning_score_template);
    }
    return current_score;
}

int pull_out_winning_dice(std::list<int> *dice_pool, const score_template_t &winning_scheme)
{
    if (dice_pool->empty() || winning_scheme.winning_pattern.empty())
    {
        return 0;
    }

    // how many winning schemes fits to the current dice pool:
    const auto max_total_passes = dice_pool->size() / winning_scheme.winning_pattern.size();

    int collected_score = 0;
    for (auto current_pass = 0u; current_pass < max_total_passes; ++current_pass)
    {
        // for purpose of this particular Kata, simple dice counter would fit,
        // but with storing values of found dices we could enhance the game with
        // non-homogeneous winning templates, e.g. { 5, 4, 3, 2, 1 }
        std::list<int> found_winning_dices;
        for (const auto &winning_dice : winning_scheme.winning_pattern)
        {
            auto found = std::find(dice_pool->begin(), dice_pool->end(), winning_dice);
            if (found != dice_pool->end())
            {
                // if found good dice, pull it out of the pool and put into "found" basket:
                found_winning_dices.splice(found_winning_dices.end(), *dice_pool, found, ++found);
            }
        }

        if (found_winning_dices.size() != winning_scheme.winning_pattern.size())
        {
            // if not found all dices from winning scheme, return dices to the pool:
            dice_pool->splice(dice_pool->end(), found_winning_dices);
        }
        else
        {
            collected_score += winning_scheme.score;
        }
    }
    return collected_score;
}

