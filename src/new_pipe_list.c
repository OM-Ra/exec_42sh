#include "sh42.h"

t_pipe_list		*new_pipe_list(t_pipe_list *pipelist)
{
	t_pipe_list	*new_list;

	if(!(new_list = (t_pipe_list *)malloc(sizeof(t_pipe_list))))
		return (NULL);	////////// можно дописать глобальное завершение
	new_list->right = NULL;
	new_list->left = NULL;
	new_list->pfd[0] = -1;
	new_list->pfd[1] = -1;
	if (pipelist)
	{
		pipelist->right = new_list;
		new_list->left = pipelist;
	}
	return (new_list);
}
