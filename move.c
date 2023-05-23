/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:56 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/23 15:49:53 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	static int	c_count;

	if (data->map[data->player.y + y][data->player.x + x] != '1')
	{
		if (data->map[data->player.y + y][data->player.x + x] == 'C')
		{
			c_count++;
			if (c_count == data->c_total)
				data->map[data->exit.y][data->exit.x] = 'F';
			data->map[data->player.y + y][data->player.x + x] = 'P';
		}
		else if (data->map[data->player.y + y][data->player.x + x] == 'F')
			destroy(data);
		else if (data->map[data->player.y + y][data->player.x + x] == 'E')
		{
			if (x == 1 || data->map[data->player.y][data->player.x] == 'P')
				data->map[data->player.y + y][data->player.x + x] = 'Z';
			else if (x == -1
				|| data->map[data->player.y][data->player.x] == 'L')
				data->map[data->player.y + y][data->player.x + x] = 'X';
		}
		else if (data->map[data->player.y + y][data->player.x + x] == '0')
		{
			if (x == 1
				|| (data->map[data->player.y][data->player.x] == 'P' && y != 0))
				data->map[data->player.y + y][data->player.x + x] = 'P';
			else if (x == -1
				|| (data->map[data->player.y][data->player.x] == 'L' && y != 0))
				data->map[data->player.y + y][data->player.x + x] = 'L';
		}
		if (data->map[data->player.y][data->player.x] == 'Z'
			|| data->map[data->player.y][data->player.x] == 'X')
		{
				data->map[data->player.y][data->player.x] = 'E';
				data->map[data->player.y + y][data->player.x + x] = 'P';
		}
		else
			data->map[data->player.y][data->player.x] = '0';
		data->player.y += y;
		data->player.x += x;
	}
}
