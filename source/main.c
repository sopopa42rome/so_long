/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2023/01/02 21:04:10 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int argc, char **argv)
{
	game_vars *game;

	if (argc <= 1)
		error_bad_arguments();
	game = initialize_game(argv[1]);
	if (!game || !game->map_matrix)
		error_program_null();
	render_map();
	// game->mlx = mlx_init();
	// height = game->height * PIXEL_SIZE;
	// game->mlx_win = 

	return (0);
}
