/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:04 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:25:06 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cross(t_map *map)
{
	free(map->whole_map);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		print_errors(2, NULL);
	map_init(&map);
	parse_map(argv[1], &map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.width * 75, map.height * 75, ".");
	print_map(&map);
	mlx_key_hook(map.win, moves, &map);
	mlx_hook(map.win, 17, (1L << 17), cross, &map);
	mlx_loop(map.mlx);
}
