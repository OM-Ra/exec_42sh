/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:03:51 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 21:00:07 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	put_error_fd(int error_fd)
{
	ft_putstr_fd(STR_ERR_SHELL, STDERR_FILENO);
	ft_putnbr_fd(error_fd, STDERR_FILENO);
	ft_putstr_fd(": invalid descriptor\n", STDERR_FILENO);
}

static int	error_fd(int fd_a, int fd_in)
{
	if (dup2(fd_a, fd_a) < 0)
		put_error_fd(fd_a);
	else
		put_error_fd(fd_in);
	return (1);
}

static int	find_redirect_fd(t_red_stream *list)
{
	t_red_stream *buflist;

	buflist = list->prev;
	while (buflist)
	{
		if (buflist->stream_a == list->stream_in)
		{
			if (buflist->stream_in > -1)
				list->stream_in = buflist->stream_in;
			else if (buflist->fd_file > -1)
				list->stream_in = buflist->fd_file;
			break ;
		}
		buflist = buflist->prev;
	}
	return (list->stream_in);
}

static int	dup_stream(t_red_stream *buf_list)
{
	int oldfd;

	if (buf_list->stream_name[0])
	{
		oldfd = (buf_list->flag_file > 0) ? buf_list->stream_a :
		buf_list->stream_in;
		if (create_file(buf_list) > -1)
			if (exec_dup_stream(oldfd, buf_list->fd_file))
				return (error_fd(oldfd, buf_list->fd_file));
	}
	else if (exec_dup_stream(buf_list->stream_a, find_redirect_fd(buf_list)))
		return (error_fd(buf_list->stream_a, buf_list->stream_in));
	return (0);
}

int			redirect_stream(t_red_stream *stream_list)
{
	t_red_stream	*buf_list;

	buf_list = stream_list;
	while (buf_list)
	{
		if (buf_list->flag_close)
		{
			if (stream_close_fd(buf_list))
				return (1);
		}
		else if ((buf_list->flag_file != -2) && dup_stream(buf_list))
			return (1);
		buf_list = buf_list->next;
	}
	return (0);
}
