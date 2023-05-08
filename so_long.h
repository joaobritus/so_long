/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:57 by jaragao-          #+#    #+#             */
/*   Updated: 2023/05/08 18:02:50 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_new/libft.h"
# include "./mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <X11/keysym.h>

typedef struct size
{
	int			x;
	int			y;
}				t_size;

typedef struct s_sprites
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectible;
	void		*exit1;
}				t_sprites;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_sprites	*images;
	char		**map;
	t_coord		size;
	t_coord		pos;
}				t_data;

typedef struct s_rect
{
	int			x;
	int			y;
	int			width;
	int			height;
	int			color;
}				t_rect;

# define P 72

/*main.c*/
char			**treatment(char *argv, t_size *size);
t_size			map_size(int fd);
void			free_map(char **map);
void			get_the_player(char **map, t_size size, t_size *player);
int				flood_fill(char **map, t_size size, t_size player);
int				walls(char **map, t_size size);
int				is_it_a_square(char **map, t_size size);
int				map_valid(char **map, t_size size, t_size *player);
int				collectible_number(char **map, t_size size);
int				player_number(char **map, t_size size);
int				exit_number(char **map, t_size size);
int				open_images(t_data *data);

#endif