/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:11:57 by jaragao-          #+#    #+#             */
/*   Updated: 2023/06/04 17:02:29 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft_new/libft.h"
# include "./mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

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
	void		*player2;
	void		*collectible;
	void		*exit1;
	void		*exit2;
	void		*exit_player;
	void		*exit_player2;
}				t_sprites;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_size		size;
	t_size		player;
	t_size		exit;
	t_size		enemy;
	int			c_total;
	t_sprites	*images;
}				t_data;

# define P 72
# define MLX_ERROR 1

/*main.c*/
char			**treatment(char *argv, t_size *size);
t_size			map_size(int fd);
void			free_map(char **map);
void			get_the_player(char **map, t_size size, t_size *player);
void			get_the_exit(t_data *data);
void			flood_fill(char **map, t_size size, t_size player);
int				walls(char **map, t_size size);
int				is_it_a_square(char **map);
int				map_valid(char **map, t_size size, t_size *player);
int				collectible_number(char **map, t_size size);
int				player_number(char **map, t_size size);
int				exit_number(char **map, t_size size);
int				open_images(t_data *data);
int				draw(void *data);
int				keypress(int keysym, t_data *data);
int				startup(char **map, t_size size, t_size player);
void			choose_image(t_data *data, t_size pos, char **map);
int				open_images(t_data *data);
void			free_window(t_data *data);
void			free_image(t_data *data);
int				free_all(t_data *data, int window, int images);
int				check_map(char **map);
void			reset_map(char **map);
void			move(t_data *data, int x, int y);
int				destroy(t_data *data);
void			choose_image2(t_data *data, t_size pos, char **map);
int				open_images2(t_data *data);
void			move1(t_data *data, int x, int y, int c_count);
void			move2(t_data *data, int x, int y);
void			move3(t_data *data, int x, int y);

#endif