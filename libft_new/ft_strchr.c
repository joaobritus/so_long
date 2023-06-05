/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:47:36 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:33:35 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*z;

	z = (char *)s;
	i = 0;
	while ((z[i] != (char)c) && z[i])
		i++;
	if (z[i] == (char)c)
		return (z + i);
	return (0);
}
