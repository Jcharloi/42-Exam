/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:08:39 by jcharloi          #+#    #+#             */
/*   Updated: 2017/10/21 18:05:06 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void*))
{
	t_list	*list_ptr;
	
	list_ptr = begin_list;
	while (list_ptr != NULL)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

