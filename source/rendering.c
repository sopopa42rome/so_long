/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:30:36 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/02 21:06:32 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elements(game_vars *game, int rows, int col)
{	
	int w;
	int h;

	w = 32 * col;
	h = 32 * rows;
	game->img = mlx_xpm_file_to_image(game->mlx, "xpm/pavimento.xpm", &w, &h);
	mlx_hook(game->mlx_win,17,0,ft_close,0);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, w, h);
	mlx_destroy_image(game->mlx, game->img);
    mlx_loop(game->mlx);
}

void    ft_render_map(game_vars *game)
{   
    int		rows;
    int		col;

    rows = 0;
	mlx_clear_window(game->mlx, game->mlx_win);
    while (game->map_matrix[rows])
	{	
		col = 0;
		while (game->map_matrix[rows][col])
		{
			ft_draw_elements(game, rows, col);
			col++;
		}
		rows++;
	}
}

int ft_close(void)
{
    exit(0);
}














// void render_map(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	void    *img;
//     int     w;
//     int     h;
//     char *path = "xpm/pavimento.xpm";

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
//     img = mlx_xpm_file_to_image(mlx, path, &w, &h);
//     mlx_hook(mlx_win,17,0,ft_close,0);
//     mlx_put_image_to_window(mlx, mlx_win, img, 32, 32);
//     //mlx_destroy_image(mlx, img);
//     mlx_loop(mlx);

// }