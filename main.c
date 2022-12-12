/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 15:55:12 by sorin             #+#    #+#             */
/*   Updated: 2022/12/11 17:44:01 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (void)
{
	// if (argc )
	// 	return (error_bad_arguments());
	game_vars *game;
	game = initialize_game("./maps/map0.ber");
	return 0;

	
}