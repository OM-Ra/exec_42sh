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
// функция завершения выволнения рекурсии
static void	end_recurs(int fd_stdin, t_pars_list **list, int pfd[2])
{
	close(pfd[0]);
	close(pfd[1]);
	create_file(*list);							// если вывод будет в файл
	// if ()									// запуск внутренних команд
	//
	// else		
	run_exec(fd_stdin, *list);					// запуск системных команд
}
// функция с родительским кодом
static int	go_recurs(int pfd[2], t_pars_list **list)
{
	int status;

	if ((*list) && ((*list)->flag_pipe))	// когда трубы продолжаются
	{
		(*list) = (*list)->right;
		status = run_pipe(pfd[0], list);
	}
	close(pfd[0]);
	close(pfd[1]);
	return (status);
}
// рекурсивно запускает трубы
int			run_pipe(int fd_stdin, t_pars_list **list)
{
	int			pfd[2];
	pid_t		pid;
	t_pars_list	*buf_list;
	int			status;

	status = 0;
	buf_list = (*list);
	pipe(pfd);
	if ((!(pid = fork())) && (*list) && (!((*list)->flag_pipe) ||	// конец труб
			(*list)->flag_semicolon))								// или команды разделены " ; "
		end_recurs(fd_stdin, list, pfd);
	if (!pid)														// процесс потомок
	{
		dup_fd_and_close(pfd[1], STDOUT_FILENO);
		// if () 													// запуск внутренних команд
		//
		// else
		run_exec(fd_stdin, (*list));								// запуск системных команд
	}
	else if (pid > 0)
	{
		status = go_recurs(pfd, list);
		waitpid(pid, &buf_list->status, WUNTRACED);
	}
	if (status > buf_list->status)
		return (status);
	return (buf_list->status);
}
