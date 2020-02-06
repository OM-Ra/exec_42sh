#include "sh42.h"

void 		write_echo_status(char **str_status)
{
	size_t	i;

	i = 0;
	while (str_status[i])
	{
		ft_strcat(str_status[i], ft_itoa(exec_status));
		i++;
	}
}
// перед запуском echo заполняет статус
void 		cmd_write_status(t_pars_list *list)
{
	if (list->echo_status)
		write_echo_status(list->str_status);
}
