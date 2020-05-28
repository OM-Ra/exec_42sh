/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_befor_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:51:19 by mdelphia          #+#    #+#             */
/*   Updated: 2020/03/05 15:51:21 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	free_befor_exec(t_info_parser *prs)
{
	if (prs->beg)
		free_pars_list(&prs->beg);
	prs->beg = NULL;
	prs->end = NULL;
}
