#include <unistd.h>

void    ft_putchar(char c)
{
    write (1, &c, 1);
}

int     ft_iswhitespace(int c)
{
    if (c == '\t' || c == ' ')
        return (1);
    return (0);
}

int     ft_isalpha(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

void    epur_str(char *str)
{
    int i;

    i = 0;
    while (ft_iswhitespace(str[i]))
        i++;
    while (str[i] != '\0')
    {
        if (ft_iswhitespace(str[i]) != 1)
            ft_putchar(str[i]);
        while (ft_iswhitespace(str[i]) && ft_iswhitespace(str[i + 1]))
            i++;
        if (ft_iswhitespace(str[i]) && ft_isalpha(str[i + 1]))
            ft_putchar(str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    char *str;

    str = argv[1];
    if (argc == 2)
        epur_str(str);
    ft_putchar('\n');
    return (0);
}

 while (str[i] != '\0' && ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t')))