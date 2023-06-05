/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:37:54 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:25:59 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destino;
	char	*source;

	if (!src && !dest)
		return (0);
	destino = (char *)dest;
	source = (char *)src;
	if (dest > src)
	{
		while (n > 0)
		{
			destino[n - 1] = source[n - 1];
			n--;
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		destino[i] = source[i];
		i++;
	}
	return (dest);
}
