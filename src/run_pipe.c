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
// код потомка
static void		cod_child(t_exec execlist, t_pipe_list **pipelist, t_pars_list *list)
{
	t_pipe_list *buf_pipelist;

	buf_pipelist = ((*pipelist)->left) ? (*pipelist)->left : (*pipelist);
	if (list->flag_pipe)
		dup_fd_and_close((*pipelist)->pfd[1], STDOUT_FILENO);
	else
		close((*pipelist)->pfd[1]);
	close((*pipelist)->pfd[0]);
	close_pipe_fd(*pipelist);
	stream_and_file(list);
	if (check_cmd(list->name_func))
	{
		stream_and_file(list);
		dup_fd_and_close(buf_pipelist->pfd[0], STDIN_FILENO);
		run_cmd(list);
		exit(list->status);
	}
	else
		run_exec(execlist, buf_pipelist->pfd[0], list);
}
// код родителя
static void		cod_parent(t_exec execlist, pid_t pid, t_pipe_list **pipelist, t_pars_list **list)
{
	t_pars_list *buf_list;

	buf_list = (*list);
	if ((buf_list->right) && (buf_list->flag_pipe))
	{
		(*list) = (*list)->right;
		run_pipe(execlist, pipelist, list);
	}
	close_all_fd(*pipelist);
	waitpid(pid, &buf_list->status, WUNTRACED);
	error_system(buf_list->status);
}
// рекурсивно запускает трубы
void			run_pipe(t_exec execlist, t_pipe_list **pipelist, t_pars_list **list)
{
	pid_t		pid;

	(*pipelist) = new_pipe_list(*pipelist);
	pipe((*pipelist)->pfd);
	if((pid = fork()) < 0)
		error_system(EXEC_ERROR_NUM);
	if (!pid)
		cod_child(execlist, pipelist, (*list));
	cod_parent(execlist, pid, pipelist, list);
}
