/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:04:56 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/05 16:07:41 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data *data, int x, int y)
{
	static int	c_count;
	int			yy;
	int			xx;

	yy = data->player.y;
	xx = data->player.x;
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

void	count_moves(t_data *data, int yy, int xx)
{
	static int	move_count;

	if (yy != data->player.y || xx != data->player.x)
	{
		move_count++;
		printf("number of moves: %d\n", move_count);
	}
}

void	move1(t_data *data, int x, int y, int c_count)
{
	if (c_count == data->c_total)
		data->map[data->exit.y][data->exit.x] = 'F';
	data->map[data->player.y + y][data->player.x + x] = 'P';
}

void	move2(t_data *data, int x, int y)
{
	if (x == 1 || data->map[data->player.y][data->player.x] == 'P')
		data->map[data->player.y + y][data->player.x + x] = 'Z';
	else if (x == -1 || data->map[data->player.y][data->player.x] == 'L')
		data->map[data->player.y + y][data->player.x + x] = 'X';
}

void	move3(t_data *data, int x, int y)
{
	if (x == 1 || (data->map[data->player.y][data->player.x] == 'P' && y != 0))
		data->map[data->player.y + y][data->player.x + x] = 'P';
	else if (x == -1 || (data->map[data->player.y][data->player.x] == 'L'
		&& y != 0))
		data->map[data->player.y + y][data->player.x + x] = 'L';
}
