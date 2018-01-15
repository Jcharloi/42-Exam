/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:12:14 by jcharloi          #+#    #+#             */
/*   Updated: 2017/10/21 19:04:18 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int sort_tab(int *tab, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	*sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int swap;
	
	swap = 0;
	while (sort_tab(tab, size))
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = swap;
			}
			i++;
		}
	}
	return (tab);
}
