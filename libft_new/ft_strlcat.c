/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:54:34 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:35:24 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	y;
	size_t	destlength;

	destlength = ft_strlen(dest);
	y = destlength;
	if (!size)
		return (ft_strlen(src));
	if (size < y)
		return (size + ft_strlen(src));
	i = 0;
	while (src[i] && y < size - 1)
	{
		dest[y] = src[i];
		i++;
		y++;
	}
	dest[y] = '\0';
	return (destlength + ft_strlen(src));
}
