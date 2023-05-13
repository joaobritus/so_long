/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:35:24 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/13 16:06:01 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	get_the_enemy(char **map, t_size size, t_size *enemy)
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
			if (map[y][x] == 'B')
			{
				player->y = y;
				player->x = x;
			}
		}
	}
}


int	enemy_stuff(void *data)
{
	int	i;

	i = 0;
	while (i < 99999999)
	{
		i++;
	}
	i = -1;
	while (++i < 99999999)
	{
		if (i % 2 == 0)
		{
			if ((data->map[y][x + 1] != '1')
				|| (data->map[y - 1][x - 1] != '1'))
			{
				if ((i - 1) % 2 == 0)
				{
					data->map[y][x] = '0';
					x++;
					data->map[y][x] = 'B';
				}
				else
				{
					data->map[y][x] = '0';
					x--;
					data->map[y][x] = 'N';
				}
			}
			else
			{
				if ((data->map[y + 1][x] != '1')
					|| (data->map[y - 1][x] != '1'))
				{
					if ((i - 1) % 2 == 0)
					{
						data->map[y][x] = '0';
						y++;
						data->map[y][x] = 'B';
					}
					else
					{
						data->map[y][x] = '0';
						y--;
						data->map[y][x] = 'B';
					}
				}
			}
		}
	}
	return (0);
}
*/