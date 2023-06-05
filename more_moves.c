/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:55:33 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/05 16:02:51 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	more_moves(t_data *data, int x, int y, int c_count)
{
	if (data->map[data->player.y + y][data->player.x + x] == '1')
		return ;
	if (data->map[data->player.y + y][data->player.x + x] == 'C')
	{
		c_count++;
		move1(data, x, y, c_count);
	}
	else if (data->map[data->player.y + y][data->player.x + x] == 'F')
		destroy(data);
	else if (data->map[data->player.y + y][data->player.x + x] == 'E')
		move2(data, x, y);
	else if (data->map[data->player.y + y][data->player.x + x] == '0')
		move3(data, x, y);
}
