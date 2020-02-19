/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_fill_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:04:02 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/16 22:04:04 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void find_last_args(t_pars_list *list, char *bufstr)
{
	size_t	i;

	i = 0;
	while (list->pars_args[i])
		i++;
	list->pars_args[i++] = ft_strdup(bufstr);
	list->pars_args[i] = NULL;
}

char 		*pars_fill_args(t_pars_list *list, char *pointstr,  char *end)
{
	char	bufstr[ARG_MAX];
	size_t	i;

	i = 0;
	while ((pointstr < end) && (*pointstr != -1))
			bufstr[i++] = *(pointstr++);
	bufstr[i] = '\0';
	find_last_args(list, bufstr);
	return (pointstr);
}
