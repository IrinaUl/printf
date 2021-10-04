#include "printf.h"
#include <stdio.h>

// gcc -Wall -Wextra -Werror main.c -I incl/ -L. libftprintf.a

int main(void)
{
	int i;
	i = ft_printf("%x\n", 118);
	printf("%d\n\n", i);
	i = printf("%x\n", 118);
	printf("%d\n", i);
	return(0);
}

