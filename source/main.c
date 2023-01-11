/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2023/01/11 17:07:26 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include "so_long.h"


		


int	ft_close(t_game_vars *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	while(game->img)
	{
		mlx_destroy_image(game->mlx, game->img->collect);
		mlx_destroy_image(game->mlx, game->img->door_closed);
		mlx_destroy_image(game->mlx, game->img->grass);
		mlx_destroy_image(game->mlx, game->img->player);
		mlx_destroy_image(game->mlx, game->img->stone);
		mlx_destroy_image(game->mlx, game->img->tree);
	}
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
	game->mlx_win = mlx_new_window(game->mlx, BLOCK * game->width,
			BLOCK * game->height, "The pirate bomb!");
	ft_render_map(game, game->img);
	mlx_hook(game->mlx_win, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, ft_close, game);
	mlx_loop(game->mlx);
	//free(game->mlx);
	//free(game->mlx_win);
	//ft_free(game);
	return (0);
}
