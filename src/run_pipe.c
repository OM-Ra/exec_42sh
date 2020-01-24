/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:43:00 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:43:03 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// подумать над тем как не закрывать нужные дескрипторы
// закрывает все дескрипторы трубы от заданного листа включительно
static void		close_all_fd(t_pipe_list *pipeList)
{
	t_pipe_list *buf_pipelist;

	buf_pipelist = pipeList;
	while (buf_pipelist)
	{
		close(buf_pipelist->pfd[0]);
		close(buf_pipelist->pfd[1]);
		buf_pipelist = buf_pipelist->left;
	}
}
// закрывает ненужные дескрипторы трубы
static void		close_pipe_fd(t_pipe_list *pipelist)
{
	t_pipe_list	*buf_pipelist;

	buf_pipelist = pipelist->left;
	if (buf_pipelist)
		close(buf_pipelist->pfd[1]);
	else
		return ;
	buf_pipelist = buf_pipelist->left;
	close_all_fd(buf_pipelist);
}
// рекурсивно запускает трубы
void			run_pipe(t_pipe_list *pipelist, t_pars_list **list)
{
	pid_t		pid;
	t_pars_list	*buf_list;
	t_pipe_list	*buf_pipelist;

	pipelist = new_pipe_list(pipelist);
	pipe(pipelist->pfd);
	buf_list = (*list);
	if((pid = fork()) < 0)
		exit(1);		////// сделать нормальное завершение
	if (!pid)
	{
		buf_pipelist = pipelist->left;
		if (buf_list->flag_pipe)
			dup_fd_and_close(pipelist->pfd[1], STDOUT_FILENO);
		else
			close(pipelist->pfd[1]);
		close(pipelist->pfd[0]);
		close_pipe_fd(pipelist);
		create_file(buf_list);
		run_exec(buf_pipelist->pfd[0], buf_list);
	}
	if ((buf_list->right) && (buf_list->flag_pipe))
	{
		(*list) = (*list)->right;
		run_pipe(pipelist, list);
	}
	close_all_fd(pipelist);
	waitpid(pid, &buf_list->status, WUNTRACED);
}
