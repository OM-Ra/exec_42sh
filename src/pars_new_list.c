/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_new_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:02:28 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 14:02:30 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static t_pars_list	*create_list(void)
{
	t_pars_list *new_list;

	if (!(new_list = (t_pars_list *)malloc(sizeof(t_pars_list))))
		error_system(EXEC_ERROR_NUM);
	new_list->name_func[0] = '\0';
	new_list->name_run_func[0] = '\0';
	new_list->pars_args[0] = NULL;
	new_list->status = 0;
	new_list->stream_list = NULL;
	new_list->str_status = NULL;
	new_list->str_lastpid = NULL;
	new_list->f_delimiter = 0;
	new_list->right = NULL;
	new_list->left = NULL;
	return (new_list);
}

t_pars_list			*pars_new_list(t_pars_list *list)
{
	t_pars_list *new_list;

	new_list = create_list();
	if (!list)
		return (new_list);
	new_list->left = list;
	list->right = new_list;
	return (new_list);
}
