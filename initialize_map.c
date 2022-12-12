/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:17:37 by sorin             #+#    #+#             */
/*   Updated: 2022/12/11 17:27:20 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

game_vars	*initialize_game(char *pathfile)
{   
    game_vars *game;

    if (check_extension_file(pathfile) == 1)
        game = malloc(sizeof(game_vars));
    if (read_and_init_map(pathfile, game) == 1)
    return (game);   
}

int read_and_init_map(char *pathfile, game_vars *game)
{
	int fd;
	int i;
	
	i = -1;
	fd = open(pathfile, O_RDONLY);
	while (get_next_line(fd) != NULL)
	{
		game->line[i++] = get_next_line(fd);
		printf("%s%s%s%s%s", game->line[0], game->line[1], game->line[2], game->line[3], game->line[5]);
	}
	return (1);
}




