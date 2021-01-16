#pragma once

#include <array>
#include <algorithm>
#include <list>

struct score_template_t
{
    const std::vector<int> winning_pattern;
    const int score = 0;
};

int score(const std::vector<int> &dice);
int pull_out_winning_dice(std::list<int> *dice_pool, const score_template_t &winning_scheme);