/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:56 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/13 15:14:07 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	if ((data->map[data->player.y + y][data->player.x + x] != '1'))
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x += x;
		data->player.y += y;
		if (x == -1)
			data->map[data->player.y][data->player.x] = 'L';
		else
			data->map[data->player.y][data->player.x] = 'P';
	}
	if (x == 1)
		printf("d");
	else if (x == -1)
		printf("a");
	else if (y == 1)
		printf("w");
	else if (y == -1)
		printf("s");
}
