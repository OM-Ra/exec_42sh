/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_dollar_shift_args.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 03:51:19 by mdelphia          #+#    #+#             */
/*   Updated: 2020/04/10 23:28:30 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		pars_shift_args(char **pars_args, int i)
{
	while (pars_args[i])
	{
		pars_args[i] = pars_args[i + 1];
		++i;
	}
}

static char		**pars_get_point_args(char **pars_args, int i)
{
	char	**ptr;

	ptr = pars_args;
	while (*ptr && *ptr != pars_args[i])
	{
		++ptr;
		++i;
	}
	return (ptr);
}

char			**pars_dollar_shift_args(char **pars_args, int i)
{
	char	**ptr;

	pars_shift_args(pars_args, i);
	return(pars_get_point_args(pars_args, i));
}
