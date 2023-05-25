/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 18:18:14 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/25 15:47:57 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	collectible_number(char **map, t_size size)
{
	int	y;
	int	x;
	int	c_number;

	y = -1;
	c_number = 0;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			if (map[y][x] == 'C')
				c_number++;
		}
	}
	return (c_number);
}

int	player_number(char **map, t_size size)
{
	int	y;
	int	x;
	int	p_number;

	y = -1;
	p_number = 0;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			if (map[y][x] == 'P')
				p_number++;
		}
	}
	return (p_number);
}

int	exit_number(char **map, t_size size)
{
	int	y;
	int	x;
	int	e_number;

	y = -1;
	e_number = 0;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
		{
			if (map[y][x] == 'E')
				e_number++;
		}
	}
	return (e_number);
}
