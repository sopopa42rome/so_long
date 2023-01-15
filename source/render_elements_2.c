/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_elements_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:47:02 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/15 20:23:20 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_collectible(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img->collect, w + 5, h + 5);
}

void	ft_draw_door_open(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img->door_opened, w + 5, h + 5);
}
