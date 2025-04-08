/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cntrl1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:14:56 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 16:43:30 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".ber", 4) != 0)
	{
		write(2, "Error\nInvalid file extension\n", 30);
		exit(1);
	}
	if (len == 4 || file[len - 5] == '/' || file[0] == '.')
	{
		write(2, "Error\nIgnore failed\n", 21);
		exit(1);
	}
}

t_game	check_empty(t_game g)
{
	if (!g.map[0])
		exit_with_error(&g, "Map is empty\n");
	return (g);
}

void	check_rectangle(t_game g)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(g.map[0]);
	while (g.map[i])
	{
		if ((int)ft_strlen(g.map[i]) != len)
			exit_with_error(&g, "Map is not rectangular\n");
		i++;
	}
}

void	check_walls(t_game g)
{
	int	i;
	int	j;

	i = 0;
	if (g.line < 3 || g.column < 3)
		exit_with_error(&g, "Map is too small\n");
	while (g.map[i])
	{
		j = 0;
		while (g.map[i][j])
		{
			if (i == 0 || i == g.column - 1 || j == 0 || j == g.line - 1)
			{
				if (g.map[i][j] != '1')
					exit_with_error(&g, "Map not surrounded by walls\n");
			}
			j++;
		}
		i++;
	}
}

t_game	check_letters(t_game g)
{
	int	i;
	int	j;

	i = 0;
	while (g.map[i])
	{
		j = 0;
		while (g.map[i][j])
		{
			if (g.map[i][j] == 'C')
				g.c++;
			else if (g.map[i][j] == 'E')
				g.e++;
			else if (g.map[i][j] == 'P')
				g.p++;
			else if (g.map[i][j] != '0' && g.map[i][j] != '1')
				exit_with_error(&g, "Invalid character in map\n");
			j++;
		}
		i++;
	}
	if (!(g.p == 1 && g.e == 1 && g.c >= 1))
		exit_with_error(&g, "Wrong count of P/E/C\n");
	return (g);
}
