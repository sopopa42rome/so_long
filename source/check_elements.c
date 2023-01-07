/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:34:20 by sopopa            #+#    #+#             */
/*   Updated: 2022/12/28 20:12:53 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     ft_check_player(game_vars *game)
{
    int r;
    int c;
    int player;

    player = 0;
    r = 0;
    while (r < game->height - 1)
    {
        c = 0;
        while(c < game->width - 1)
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
    
    exit = 0;
    r = 0;
    while (r < game->height - 1)
    {
        c = 0;
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
    if (exit >= 1)
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
    collect = 0;
    while (r < game->height - 1)
    {
        c = 0;
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
    if (collect > 0)
        return (1);
    else
        return (0);
}
