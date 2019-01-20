/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2018
** File description:
** The game structures of the my_runner project
*/

#ifndef GAME_H
#define GAME_H

#define SKY_PATH "textures/backgrounds/sky.png"
#define ROAD_PATH "textures/backgrounds/road.png"
#define HOUSES_PATH "textures/backgrounds/houses.png"

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

typedef struct s_game {
    sfVideoMode mode;
    sfRenderWindow* window;
    sfMusic* music;
    sfTexture* sky;
    sfSprite* sky_sprite;
    sfTexture* road;
    sfSprite* road_sprite;
    sfSprite* road_sprite2;
    sfTexture* houses;
    sfSprite* houses_sprite;
    sfSprite* houses_sprite2;
} game_t;

typedef struct s_background {

} background_t;

#endif