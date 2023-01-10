/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopopa <sopopa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:47:12 by sorin             #+#    #+#             */
/*   Updated: 2023/01/10 21:32:04 by sopopa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

// Num error define
# define FILE_EXTENSION_WRONG 3
# define BAD_NUMBER_ARGS 4
# define FILE_EMPTY 5
# define NOT_RECTANGULAR 6
# define NO_PLAYER 7
# define NO_COLLECTIBLE 8
# define NO_EXIT 9
# define FILE_NOT_FOUND 10
# define NO_WALLS 11
# define GAME_NULL 12
# define IMG_NOT_ASSIGNED 13

// Generic values and paths
# define BLOCK 64
# define PLAYER "xpm/player2.xpm"
# define GRASS "xpm/erba_fiori.xpm"
# define TREE "xpm/albero2.xpm"
# define STONE "xpm/stone.xpm"
# define DOOR_CLOSED "xpm/door_closed.xpm"
# define COLLECT "xpm/collect.xpm"

//Movements macros
# define KEY_UP 15
# define KEY_DOWN 30
# define KEY_LEFT 45
# define KEY_RIGHT 60
# define KEY_ESC 53

typedef struct img
{	
	int		w;
	int		h;
	void	*player;
	void	*grass;
	void	*tree;
	void	*stone;
	void	*door_closed;
	void	*collect;
}	t_img;

typedef struct game
{
	char	**map_matrix;
	int		height;
	int		width;
	int		pos_player_x;
	int		pos_player_y;
	char	*pathfile;
	void	*mlx;
	void	*mlx_win;
	char	**line;
	t_img	*img;
}	t_game_vars;

//init and free
t_game_vars	*initialize_game(char *pathfile);
t_img		*initialize_images(t_img *img);
int			read_and_init_map(char *pathfile, t_game_vars *game);
int			count_rows(int fd);
int			ft_free(t_game_vars **game);
int			ft_close(t_game_vars *game);

//rendering
void		ft_render_map(t_game_vars *game, t_img *img);
void		get_image_pointer(t_game_vars *game, t_img *img);
void		ft_draw_elements(t_game_vars *game, char c, int rows, int col);
void		ft_draw_grass(t_game_vars *game, int rows, int col);
void		ft_draw_tree(t_game_vars *game, int rows, int col);
void		ft_draw_stone(t_game_vars *game, int rows, int col);
void		ft_draw_player(t_game_vars *game, int rows, int col);
void		ft_draw_door_closed(t_game_vars *game, int rows, int col);
void		ft_draw_collectible(t_game_vars *game, int rows, int col);

//movements and events
int			key_press(t_game_vars *game, int keycode);

//checks map structure
int			check_extension_file(char *pathfile);
int			ft_check_errors(t_game_vars *game);
int			ft_check_walls(t_game_vars *game);
int			ft_check_width(t_game_vars *game);
int			ft_check_player(t_game_vars *game);
int			ft_check_collectible(t_game_vars *game);
int			ft_check_exit(t_game_vars *game);

// errors
void		error_file_extension_wrong(void);
void		error_bad_arguments(void);
void		error_empty_map(void);
void		error_irregular_map(void);
void		error_player_inexistent(void);
void		error_collectible_inexistent(void);
void		error_exit_inexistent(void);
void		error_map_not_found(void);
void		error_incomplete_walls(void);
void		error_program_null(void);
void		error_img_not_assigned(void);

#endif