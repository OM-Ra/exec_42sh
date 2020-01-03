/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:39:24 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 12:41:09 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				len;
	unsigned int	nbr;

	if (n < 0)
	{
		nbr = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nbr = n;
	len = ft_digitint(nbr);
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		while (len >= 1)
		{
			ft_putchar_fd((nbr / len + '0'), fd);
			nbr %= len;
			len /= 10;
		}
}
