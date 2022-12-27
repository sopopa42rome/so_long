/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:34:20 by sopopa            #+#    #+#             */
/*   Updated: 2022/12/27 18:44:08 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     ft_check_player(game_vars *game)
{
    int r;
    int c;
    int player;

    r = 0;
    c = 0;
    player = 0;
    while (r < game->height)
    {
        while(c <= game->width)
        {
            if (game->map_matrix[r][c] == 'P')
            {
                player++;
                game->x = r;
                game->y = c;
            }
            c++;
        }
        r++;
    }
    if (player == 1)
        return (1);
    else
        return (0);
}

int     ft_check_exit(game_vars *game)
{
    int r;
    int c;
    int exit;

    r = 0;
    c = 0;
    exit = 0;
    while (r < game->height)
    {
        while(c <= game->width)
        {
            if (game->map_matrix[r][c] == 'C')
            {
                exit++; 
            }
            c++;
        }
        r++;
    }
    if (exit = 1)
        return (1);
    else
        return (0);
}

int     ft_check_collectible(game_vars *game)
{
    int r;
    int c;
    int collect;

    r = 0;
    c = 0;
    collect = 0;
    while (r < game->height)
    {
        while(c <= game->width)
        {
            if (game->map_matrix[r][c] == 'C')
            {
                collect++; 
            }
            c++;
        }
        r++;
    }
    if (collect => 1)
        return (1);
    else
        return (0);
}
