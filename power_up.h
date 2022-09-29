#include "splashkit.h"
#include <vector>
using namespace std;

// the various power ups custom datatype
enum power_up_kind
{
    SHIELD,
    HEART,
    COIN,
    BATTERY,
    LEVEL,
    FUEL
};

struct power_up_data
{
    sprite power_up_sprite;
    power_up_kind powers;
};

power_up_data new_power_up(double x, double y);

void draw_power_up(const power_up_data &power_up_to_draw);

void update_power_up(power_up_data &power_up_to_update);
