/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:35:42 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:23:51 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*zas;

	zas = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)zas[i] == (unsigned char)c)
		{
			return ((void *)&zas[i]);
		}
		i++;
	}
	return (NULL);
}
