/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:33:42 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/08 18:19:02 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	startup(char **map, t_size size)
{
	t_data		data;

	if (size.y * P > 1920 || size.x * P > 1080)
		return (ft_printf("Error\nMap is too big to fit in window.\n"));
	data.mlx_ptr = mlx_mlx_ptr();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, size.y * P, size.x * P, "So_long");
	if (!data.win_ptr)
		return (free_all(&data, 1, 0, 0));
	if (!open_images(&data))
		return (free_all(&data, 1, 0, 0));
	data.map = map;
	data.pos = find_pos(data.map, size.x, size.y, 'P');
	data.size = size;
	draw_start(&data, map);
	mlx_loop_hook(data.mlx_ptr, no_event, &data);
	mlx_hook(data.win_ptr, 2, 1L << 0, keypress, &data);
	mlx_hook(data.win_ptr, 17, 1L << 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (free_all(&data, 1, 1, 1));
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

