/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_elements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:05:06 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/07 15:25:20 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_walls(game_vars *game, t_img *img, int rows, int col)
{	
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->wall_front, w, h);
}

void	ft_draw_floor(game_vars *game, t_img *img, int rows, int col)
{	
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->floor, w, h);
}

void	ft_draw_frame_up(game_vars *game, t_img *img, int rows, int col)
{
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->frame_up , w, h);	
}

void	ft_draw_frame_down(game_vars *game, t_img *img, int rows, int col)
{
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->frame_down , w, h);
}

void	ft_draw_frame_left(game_vars *game, t_img *img, int rows, int col)
{
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->frame_left , w, h);
}