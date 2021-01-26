#include "solution.hpp"

int Evaporator::evaporator(double content, double evap_per_day, double threshold)
{
    auto content_left = content;
    int days = 0;
    while (content_left * 100.0 / content > threshold)
    {
        double today_loss = evap_per_day * content_left / 100.0;
        content_left -= today_loss;
        ++days;
    }
    return days;
}
