/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_open_std.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:51:00 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 19:51:02 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// открывает нужный поток
static void	open_std(t_red_stream *buflist, int find_std)
{
	int open_fd;

	close(find_std);
	open_fd = open(term_lst.path_term, O_RDWR);
	dup2(buflist->save_std, open_fd);
	close(buflist->save_std);
}
// ищет нужный поток
static void	check_std(t_red_stream *stream_list, int find_std)
{
	t_red_stream *buflist;

	buflist = stream_list;
	while (buflist)
	{
		if (buflist->stream_a == find_std)
		{
			open_std(buflist, find_std);
			break ;
		}
		buflist = buflist->next;
	}
}

static void	find_close_std(t_red_stream *stream_list)
{
	check_std(stream_list, STDIN_FILENO);
	check_std(stream_list, STDOUT_FILENO);
	check_std(stream_list, STDERR_FILENO);
}
// закрывает открытые дескрипторы
static void	close_jobs_fd(t_red_stream *stream_list)
{
	t_red_stream *buflist;

	buflist = stream_list;
	while (buflist)
	{
		if (buflist->save_std > -1)
			close(buflist->save_std);
		if ((buflist->fd_file > -1) && ((buflist->fd_file != STDIN_FILENO) &&
			(buflist->fd_file != STDOUT_FILENO) &&
			(buflist->fd_file != STDERR_FILENO)))
			close(buflist->fd_file);
		buflist = buflist->next;
	}
}

void		close_and_open_std(t_red_stream *stream_list)
{
	if (stream_list)
	{
		find_close_std(stream_list);
		close_jobs_fd(stream_list);
	}
}
