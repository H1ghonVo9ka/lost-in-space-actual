#include "power_up.h"
#include "splashkit.h"

// the bitmaps/sprite of each power-up
bitmap power_up_bitmap(power_up_kind powers)
{
    switch (powers)
    {
    case FUEL:
        return bitmap_named("fuel");
    case SHIELD:
        return bitmap_named("shield");
    case HEART:
        return bitmap_named("heart");
    case COIN:
        return bitmap_named("coin");
    case BATTERY:
        return bitmap_named("battery");
    case LEVEL:
    default:
        return bitmap_named("level");
    }
}
// positions the new power up sprite on the screen
power_up_data new_power_up(double x, double y)
{
    power_up_data result;
    // result.counter = 1;//if the counter less than 0, we del power up
    result.powers = static_cast<power_up_kind>(rnd(6));
    bitmap default_power_bitmap = power_up_bitmap(result.powers);
    result.power_up_sprite = create_sprite(default_power_bitmap);
    sprite_set_x(result.power_up_sprite, x);
    sprite_set_y(result.power_up_sprite, y);
    sprite_set_dx(result.power_up_sprite, rnd() * 4 - 2);
    sprite_set_dy(result.power_up_sprite, rnd() * 4 - 2);
    return result;
}

void draw_power_up(const power_up_data &power_up_to_draw)
{
    draw_sprite(power_up_to_draw.power_up_sprite);
}

void update_power_up(power_up_data &power_up_to_update)
{
    update_sprite(power_up_to_update.power_up_sprite);
}