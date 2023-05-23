/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:31:00 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/23 16:05:18 by jaragao-         ###   ########.fr       */
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
	flood_fill(map, size, (t_size){player.y + 1, player.x});
	flood_fill(map, size, (t_size){player.y - 1, player.x});
	flood_fill(map, size, (t_size){player.y, player.x + 1});
	flood_fill(map, size, (t_size){player.y, player.x - 1});
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
				printf("Error\ncan't reach collectible\n");
				return (0);
			}
			if (map[y][x] == 'E')
			{
				printf("Error\ncan't reach exit\n");
				return (0);
			}
		}
	}
	reset_map(map);
	return (1);
}

t_size	map_size(int fd)
{
	char	buffer;
	t_size	i;

	i.x = 0;
	i.y = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (i.y == 0 && buffer != '\n')
			i.x++;
		if (buffer == '\n')
			i.y++;
	}
	if (read(fd, &buffer, 1) == -1)
		return ((t_size){0, 0});
	return (i);
}

int	walls(char **map, t_size size)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size.y && (x == 0 || x == size.x))
	{
		if ((map[y][0] != '1') || (map[y][size.y - 1] != '1'))
			return (0);
		x = -1;
		while (++x < size.x && (y == 0 || y == size.y - 1))
		{
			if (map[y][x] != '1')
				return (0);
		}
	}
	return (1);
}

int	is_it_a_square(char **map, t_size size)
{
	int	y;

	y = -1;
	while (++y < size.y - 1)
	{
		if (ft_strlen(map[y]) != ft_strlen(map[y + 1]))
			return (0);
	}
	return (1);
}

int	map_valid(char **map, t_size size, t_size *player)
{
	get_the_player(map, size, player);
	if (exit_number(map, size) != 1 || player_number(map, size) != 1
		|| collectible_number(map, size) < 1 || !is_it_a_square(map, size)
		|| !walls(map, size))
		return (0);
	flood_fill(map, size, *player);
	if (!check_map(map))
		return (0);
	reset_map(map);
	return (1);
}
