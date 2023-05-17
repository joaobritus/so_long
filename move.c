/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:56 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/17 16:55:27 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	static int	c_count;

	if ((data->map[data->player.y + y][data->player.x + x] != '1'))
	{
		if (data->map[data->player.y + y][data->player.x + x] != '0')
		{
			if (data->map[data->player.y + y][data->player.x + x] == 'C')
			{
				c_count++;
				if (c_count == data->c_total)
					data->map[data->exit.y][data->exit.x] = 'F';
			}
			else if (data->map[data->player.y + y][data->player.x + x] == 'F')
				destroy(data);
		}
		data->map[data->player.y][data->player.x] = '0';
		data->player.x += x;
		data->player.y += y;
		if ((x == -1) && (data->map[data->player.y][data->player.x] = '0'))
			data->map[data->player.y][data->player.x] = 'L';
		else
			data->map[data->player.y][data->player.x] = 'P';
	}
}
