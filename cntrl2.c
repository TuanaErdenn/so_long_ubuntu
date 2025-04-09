/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:20:21 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 21:31:50 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_size(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	g->column = i;
	g->line = ft_strlen(g->map[0]);
}

void	get_max_screen_size(void *mlx, int *width, int *height)
{
	if (!mlx || !width || !height)
		return ;
	mlx_get_screen_size(mlx, width, height);
}

void	maxmapcontrol(t_game *g)
{
	int	map_width;
	int	map_height;

	map_width = g->line * TILE_SIZE;
	map_height = g->column * TILE_SIZE;
	if (map_width > g->screen_w || map_height > g->screen_h)
	{
		write(1, "Error.\nThe map is too big for the screen.\n", 43);
		close_game(g);
	}
}

t_game	control_all(t_game g)
{
	g = check_empty(g);
	map_size(&g);
	check_rectangle(g);
	check_walls(g);
	g = check_letters(g);
	check_path(g);
	return (g);
}

t_game	control2(t_game *g)
{
	if (g->init)
	{
		mlx_get_screen_size(g->init, &g->screen_w, &g->screen_h);
	}
	if (g->screen_w > 0 && g->screen_h > 0)
		maxmapcontrol(g);
	return (*g);
}
