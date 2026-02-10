/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 13:44:22 by ksener            #+#    #+#             */
/*   Updated: 2026/01/23 16:25:50 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*temp;
	t_list	*result;

	if (!lst || !f || !del)
		return (NULL);
	map = NULL;
	while (lst != NULL)
	{
		result = f(lst->content);
		temp = ft_lstnew(result);
		if (temp == NULL)
		{
			del(result);
			ft_lstclear(&map, del);
			return (NULL);
		}
		ft_lstadd_back(&map, temp);
		lst = lst->next;
	}
	return (map);
}
