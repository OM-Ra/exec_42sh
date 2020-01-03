/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 09:50:09 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/21 09:50:13 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterror(int fd, char *str, int er)
{
	if (str)
		ft_putstr_fd(str, fd);
	else
		ft_putstr_fd("error\n", fd);
	return (er);
}
