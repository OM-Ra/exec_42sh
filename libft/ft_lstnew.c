/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 13:29:21 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 13:29:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void	const *content, size_t content_size)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))))
	{
		if ((list->content = (char *)malloc(content_size)) && content)
		{
			list->content = ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
		else if (list->content && !content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			free(list);
			list = NULL;
			return (NULL);
		}
		list->next = NULL;
		return (list);
	}
	return (NULL);
}
