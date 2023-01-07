/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:17:37 by sorin             #+#    #+#             */
/*   Updated: 2023/01/06 20:58:28 by sopopa           ###   ########.fr       */
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
	if (fd < 0)
		error_map_not_found();
	rows = count_rows(fd);
	if (rows == 0)
		error_empty_map();
	game->map_matrix = malloc(sizeof(char *) * rows);
	close(fd);
	fd = open(pathfile, O_RDONLY);
	i = -1;
	while (++i < rows && game->map_matrix)
		game->map_matrix[i] = get_next_line(fd);
	close(fd);
	game->height = rows;
	if (game->map_matrix)
		game->width = ft_strlen(game->map_matrix[i - 1]);
	if (!game->map_matrix || !ft_check_errors(game))
		ft_free(&game);
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

int		ft_free(game_vars **game)
{	
	int	i;

	i = -1;
	if (!game || !(*game))
		return (0);
	while (++i < (*game)->height)
		free((*game)->map_matrix[i]);
	free((*game)->map_matrix);
	free(*game);
	*game = NULL;
	return (0);
}




