/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:31:00 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/08 17:24:31 by jaragao-         ###   ########.fr       */
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


/*
void	flood_fill(char **map, t_size size, t_size player)
{
	if ((map[player.x][player.y] != '0' && map[player.x][player.y] != 'C'
	&& map[player.x][player.y] != 'P' && map[player.x][player.y] != 'E'
	&& map[player.x][player.y] != 'B')
	|| player.x < 0 || player.y < 0 || player.x >= size.x || player.y >= size.y)
		return ;
	if (map[player.x][player.y] == 'E')
		map[player.x][player.y] = 'e';
	if (map[player.x][player.y] == 'B')
		map[player.x][player.y] = 'b';
	if (map[player.x][player.y] == 'P')
		map[player.x][player.y] = 'p';
	if (map[player.x][player.y] == 'C')
		map[player.x][player.y] = 'c';
	if (map[player.x][player.y] == '0')
		map[player.x][player.y] = 'o';
	flood_fill(map, size, (t_size){player.x + 1, player.y});
	flood_fill(map, size, (t_size){player.x - 1, player.y});
	flood_fill(map, size, (t_size){player.x, player.y + 1});
	flood_fill(map, size, (t_size){player.x, player.y - 1});
}*/

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
	if ((exit_number(map, size) != 1))
		return (0);
	if ((player_number(map, size) != 1))
		return (0);
	if ((collectible_number(map, size) < 1) || (!is_it_a_square(map, size))
		|| (!walls(map, size))) // || (!flood_fill(map, size, player)) 
		return (0);
	return (1);
}
