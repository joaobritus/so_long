/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:41:12 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/08 17:05:23 by jaragao-         ###   ########.fr       */
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
	data->images = image;
	return (1);
}
