#include <unistd.h>

char	int_to_hex(int i)
{
	if (i > 9)
		return ('a' + (i - 10));
	return ('0' + i);
}

void	print_char_as_hex(char *src)
{
	char	hex[4];

	hex[0] = '\\';
	hex[1] = int_to_hex(*src / 16);
	hex[2] = int_to_hex(*src % 16);
	hex[3] = '\0';
	write(1, &hex, 3);
}

void	ft_putstr_non_printable(char *src)
{
	while (*src != '\0')
	{
		if (*src < ' ' || *src > '~')
			print_char_as_hex(src);
		else
			write(1, src, 1);
		src++;
	}
}
