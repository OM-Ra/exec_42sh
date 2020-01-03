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
// запуск fork
static int	run_fork(t_pars_list **list)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		if (create_file(*list) < 0)
			exit(1);
		run_exec(-1, *list);
	}
	else if (pid > 0)
		waitpid(pid, &(*list)->status, WUNTRACED);
	return ((*list)->status);
}
// определяет характер выполнения кода
int		check_run(t_pars_list **list)
{
	int status;
	// дописсать вариант запуска внутренних команд
	if ((*list)->flag_pipe)
		status = run_pipe(-1, list);
	else
		status = run_fork(list);
	return (status);
}
