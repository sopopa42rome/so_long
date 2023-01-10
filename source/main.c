/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2023/01/10 18:23:44 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game_vars	*game;

	if (argc <= 1)
		error_bad_arguments();
	game = initialize_game(argv[1]);
	if (!game || !game->img || !game->map_matrix)
		error_program_null();
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, BLOCK * game->width,
			BLOCK * game->height, "Hello world!");
	ft_render_map(game, game->img);
	mlx_hook(game->mlx_win, 17, 0, ft_close, 0);
	mlx_loop(game->mlx);
	return (0);
}
