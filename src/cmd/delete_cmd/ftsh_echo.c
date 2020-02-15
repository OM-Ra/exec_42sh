#include "sh42.h"

int						ftsh_echo(int argc, char **argv, char **env)
{
	ft_putstr_fd("echo\n", STDOUT_FILENO);
	return (0);
}
