/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 07:51:30 by sorin             #+#    #+#             */
/*   Updated: 2022/12/11 17:37:00 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    error_file_extension_wrong(void)
{
    ft_putstr_fd("Error:\nFile extension wrong!", 1);
    exit(FILE_EXTENSION_WRONG);
}

void error_bad_arguments(void)
{
    ft_putstr_fd("Error:\nWrong number of arguments!", 1);
    exit(BAD_NUMBER_ARGS);
}
