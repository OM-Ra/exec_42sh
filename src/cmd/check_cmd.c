#include "sh42.h"

int			run_cmd(t_pars_list *list)
{
	if (!ft_strcmp("true", list->name_func))
		return (1);
	else if (!ft_strcmp("false", list->name_func))
		return (1);
	return (0);
}
