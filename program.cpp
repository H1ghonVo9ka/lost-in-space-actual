// game screencast: https://video.deakin.edu.au/media/t/1_2gtzg4fr
// code explanation screencast: https://video.deakin.edu.au/media/t/1_8o3fhtnu
#include "splashkit.h"
#include "lost_in_space.h"

/**
 * Load the game images, sounds, etc.
 */
void load_resources()
{
    load_resource_bundle("game_bundle", "lost_in_space.txt");
}
// game over screen
void game_over(game_data &game)
{
    clear_screen();
    load_bitmap("congrats", "congrats.png");
    draw_bitmap("congrats", 0, 0, option_part_bmp(0, 0, bitmap_width("background"), bitmap_height("background"), option_to_screen()));
    draw_text("GAME OVER!", COLOR_WHITE, "starcraft.ttf", 55, 520, 300, option_to_screen());
    draw_text("Your score is: " + to_string(game.player.score), COLOR_WHITE, "starcraft.ttf", 15, 550, 360, option_to_screen());
    draw_text("To Restart the Game, Press S.", COLOR_WHITE, "starcraft.ttf", 20, 530, 380, option_to_screen());
    refresh_screen(60);
}
// restarts the game
void restart(game_data &game)
{
    clear_screen();
    game = new_game();
    handle_input(game.player);
    update_game(game);
    draw_game(game);
}

int main()
{
    open_window("Lost In Space", 1200, 650);
    load_resources();
    game_data game_new;
    game_new = new_game();
    bool game_running = false;

    while (not quit_requested())
    {

        process_events();
        clear_screen();

        // game ends when player scores less than -1000, more than or equal to 1000 or when they run out of fuel
        if (game_new.player.fuel_pct <= 0.00 or game_new.player.score >= 1000 or game_new.player.score < -900)
        {
            game_running = false;
            game_over(game_new);
            if (key_typed(S_KEY))
            {
                restart(game_new); // this procedure restarts the game
                game_running = true;
            }
        }
        else
        {
            handle_input(game_new.player);
            update_game(game_new);
            draw_game(game_new);
        }

        refresh_screen(60);
    }

    return 0;
}
