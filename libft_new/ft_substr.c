/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:39:19 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/22 16:09:17 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	y;
	char	*zas;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	zas = (char *)malloc((len + 1));
	if (!zas)
		return (NULL);
	y = 0;
	i = 0;
	while (s[i])
	{
		if (i >= start && y < len)
		{
			zas[y] = s[i];
			y++;
		}
		i++;
	}
	zas[y] = '\0';
	return (zas);
}
