/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:30:36 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/06 21:16:06 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elements(game_vars *game, t_img *img, char c, int rows, int col)
{
	if (c == '1' && rows == 0)
		ft_draw_walls(game, img, rows, col);
	if (rows > 0 && rows <= game->height)
		ft_draw_floor(game, img, rows, col);
	if (c == '1' && rows == 0 && col > 0 && col < game->width - 1)
	  	ft_draw_frame_up(game, img, rows, col);
	if (c == '1' && rows == game->height - 1 && col > 0 && col < game->width - 1)
		ft_draw_frame_down(game, img, rows, col);
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
			ft_draw_elements(game, img, game->map_matrix[rows][col], rows, col);
			col++;
		}
		rows++;
	}
}

void		get_image_pointer(game_vars *game, t_img *img)
{
	img->frame_up = mlx_xpm_file_to_image(game->mlx, FRAME_UP, &img->w, &img->h);
	img->floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &img->w, &img->h);
	img->wall_front = mlx_xpm_file_to_image(game->mlx, WALL_FRONT, &img->w, &img->h);
	img->frame_down = mlx_xpm_file_to_image(game->mlx, FRAME_DOWN, &img->w, &img->h);

}

t_img	*initialize_images(t_img *img)
{
	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	return (img);
		
}
