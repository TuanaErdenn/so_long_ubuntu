/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:14:22 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 14:52:30 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_newlines(char *map_text)
{
	int	i;

	i = 0;
	while (map_text[i] && map_text[i + 1])
	{
		if (map_text[i] == '\n' && map_text[i + 1] == '\n')
		{
			write(2, "Error\nConsecutive empty lines in map\n", 37);
			free(map_text);
			exit(1);
		}
		i++;
	}
	if (map_text[0] == '\n' || map_text[i] == '\n' || i == 0)
	{
		write(2, "Error\nMap starts or ends with newline\n", 39);
		free(map_text);
		exit(1);
	}
}

void	exit_open_error(void)
{
	write(2, "Error\nFile not found\n", 22);
	exit(1);
}

t_game	load_map(t_game g, char **av)
{
	int		fd;
	char	*line;
	char	*all;
	char	*tmp;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_open_error();
	all = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = all;
		all = ft_strjoin(all, line);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	check_newlines(all);
	g.map = ft_split(all, '\n');
	free(all);
	set_player_pos(&g);
	return (g);
}
