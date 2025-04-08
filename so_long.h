/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:14:12 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 21:08:50 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define TILE_SIZE 64

typedef struct s_game
{
	void	*init;
	void	*win;
	char	**map;
	int		line;
	int		column;
	int		x;
	int		y;
	int		c;
	int		p;
	int		e;
	int		move;
	void	*player;
	void	*coin;
	void	*wall;
	void	*door;
	void	*soil;
	int		screen_w;
	int		screen_h;
}			t_game;

void		init_values(t_game *g);
void		check_extension(char *file);
void		setup_window(t_game *g);
void		render_map(t_game g);
void		set_player_pos(t_game *g);
int			key_press(int key, t_game *g);
int			close_game(t_game *g);
void		move_player(t_game *g, int dx, int dy);
t_game		load_map(t_game g, char **av);
t_game		control_all(t_game g);
void		exit_with_error(t_game *g, char *msg);
void		free_map(char **map);
void		check_path(t_game g);
void		handle_exit(t_game *g);
void		print_moves(int move);
void		check_extension(char *file);
t_game		check_empty(t_game g);
void		check_rectangle(t_game g);
void		check_walls(t_game g);
t_game		check_letters(t_game g);
void		exit_open_error(void);
t_game		control2(t_game *g);

#endif
