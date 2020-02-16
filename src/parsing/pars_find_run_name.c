/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_find_run_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:02:14 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/16 22:02:22 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void	error_run_exec(char *name_cmd)
{
	ft_putstr_fd("42sh: command not found: ", 2);
	ft_putstr_fd(name_cmd, 2);
	ft_putchar_fd('\n', 2);
	exit(127);
}
// вывод об ошибке если доступ к запуску команды не разрешён
static void error_access_exec(char *name_cmd)
{
	ft_putstr_fd("42sh: command not access: ", 2);
	ft_putstr_fd(name_cmd, 2);
	ft_putchar_fd('\n', 2);
	exit(126);
}
// записывает адрес и имя функции для запуска
static void	find_name_path(char *name_path, size_t *i, char *name_cmd, char *buf_name_cmd)
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
		buf_name_cmd[j++] = name_path[(*i)++];
	}
	buf_name_cmd[j] = '\0';
	ft_strcat(buf_name_cmd, "/");
	ft_strcat(buf_name_cmd, name_cmd);
}
// запись имени функции с путём запуска
void		pars_find_run_name(t_exec_lst execlist, char *name_cmd, char *buf_name_cmd)
{
	size_t	i;

	i = 0;
	while (execlist.exec_envlist.path[i])
	{
		find_name_path(execlist.exec_envlist.path, &i, name_cmd, buf_name_cmd);
		if (!access(buf_name_cmd, 0))
		{
			if (!access(buf_name_cmd, 1))
				return ;
			else
				error_access_exec(name_cmd);
		}
	}
	error_run_exec(name_cmd);
}

