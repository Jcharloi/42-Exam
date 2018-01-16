/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:45:36 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/16 18:35:34 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		is_operateur(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '%' || str[i] == '/')
	{
		if (ft_isdigit(str[i + 1]) == 0)
			return (1);
	}
	return (0);
}

long		*rpn_calc(char *str)
{
	long	*tab;
	int		i;
	int		j;
		
	i = 0;
	j = 0;
	if (!(tab = (long*)malloc(sizeof(long) * ft_strlen(str))))
		return (NULL);
	while (str[i] != '\0')
	{
		while (is_operateur(str + i) == 0)
		{
			tab[j] = atoi(str + i);
			j++;
			while (str[i] != '\0' && str[i] != ' ')
				i++;
			if (str[i] == '\0')
			{
				printf("Error\n");
				return (NULL);
			}
			while (str[i] == ' ')
				i++;
		}
		if (j < 2)
		{
			printf("Error\n");
			return (NULL);
		}
		if (str[i] == '/')
		{
			if (tab[j - 1] == 0)
			{
				printf("Error\n");
				return (NULL);
			}
			tab[j - 2] = tab[j - 2] / tab[j - 1];
		}
		else if (str[i] == '-')
			tab[j - 2] = tab[j - 2] - tab[j - 1];
		else if (str[i] == '+')
			tab[j - 2] = tab[j - 2] + tab[j - 1];
		else if (str[i] == '*')
			tab[j - 2] = tab[j - 2] * tab[j - 1];
		else if (str[i] == '%')
		{
			if (tab[j - 1] == 0)
			{
				printf("Error\n");
				return (NULL);
			}
			tab[j - 2] = tab[j - 2] % tab[j - 1];
		}
		j--;
		i++;
		while (str[i] == ' ')
			i++;
	}
	if (j > 1)
	{
		printf("Error\n");
		return (NULL);
	}
	return (tab);
}

int		main(int argc, char **argv)
{
	long	*tab;

	if (argc == 2 && argv[1][0] != '\0')
	{
		tab = rpn_calc(argv[1]);
		if (tab != NULL)
			printf("%ld\n", tab[0]);
		return (0);
	}
	printf("Error\n");
	return (0);
}
