/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:12:33 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 15:12:35 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*p1;
	t_list	*p2;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	if (!(p1 = ft_lstnew((void const *)f(lst)->content, f(lst)->content_size)))
		return (NULL);
	start = p1;
	while ((lst = lst->next))
	{
		p2 = p1;
		if (!(p1 = ft_lstnew((void const *)f(lst)->content,
			f(lst)->content_size)))
		{
			ft_lstdel(&start, &ft_del);
			return (NULL);
		}
		ft_lstadd_end(&p2, p1);
	}
	return (start);
}
