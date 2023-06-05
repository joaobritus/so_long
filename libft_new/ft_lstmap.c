/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaragao- <jaragao-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:57:16 by jaragao-          #+#    #+#             */
/*   Updated: 2022/11/15 17:17:34 by jaragao-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*zas;
	t_list	*zaza;

	zaza = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		zas = ft_lstnew(f(lst->content));
		if (zas == NULL)
			(*del)(zas->content);
		ft_lstadd_back(&zaza, zas);
		lst = lst->next;
	}
	return (zaza);
}
