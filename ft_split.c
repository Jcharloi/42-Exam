/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:04:14 by jcharloi          #+#    #+#             */
/*   Updated: 2017/11/22 19:27:28 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		nbr_words(char *str)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			i++;
		if (str[i] == '\0')
		{
			nb++;
			break ;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			nb++;
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			i++;
	}
	return (nb);
}

char    **ft_split(char *str)
{
	char	**tab;
	int		words;
	int		letters;
	int		var;
	int		i;
	int		o;

	i = 0;
	o = 0;
	if (str == NULL)
	{
		tab = (char**)malloc(sizeof(char*));
		tab[o] = NULL;
		return (tab);
	}
	words = nbr_words(str);
	if (!(tab = (char**)malloc(sizeof(char*) * words + 1)))
		return (NULL);	
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
	    i++;	
	while (str[i] != '\0' && o < words)
	{
		letters = 0;
		while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		{
			letters++;
			i++;
		}
		if (!(tab[o] = (char*)malloc(sizeof(char) * letters)))
			return (NULL);
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			 i++;
		o++;
	}
	tab[o] = NULL;
	i = 0;
	o = 0;
	var = 0;
	while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
	   	i++;
	while (str[i] != '\0')
	{
		var = 0;
		while (str[i] != '\0' && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		{
			tab[o][var] = str[i];
			var++;
		 	i++;
		}
		if (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			o++;
		while (str[i] == '\t' || str[i] == ' ' || str[i] == '\n')
			i++;
	}	
	return (tab);
}

