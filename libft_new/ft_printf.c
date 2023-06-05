/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:09:09 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/30 16:25:55 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int a)
{
	return (write(1, &a, 1));
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	char	*zas;
	int		len;

	len = 0;
	zas = ft_itoa(n);
	len = ft_printstr(zas);
	free(zas);
	return (len);
}

int	ft_output(va_list ptr, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(ptr, int));
	else if (c == 's')
		len += ft_printstr(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(ptr, int));
	else if (c == 'x' || c == 'X')
		len += ft_printhex(va_arg(ptr, unsigned int), c);
	else if (c == 'u')
		len += ft_printunsigned(va_arg(ptr, unsigned int));
	else if (c == 'p')
		len += ft_printptr(va_arg(ptr, unsigned long long));
	else if (c == '%')
		len = write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ptr;

	i = 0;
	length = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			length += ft_output(ptr, str[i]);
		}
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(ptr);
	return (length);
}
