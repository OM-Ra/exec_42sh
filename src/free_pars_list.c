/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pars_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 16:25:59 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 20:59:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void			free_stream_list(t_red_stream *stream_list)
{
	t_red_stream *buf_list;

	while (stream_list)
	{
		buf_list = stream_list;
		stream_list = stream_list->next;
		free(buf_list);
	}
}

void			free_args(t_pars_list *list)
{
	size_t i;

	i = 0;
	while (list->pars_args[i])
		free(list->pars_args[i++]);
	free(list->pars_args);
}

t_pars_list		*free_pars_list(t_pars_list **list)
{
	t_pars_list	*buf_list;

	while (*list)
	{
		buf_list = (*list);
		(*list) = (*list)->next;
		if (buf_list->pars_args)
			free_args(buf_list);
		if (buf_list->stream_list)
			free_stream_list(buf_list->stream_list);
		free(buf_list);
	}
	return (NULL);
}
