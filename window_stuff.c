/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:33:42 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/30 16:58:09 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_data *data)
{
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		destroy(data);
	else if (keysym == XK_w)
		move(data, 0, -1);
	else if (keysym == XK_s)
		move(data, 0, 1);
	else if (keysym == XK_a)
		move(data, -1, 0);
	else if (keysym == XK_d)
		move(data, 1, 0);
	return (0);
}

int	startup(char **map, t_size size, t_size player)
{
	t_data	*data;

	data = (t_data *)ft_calloc(1, sizeof(t_data));
	data->map = map;
	data->size = size;
	data->player = player;
	get_the_exit(data);
	data->c_total = collectible_number(map, size);
	if (size.y * P > 1920 || size.x * P > 1080)
		return (ft_printf("Error\nMap is too big to fit in window.\n"));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, size.x * P, size.y * P,
			"So_long");
	if (!data->win_ptr)
		return (free_all(data, 1, 0));
	if (!open_images(data))
		return (1);
	mlx_loop_hook(data->mlx_ptr, draw, data);
	mlx_hook(data->win_ptr, 2, 1L << 0, &keypress, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &destroy, data);
	mlx_loop(data->mlx_ptr);
	free_all(data, 1, 1);
	return (1);
}
