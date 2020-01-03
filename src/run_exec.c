/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:49 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:42:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// вывод об ошибке запуска программы
static void	error_run_exec(t_pars_list *list)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putstr_fd(list->name_run_func, 2);
	ft_putchar_fd('\n', 2);
	exit(127);
}
// запуск нового приложения
void		run_exec(int fd, t_pars_list *list)
{
	extern char	**environ;

	if (fd > -1)							// если необходимо изменить поток чтения
		dup_fd_and_close(fd, STDIN_FILENO);
	if (execve(list->name_run_func, list->pars_args, environ))
		error_run_exec(list);
}
