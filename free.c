/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:07:25 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/08 18:10:59 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map, int xi)
{
	while (xi >= 0)
	{
		free(map[xi]);
		xi--;
	}
	free(map);
	return (0);
}

/*Frees mlx window*/
void	free_window(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return ;
}

/*Frees images*/
void	free_image(t_data *data)
{
	if (data->images->floor)
		mlx_destroy_image(data->mlx_ptr, data->images->floor);
	if (data->images->wall)
		mlx_destroy_image(data->mlx_ptr, data->images->wall);
	if (data->images->exit1)
		mlx_destroy_image(data->mlx_ptr, data->images->exit1);
	if (data->images->collectible)
		mlx_destroy_image(data->mlx_ptr, data->images->collectible);
	if (data->images->player)
		mlx_destroy_image(data->mlx_ptr, data->images->player);
	if (data->images->player)
		mlx_destroy_image(data->mlx_ptr, data->images->player);
	free (data->images);
	return ;
}

/*Gets ifo on what to free and calls appropriate functions*/
int	free_all(t_data *data, int window, int images, int images2)
{
	if (images)
		free_image(data);
	if (window)
		free_window(data);
	return (1);
}