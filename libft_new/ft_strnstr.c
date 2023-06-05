/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:00:36 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/17 14:50:32 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	y;
	char	*str;

	str = (char *)haystack;
	if (needle[0] == '\0')
		return (str);
	i = 0;
	while (str[i] && i < n)
	{
		y = 0;
		while (needle[y])
		{
			if (haystack[i + y] == needle[y] && y + i < n)
			{
				y++;
			}
			else
				break ;
			if (needle[y] == '\0')
				return (str + i);
		}
		i++;
	}
	return (0);
}
