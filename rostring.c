/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcharloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 13:40:03 by jcharloi          #+#    #+#             */
/*   Updated: 2017/10/19 17:08:57 by jcharloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strcpy(char *str)
{
	char    *copy;
	int		i;
	int		o;
	
	i = 0;
	o = 0;
	if (!(copy = (char*)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
		copy[o] = str[i];
		i++;
		o++;
	}
	copy[o] = '\0';
	return (copy);
}

void	rostring(char *str)
{
	char	*copy;
	int		i;
	int		neg;
	
	i = 0;
	neg = 0;
	copy = ft_strcpy(str);
	if (copy == NULL)
		return ;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		{
			ft_putchar(str[i]);
			neg = 1;
			i++;
		}
		while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (neg == 1)
		   	ft_putchar(' ');
	}
	ft_putstr(copy);
	free(copy);
}

int		 main(int argc, char **argv)
{
	char 	*str;

	if (argc > 1)
	{
		str = argv[1];
		rostring(str);
	}
	ft_putchar('\n');
	return (0);
}

--------------------------------------------------------------

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int            ft_strlen(char *str)
{
    int i = 0;
    
    while (str[i] != '\0')
        i++;
    return (i);
}

void        ft_putstr(char *str)
{
    write(1, str, ft_strlen(str));
}

void        ft_putchar(char c)
{
    write(1, &c, 1);
}

int            len_first_word(char *str)
{
    int    word = 0;
    int i = 0;
    
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
        word++;
        i++;
    }
    return (word);
}

char        *get_first_word(char *str)
{
    char    *word;
    int        first;
    int        i;
    int        j;
    
    i = 0;
    j = 0;
    first = len_first_word(str);
    if (!(word = (char*)malloc(sizeof(char) * (first + 1))))
        return (NULL);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
    {
        word[j] = str[i];
        j++;
        i++;
    }
    word[j] = '\0';
    return (word);
}

char        *fonction(char *str)
{
    char     *first_word;
    char    *copy;
    int     i = 0;
    int        o = 0;
    
    first_word = get_first_word(str);
    if (first_word == NULL)
        return (NULL);
    if (!(copy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
        return (NULL);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        i++;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != '\0')
    {
        if (o > 0)
            copy[o++] = ' ';
        while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        {
            copy[o] = str[i];
            o++;
            i++;
        }
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        if (str[i] == '\0')
            copy[o++] = ' ';
    }
    copy[o] = '\0';
    ft_putstr(copy);
    free(copy);
    return (first_word);
}

int main(int argc, char **argv)
{
    char    *str;
    char    *first_word;
    
    if (argc > 1)
    {
        str = argv[1];
        first_word = fonction(str);
        if (first_word == NULL)
            return (0);
        ft_putstr(first_word);
        free(first_word);
    }
    ft_putstr("\n");
    return (0);
}
