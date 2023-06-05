/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:32:40 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/22 14:05:47 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	length(int n)
{
	int		len;
	long	n2;

	n2 = n;
	len = 0;
	if (n2 <= 0)
	{
		n2 = n2 * -1;
		len++;
	}
	while (n2 > 0)
	{
		len++;
		n2 = (n2 / 10);
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*zas;

	i = length(n);
	zas = (char *)malloc((i + 1) * sizeof(char));
	if (!zas)
		return (NULL);
	zas[i--] = '\0';
	if (n == -2147483648)
		return (ft_memcpy(zas, "-2147483648", 11));
	if (n < 0)
	{
		zas[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		zas[i--] = (n % 10) + 48;
		n = (n / 10);
	}
	if (n >= 0 && n <= 9)
		zas[i] = n + 48;
	return (zas);
}
