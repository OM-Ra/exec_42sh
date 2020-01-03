/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 11:54:52 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/23 11:54:56 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lenint(unsigned int nbr)
{
	unsigned int		i;
	unsigned long		digit;

	i = 0;
	digit = 1;
	if (nbr == 0)
		return (1);
	while ((nbr / digit))
	{
		digit *= 10;
		i++;
	}
	return (i);
}
