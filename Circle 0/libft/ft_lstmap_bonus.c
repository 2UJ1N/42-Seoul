/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youjlee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:20:56 by youjlee           #+#    #+#             */
/*   Updated: 2023/12/19 14:20:58 by youjlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*result;
	void	*tmp_content;

	result = NULL;
	while (lst != NULL)
	{
		tmp_content = f(lst->content);
		new_lst = ft_lstnew(tmp_content);
		if (new_lst == NULL)
		{
			del(tmp_content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, new_lst);
		lst = lst->next;
	}
	return (result);
}
