/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:00:44 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/30 16:50:56 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n /= 16;
		counter++;
	}
	return (counter);
}

void	ft_puthex(unsigned int n, char c)
{
	while (n >= 16)
	{
		ft_puthex(n / 16, c);
		n %= 16;
	}
	if (n <= 9)
		ft_printchar(n + 48);
	else if (c == 'x')
		ft_printchar((n - 10) + 97);
	else if (c == 'X')
		ft_printchar((n - 10) + 65);
}

int	ft_printhex(unsigned int n, char c)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(n, c);
	return (ft_hexlen(n));
}
