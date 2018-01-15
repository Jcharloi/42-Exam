/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 14:59:48 by jcharloi          #+#    #+#             */
/*   Updated: 2018/01/14 19:02:48 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int		i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		is_symbole(char c)
{
	if (c == '(' || c == '[' || c == '{')
		return (1);
	return (0);
}

int		is_rsymbole(char c)
{
	if (c == ')' || c == ']' || c == '}')
		return (1);
	return (0);
}

int		parcours(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_rsymbole(str[i]) == 1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	brackets(char *str)
{
	int		i;
	int		endroit;
	char	c;
	int		test;

	i = ft_strlen(str);
	while (i >= 0)
	{
		test = 0;
		endroit = 0;
		c = '\0';
		i = ft_strlen(str);
		while (i >= 0)
		{
			if (is_symbole(str[i]) == 1)
			{
				c = str[i];
				endroit = i;
				break ;
			}
			i--;
		}
		if (c == '\0' && parcours(str) == 0)
		{
			ft_putstr("OK");
			return ;
		}
		else if (c == '\0' && parcours(str) == 1)
		{
			ft_putstr("Error");
			return ;
		}
		while (str[i] != '\0')
		{
			if (is_rsymbole(str[i]) == 1)
			{
				test = 1;
				if (c == '(')
				{
					if (str[i] != ')')
				{
						ft_putstr("Error");
						return ;
					}
					else
					{
						str[i] = ' ';
						str[endroit] = ' ';
						break ;
					}
				}
				else if (c == '[')
				{
					if (str[i] != ']')
					{
						ft_putstr("Error");
						return ;
					}
					else
					{
						str[i] = ' ';
						str[endroit] = ' ';
						break ;
					}
				}
				else if (c == '{')
				{
					if (str[i] != '}')
					{
						ft_putstr("Error");
						return ;
					}
					else
					{
						str[i] = ' ';
						str[endroit] = ' ';
						break ;
					}
				}
			}
			i++;
		}
		if (test == 0)
		{
			ft_putstr("Error");
			return ;
		}
	}
	ft_putstr("OK");
}

int main(int argc, char **argv)
{
	int		count;

	count = 1;
	if (argc > 1)
	{
		while (count < argc)
		{
			brackets(argv[count]);
			count++;
			if (count < argc)
				ft_putstr("\n");
		}
	}
	ft_putstr("\n");
	return (0);
}