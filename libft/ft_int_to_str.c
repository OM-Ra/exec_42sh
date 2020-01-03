/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 12:01:02 by mdelphia          #+#    #+#             */
/*   Updated: 2019/07/23 12:01:06 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_int_to_str(int nbr)
{
	char			*str;
	unsigned long	digit;
	unsigned int	nb;
	size_t			i;

	i = 0;
	if (!(str = ft_strnew((size_t)(ft_lenint(nbr)))))
		return (NULL);
	if (nbr < 0)
	{
		str[i++] = '-';
		nb = -nbr;
	}
	else
		nb = nbr;
	digit = ft_digitint(nb);
	while (digit)
	{
		str[i++] = nb / digit + '0';
		nb %= digit;
		digit /= 10;
	}
	str[i] = '\0';
	return (str);
}
