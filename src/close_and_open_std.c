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

static void	open_new_std(char *path_name, int fd_std)
{
	close(fd_std);
	open(path_name, O_RDWR);
}

static void	redirect_std(int save_fd)
{
	char *path_name;

	path_name = ttyname(save_fd);
	open_new_std(path_name, STDIN_FILENO);
	open_new_std(path_name, STDOUT_FILENO);
	open_new_std(path_name, STDERR_FILENO);
}

static void	find_std(t_red_stream *stream_list)
{
	t_red_stream	*buflist;

	buflist = stream_list;
	while (buflist)
	{
		if ((buflist->save_fd > -1) && (isatty(buflist->save_fd)))
		{
			redirect_std(buflist->save_fd);
			break ;
		}
		buflist = buflist->next;
	}
}

void		close_and_open_std(t_red_stream *stream_list)
{
	if (stream_list)
		find_std(stream_list);
}
