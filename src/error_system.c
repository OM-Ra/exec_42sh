/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:21:09 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/29 20:50:28 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		error_system(t_exec_lst *execlist, int status)
{
	if (status == EXEC_ERROR_NUM)
		exit((execlist->sh_term_lst.exec_status = EXEC_ERROR_NUM));
}
