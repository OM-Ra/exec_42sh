/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:37:50 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/08 16:37:52 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static	void	write_status(char	**str_status)
{
	size_t	i;

	i = 0;
	while (str_status[i])
	{
		ft_strcat(str_status[i], ft_itoa(exec_status));
		i++;
	}
}

void	cmd_echo_status(t_pars_list *list)
{
	if (list->echo_status)
		write_status(list->str_status);
}
