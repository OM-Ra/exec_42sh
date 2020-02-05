/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_system.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:21:09 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 19:21:11 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

void		error_system(int status)
{
	if (status == EXEC_ERROR_NUM)
		exit((exec_status = EXEC_ERROR_NUM));
}
