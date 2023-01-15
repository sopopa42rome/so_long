/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:50:08 by sopopa            #+#    #+#             */
/*   Updated: 2023/01/15 19:09:33 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_img_not_assigned(void)
{
	ft_putstr_fd("Error:\nThe mlx image was not assigned to data_struct!\n", 2);
	exit (IMG_NOT_ASSIGNED);
}

int	error_forbidden_char(void)
{
	ft_putstr_fd("Error:\nForbidden character inside the map!\n", 2);
	exit (FORBIDDEN_CHAR);
}
