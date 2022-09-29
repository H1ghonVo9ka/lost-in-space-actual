#include "splashkit.h"
#include "lost_in_space.h"

#include <vector>
using std::vector;
using namespace std;

void add_power_up(game_data &game)
{
    game.power_up.push_back(new_power_up(rnd(1500), rnd(1500)));
}

// Generates planets at random positions and player at the center
void generate_random(game_data &game, int width, int height, int num_planets)
{
    // Position in the centre of the initial screen using height and width
    sprite_set_x(game.player.player_sprite, (width - sprite_width(game.player.player_sprite)) / 2);
    sprite_set_y(game.player.player_sprite, (height - sprite_height(game.player.player_sprite)) / 2);

    for (int i = 0; i < num_planets; i++)
    {
        // generates random values of x and y coordinates for the planet
        game.planets.push_back(new_planet(rnd(3000), rnd(3000)));
    }
}
// contains features which initialises/erases the data from the game to start a brand new one
game_data new_game()
{
    game_data game;
    game.player = new_player();
    game.player.score = 0;
    generate_random(game, 3500, 3500, 20);

    // initialising planet scores
    obstacle_data planet_scores;
    planet_scores.mercury_score = 0;
    planet_scores.venus_score = 0;
    planet_scores.earth_score = 0;
    planet_scores.mars_score = 0;
    planet_scores.jupiter_score = 0;
    planet_scores.saturn_score = 0;
    planet_scores.uranus_score = 0;
    planet_scores.neptune_score = 0;
    planet_scores.pluto_score = 0;
    planet_scores.debris_score = 0;

    game.obstacles = planet_scores;

    return game;
}
// contains majority of the design aspects of the game
void draw_hud(vector<planet_data> &planets, const player_data &player)
{
    game_data game;
    float x = sprite_x(player.player_sprite);
    float y = sprite_y(player.player_sprite);

    load_bitmap("purple_bar", "purple_bar.png");
    load_bitmap("heart", "heart.png");
    load_bitmap("bar_white_fill", "bar_white_fill.png");
    load_bitmap("green_bar_lines", "green_bar_lines.png");
    load_bitmap("background", "background.png");
    draw_bitmap("background", 0, 0, option_to_screen());

    fill_rectangle(COLOR_PALE_TURQUOISE, 0, 550, 300, 150, option_to_screen());
    fill_rectangle(COLOR_DARK_BLUE, 5, 555, 290, 140, option_to_screen());
    // draw_text("Welcome to Lost in Space!", COLOR_WHITE, "starcraft.ttf", 40, 280, 250, option_to_screen());
    draw_text("Get 1000 Points to Pass the Level!", COLOR_WHITE, "starcraft.ttf", 10, 10, 560, option_to_screen());
    draw_text("The Game Ends:", COLOR_WHITE, "starcraft.ttf", 10, 10, 580, option_to_screen());
    draw_text("- When the Player gains 1000 points", COLOR_WHITE, "starcraft.ttf", 10, 15, 595, option_to_screen());
    draw_text("- Gets less than -900 points", COLOR_WHITE, "starcraft.ttf", 10, 15, 615, option_to_screen());
    draw_text("- When you run out of fuel!", COLOR_WHITE, "starcraft.ttf", 10, 15, 635, option_to_screen());

    draw_text("LOST IN SPACE", COLOR_WHITE, "starcraft.ttf", 50, 375, 10, option_to_screen());
    draw_text("LOCATION: " + to_string(x) + ", " + to_string(y), COLOR_WHITE, "starcraft.ttf", 15, 200, 100, option_to_screen());
    draw_text("BATTERY: ", COLOR_WHITE, "starcraft.ttf", 15, 200, 130, option_to_screen());
    draw_text("HEART: ", COLOR_WHITE, "starcraft.ttf", 15, 630, 70, option_to_screen());
    draw_text("FUEL: ", COLOR_WHITE, "starcraft.ttf", 15, 630, 100, option_to_screen());
    draw_text("SCORE: " + to_string(player.score), COLOR_WHITE, "starcraft.ttf", 15, 200, 70, option_to_screen());

    draw_bitmap("bar_white_fill", 320, 130, option_to_screen());
    draw_bitmap("purple_bar", 320, 130, option_part_bmp(0, 0, bitmap_width("purple_bar") * 0.85, bitmap_height("purple_bar"), option_to_screen()));

    draw_bitmap("heart", 700, 65, option_part_bmp(0, 0, bitmap_width("heart"), bitmap_height("heart"), option_to_screen()));
    draw_bitmap("heart", 730, 65, option_part_bmp(0, 0, bitmap_width("heart"), bitmap_height("heart"), option_to_screen()));
    draw_bitmap("heart", 760, 65, option_part_bmp(0, 0, bitmap_width("heart"), bitmap_height("heart"), option_to_screen()));
    draw_bitmap("bar_white_fill", 690, 100, option_to_screen());
    draw_bitmap("green_bar_lines", 690, 100, option_part_bmp(0, 0, bitmap_width("green_bar_lines") * player.fuel_pct, bitmap_height("green_bar_lines"), option_to_screen()));
}
// sidebar of the game which displays the data of contact between player and planets
void draw_sidebar(game_data &planets)
{
    load_bitmap("debris_icon", "small_debris.png");
    draw_bitmap("debris_icon", 980, 50, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.debris_score), COLOR_WHITE, "starcraft.ttf", 17, 1005, 75, option_to_screen());

    load_bitmap("neptune_icon", "neptune_icon.png");
    draw_bitmap("neptune_icon", 980, 150, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.neptune_score), COLOR_WHITE, "starcraft.ttf", 17, 1005, 185, option_to_screen());

    load_bitmap("jupiter_icon", "jupiter_icon.png");
    draw_bitmap("jupiter_icon", 980, 250, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.jupiter_score), COLOR_WHITE, "starcraft.ttf", 17, 1005, 285, option_to_screen());

    load_bitmap("venus_icon", "venus_icon.png");
    draw_bitmap("venus_icon", 980, 350, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.venus_score), COLOR_WHITE, "starcraft.ttf", 17, 1005, 385, option_to_screen());

    load_bitmap("mars_icon", "mars_icon.png");
    draw_bitmap("mars_icon", 980, 450, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.mars_score), COLOR_WHITE, "starcraft.ttf", 17, 1005, 485, option_to_screen());

    load_bitmap("earth_icon", "earth_icon.png");
    draw_bitmap("earth_icon", 1080, 50, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.earth_score), COLOR_WHITE, "starcraft.ttf", 17, 1115, 85, option_to_screen());

    load_bitmap("mercury_icon", "mercury_icon.png");
    draw_bitmap("mercury_icon", 1080, 150, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.mercury_score), COLOR_WHITE, "starcraft.ttf", 17, 1115, 185, option_to_screen());

    load_bitmap("saturn_icon", "saturn_icon.png");
    draw_bitmap("saturn_icon", 1080, 250, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.saturn_score), COLOR_WHITE, "starcraft.ttf", 17, 1115, 285, option_to_screen());

    load_bitmap("uranus_icon", "uranus_icon.png");
    draw_bitmap("uranus_icon", 1080, 350, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.uranus_score), COLOR_WHITE, "starcraft.ttf", 17, 1115, 385, option_to_screen());

    load_bitmap("pluto_icon", "pluto_icon.png");
    draw_bitmap("pluto_icon", 1080, 450, option_part_bmp(0, 0, bitmap_width("pegasi"), bitmap_height("fuel"), option_to_screen()));
    draw_text(to_string(planets.obstacles.pluto_score), COLOR_WHITE, "starcraft.ttf", 17, 1115, 485, option_to_screen());
}

// draws the main features when called in the main for the game
void draw_game(game_data &game)
{
    clear_screen();

    draw_hud(game.planets, game.player);
    draw_sidebar(game);
    draw_player(game.player);

    for (int i = 0; i < game.planets.size(); i++)
    {
        draw_planet(game.planets[i]);
    }
    for (int i = 0; i < game.power_up.size(); i++)
    {
        draw_power_up(game.power_up[i]);
    }
}

// powerups and obstacles are updated as the game keeps going
void update_game(game_data &game)
{
    update_player(game.player);
    game.player.fuel_pct = game.player.fuel_pct - 0.000278;
    if (rnd() < 0.05)
    {
        add_power_up(game);
    }
    for (int i = 0; i < game.power_up.size(); i++)
    {
        update_power_up(game.power_up[i]);
    }
    for (int i = 0; i < game.planets.size(); i++)
    {
        update_planet(game.planets[i]);
    }
    check_collisions(game);
}
// score of the player changes depending on the contact between the player and power ups
void apply_power_up(player_data &player, power_up_data &power_up)
{
    switch (power_up.powers)
    {
    case FUEL:
        if (player.fuel_pct < 0.75)
        {
            player.fuel_pct = player.fuel_pct + 0.25;
        }
    case SHIELD:
        player.score = player.score + 30;
        break;
    case HEART:
        player.score = player.score + 100;
        break;
    case COIN:
        player.score = player.score + 50;
        break;
    case BATTERY:
        player.score = player.score + 20;
        break;
    case LEVEL:
        player.score = player.score + 10;
        break;
    }
}
// deducts player score and records the number of planets the player has been in contact with
void apply_deduction(player_data &player, game_data &planets, int index)
{
    switch (planets.planets[index].kind)
    {
    case MERCURY:
        player.score = player.score - 130;
        planets.obstacles.mercury_score += 1;
        break;
    case VENUS:
        player.score = player.score - 70;
        planets.obstacles.venus_score += 1;
        break;
    case EARTH:
        player.score = player.score - 100;
        planets.obstacles.earth_score += 1;
        break;
    case MARS:
        player.score = player.score - 120;
        planets.obstacles.mars_score += 1;
        break;
    case JUPITER:
        player.score = player.score - 250;
        planets.obstacles.jupiter_score += 1;
        break;
    case SATURN:
        player.score = player.score - 150;
        planets.obstacles.saturn_score += 1;
        break;
    case URANUS:
        player.score = player.score - 450;
        planets.obstacles.uranus_score += 1;
        break;
    case NEPTUNE:
        player.score = player.score - 300;
        planets.obstacles.neptune_score += 1;
        break;
    case PLUTO:
        player.score = player.score - 1000;
        planets.obstacles.pluto_score += 1;
        break;
    case DEBRIS:
        player.score = player.score - 50;
        planets.obstacles.debris_score += 1;
        break;
    case SMALL:
        player.score = player.score - 10;
        planets.obstacles.debris_score += 1;
        break;
    case SMALL1:
        player.score = player.score - 10;
        planets.obstacles.debris_score += 1;
        break;
    case SMALL2:
        player.score = player.score - 10;
        planets.obstacles.debris_score += 1;
        break;
    case SMALL3:
        player.score = player.score - 10;
        planets.obstacles.debris_score += 1;
        break;
    case SMALL4:
        player.score = player.score - 10;
        planets.obstacles.debris_score += 1;
        break;
    case SMALL5:
        player.score = player.score - 10;
        planets.obstacles.debris_score += 1;
        break;
    }
}
// removes planets/debris from the game
void remove_obstacles(game_data &game, int index)
{
    if (index > 0 and index < game.planets.size())
    {
        int last_idx;
        last_idx = game.planets.size() - 1;
        game.planets[index] = game.planets[last_idx];
        game.planets.pop_back();
    }
}
// removes power ups from the game
void remove_power_up(game_data &game, int index)
{
    if (index > 0 and index < game.power_up.size())
    {
        int last_idx;
        last_idx = game.power_up.size() - 1;
        game.power_up[index] = game.power_up[last_idx];
        game.power_up.pop_back();
    }
}

// when player collides with either planet or power up, the above procedures will be applied and sound will be created
void check_collisions(game_data &game)
{
    for (int i = 0; i < game.power_up.size(); i++)
    {
        if (sprite_collision(game.player.player_sprite, game.power_up[i].power_up_sprite))
        {
            apply_power_up(game.player, game.power_up[i]);
            remove_power_up(game, i);
            load_sound_effect("Got_it", "Got_it.wav");
            play_sound_effect("Got_it");
        }
    }
    for (int i = 0; i < game.planets.size(); i++)
    {
        if (sprite_collision(game.player.player_sprite, game.planets[i].planet_sprite))
        {
            if (game.planets[i].planet_visit == false)
            {
                game.planets[i].planet_visit = true;
                apply_deduction(game.player, game, i);
                remove_obstacles(game, i);
                load_sound_effect("Explosion", "explosion.wav");
                play_sound_effect("Explosion");
            }
        }
    }
}
