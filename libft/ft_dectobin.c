/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectobin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:37:04 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/29 12:01:46 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_dectobin(int a)
{
	long long int	res;
	long long int	num;
	int				i;

	res = 0;
	i = 0;
	num = (long long int)a;
	while (num && i <= 19)
	{
		if (num < 2)
		{
			res = res * 10 + 1;
			return (res);
		}
		res = (res * 10) + (num % 2);
		num /= 2;
		i++;
	}
	if (i > 19)
		return (-1);
	return (res);
}
