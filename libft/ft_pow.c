/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:39:21 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/29 12:03:01 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_pow(int b, int p)
{
	long double	res;
	long double	a;

	res = 1;
	a = (long double)b;
	if (p < 0 || a == 0)
		return (0);
	while (p > 0)
	{
		if (!(p % 2))
		{
			a *= a;
			p /= 2;
		}
		else
		{
			res *= a;
			p--;
		}
		if (ft_llintlimit(res))
			return (0);
	}
	return (res);
}
