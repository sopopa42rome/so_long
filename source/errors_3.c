/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:50:08 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/09 20:07:54 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_img_not_assigned(void)
{
	ft_putstr_fd("Error:\nThe image was not processsed correctly!\n", 2);
	exit(IMG_NOT_ASSIGNED);
}