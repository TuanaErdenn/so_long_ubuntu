/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:14:32 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 20:58:13 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_pos(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->x = j;
				g->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	print_moves(int move)
{
	ft_putnbr_fd(move, 1);
	write(1, "\n", 1);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = g->x + dx;
	new_y = g->y + dy;
	if (g->map[new_y][new_x] == '1')
		return ;
	if (g->map[new_y][new_x] == 'C')
		g->c--;
	if (g->map[new_y][new_x] == 'E')
	{
		handle_exit(g);
		return ;
	}
	print_moves(g->move);
	g->move++;
	g->map[g->y][g->x] = '0';
	g->map[new_y][new_x] = 'P';
	g->x = new_x;
	g->y = new_y;
	render_map(*g);
}

int	key_press(int key, t_game *g)
{
	if (key == ESC)
		close_game(g);
	else if (key == W || key == UP)
		move_player(g, 0, -1);
	else if (key == S || key == DOWN)
		move_player(g, 0, 1);
	else if (key == A || key == LEFT)
		move_player(g, -1, 0);
	else if (key == D || key == RIGHT)
		move_player(g, 1, 0);
	return (0);
}

int	close_game(t_game *g)
{
	if (g->player)
		mlx_destroy_image(g->init, g->player);
	if (g->wall)
		mlx_destroy_image(g->init, g->wall);
	if (g->coin)
		mlx_destroy_image(g->init, g->coin);
	if (g->door)
		mlx_destroy_image(g->init, g->door);
	if (g->soil)
		mlx_destroy_image(g->init, g->soil);
	if (g->win)
		mlx_destroy_window(g->init, g->win);
	if (g->init)
	{
		mlx_destroy_display(g->init);
		free(g->init);
	}
	free_map(g->map);
	exit(0);
	return (0);
}
