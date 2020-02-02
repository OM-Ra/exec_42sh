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
// вывод об ошибке запуска программы если команда не найдена
static void	error_run_exec(t_pars_list *list)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putstr_fd(list->name_func, 2);
	ft_putchar_fd('\n', 2);
	exec_status = 127;
	exit(127);
}
// вывод об ошибке если доступ к запуску команды не разрешён
static void error_access_exec(t_pars_list *list)
{
	ft_putstr_fd("42sh: command not access: ", 2);
	ft_putstr_fd(list->name_func, 2);
	ft_putchar_fd('\n', 2);
	exec_status = 126;
	exit(126);
}
// записывает адрес и имя функции для запуска
static void	find_name_path(char *name_path, size_t *i, t_pars_list *list)
{
	size_t j;

	j = 0;
	while (name_path[*i])
	{
		if (name_path[*i] == ':')
		{
			(*i)++;
			break ;
		}
		list->name_run_func[j++] = name_path[(*i)++];
	}
	list->name_run_func[j] = '\0';
	ft_strcat(list->name_run_func, "/");
	ft_strcat(list->name_run_func, list->name_func);
}
// запись имени функции с путём запуска
static void	write_name_run(t_exec execlist, t_pars_list *list)
{
	size_t	i;

	i = 0;
	while (execlist.exec_envlist.path[i])
	{
		find_name_path(execlist.exec_envlist.path, &i, list);
		if (!access(list->name_run_func, 0))
		{
			if (!access(list->name_run_func, 1))
				return ;
			else
				error_access_exec(list);
		}
	}
	error_run_exec(list);
}
// запуск нового приложения
void		run_exec(t_exec execlist, int fd, t_pars_list *list)
{
	extern char	**environ;

	if (fd > -1)							// если необходимо изменить поток чтения
		dup_fd_and_close(fd, STDIN_FILENO);
	write_name_run(execlist, list);
	if (execve(list->name_run_func, list->pars_args, environ))
		error_run_exec(list);
}
