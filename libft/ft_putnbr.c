/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:35:28 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 11:35:33 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_writenbr(unsigned int nbr, int flag)
{
	unsigned long int	len;
	char				*str;
	char				*buf;

	if (!(buf = ft_strnew(11)))
		return (NULL);
	len = ft_digitint(nbr);
	str = buf;
	if (flag)
		*str++ = '-';
	while (len >= 1)
	{
		*str++ = (nbr / len + '0');
		nbr %= len;
		len /= 10;
	}
	return (buf);
}

void		ft_putnbr(int n)
{
	unsigned int		nbr;
	char				*buf;
	int					flag;

	buf = NULL;
	flag = 0;
	if (n < 0)
	{
		flag = 1;
		nbr = -n;
	}
	else
		nbr = n;
	if (n == 0)
		ft_putchar('0');
	else
		ft_putstr((buf = ft_writenbr(nbr, flag)));
	if (buf)
		free(buf);
}
