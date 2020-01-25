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
static void		cod_child(t_pipe_list *pipelist, t_pars_list *list)
{
	t_pipe_list *buf_pipelist;

	buf_pipelist = (pipelist->left) ? pipelist->left : pipelist;
	if (list->flag_pipe)
		dup_fd_and_close(pipelist->pfd[1], STDOUT_FILENO);
	else
		close(pipelist->pfd[1]);
	close(pipelist->pfd[0]);
	close_pipe_fd(pipelist);
	create_file(list);
	run_exec(buf_pipelist->pfd[0], list);
}
// код родителя
static void		cod_parent(pid_t pid, t_pipe_list *pipelist, t_pars_list **list)
{
	t_pars_list *buf_list;

	buf_list = (*list);
	if ((buf_list->right) && (buf_list->flag_pipe))
	{
		(*list) = (*list)->right;
		run_pipe(pipelist, list);
	}
	close_all_fd(pipelist);
	waitpid(pid, &buf_list->status, WUNTRACED);
}
// рекурсивно запускает трубы
void			run_pipe(t_pipe_list *pipelist, t_pars_list **list)
{
	pid_t		pid;

	pipelist = new_pipe_list(pipelist);
	pipe(pipelist->pfd);
	if((pid = fork()) < 0)
		exit(1);		////// сделать нормальное завершение
	if (!pid)
		cod_child(pipelist, (*list));
	cod_parent(pid, pipelist, list);
}
