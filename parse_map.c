/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:36:42 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:09:28 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->player = 0;
	map->wall = 0;
	map->collectable = 0;
	map->empty = 0;
	map->exit = 0;
	map->moves = 0;
}

void	fill_map(t_map *map, char *map_name)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->whole_map[i++] = line;
	}
	map->whole_map[i] = NULL;
	close(fd);
}

void	collect_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (map->whole_map[i][j] == 'E')
				map->exit += 1;
			if (map->whole_map[i][j] == 'C')
				map->collectable += 1;
			if (map->whole_map[i][j] == 'P')
				map->player += 1;
			j++;
		}
		i++;
	}
	if (map->collectable < 1 || map->exit < 1 || map->player != 1)
		print_errors(0, map);
}

void	parse_map(char *map_name, t_map *map)
{
	char	*line;
	int		fd;

	check_extension(map_name);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		print_errors(0, NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->height++;
		free(line);
	}
	close(fd);
	map->whole_map = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!map->whole_map)
		return ;
	fill_map (map, map_name);
	collect_map (map);
	map->width = ft_strlen(map->whole_map[0]) - 1;
	if (!check_rectancle(map) || !surrounded_by_walls(map))
		print_errors(0, map);
}
