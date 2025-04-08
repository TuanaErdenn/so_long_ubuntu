/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terden <terden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 13:13:57 by terden            #+#    #+#             */
/*   Updated: 2025/04/08 21:09:40 by terden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit(t_game *g)
{
	if (g->c == 0)
	{
		print_moves(g->move);
		g->move++;
		write(1, "**********************************************************",
			59);
		write(1, "\n   🎉Congratulations! You've collected all the fish!🎉\n",
			61);
		write(1, "**********************************************************\n",
			60);
		close_game(g);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	exit_with_error(t_game *g, char *msg)
{
	if (g->map)
		free_map(g->map);
	if (g->init)
	{
		mlx_destroy_display(g->init);
		free(g->init);
	}
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 35);
		return (1);
	}
	check_extension(av[1]);
	init_values(&game);
	game = load_map(game, av);
	game = control_all(game);
	setup_window(&game);
	game = control2(&game);
	render_map(game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.init);
	return (0);
}
