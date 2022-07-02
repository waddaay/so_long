/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywadday <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:37:33 by ywadday           #+#    #+#             */
/*   Updated: 2022/07/02 02:49:23 by ywadday          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && ((unsigned char)s1[i] == (unsigned char)s2[i])
		&& (unsigned char)s1[i] && (unsigned char)s2[i])
		i++;
	if (i == n)
	{
		return ((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_putchar(char letter)
{
	write(1, &letter, 1);
	return (1);
}

size_t	ft_putnbr(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len += ft_putchar('-');
	}
	if (n >= 10)
	{
		len += ft_putnbr(n / 10);
	}
	len += ft_putchar(n % 10 + '0');
	return (len);
}
