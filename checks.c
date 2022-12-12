/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:31:21 by sorin             #+#    #+#             */
/*   Updated: 2022/12/11 17:54:25 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_extension_file(char *pathfile)
{
	char *str;

	str = ft_strchr(pathfile, '.');
	if (ft_strncmp(str, ".ber", 4) == 0 && ft_strlen(str) == 4)
		return (1);
	return (FILE_EXTENSION_WRONG);

}

// int main (void)
// {
// 	int a = check_extension_file("soaerr.ber");
// 	printf("%d", a);
// }
