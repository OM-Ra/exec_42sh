#include "sh42.h"

static int 	cod_parent(int pid, char *str, int *pfd)
{
	size_t	len;
	char 	buf[BUFSIZ];
	int		status;

	close(pfd[1]);
	while ((len = read(pfd[0], buf, (BUFSIZ - 1))))
	{
		buf[len] = '\0';
		ft_strcat(str, buf);
	}
	close(pfd[0]);
	waitpid(pid, &status, WUNTRACED);
	return (status);
}

static void		cod_chuild(t_exec_lst execlist, char **arg_cmd, int *pfd)
{
	extern char	**environ;	///// заменить на массив из execlist
	t_pars_list	list;
	char 		buf_name_cmd[BUFSIZ];

	dup_fd_and_close(STDOUT_FILENO, pfd[1]);
	dup_fd_and_close(STDERR_FILENO, pfd[1]);
	pars_find_run_name(execlist, arg_cmd[0], buf_name_cmd);
	close(pfd[0]);
	if (check_cmd(arg_cmd[0]))
	{
		ft_strcat(list.name_func, arg_cmd[0]);
		list.status = 0;
		run_cmd(&list);
		exit(list.status);
	}
	execve(buf_name_cmd, arg_cmd, environ);
}

int 			pars_run_cmd(t_exec_lst execlist, char **arg_cmd, char *str)
{
	pid_t	pid;
	int 	pfd[2];

	pipe(pfd);
	if ((pid = fork()) < 0)
		error_system(EXEC_ERROR_NUM);
	if (!pid)
		cod_chuild(execlist, arg_cmd, pfd);
	return (cod_parent(pid, str, pfd));
}
