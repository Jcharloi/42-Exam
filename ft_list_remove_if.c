/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:12:02 by exam              #+#    #+#             */
/*   Updated: 2017/12/11 14:28:04 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"
#include <stdio.h>

int cmp(void *data, void *data_ref)
{
	int *i = data;
	int *j = data_ref;

	if (*i == *j)
		return (0);
	return (1);
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;
	t_list *tmp;
	int i = 0;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	tmp = *begin_list;
	while ((*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = (*begin_list)->next;
		free(*begin_list);
		(*begin_list) = tmp;
	}
	lst = *begin_list;
	tmp = *begin_list;
	while (lst != NULL)
	{
		if ((*cmp)(lst->data, data_ref) == 0)
		{
			tmp->next = lst->next;
			free(lst);
			lst = tmp;
			i = 0;
		}
		if (i > 0)
			tmp = tmp->next;
		if (lst != NULL)
			lst = lst->next;
		i++;
	}
}

int main(void)
{
	t_list *lst;
	int i = 1;
	int j = 2;

	lst = (t_list*)malloc(sizeof(t_list));
	lst->data = &j;
	lst->next = (t_list*)malloc(sizeof(t_list));
	lst->next->data = &j;
	lst->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->data = &i;
	lst->next->next->next = (t_list*)malloc(sizeof(t_list));
	lst->next->next->next->data = &i;
	lst->next->next->next->next =  NULL;

	ft_list_remove_if(&lst, &j, cmp);

	while (lst != NULL)
	{
		printf("%d\n", *(int*)lst->data);
		lst = lst->next;
	}

	return (0);
}

