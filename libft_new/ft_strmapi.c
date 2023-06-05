/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:58:53 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:36:41 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*zas;

	i = 0;
	while (s[i])
		i++;
	zas = (char *)malloc((i + 1) * sizeof(char));
	if (!zas)
		return (0);
	i = 0;
	while (s[i])
	{
		zas[i] = f(i, s[i]);
		i++;
	}
	zas[i] = '\0';
	return (zas);
}
