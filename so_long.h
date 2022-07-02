/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 01:07:22 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:46:37 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include <string.h>

# define WALL "assets/wall.xpm"
# define COLLECTABLE "assets/collectable.xpm"
# define EXIT "assets/exit.xpm"
# define PLAYER "assets/player.xpm"
# define EMPTY "assets/empty.xpm"

typedef struct s_map{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**whole_map;
	int		moves;
	int		player;
	int		pos_x;
	int		pos_y;
	int		wall;
	int		collectable;
	int		empty;
	int		x;
	int		y;
	int		exit;

}t_map;

char	*get_next_line(int fd);
void	parse_map(char *map_name, t_map *map);
char	*ft_strchr(const char *s, int c);
void	print_errors(int i, t_map *map);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	map_init(t_map *map);
int		surrounded_by_walls(t_map *map);
void	print_map(t_map *map);
void	move_up(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);
void	move_left(t_map *map);
void	player_position(t_map *map);
void	exit_game(t_map *map);
int		moves(int keycode, t_map *map);
void	check_extension(char *av);
int		check_rectancle(t_map *map);
size_t	ft_putnbr(int n);
size_t	ft_putchar(char letter);

#endif
