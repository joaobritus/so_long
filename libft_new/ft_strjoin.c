/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:52:45 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:35:04 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		y;
	char	*zas;

	zas = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!zas)
		return (0);
	i = 0;
	while (s1[i])
	{
		zas[i] = s1[i];
		i++;
	}
	y = 0;
	while (s2[y])
	{
		zas[i] = s2[y];
		i++;
		y++;
	}
	zas[i] = '\0';
	return (zas);
}
