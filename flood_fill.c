/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:14:48 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 16:44:09 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game g)
{
	int		i;
	char	**copy;

	i = 0;
	copy = malloc(sizeof(char *) * (g.column + 1));
	if (!copy)
		exit_with_error(&g, "Memory allocation failed\n");
	while (i < g.column)
	{
		copy[i] = ft_strdup(g.map[i]);
		if (!copy[i])
			exit_with_error(&g, "Memory allocation failed\n");
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'X';
	fill(map, x + 1, y);
	fill(map, x - 1, y);
	fill(map, x, y + 1);
	fill(map, x, y - 1);
}

void	check_fill(t_game g, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				free_map(map);
				exit_with_error(&g, "Unreachable C or E\n");
			}
			j++;
		}
		i++;
	}
}

void	check_path(t_game g)
{
	char	**copy;

	if (g.x < 0 || g.y < 0)
		exit_with_error(&g, "Player position not found\n");
	copy = copy_map(g);
	fill(copy, g.x, g.y);
	check_fill(g, copy);
	free_map(copy);
}
