/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_assets.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:36:53 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:40:46 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(char *img_path, t_map map)
{
	void	*img;
	int		a;
	int		b;

	img = mlx_xpm_file_to_image(map.mlx, img_path, &a, &b);
	mlx_put_image_to_window(map.mlx, map.win, img, map.pos_x, map.pos_y);
}

void	put_asset(t_map map, char char_)
{
	put_image(EMPTY, map);
	if (char_ != '1' && char_ != '0' && char_ != 'P'
		&& char_ != 'E' && char_ != 'C' && char_ != '\n')
		print_errors(0, &map);
	else
	{
		if (char_ == '1')
			put_image(WALL, map);
		else if (char_ == '0')
			put_image(EMPTY, map);
		else if (char_ == 'P')
			put_image(PLAYER, map);
		else if (char_ == 'E')
			put_image(EXIT, map);
		else if (char_ == 'C')
			put_image(COLLECTABLE, map);
	}
}

void	print_map(t_map *map)
{
	int	i;
	int	j;

	map->pos_x = 0;
	map->pos_y = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			put_asset (*map, map->whole_map[i][j]);
			map->pos_x += 75;
			j++;
		}
		map->pos_x = 0;
		map->pos_y += 75;
		i++;
	}
}

void	exit_game(t_map *map)
{
	free (map->whole_map);
	exit(0);
}

int	moves(int keycode, t_map *map)
{
	player_position(map);
	if (keycode == 53)
		exit_game(map);
	else if (keycode == 13)
		move_up(map);
	else if (keycode == 2)
		move_right(map);
	else if (keycode == 0)
		move_left(map);
	else if (keycode == 1)
		move_down(map);
	mlx_clear_window(map->mlx, map->win);
	print_map(map);
	return (0);
}
