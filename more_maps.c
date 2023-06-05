/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:04:41 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/05 11:45:02 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_the_player(char **map, t_size size, t_size *player)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			if (map[y][x] == 'P')
			{
				player->y = y;
				player->x = x;
			}
		}
	}
}

void	get_the_exit(t_data *data)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < data->size.y)
	{
		x = -1;
		while (++x < data->size.x)
		{
			if (data->map[y][x] == 'E')
			{
				data->exit.y = y;
				data->exit.x = x;
			}
		}
	}
}

void	flood_fill(char **map, t_size size, t_size player)
{
	if ((player.x < 0 || player.y < 0 || player.x >= size.x
			|| player.y >= size.y) || (map[player.y][player.x] != '0'
		&& map[player.y][player.x] != 'C' && map[player.y][player.x] != 'P'
		&& map[player.y][player.x] != 'E'))
		return ;
	if (map[player.y][player.x] == 'E')
		map[player.y][player.x] = 'e';
	if (map[player.y][player.x] == 'P')
		map[player.y][player.x] = 'p';
	if (map[player.y][player.x] == 'C')
		map[player.y][player.x] = 'c';
	if (map[player.y][player.x] == '0')
		map[player.y][player.x] = 'o';
	flood_fill(map, size, (t_size){player.x + 1, player.y});
	flood_fill(map, size, (t_size){player.x - 1, player.y});
	flood_fill(map, size, (t_size){player.x, player.y + 1});
	flood_fill(map, size, (t_size){player.x, player.y - 1});
}

void	reset_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'c')
				map[y][x] = 'C';
			if (map[y][x] == 'e')
				map[y][x] = 'E';
			if (map[y][x] == 'o')
				map[y][x] = '0';
			if (map[y][x] == 'p')
				map[y][x] = 'P';
		}
	}
}

int	check_map(char **map)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				ft_printf("Error\ncan't reach collectible\n");
				return (0);
			}
			if (map[y][x] == 'E')
			{
				ft_printf("Error\ncan't reach exit\n");
				return (0);
			}
		}
	}
	reset_map(map);
	return (1);
}
