/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_elements_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:19:22 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/07 17:21:58 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_frame_right(game_vars *game, t_img *img, int rows, int col)
{
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->frame_right, w, h);
}

void	ft_draw_barrel(game_vars *game, t_img *img, int rows, int col)
{
	int w;
	int h;

	w = BLOCK * col;
	h = BLOCK * rows;
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->barrel, w, h);
}
