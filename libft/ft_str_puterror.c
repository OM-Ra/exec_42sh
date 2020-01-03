/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_puterror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:31:22 by mdelphia          #+#    #+#             */
/*   Updated: 2019/05/23 11:31:25 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_puterror(int fd, char *str)
{
	if (str)
		ft_putstr_fd(str, fd);
	else
		ft_putstr_fd("error\n", fd);
	return (NULL);
}
