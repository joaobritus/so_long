/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:59:39 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:37:10 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		a = (unsigned char)s1[i];
		b = (unsigned char)s2[i];
		if (s1[i] != s2[i])
		{
			return (a - b);
		}
		i++;
	}
	a = s1[i];
	b = s2[i];
	if (i < n)
		return (a - b);
	return (0);
}
