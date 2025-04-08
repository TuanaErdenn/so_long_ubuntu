/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:14:41 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 20:09:04 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_values(t_game *g)
{
	g->map = NULL;
	g->line = 0;
	g->column = 0;
	g->move = 1;
	g->x = 0;
	g->y = 0;
	g->e = 0;
	g->c = 0;
	g->p = 0;
	g->player = NULL;
	g->coin = NULL;
	g->wall = NULL;
	g->door = NULL;
	g->soil = NULL;
	g->init = NULL;
	g->win = NULL;
	g->screen_h = 0;
	g->screen_w = 0;
}

void	setup_window(t_game *g)
{
	int	size;

	size = 64;
	g->init = mlx_init();
	if (!g->init)
		exit_with_error(g, "Failed to start graphics.\n");
	g->win = mlx_new_window(g->init, g->line * size, g->column * size,
			"so_long");
	if (!g->win)
		exit_with_error(g, "Failed to create window.\n");
	g->player = mlx_xpm_file_to_image(g->init, "images/player.xpm", &size,
			&size);
	g->wall = mlx_xpm_file_to_image(g->init, "images/wall.xpm", &size, &size);
	g->coin = mlx_xpm_file_to_image(g->init, "images/collectible.xpm", &size,
			&size);
	g->door = mlx_xpm_file_to_image(g->init, "images/exit.xpm", &size, &size);
	g->soil = mlx_xpm_file_to_image(g->init, "images/floor.xpm", &size, &size);
	if (!g->player || !g->wall || !g->coin || !g->door || !g->soil)
	{
		write(2, "Error\nFailed to load textures\n", 30);
		close_game(g);
	}
}

void	render_map(t_game g)
{
	int	i;
	int	j;

	i = 0;
	while (g.map[i])
	{
		j = 0;
		while (g.map[i][j])
		{
			if (g.map[i][j] == '1')
				mlx_put_image_to_window(g.init, g.win, g.wall, j * 64, i * 64);
			else if (g.map[i][j] == '0')
				mlx_put_image_to_window(g.init, g.win, g.soil, j * 64, i * 64);
			else if (g.map[i][j] == 'C')
				mlx_put_image_to_window(g.init, g.win, g.coin, j * 64, i * 64);
			else if (g.map[i][j] == 'E')
				mlx_put_image_to_window(g.init, g.win, g.door, j * 64, i * 64);
			else if (g.map[i][j] == 'P')
				mlx_put_image_to_window(g.init, g.win, g.player, j * 64, i
					* 64);
			j++;
		}
		i++;
	}
}
