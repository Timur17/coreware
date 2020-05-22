#include "asm.h"

char         *command_2(char *s)
{
    if (!(ft_strcmp(s, LDI)))
        return ("0a");
    else if (!(ft_strcmp(s, STI)))
        return ("0b");
    else if (!(ft_strcmp(s, FORK)))
        return ("0c");
    else if (!(ft_strcmp(s, LLD)))
        return ("0d");
    else if (!(ft_strcmp(s, LLDI)))
        return ("0e");
    else if (!(ft_strcmp(s, LFORK)))
        return ("0f");
    else if (!(ft_strcmp(s, AFF)))
        return ("10");
    else
        return (NULL);        
}

char         *command(char *s)
{
    if (!(ft_strcmp(s, LIVE)))
        return ("01");
    else if (!(ft_strcmp(s, LD)))
        return ("02");
    else if (!(ft_strcmp(s, ST)))
        return ("03");
    else if (!(ft_strcmp(s, ADD)))
        return ("04");
    else if (!(ft_strcmp(s, SUB)))
        return ("05");
    else if (!(ft_strcmp(s, AND)))
        return ("06");
    else if (!(ft_strcmp(s, OR)))
        return ("07");
    else if (!(ft_strcmp(s, XOR)))
        return ("08");
    else if (!(ft_strcmp(s, ZJMP)))
        return ("09");
    else
        return (command_2(s));
}