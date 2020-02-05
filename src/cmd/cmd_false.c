#include "sh42.h"

int		cmd_false(t_pars_list *list)
{
	list->status = 1;
	return (exec_status = 1);
}
