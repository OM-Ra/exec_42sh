/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:41:46 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:41:48 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// код потомка
static void	cod_child(t_exec execlist, t_pars_list **list)
{
	if (!stream_and_file(*list))
		run_exec(execlist, -1, (*list));
	else
		exit(1);
}
// запуск fork
static int	run_fork(struct s_exec execlist, t_pars_list **list)
{
	pid_t pid;

	if ((pid = fork()) < 0)
		error_system(EXEC_ERROR_NUM);	/// дописать нормальное завершение
	if (!pid)
		cod_child(execlist, list);
	waitpid(pid, &(*list)->status, WUNTRACED);
	error_system((*list)->status);
	exec_status = (*list)->status;
	return ((*list)->status);
}
// код запуска труб
static int	code_pipe(t_exec execlist, t_pars_list **list)
{
	int			status;
	t_pipe_list	**pipeList;
	t_pipe_list	*bufpipelist;

	bufpipelist = NULL;
	pipeList = &bufpipelist;
	run_pipe(execlist, pipeList, list);
	error_system((*list)->status);
	exec_status = (*list)->status;
	status = exec_status;
	free_pipe_list(*pipeList);
	return (status);
}
// определяет характер выполнения кода
int			check_run(t_exec execlist, t_pars_list **list)
{
	int			status;

	if ((*list)->flag_pipe)
		status = code_pipe(execlist, list);
	else if (check_cmd((*list)->name_func))						// дописсать вариант запуска внутренних команд
	{
		stream_and_file(*list);
		status = run_cmd(*list);
	}
	else
		status = run_fork(execlist, list);
	return (status);
}
