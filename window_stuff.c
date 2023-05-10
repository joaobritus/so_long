/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:33:42 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/10 10:42:10 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		destroy(data);
	else if (keysym == XK_w)
		printf("w\n");
	else if (keysym == XK_s)
		printf("s\n");
	else if (keysym == XK_a)
		printf("a\n");
	else if (keysym == XK_d)
		printf("d\n");
	return (0);
}

int	no_event(void)
{
	return (0);
}

int	startup(char **map, t_size size)
{
	t_data		data;

	if (size.y * P > 1920 || size.x * P > 1080)
		return (ft_printf("Error\nMap is too big to fit in window.\n"));
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, size.x * P, size.y * P, "So_long");
	if (!data.win_ptr)
		return (free_all(&data, 1, 0));
	if (!open_images(&data))
		return (1);
	data.map = map;
	data.size = size;
	draw(&data, map);
	mlx_loop_hook(data.mlx_ptr, no_event, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, KeyPressMask, &destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (free_all(&data, 1, 1));
}
