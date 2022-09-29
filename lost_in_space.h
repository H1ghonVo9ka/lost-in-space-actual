#ifndef LOST_IN_SPACE
#define LOST_IN_SPACE

#include "splashkit.h"
#include "power_up.h"
#include "player.h"
#include "planet.h"
#include <vector>
using namespace std;
using std::vector;
// stores the contact with each planet by the player
struct obstacle_data
{
    int mercury_score;
    int venus_score;
    int earth_score;
    int mars_score;
    int jupiter_score;
    int saturn_score;
    int uranus_score;
    int neptune_score;
    int pluto_score;
    int debris_score;
};

// all the variables needed for game to run
struct game_data
{
    player_data player;
    vector<power_up_data> power_up;
    vector<planet_data> planets;
    obstacle_data obstacles;
};

/**
 *
 *
 * @param game
 * @param width
 * @param height
 * @param num_planets
 */
void setup_level(game_data &game, int width, int height, int num_planets);
game_data new_game();
void draw_hud(const vector<planet_data> &planets, const player_data &player);
void draw_game(game_data &game);

// int closest_planet_index(const player_data &player, const vector<planet_data> &planets);
void check_collisions(game_data &game);
void update_game(game_data &game);

#endif