/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirect_heredoc.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 16:30:50 by mdelphia          #+#    #+#             */
/*   Updated: 2020/04/07 13:17:15 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int			add_param_for_heredoc(t_exec_lst *execlist,
						t_red_stream *buf_list, char *line)
{
	int fd;

	fd = new_or_open_file(execlist->path_heredoc, 1);
	ft_putstr_fd(line, fd);
	exec_dup_stream(STDIN_FILENO, fd);
	return (fd);
}

static int			go_heredoc(t_exec_lst *execlist, t_red_stream *buf_list)
{
	char *line;

	if ((line = input_heredoc(execlist, buf_list->stream_name)))
		buf_list->fd_file = add_param_for_heredoc(execlist, buf_list, line);
	else
		return (1);
	return (0);
}

static t_red_stream	*check_heredoc(t_red_stream *stream_list)
{
	while (stream_list)
	{
		if (stream_list->flag_file == -2)
			return (stream_list);
		stream_list = stream_list->next;
	}
	return (NULL);
}

static void			heredoc_in_cycle(t_exec_lst *execlist,
						t_red_stream *buf_list)
{
	int tmp_fd;

	while (buf_list)
	{
		if (go_heredoc(execlist, buf_list))
			break ;
		tmp_fd = buf_list->save_std;
		buf_list = buf_list->next;
		if ((buf_list = check_heredoc(buf_list)))
			close(tmp_fd);
	}
}

void				exec_redirect_heredoc(t_exec_lst *execlist,
						t_pars_list *list)
{
	t_red_stream	*buf_list;

	if ((buf_list = check_heredoc(list->stream_list)))
	{
		if (check_cmd(list->name_func))
		{
			buf_list->save_std = dup(STDIN_FILENO);
			buf_list->stream_a = STDIN_FILENO;
		}
		heredoc_in_cycle(execlist, buf_list);
	}
}
