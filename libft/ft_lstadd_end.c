/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelphia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:43:01 by mdelphia          #+#    #+#             */
/*   Updated: 2019/04/25 13:43:03 by mdelphia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_end(t_list **alst, t_list *new)
{
	if (!new && (alst && *alst))
		return (*alst);
	else if ((!alst || !*alst) && new)
		return (new);
	else if ((!alst || !*alst) && !new)
		return (NULL);
	(*alst)->next = new;
	return (new);
}
