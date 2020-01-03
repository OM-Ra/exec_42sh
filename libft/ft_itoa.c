/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 10:38:36 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 10:38:41 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null(void)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*ft_write(int n, char *str)
{
	unsigned long int	digit;
	unsigned int		nbr;
	size_t				i;

	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		nbr = -n;
	}
	else
		nbr = n;
	digit = ft_digitint(nbr);
	while (digit >= 1)
	{
		str[i] = (nbr / digit) + '0';
		nbr %= digit;
		digit /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_itoa(int n)
{
	char				*str;
	unsigned int		nbr;

	if (n == 0)
		return (str = ft_null());
	if (n < 0)
		nbr = -n;
	else
		nbr = n;
	if (!(str = (char *)malloc(sizeof(char) * (ft_lenint(nbr) + 2))))
		return (NULL);
	return (ft_write(n, str));
}
