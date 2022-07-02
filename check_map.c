/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:11 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:24:43 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_extension(char	*av)
{
	char	*ptr;

	ptr = ft_strchr(av, '.');
	if (!ptr || ft_strncmp(ptr, ".ber", 4) != 0)
		print_errors(1, NULL);
}

int	surrounded_by_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->whole_map[i][0] != '1' ||
			map->whole_map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->whole_map[0][i] != '1' ||
				map->whole_map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rectancle(t_map *map)
{
	size_t	len;
	int		i;
	int		b;

	i = 1;
	b = 1;
	len = ft_strlen(map->whole_map[0]);
	while (i < map->height - 1)
	{
		if (len != ft_strlen(map->whole_map[i]))
			b = 0;
		i++;
	}
	return (b);
}
