/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_and_open_std.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 19:51:00 by mdelphia          #+#    #+#             */
/*   Updated: 2020/02/02 19:51:02 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

static void	open_std(void)
{
	new_or_open_file("/dev/fd/0", 1);
	new_or_open_file("/dev/fd/1", 1);
	new_or_open_file("/dev/fd/2", 1);
}

static void	close_std(void)
{
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void		close_and_open_std(void)
{
	close_std();
	open_std();
}
