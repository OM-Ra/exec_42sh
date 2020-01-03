/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ulli_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:20:31 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/23 16:20:33 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int	ft_digitlli(unsigned long long int nb)
{
	unsigned long long int digit;

	digit = 1;
	while (nb / digit)
		digit *= 10;
	digit /= 10;
	return (digit);
}

void							ft_put_lli_nbr(long long int nbr)
{
	unsigned long long int	nb;
	unsigned long long int	digit;
	char					buf[21];
	size_t					i;

	i = 0;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	digit = ft_digitlli(nb);
	while (digit)
	{
		buf[i++] = nb / digit + '0';
		nb %= digit;
		digit /= 10;
	}
	buf[i] = '\0';
	ft_putstr(buf);
}
