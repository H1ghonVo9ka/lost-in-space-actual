#ifndef LOST_IN_SPACE_PLANET
#define LOST_IN_SPACE_PLANET

#include "splashkit.h"
#include <vector>

using namespace std;

// different kinds of obstacles custom datatype
enum planet_kind
{
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER,
    SATURN,
    URANUS,
    NEPTUNE,
    PLUTO,
    DEBRIS,
    SMALL,
    SMALL1,
    SMALL2,
    SMALL3,
    SMALL4,
    SMALL5,
};

struct planet_data
{
    sprite planet_sprite;
    bool planet_visit;
    planet_kind kind;
};

/**
 *
 *
 * @param player_to_update
 */
bitmap planet_bitmap(planet_kind kind);

/**
 * a planet is generates in specified x and y values
 *
 * @param  xy
 * @returns
 */
planet_data new_planet(double x, double y);

/**
 *
 *
 * @param planet_to_draw
 */

void draw_planet(const planet_data &planet_to_draw);

/**
 *
 *
 * @param planet_to_update
 */
void update_planet(const planet_data &planet_to_update);

#endif