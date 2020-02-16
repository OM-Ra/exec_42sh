/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_check_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:37:50 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/08 16:37:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void	write_str_var(char	**str_var)
{
	size_t	i;

	i = 0;
	while (str_var && str_var[i])
	{
		ft_strcpy(str_var[i], ft_itoa(exec_status));
		i++;
	}
}

void		cmd_check_var(t_pars_list *list)
{
	if (list->f_delimiter & V_STATUS)
		write_str_var(list->str_status);
	if (list->f_delimiter & V_LASTPID)
		write_str_var(list->str_lastpid);
}
