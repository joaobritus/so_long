/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:41:12 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/10 10:04:32 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_images(t_data *data)
{
	t_sprites	*image;
	int			s;

	s = P;
	image = (t_sprites *)malloc(sizeof(t_sprites));
	if (!image)
		return (0);
	image->floor = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/floor.xpm", &s, &s);
	image->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/wall.xpm", &s, &s);
	image->exit1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/exit1.xpm", &s, &s);
	image->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/player.xpm", &s, &s);
	image->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./images/collectible.xpm", &s, &s);
	data->images = image;
	return (1);
}

void	choose_image(t_data *data, t_size pos, char **map)
{
	if (map[pos.x][pos.y] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->floor, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->wall, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->player, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->exit1, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->collectible, pos.y * P, pos.x * P);
	return ;
}

void	draw(t_data *data, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
			choose_image(data, (t_size){x, y}, map);
	}
	return ;
}
