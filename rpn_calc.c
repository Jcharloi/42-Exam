/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:45:36 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/15 20:27:37 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_operateur(char c)
{
	if (c == '*' || c == '+' || c == '-' || c == '%' || c == '/')
		return (1);
	return (0);
}

void	print_tab(int *tab, int len)
{
	int i = 0;

	while (i < len)
	{
		printf("tab[i] : %d\n", tab[i]);
		i++;
	}
	printf("\n");
}

void	rpn_calc(char *str)
{
	int	*tab;
	int		i;
	int		j;
		
	i = 0;
	j = 0;
	if (!(tab = (int*)malloc(sizeof(int) * ft_strlen(str))))
		return ;
	tab[j] = atoi(str);
	while (str[i] != '\0')
	{
		if (isdigit(str[i]) == 1)
		{
			tab[j] = atoi(str + i);
			print_tab(tab, 6);
			j++;
		}
		i++;
		if (is_operateur(str[i]) == 1)
		{
			printf("%d\n", j);
			if (str[i] == '+')
			{
				printf("j - 2 : %d et operateur : %c\n", tab[j - 2], str[i]);
				tab[j - 2] = tab[j - 2] + tab[j - 1];
				print_tab(tab, 3);
			}
			else if (str[i] == '*')
			{
				printf("j - 2 : %d et operateur : %c\n", tab[j - 2], str[i]);
				tab[j - 2] = tab[j - 2] * tab[j - 1];
				print_tab(tab, 3);
			}
			else if (str[i] == '/')
			{
				printf("j - 2 : %d et operateur : %c\n", tab[j - 2], str[i]);
				tab[j - 2] = tab[j - 2] / tab[j - 1];
				print_tab(tab, 3);
			}
			else if (str[i] == '%')
			{
				printf("j - 2 : %d et operateur : %c\n", tab[j - 2], str[i]);
				tab[j - 2] = tab[j - 2] % tab[j - 1];
				print_tab(tab, 3);
			}
			else if (str[i] == '-')
			{
				printf("j - 2 : %d et operateur : %c\n", tab[j - 2], str[i]);
				tab[j - 2] = tab[j - 2] - tab[j - 1];
				print_tab(tab, 3);
			}
			j--;
			printf("j apres : %d\n", j);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		rpn_calc(argv[1]);
		return (0);
	}
	printf("Error\n");
	return (0);
}
