/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:38:18 by ywadday           #+#    #+#             */
/*   Updated: 2021/12/25 19:54:52 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rest(char *str)
{
	char	*new_str;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = ft_substr(str, i + 1, (ft_strlen(str) - i) + 1);
	free(str);
	return (new_str);
}

char	*get_line(char *str)
{
	char	*new_str;
	int		i;

	if (!str[0])
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	new_str = ft_substr(str, 0, i + 1);
	return (new_str);
}

char	*ft_read(char *string, int fd)
{
	char	*to_read;
	int		read_bytes;

	to_read = (char *)malloc(BUFFER_SIZE + 1);
	if (!to_read)
		return (NULL);
	read_bytes = 1;
	while (!check_new_line(string) && read_bytes != 0)
	{
		read_bytes = read(fd, to_read, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(to_read);
			return (NULL);
		}
		to_read[read_bytes] = '\0';
		string = ft_strjoin(string, to_read);
	}
	free(to_read);
	return (string);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!check_new_line(str))
		str = ft_read(str, fd);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = get_rest(str);
	return (line);
}
