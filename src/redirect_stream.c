/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:03:51 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 14:03:53 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// вывод об ошибке неисправного дескриптора
static void put_error_fd(int error_fd)
{
	ft_putstr_fd("42sh: ", 2);
	ft_putnbr_fd(error_fd, 2);
	ft_putstr_fd(": invalid descriptor\n", 2);
}
// поиск неисправного дескриптора
static int	error_fd(int fd_a, int fd_in)
{
	if (dup2(fd_a, fd_a) < 0)
		put_error_fd(fd_a);
	else
		put_error_fd(fd_in);
	return (1);
}
// поиск перенаправленного дескриптора
static int	find_redirect_fd(t_red_stream *list)
{
	t_red_stream *buflist;

	buflist = list->left;
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
		buflist = buflist->left;
	}
	return (list->stream_in);
}
// перенаправляет потоки из листов
static int	dup_stream(t_red_stream *buf_list)
{
	if (buf_list->stream_name[0])
	{
		if (create_file(buf_list) > -1)
			if (dup_fd_and_close(buf_list->stream_a, buf_list->fd_file))
				return (error_fd(buf_list->stream_a, buf_list->fd_file));
	}
	else if (dup_fd_and_close(buf_list->stream_a, find_redirect_fd(buf_list)))
		return (error_fd(buf_list->stream_a, buf_list->stream_in));
	return(0);
}
// листает список с дескрипторами для перенаправления
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
		else if (dup_stream(buf_list))
			return (1);
		buf_list = buf_list->next;
	}
	return (0);
}
