/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:56 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/10 17:35:32 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	if ((*data->map[data->player.x + x] != '1')
		&& (*data->map[data->player.x + x] != '1'))
	{
		data->map[data->player.y][data->player.x] = '0';
		data->player.x += x;
		data->player.y += y;
		data->map[data->player.y][data->player.x] = 'P';
	}
	if (x == 1)
		printf("d");
	if (x == -1)
		printf("a");
	if (y == 1)
		printf("w");
	if (y == -1)
		printf("s");
}
