/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:07:25 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/24 14:51:50 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_window(t_data *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return ;
}

void	free_image(t_data *data)
{
	if (data->images->floor)
		mlx_destroy_image(data->mlx_ptr, data->images->floor);
	if (data->images->wall)
		mlx_destroy_image(data->mlx_ptr, data->images->wall);
	if (data->images->exit1)
		mlx_destroy_image(data->mlx_ptr, data->images->exit1);
	if (data->images->exit2)
		mlx_destroy_image(data->mlx_ptr, data->images->exit2);
	if (data->images->collectible)
		mlx_destroy_image(data->mlx_ptr, data->images->collectible);
	if (data->images->player)
		mlx_destroy_image(data->mlx_ptr, data->images->player);
	if (data->images->player2)
		mlx_destroy_image(data->mlx_ptr, data->images->player2);
	if (data->images->exit_player)
		mlx_destroy_image(data->mlx_ptr, data->images->exit_player);
	if (data->images->exit_player2)
		mlx_destroy_image(data->mlx_ptr, data->images->exit_player2);
	free (data->images);
	return ;
}

int	free_all(t_data *data, int window, int images)
{
	if (images)
		free_image(data);
	if (window)
		free_window(data);
	return (1);
}
