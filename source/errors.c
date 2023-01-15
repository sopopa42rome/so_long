/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 07:51:30 by sorin             #+#    #+#             */
/*   Updated: 2023/01/15 18:22:50 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_file_extension_wrong(void)
{
	ft_putstr_fd("Error:\nFile extension wrong!\n", 2);
	exit (FILE_EXTENSION_WRONG);
}

int	error_bad_arguments(void)
{
	ft_putstr_fd("Error:\nWrong number of arguments!\n", 2);
	exit (BAD_NUMBER_ARGS);
}

int	error_empty_map(void)
{
	ft_putstr_fd("Error:\nThe file is empty!\n", 2);
	exit (FILE_EMPTY);
}

int	error_irregular_map(void)
{
	ft_putstr_fd("Error:\nThe map is not rectangular!\n", 2);
	exit (NOT_RECTANGULAR);
}

int	error_player_inexistent(void)
{
	ft_putstr_fd("Error:\nToo much players or inexistent!\n", 2);
	exit (NO_PLAYER);
}
