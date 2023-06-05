/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:37:23 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:24:55 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*za;
	char	*ze;

	if (!src && !dest)
		return (0);
	za = (char *)dest;
	ze = (char *)src;
	i = 0;
	while (i < n)
	{
		za[i] = ze[i];
		i++;
	}
	return (dest);
}
