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

static int	find_variable(char *pointstr, char *end)
{
		if (*pointstr == $ && (*pointstr - 1) != '\\')
			return (1);
	return (0);
}

static int	find_quotes(char *pointstr, char *end)
{
	if (pointstr < end && (*pointstr == '"' || *pointstr == '\'' ||
		*pointstr == '"'))
		return (1);
	return (0);
}

static void	find_endstr(char *bufstr, size_t &i)
{
	while (bufstr[*i])
		(*i)++;
}

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
	{
		if (find_quotes(pointstr, end))
		{	// "
			bufstr[i] = '\0';
			ft_strcat(&bufstr[i], );
			find_endstr(bufstr, &i);
		}
		else if (find_variable(pointstr, end))
		{	// $
			bufstr[i] = '\0';
			ft_strcat(&bufstr[i], );
			find_endstr(bufstr, &i);
		}
		else
			bufstr[i++] = *(pointstr++);
	}
	bufstr[i] = '\0';
	find_last_args(list, bufstr);
	return (pointstr);
}
