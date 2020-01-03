/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:01:11 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 14:01:13 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list *p;

	if (alst && del)
	{
		while (*alst)
		{
			p = (*alst);
			(*alst) = (*alst)->next;
			del(p->content, p->content_size);
			free(p);
		}
		p = NULL;
	}
}
