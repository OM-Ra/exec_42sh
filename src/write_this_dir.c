/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_this_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:36:29 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/16 19:36:32 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// проверяет запускаемую команду в текущей директории
int			write_this_dir(t_pars_list *list)
{
	ft_strcpy(list->name_run_func, "./");
	ft_strcat(list->name_run_func, list->name_func);
	if (!access(list->name_run_func, 0))
		if (!access(list->name_run_func, 1))
			return (1);
	return (0);
}
