/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:04:11 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/15 17:09:59 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*zas;

	if (lst)
	{
		if (*lst)
		{
			zas = ft_lstlast(*lst);
			zas->next = new;
		}
		else
		*lst = new;
	}
}
