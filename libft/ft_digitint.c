/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:39:36 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/12 11:39:39 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long int	ft_digitint(unsigned int n)
{
	unsigned long int	digit;

	digit = 1;
	while ((n / digit))
		digit *= 10;
	digit /= 10;
	return (digit);
}
