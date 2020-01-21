#include "sh42.h"

static char	*error_big_line(void)
{
	ft_putstr_fd("42sh: long line\n", 2);
	return (NULL);
}
// читает строку с терминала длиной BUFSIZ
char		*pars_read(void)
{
	char	buf[BUFSIZ];
	size_t	len;

	if ((len = read(1, buf, BUFSIZ)) == BUFSIZ)
		return (error_big_line());
	buf[len] = '\0';
	if (!ft_strcmp(buf, "exit\n"))
		exit(0);
	return (ft_strdup(buf));
//	return (ft_strdup("ls -l && pwd"));
}
