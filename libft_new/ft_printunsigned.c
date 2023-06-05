/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:16:30 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/30 16:47:10 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = ft_numlen(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (str);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*str;

	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		str = ft_uitoa(n);
		len = ft_printstr(str);
		free(str);
	}
	return (len);
}
