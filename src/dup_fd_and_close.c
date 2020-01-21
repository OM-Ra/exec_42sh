/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_fd_and_close.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:42:17 by mdelphia          #+#    #+#             */
/*   Updated: 2019/12/10 11:42:19 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"
// вывод ошибки дескриптора файла
int		error_deskriptor(int fd)
{
	ft_putstr_fd("42sh: fd = ", 2);
	ft_putnbr_fd(fd, 2);
	ft_putstr_fd(": invalid file descriptor\n", 2);
	return (1);
}
// для дублирования дескрипторов
int		dup_fd_and_close(int fd, int dup_fd)
{
	if (fd != dup_fd)
	{
		dup2(fd, dup_fd);
		close(fd);
	}
	return (0);
}
