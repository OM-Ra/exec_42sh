#include "sh42.h"

void		free_pipe_list(t_pipe_list *list)
{
	t_pipe_list		*buf_list;

	while (list)
	{
		buf_list = list;
		list = list->left;
		free(buf_list);
	}
}
