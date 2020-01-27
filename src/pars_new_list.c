#include "sh42.h"

static t_pars_list	*error_list(void)
{
	ft_putstr_fd("42sh: error malloc\n", 2);
	return (NULL);
}

static t_pars_list	*create_list(void)
{
	t_pars_list *new_list;

	if (!(new_list = (t_pars_list *)malloc(sizeof(t_pars_list))))
		return (error_list());
	new_list->name_func[0] = '\0';
	new_list->name_run_func[0] = '\0';
	new_list->pars_args[0] = NULL;
	new_list->status = 0;
	new_list->stream_list = NULL;
	new_list->echo_status = 0;
	new_list->str_status[0][0] = '\0';
	new_list->flag_ampersant = 0;
	new_list->nbr_ampersant = 0;
	new_list->flag_pipe = 0;
	new_list->flag_semicolon = 0;
	new_list->flag_and = 0;
	new_list->flag_or = 0;
	new_list->right = NULL;
	new_list->left = NULL;
	return (new_list);
}

t_pars_list			*pars_new_list(t_pars_list *list)
{
	t_pars_list *new_list;

	if (!(new_list = create_list()))
		return (NULL);
	if (!list)
		return (new_list);
	new_list->left = list;
	list->right = new_list;
	return (new_list);
}
