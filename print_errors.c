/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:25 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 01:46:31 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map->whole_map[i])
		free(map->whole_map[i++]);
	free(map->whole_map[i]);
}

void	print_errors(int i, t_map *map)
{
	if (i == 0)
		write(2, "Error\nInvalide map\n", 20);
	if (i == 1)
		write(2, "Error\nInvalide map extension\n", 29);
	if (i == 2)
		write(2, "Error\nInvalide Arguments\n", 25);
	freemap(map);
	exit(0);
}
