/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <jcharloi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:12:20 by jcharloi          #+#    #+#             */
/*   Updated: 2017/12/07 13:52:43 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int			ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char		*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		**create_tab(int len, char **argv)
{
	char	**tab;
	int		i;

	i = 1;
	if (!(tab = (char**)malloc(sizeof(char*) * len + 1)))
		return (NULL);
	tab[len] = NULL;
	while (i < len + 1)
	{
		if (!(tab[i - 1] = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		tab[i - 1][len] = '\0';
		tab[i - 1] = ft_strcpy(tab[i - 1], argv[i]);
		i++;
	}
	return (tab);
}

int		check_rook(char **tab, int y, int x)
{
	int i;
	int j;

	//printf("hjhr\n");
	j = x + 1;
	//a droite
	while (tab[y][j] != '\0')
	{
		if (tab[y][j] == 'P' || tab[y][j] == 'B' || tab[y][j] == 'Q' || tab[y][j] == 'R')
			return (0);
		if (tab[y][j] == 'K')
		{
			ft_putstr("Success\n");
			return (1);
		}
		j++;
	}
	
	j = x - 1;
	//printf("j : %d\n", j);
	//a gauche
	while (j >= 0)
	{
		if (tab[y][j] == 'P' || tab[y][j] == 'B' || tab[y][j] == 'Q' || tab[y][j] == 'R')
			return (0);
		if (tab[y][j] == 'K')
		{
			ft_putstr("Success\n");
			return (1);
		}
		j--;
	}
	//printf("b\n");
	i = y + 1;
	//en bas
	while (tab[i] != NULL)
	{
		if (tab[i][x] == 'P' || tab[i][x] == 'B' || tab[i][x] == 'Q' || tab[i][x] == 'R')
			return (0);
		if (tab[i][x] == 'K')
		{
			ft_putstr("Success\n");
			return (1);
		}
		i++;
	}
	i = y - 1;
	//en haut
	//printf("i : %d\n", i);
	while (i >= 0)
	{
		if (tab[i][x] == 'P' || tab[i][x] == 'B' || tab[i][x] == 'Q' || tab[i][x] == 'R')
			return (0);
		if (tab[i][x] == 'K')
		{	
			ft_putstr("Success\n");
			return (1);
		}
		i--;
	}
	return (0);
}

int		check_pawn(char **tab, int y, int x)
{
	if (y > 0 && (tab[y - 1][x - 1] == 'K' || tab[y - 1][x + 1] == 'K'))
	{
		ft_putstr("Success\n");
		return (1);
	}
	return (0);
}

int		check_bishop(char **tab, int y, int x)
{
	int i;
	int j;

	i = y + 1;
	j = x + 1;
	//en bas a droite;
	while (tab[i] != NULL)
	{
		if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
			return (0);
		if (tab[i][j] == 'K')
		{	
			ft_putstr("Success\n");
			return (1);
		}
		i++;
		j++;
	}
	i = y + 1;
	j = x - 1;
	//en bas a gauche
	while (tab[i] != NULL)
	{
		if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
			return (0);
		if (tab[i][j] == 'K')
		{	
			ft_putstr("Success\n");
			return (1);
		}
		i++;
		j--;
	}
	i = y - 1;
	j = x + 1;
	//en haut a droite;
	while (i >= 0)
	{
		if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
			return (0);
		if (tab[i][j] == 'K')
		{	
			ft_putstr("Success\n");
			return (1);
		}
		i--;
		j++;
	}
	i = y - 1;
	j = x - 1;
	//en haut a gauche
	while (i >= 0)
	{
		if (tab[i][j] == 'P' || tab[i][j] == 'B' || tab[i][j] == 'Q' || tab[i][j] == 'R')
			return (0);
		if (tab[i][j] == 'K')
		{	
			ft_putstr("Success\n");
			return (1);
		}
		i--;
		j--;
	}
	return (0);
}

int		check_queen(char **tab, int i, int j)
{
	if (check_bishop(tab, i, j) == 1)
		return (1);
	if (check_rook(tab, i, j) == 1)
		return (1);
	return (0);
}

int 	main(int argc, char **argv)
{
	char	**tab;
	int i = 0;
	int j = 0;
	if (argc > 1)
	{
		tab = create_tab(argc - 1, argv);
		if (tab == NULL)
			return (-1);
		while (tab[i] != NULL)
		{
			printf("tab[i] : %s\n", tab[i]);
			i++;
		}
		i = 0;
		while (tab[i] != NULL)
		{
			j = 0;
			while (tab[i][j] != '\0')
			{
				if (tab[i][j] == 'R')
				{
					if (check_rook(tab, i, j) == 1)
						return (0);
				}
				else if (tab[i][j] == 'P')
				{
					if (check_pawn(tab, i, j) == 1)
						return (0);
				}
				else if (tab[i][j] == 'B')
				{
					if (check_bishop(tab, i, j) == 1)
						return (0);
				}
				else if (tab[i][j] == 'Q')
				{
					if (check_queen(tab, i, j) == 1)
						return (0);
				}
				j++;
			}
			i++;
		}
		ft_putstr("Fail");
		free(*tab);
	}
	ft_putstr("\n");
	return (0);
}