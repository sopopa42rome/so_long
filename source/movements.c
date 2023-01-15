/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:24:11 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/15 20:33:44 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game_vars *game)
{
	if (keycode == KEY_ESC)
		ft_close(game);
	if ((keycode == KEY_DOWN || keycode == KEY_UP) && game->render)
		ft_movements_hook(game, keycode);
	if ((keycode == KEY_LEFT || keycode == KEY_RIGHT) && game->render)
		ft_movements_hook(game, keycode);
	return (0);
}

int	ft_movements_hook(t_game_vars *game, int keycode)
{
	if (!ft_denied_move(game, keycode))
		return (0);
	ft_allow_move(game);
	return (1);
}

int	ft_denied_move(t_game_vars *game, int direction)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (direction == KEY_UP)
		x = -1;
	if (direction == KEY_DOWN)
		x = 1;
	if (direction == KEY_LEFT)
		y = -1;
	if (direction == KEY_RIGHT)
		y = 1;
	if (game->map_matrix[game->pos_x + (x)][game->pos_y + (y)] == '1')
		return (0);
	if (game->map_matrix[game->pos_x + (x)][game->pos_y + (y)] == 'E')
		if (game->cristal > 0)
			return (0);
	game->map_matrix[game->pos_x][game->pos_y] = '0';
	game->pos_x += x;
	game->pos_y += y;
	return (1);
}

int	ft_allow_move(t_game_vars *game)
{
	if (game->map_matrix[game->pos_x][game->pos_y] == 'C')
		game->cristal--;
	if (game->map_matrix[game->pos_x][game->pos_y] == 'E')
		if (game->cristal == 0)
			ft_close(game);
	game->map_matrix[game->pos_x][game->pos_y] = 'P';
	if (game->render)
	{	
		game->moves++;
		ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(game->moves, 1);
		ft_putchar_fd('\n', 1);
		ft_render_map(game, game->img);
	}
	return (1);
}
