/*
** EPITECH PROJECT, 2019
** PSU_tetris_2018
** File description:
** debug_mode
*/

#include "my_string.h"
#include "tetris.h"

void print_keys(struct game_props_s *game, int i)
{
    for (int j = 0; game->keys[i][j]; j++) {
        if (game->keys[i][j] == 27) {
            write(1, "^E", 2);
            continue;
        }
        my_printf("%s", &game->keys[i][j++]);
    }
}

void print_debug(struct game_props_s *game)
{
    my_puts("*** DEBUG MODE ***");
    for (int i = 0; i < 6; i++) {
        my_printf("%s : ", my_key_print[i]);
        if (my_strcmp(" ", game->keys[i]) == 0) {
            my_printf("(space)\n");
            continue;
        }
        print_keys(game, i);
        my_printf("\n");
    }
    my_printf("Next : %s\n", (game->next == false ? "No" : "Yes"));
    my_printf("Level : %d\n", game->level);
    my_printf("Size : %d*%d\n", game->size[0], game->size[1]);
    my_printf("Tetriminos : %d\n", game->nb_tetriminos);
}

void debug_mode(struct game_props_s *game)
{
    char buff[READ_SIZE];

    print_debug(game);
    my_printf("Press any key to start Tetris\n");
    my_set_term(0);
    for (int i = 0; i < READ_SIZE; i++)
        buff[i] = '\0';
    while (my_strlen(buff) <= 0)
        read(0, buff, READ_SIZE);
    my_set_term(1);
    return;
}