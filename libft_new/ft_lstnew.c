/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:01:16 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/08 14:22:47 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*zas;

	zas = (t_list *)malloc(sizeof(*zas));
	if (!zas)
		return (NULL);
	zas->content = content;
	zas->next = NULL;
	return (zas);
}
