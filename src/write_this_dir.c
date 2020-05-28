/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_this_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:36:29 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 20:38:23 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static int	exec_check_valid_file(t_pars_list *list)
{
	if (!access(list->name_run_func, 0))
		if (!access(list->name_run_func, 1))
			return (1);
	return (0);
}

int			write_this_dir(t_pars_list *list)
{
	ft_strcpy(list->name_run_func, list->name_func);
	if (exec_check_valid_file(list))
		return (1);
	ft_strcpy(list->name_run_func, "./");
	ft_strcat(list->name_run_func, list->name_func);
	if (exec_check_valid_file(list))
		return (1);
	return (0);
}
