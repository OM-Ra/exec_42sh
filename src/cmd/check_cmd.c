#include "sh42.h"
// заполянет буфер символом
static void write_character(char *buf, char sim)
{
	buf[0] = sim;
	buf[1] = '\0';
}
// проверяет наличие внутренних команд в листе
static int	check_name_cmd(t_pars_list *list)
{
	if (!(ft_strcmp("true", list->name_func)) ||
		!(ft_strcmp("false", list->name_func)) ||
		!(ft_strcmp("cd", list->name_func)) ||
		!(ft_strcmp("echo", list->name_func)) ||
		!(ft_strcmp("pwd", list->name_func)) ||
		!(ft_strcmp("setenv", list->name_func)) ||
		!(ft_strcmp("unsetenv", list->name_func)) ||
		!(ft_strcmp("env", list->name_func)))
		return (1);
	return (0);
}
// проверяет наличие первого символа внутренних команд в листе
int			check_cmd(t_pars_list *list)
{
	char buf[2];

	write_character(buf, list->name_func[0]);
	if (!(ft_strcmp("t", buf)) || !(ft_strcmp("f", buf)) ||
		!(ft_strcmp("c", buf)) || !(ft_strcmp("e", buf)) ||
		!(ft_strcmp("p", buf)) || !(ft_strcmp("s", buf)) ||
		!(ft_strcmp("u", buf))) // true, false, cd, echo, pwd, setenv, unsetenv, env
		return (1);
	return (0);
}
