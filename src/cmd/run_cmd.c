#include "sh42.h"
// поиск и запуск необходимой внутренней команды
static int	find_and_run_cmd(t_pars_list *list)
{
	if (!ft_strcmp("true", list->name_func))
		list->status = cmd_true(list);
	else if (!ft_strcmp("false", list->name_func))
		list->status = cmd_false(list);
	else if (!ft_strcmp("cd", list->name_func))
		list->status = ftsh_cd(0, NULL, NULL);	//////// замена
	else if (!ft_strcmp("echo", list->name_func))
	{
		cmd_write_status(list);
		list->status = ftsh_echo(0, NULL, NULL);	//////// замена
	}
	else if (!ft_strcmp("pwd", list->name_func))
		list->status = ftsh_pwd(0, NULL, NULL);	//////// замена
	else if (!ft_strcmp("setenv", list->name_func))
		list->status = ftsh_setenv(NULL, NULL, 0);	//////// замена
	else if (!ft_strcmp("unsetenv", list->name_func))
		list->status = ftsh_unsetenv(NULL);	//////// замена
	else if (!ft_strcmp("env", list->name_func))
		list->status = minishell_env(0, NULL, NULL);	//////// замена
	return (exec_status = list->status);
}

int			run_cmd(t_pars_list *list)
{
	return (find_and_run_cmd(list));
}
