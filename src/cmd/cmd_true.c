#include "sh42.h"

int		cmd_true(t_pars_list *list)
{
	list->status = 0;
	return (exec_status = 0);
}
