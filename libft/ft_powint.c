/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:40:18 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/29 11:40:22 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_powint(int b, int p)
{
	long long int	res;

	res = ft_pow(b, p);
	if (ft_intlimit(res))
		return (0);
	return ((int)res);
}
