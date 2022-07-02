/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:20 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:47:40 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->whole_map[i][j])
		{
			if (map->whole_map[i][j] == 'P')
			{
				map->x = i;
				map->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_up(t_map *map)
{
	if (map->whole_map[map->x - 1][map->y] == '0')
	{
		map->whole_map[map->x - 1][map->y] = 'P';
		map->whole_map[map->x][map->y] = '0';
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x - 1][map->y] == 'C')
	{
		map->whole_map[map->x - 1][map->y] = 'P';
		map->whole_map[map->x][map->y] = '0';
		map->collectable--;
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x - 1][map->y] == 'E' && map->collectable == 0)
	{
		ft_putnbr(map->moves);
		ft_putchar('\n');
		exit_game(map);
	}
}

void	move_down(t_map *map)
{
	if (map->whole_map[map->x + 1][map->y] == '0')
	{
		map->whole_map[map->x + 1][map->y] = 'P';
		map->whole_map[map->x][map->y] = '0';
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x + 1][map->y] == 'C')
	{
		map->whole_map[map->x + 1][map->y] = 'P';
		map->whole_map[map->x][map->y] = '0';
		map->collectable--;
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x - 1][map->y] == 'E' && map->collectable == 0)
	{
		ft_putnbr(map->moves);
		ft_putchar('\n');
		exit_game(map);
	}
}

void	move_right(t_map *map)
{
	if (map->whole_map[map->x][map->y + 1] == '0')
	{
		map->whole_map[map->x][map->y + 1] = 'P';
		map->whole_map[map->x][map->y] = '0';
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x][map->y + 1] == 'C')
	{
		map->whole_map[map->x][map->y + 1] = 'P';
		map->whole_map[map->x][map->y] = '0';
		map->collectable--;
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x][map->y + 1] == 'E' && map->collectable == 0)
	{
		ft_putnbr(map->moves);
		ft_putchar('\n');
		exit_game(map);
	}
}

void	move_left(t_map *map)
{
	if (map->whole_map[map->x][map->y - 1] == '0')
	{
		map->whole_map[map->x][map->y - 1] = 'P';
		map->whole_map[map->x][map->y] = '0';
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x][map->y - 1] == 'C')
	{
		map->whole_map[map->x][map->y - 1] = 'P';
		map->whole_map[map->x][map->y] = '0';
		map->collectable--;
		ft_putnbr(++map->moves);
		ft_putchar('\n');
	}
	else if (map->whole_map[map->x][map->y - 1] == 'E' && map->collectable == 0)
	{
		ft_putnbr(map->moves);
		ft_putchar('\n');
		exit_game(map);
	}
}
