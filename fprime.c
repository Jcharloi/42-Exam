/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:20:46 by jcharloi          #+#    #+#             */
/*   Updated: 2017/12/11 17:12:41 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     main(int ac, char **av)
{
    int     div = 2;
    int     nb;

    if (ac == 2)
    {
        nb = atoi(av[1]);
        if (nb <= 1)
        {
            printf("%d\n", nb);
            return (0);
        }
        while (nb != 1)
        {
        	if (nb % div == 0)
        	{
        		printf("%d\n", div);
        		nb = nb / div;
        		div = 2;
        	}
        	else
        		div++;
        }
    }
    printf("\n");
    return (0);
}
