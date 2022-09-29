#include "splashkit.h"
#include "planet.h"
#include "player.h"

bitmap planet_bitmap(planet_kind kind)
{
    switch (kind)
    {
    case MERCURY:
        return bitmap_named("mercury");
    case VENUS:
        return bitmap_named("venus");
    case EARTH:
        return bitmap_named("earth");
    case MARS:
        return bitmap_named("mars");
    case JUPITER:
        return bitmap_named("jupiter");
    case SATURN:
        return bitmap_named("saturn");
    case URANUS:
        return bitmap_named("uranus");
    case NEPTUNE:
        return bitmap_named("neptune");
    case PLUTO:
        return bitmap_named("pluto");
    case DEBRIS:
        return bitmap_named("debris");
    case SMALL:
        return bitmap_named("small_debris");
    case SMALL1:
        return bitmap_named("small_debris");
    case SMALL2:
        return bitmap_named("small_debris");
    case SMALL3:
        return bitmap_named("small_debris");
    case SMALL4:
        return bitmap_named("small_debris");
    case SMALL5:
        return bitmap_named("small_debris");
    default:
        return bitmap_named("small_debris");
    }
}

/**
 * at the specified x and y coordinates, a new planet is created.
 *
 * @param  xy
 */
planet_data new_planet(double x, double y)
{
    planet_data result;
    result.kind = static_cast<planet_kind>(rnd(9));
    // create the planet with any random planet bitmap
    result.planet_sprite = create_sprite(planet_bitmap(result.kind));

    result.planet_visit = false;

    // Position the bitmap using parameters x and y
    sprite_set_x(result.planet_sprite, x);
    sprite_set_y(result.planet_sprite, y);

    // velocity of the planets
    sprite_set_dy(result.planet_sprite, rnd());
    sprite_set_dx(result.planet_sprite, rnd());

    return result;
}

void draw_planet(const planet_data &planet_to_draw)
{
    draw_sprite(planet_to_draw.planet_sprite);
}

void update_planet(const planet_data &planet_to_update)
{
    update_sprite(planet_to_update.planet_sprite);
}
