/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:30:36 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/09 21:30:49 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elements(game_vars *game, char c, int rows, int col)
{
	if ( c && rows >= 0 && col >= 0 && col <= game->width -1)
	 	ft_draw_grass(game, rows, col);
	// if (c == '1' && (rows >= 0 && rows <= game->height - 1) && (col == 0 || col == game->width -1 ))
	// 	ft_draw_stone(game, rows, col);
	// if (c == '1' && (rows == 0 || rows == game->height - 1) && (col >= 0 && col <= game->width -1 ))
	// 	ft_draw_stone(game, rows, col);
	// if (c == '1' && rows > 0 && rows < game->height - 1 && col > 0 && col < game->width -1)
	// 	ft_draw_tree(game, rows, col);
	// if (c == 'P')
	// 	ft_draw_player(game, rows, col);
	// if (c == 'E')
	// 	ft_draw_door_closed(game, rows, col);
	// if (c == 'C')
	// 	ft_draw_collectible(game, rows, col);
}		

void    ft_render_map(game_vars *game, t_img *img)
{   
    int		rows;
    int		col;

    rows = 0;
	get_image_pointer(game, img);
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

void	get_image_pointer(game_vars *game, t_img *img)
{
	img->grass = mlx_xpm_file_to_image(game->mlx, GRASS, &img->w, &img->h);
	img->tree = mlx_xpm_file_to_image(game->mlx, TREE, &img->w, &img->h);
	img->stone = mlx_xpm_file_to_image(game->mlx, STONE, &img->w, &img->h);
	img->player = mlx_xpm_file_to_image(game->mlx, PLAYER, &img->w, &img->h);
	img->door_closed = mlx_xpm_file_to_image(game->mlx, DOOR_CLOSED, &img->w, &img->h);
	img->collect = mlx_xpm_file_to_image(game->mlx, COLLECT, &img->w, &img->h);
	// if (!game->img->grass || !game->img->tree || !game->img->stone || 
	// 	!game->img->player || !game->img->door_closed || !game->img->collect)
	// 	error_img_not_assigned();
}

t_img	*initialize_images(game_vars *game)
{
	game->img = malloc(sizeof(game->img));
	if (!game->img)
		error_program_null();
	return (game->img);
		
}
