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


void render_map(void)
{
	void	*mlx;
	void	*mlx_win;
	void    *img;
    int     w;
    int     h;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello world!");
    img = mlx_xpm_file_to_image(mlx, "../xpm/pavimento.xpm", &w, &h);
    mlx_put_image_to_window(mlx, mlx_win, img, 32, 32);
    mlx_destroy_image(mlx, img);
    mlx_loop(mlx);

}