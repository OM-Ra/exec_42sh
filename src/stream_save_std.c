/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_save_std.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:52:02 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/05 15:52:04 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	save_dup_std(t_red_stream *buflist)
{
	buflist->save_std = dup(buflist->stream_a);
}

static void	find_save(t_red_stream *stream_list)
{
	t_red_stream *buflist;

	buflist = stream_list;
	while (buflist)
	{
		if ((buflist->stream_a == STDIN_FILENO) ||
			(buflist->stream_a == STDOUT_FILENO) ||
			(buflist->stream_a == STDERR_FILENO) ||
			(buflist->stream_in == STDIN_FILENO) ||
			(buflist->stream_in == STDOUT_FILENO) ||
			(buflist->stream_in == STDERR_FILENO))
			save_dup_std(buflist);
		buflist = buflist->next;
	}
}

void		stream_save_std(t_red_stream *stream_list)
{
	if (stream_list)
		find_save(stream_list);
}
