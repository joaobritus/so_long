/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:50:39 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/22 16:25:17 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*zas;

	i = 0;
	zas = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (zas == NULL)
		return (0);
	while (s[i])
	{
		zas[i] = s[i];
		i++;
	}
	zas[i] = '\0';
	return (zas);
}
