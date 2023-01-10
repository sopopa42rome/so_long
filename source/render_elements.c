/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:19:22 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/10 18:23:44 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_grass(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->grass, w, h);
}

void	ft_draw_tree(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->tree, w, h);
}

void	ft_draw_stone(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img->stone, w, h);
}

void	ft_draw_player(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img->player, w + 4, h + 10);
}

void	ft_draw_door_closed(t_game_vars *game, int rows, int col)
{	
	int	w;
	int	h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->img->door_closed, w + 5, h + 5);
}
