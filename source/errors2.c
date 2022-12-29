/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:35:57 by sopopa            #+#    #+#             */
/*   Updated: 2022/12/29 15:36:50 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_incomplete_walls(void)
{
    ft_putstr_fd("Error:\nIncomplete map walls!\n", 2);
    exit(NO_WALLS);
}

void	error_collectible_inexistent(void)
{
    ft_putstr_fd("Error:\nThere must be at least one collectible!\n", 2);
    exit(NO_COLLECTIBLE);
}

void	error_exit_inexistent(void)
{
    ft_putstr_fd("Error:\nThe exit is inexistent!\n", 2);
    exit(NO_EXIT);
}

void    error_map_not_found(void)
{
    ft_putstr_fd("Error:\nFile not found!\n", 2);
    exit(FILE_NOT_FOUND);
}

void    error_program_null(void)
{
    ft_putstr_fd("Error:\nLack of parameters!\n", 2);
    exit(GAME_NULL);
}