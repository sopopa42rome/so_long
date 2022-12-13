/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sorin <sorin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:47:12 by sorin             #+#    #+#             */
/*   Updated: 2022/12/12 20:36:49 by sorin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H



#include "./mlx_linux/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

# define FILE_EXTENSION_WRONG 3
# define BAD_NUMBER_ARGS 4
# define FILE_EMPTY 5
# define NOT_RECTANGULAR 6
# define NO_PLAYER 7
# define NO_COLLECTIBLE 8
# define NO_EXIT 9

typedef struct game{
    char	**map_matrix;
    int		height;
	int		width;
	int		x;
	int		y;
	char	*pathfile;
	void	*mlx;
	void	*mlx_win;
	char	**line;


}	game_vars;

game_vars	*initialize_game(char *pathfile);
int			read_and_init_map(char *pathfile, game_vars *game);

int		check_extension_file(char *pathfile);
int		count_rows(int fd);

// errors
void	error_file_extension_wrong(void);
void	error_bad_arguments(void);
void    error_empty_map(void);
void    error_irregular_map(void);
void    error_player_inexistent(void);
void    error_collectible_inexistent(void);
void    error_exit_inexistent(void);

#endif