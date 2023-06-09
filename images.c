/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:41:12 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/05 14:17:38 by jaragao-         ###   ########.fr       */
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
			"./textures/floor.xpm", &s, &s);
	image->wall = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/wall.xpm", &s, &s);
	image->exit1 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit.xpm", &s, &s);
	image->exit2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit2.xpm", &s, &s);
	image->exit_player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_player.xpm", &s, &s);
	image->exit_player2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/exit_player2.xpm", &s, &s);
	image->player = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player.xpm", &s, &s);
	image->player2 = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/player2.xpm", &s, &s);
	data->images = image;
	return (1);
}

int	open_images2(t_data *data)
{
	int			s;

	s = P;
	data->images->collectible = mlx_xpm_file_to_image(data->mlx_ptr,
			"./textures/collectible.xpm", &s, &s);
	return (1);
}

void	choose_image(t_data *data, t_size pos, char **map)
{
	if (map[pos.y][pos.x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->floor, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->wall, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->player, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == 'L')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->player2, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->exit1, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == 'F')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->exit2, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == 'Z')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->exit_player, pos.x * P, pos.y * P);
	else if (map[pos.y][pos.x] == 'X')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->exit_player2, pos.x * P, pos.y * P);
	return ;
}

void	choose_image2(t_data *data, t_size pos, char **map)
{
	if (map[pos.y][pos.x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->images->collectible, pos.x * P, pos.y * P);
	return ;
}

int	draw(void *data)
{
	int	x;
	int	y;

	y = -1;
	while (((t_data *)data)->map[++y])
	{
		x = -1;
		while (((t_data *)data)->map[y][++x])
		{
			choose_image(data, (t_size){x, y}, ((t_data *)data)->map);
			choose_image2(data, (t_size){x, y}, ((t_data *)data)->map);
		}
	}
	return (1);
}
