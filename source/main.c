/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2023/01/15 16:28:35 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include "so_long.h"


		




int	main(int argc, char **argv)
{
	t_game_vars	*game;

	if (argc > 2)
		error_bad_arguments();
	game = initialize_game(argv[1]);
	//printf("game %lu\n", sizeof(game));
	//printf("struct %lu", sizeof(t_game_vars));
	if (!game || !game->img || !game->map_matrix)
	 	error_program_null();
	game->mlx_win = mlx_new_window(game->mlx, BLOCK * game->width,
			BLOCK * game->height, "The pirate bomb!");
	ft_render_map(game, game->img);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, ft_close, game);
	mlx_loop(game->mlx);
	ft_free(game);
	return (0);
}
