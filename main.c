/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2022/12/12 19:11:14 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char **argv)
{
	game_vars *game;

	

	if (argc != 2)
		error_bad_arguments();
	game = initialize_game(argv[1]);

	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 800, 600, "Chopper's Adventure");
	(void)(game->mlx_win);
	return (0);
}