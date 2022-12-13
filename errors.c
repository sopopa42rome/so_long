/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 07:51:30 by sorin             #+#    #+#             */
/*   Updated: 2022/12/13 13:31:22 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	error_file_extension_wrong(void)
{
    ft_putstr_fd("Error:\nFile extension wrong!", 2);
    exit(FILE_EXTENSION_WRONG);
}

void	error_bad_arguments(void)
{
    ft_putstr_fd("Error:\nWrong number of arguments!", 2);
    exit(BAD_NUMBER_ARGS);
}

void	error_empty_map(void)
{
    ft_putstr_fd("Error:\nThe file is empty!\n", 2);
    exit(FILE_EMPTY);
}

void	error_irregular_map(void)
{
    ft_putstr_fd("Error:\nThe map is not rectangular!\n", 2);
    exit(NOT_RECTANGULAR);
}

void	error_player_inexistent(void)
{
    ft_putstr_fd("Error:\nThe player is inexistent!\n", 2);
    exit(NO_PLAYER);
}


ciao

void	error_collectible_inexistent(void)
{
    ft_putstr_fd("Error:\nThere must be at least one collectible!\n", 2);
    exit(NO_COLLECTIBLE);
}
void	error_exit_inexistent(void)
{
    ft_putstr_fd("Error:\nThe map is not rectangular!\n", 2);
    exit(NO_EXIT);
}
