/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:30:36 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/15 20:34:25 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elements(t_game_vars *game, char c, int rows, int col)
{
	if (rows >= 0 && col >= 0 && col <= game->width - 1)
		ft_draw_grass(game, rows, col);
	if (c == '1' && (rows >= 0 && rows <= game->height - 1)
		&& (col == 0 || col == game->width -1))
		ft_draw_stone(game, rows, col);
	if (c == '1' && (rows == 0 || rows == game->height - 1)
		&& (col >= 0 && col <= game->width -1))
		ft_draw_stone(game, rows, col);
	if (c == '1' && rows > 0 && rows < game->height - 1
		&& col > 0 && col < game->width -1)
		ft_draw_tree(game, rows, col);
	if (c == 'P')
		ft_draw_player(game, rows, col);
	if (c == 'E')
	{	
		if (game->cristal == 0)
			ft_draw_door_open(game, rows, col);
		else if (game->cristal > 0)
			ft_draw_door_closed(game, rows, col);
	}
	if (c == 'C')
		ft_draw_collectible(game, rows, col);
}		

void	ft_render_map(t_game_vars *game, t_img *img)
{
	int		rows;
	int		col;

	rows = 0;
	if (game->render == 0)
	{
		get_image_pointer(game, img);
		game->render = 1;
	}
	while (rows <= game->height - 1)
	{	
		col = 0;
		while (col < game->width)
		{
			ft_draw_elements(game, game->map_matrix[rows][col], rows, col);
			col++;
		}
		rows++;
	}
}

void	get_image_pointer(t_game_vars *game, t_img *img)
{
	img->grass = mlx_xpm_file_to_image(game->mlx, GRASS, &img->w, &img->h);
	img->tree = mlx_xpm_file_to_image(game->mlx, TREE, &img->w, &img->h);
	img->stone = mlx_xpm_file_to_image(game->mlx, STONE, &img->w, &img->h);
	img->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &img->w, &img->h);
	img->door_closed = mlx_xpm_file_to_image(game->mlx, DOOR_CLOSED,
			&game->img->w, &img->h);
	img->door_opened = mlx_xpm_file_to_image(game->mlx, DOOR_OPENED,
			&game->img->w, &img->h);
	img->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &img->w, &img->h);
	if (!img->grass || !img->tree || !img->stone
		|| !img->player || !img->door_closed
		|| !img->collect || !img->door_opened)
		error_img_not_assigned();
}
