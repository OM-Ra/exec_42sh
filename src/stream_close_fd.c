/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stream_close_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:04:35 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 21:00:07 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	error_fd(int fd)
{
	ft_putstr_fd(STR_ERR_SHELL, STDERR_FILENO);
	ft_putnbr_fd(fd, STDERR_FILENO);
	ft_putstr_fd(": invalid descriptor\n", STDERR_FILENO);
	return (1);
}

static int	error_name(char *stream_name)
{
	ft_putstr_fd(STR_ERR_SHELL, STDERR_FILENO);
	ft_putchar_fd('\'', STDERR_FILENO);
	ft_putstr_fd(stream_name, STDERR_FILENO);
	ft_putstr_fd("': No such file or directory\n", STDERR_FILENO);
	return (1);
}

static int	find_file(t_red_stream *stream_list)
{
	t_red_stream *buflist;

	buflist = stream_list->prev;
	while (buflist)
	{
		if (!ft_strcmp(buflist->stream_name, stream_list->stream_name))
		{
			if (close(buflist->stream_a) == -1)
				return (error_fd(buflist->stream_a));
			return (0);
		}
		buflist = buflist->prev;
	}
	return (error_name(stream_list->stream_name));
}

int			stream_close_fd(t_red_stream *stream_list)
{
	if (stream_list->stream_name[0])
		return (find_file(stream_list));
	else if (close(stream_list->stream_a) == -1)
		return (1);
	return (0);
}
