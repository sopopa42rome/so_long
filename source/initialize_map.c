/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:17:37 by sorin             #+#    #+#             */
/*   Updated: 2023/01/15 20:31:18 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_vars	*initialize_game(char *pathfile)
{
	t_game_vars	*game;

	if (check_extension_file(pathfile) != 1)
		error_file_extension_wrong();
	game = malloc(sizeof(t_game_vars));
	game->img = malloc(sizeof(t_img));
	game->render = 0;
	game->moves = 0;
	game->mlx = mlx_init();
	if (read_and_init_map(pathfile, game) != 1)
		game = NULL;
	return (game);
}

int	read_and_init_map(char *pathfile, t_game_vars *game)
{
	int	fd;
	int	i;
	int	rows;

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
	if (!game->map_matrix || !game->img || ft_check_errors(game) != 1)
		ft_free(game);
	return (1);
}

int	count_rows(int fd)
{
	int		i;
	char	*str;

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

int	ft_free(t_game_vars *game)
{	
	int	i;

	i = -1;
	if (!game || !game->map_matrix || !game->img)
		return (0);
	while (++i < game->height)
	{
		free(game->map_matrix[i]);
		game->map_matrix[i] = NULL;
	}
	free(game->map_matrix);
	free(game->img);
	free(game);
	return (0);
}

int	ft_close(t_game_vars *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_image(game->mlx, game->img->collect);
	mlx_destroy_image(game->mlx, game->img->door_closed);
	mlx_destroy_image(game->mlx, game->img->grass);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->stone);
	mlx_destroy_image(game->mlx, game->img->tree);
	exit(0);
}
