/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bintodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:36:17 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/29 12:00:39 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bintodec(int a)
{
	long double	res;
	int			i;

	res = 0;
	i = 0;
	while (a)
	{
		res += (long double)((a % 10) * ft_powint(2, i));
		a /= 10;
		i++;
		if (ft_intlimit(res))
			return (0);
	}
	return (res);
}
