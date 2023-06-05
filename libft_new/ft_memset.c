/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:38:23 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/07 10:54:26 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*zaz;

	zaz = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		zaz[i] = c;
		i++;
	}
	return ((void *)zaz);
}
