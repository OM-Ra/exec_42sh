/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proba_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:13:51 by mdelphia          #+#    #+#             */
/*   Updated: 2020/01/22 17:22:13 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

int			proba_pipe(int *fd_stdin, t_pars_list **list)
{
	int			pfd[2];
	pid_t		pid;
	t_pars_list	*buf_list;
	int			status;

	status = 0;
	buf_list = (*list);
	(*list) = (*list)->right;
	if (pipe(pfd) < 0)
		exit(1);
	pid = fork();
	if (/*!(pid = fork()) && */(!(buf_list->flag_pipe) ||
			buf_list->flag_semicolon || !(*list)))
	{
		close(pfd[0]);
		close(pfd[1]);
		run_exec(fd_stdin[0], buf_list);
	}
	else if (!pid)
	{
		if (fd_stdin[1] > 0)
			close(fd_stdin[1]);
		dup_fd_and_close(pfd[1], STDOUT_FILENO);
		//////////// код для внутренних программ
		run_exec(fd_stdin[0], buf_list);
	}
	else if(pid > 0)
	{
		if ((*list) && (*list)->flag_pipe)
			status = proba_pipe(pfd, list);
		close(pfd[0]);
		close(pfd[1]);
		waitpid(pid, &buf_list->status, WUNTRACED);
	}
	if (status > buf_list->status)
		return (status);
	return (status);
}
