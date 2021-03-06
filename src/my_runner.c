/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** The main file of the my_runner project
*/

#include "runner.h"

int init_game(game_t *game)
{
    game->mode.width = 1920;
    game->mode.height = 1080;
    game->mode.bitsPerPixel = 32;
    game->window = sfRenderWindow_create(game->mode, "The Adventure", sfResize | sfClose, NULL);
    game->music = sfMusic_createFromFile("assets/sounds/theme.ogg");
    game->sky = sfTexture_createFromFile(SKY_PATH, NULL);
    game->road = sfTexture_createFromFile(ROAD_PATH, NULL);
    game->houses = sfTexture_createFromFile(HOUSES_PATH, NULL);
    game->sky_sprite = sfSprite_create();
    game->road_sprite = sfSprite_create();
    game->road_sprite2 = sfSprite_create();
    game->houses_sprite = sfSprite_create();
    game->houses_sprite2 = sfSprite_create();
    if (!game->window || !game->sky || !game->sky_sprite || !game->music)
        return (84);
    set_background(game);
    sfMusic_play(game->music);
    sfMusic_setLoop(game->music, sfTrue);
    return (0);
}

int game(void)
{
    sfEvent event;
    game_t game;
    float road_posX = 0;
    float road_posX2 = 1920;
    float houses_posX = 0;
    float houses_posX2 = 1920;
    sfVector2f road_pos = {road_posX, 0};
    sfVector2f road_pos2 = {road_posX2, 0};
    sfVector2f houses_pos = {houses_posX, 0};
    sfVector2f houses_pos2 = {houses_posX2, 0};

    if (init_game(&game) == 84)
        return (84);
    while (sfRenderWindow_isOpen(game.window)) {
        while (sfRenderWindow_pollEvent(game.window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(game.window);
        }
        road_posX2 = road_posX2 - 0.2;
        road_posX = road_posX - 0.2;
        houses_posX2 = houses_posX2 - 0.05;
        houses_posX = houses_posX - 0.05;
        if (road_posX < -1920)
            road_posX = 1920;
        if (road_posX2 < -1920)
            road_posX2 = 1920;
        if (houses_posX < -1920)
            houses_posX = 1920;
        if (houses_posX2 < -1920)
            houses_posX2 = 1920;
        road_pos.x = road_posX;
        road_pos2.x = road_posX2;
        houses_pos.x = houses_posX;
        houses_pos2.x = houses_posX2;
        sfRenderWindow_clear(game.window, sfBlack);
        sfSprite_setPosition(game.road_sprite, road_pos);
        sfSprite_setPosition(game.road_sprite2, road_pos2);
        sfSprite_setPosition(game.houses_sprite, houses_pos);
        sfSprite_setPosition(game.houses_sprite2, houses_pos2);
        sfRenderWindow_drawSprite(game.window, game.sky_sprite, NULL);
        sfRenderWindow_drawSprite(game.window, game.road_sprite, NULL);
        sfRenderWindow_drawSprite(game.window, game.road_sprite2, NULL);
        sfRenderWindow_drawSprite(game.window, game.houses_sprite, NULL);
        sfRenderWindow_drawSprite(game.window, game.houses_sprite2, NULL);
        sfRenderWindow_display(game.window);
    }
    destroy_sprite(game);
    return (0);
}

int main(int argc, char *argv[])
{

    if (argc > 1) {
        if (my_strcmp(argv[1], "-h") == 0) {
            help();
        } else if (game() == 84) {
            return (84);
        }
    } else {
        print_error(1);
    }
    return (0);
}
