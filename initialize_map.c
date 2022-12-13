/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:17:37 by sorin             #+#    #+#             */
/*   Updated: 2022/12/12 20:42:34 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

game_vars	*initialize_game(char *pathfile)
{   
    game_vars *game;

    if (check_extension_file(pathfile) != 1)
		error_file_extension_wrong();
    game = malloc(sizeof(game_vars));
	if (read_and_init_map(pathfile, game) != 1)
		game = NULL;
	return (game);
}

int read_and_init_map(char *pathfile, game_vars *game)
{
	int fd;
	int i;
	int rows;
	
	fd = open(pathfile, O_RDONLY);
	rows = count_rows(fd);
	if (rows == 0)
		error_empty_map()
	game->map_matrix malloc(sizeof(char *) * rows);
		
	
	
	return (1);
}

int	count_rows(int fd)
{
	int i;
	char *str;
	
	i = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{	
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (i);
}





