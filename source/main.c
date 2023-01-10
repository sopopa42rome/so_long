/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2023/01/10 21:39:43 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_game_vars *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game_vars	*game;

	if (argc > 2)
		error_bad_arguments();
	game = initialize_game(argv[1]);
	if (!game || !game->img || !game->map_matrix)
		error_program_null();
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, BLOCK * game->width,
			BLOCK * game->height, "Hello world!");
	ft_render_map(game, game->img);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, 0);
	mlx_hook(game->mlx_win, 17, 0, ft_close, 0);
	mlx_loop(game->mlx);
	return (0);
}
