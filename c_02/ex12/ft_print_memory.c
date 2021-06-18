#include <unistd.h>

char	int_to_hex(int i)
{
	if (i > 9)
		return ('a' + (i - 10));
	return ('0' + i);
}

void	print_memory_address(void *addr)
{
	int		i;
	int		aux;
	char	hex[18];

	i = 15;
	aux = (int) addr;
	while (i >= 0)
	{
		if (aux > 0)
		{
			hex[i] = int_to_hex(aux % 16);
			aux = aux / 16;
		}
		else
			hex[i] = '0';
		i--;
	}
	hex[16] = ':';
	hex[17] = ' ';
	write(1, hex, 18);
}

void	print_content_in_hex(char *addr, int size)
{
	int		i;
	char	aux;

	i = 0;
	while (i < size)
	{
		aux = int_to_hex(*(addr + i) / 16);
		write(1, &aux, 1);
		aux = int_to_hex(*(addr + i) % 16);
		write(1, &aux, 1);
		i++;
		if (i % 2 == 0)
			write(1, " ", 1);
	}
	i = i * 3;
	while (i < 46)
	{
		write(1, " ", 1);
		i++;
	}
}

void	print_content(char *addr, int size)
{
	int		i;
	char	aux;

	i = 0;
	while (i < size)
	{
		if (*(addr + i) < ' ' || *(addr + i) > '~')
			aux = '.';
		else
			aux = *(addr + i);
		write(1, &aux, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	int				length_line;

	i = 0;
	while (i < size)
	{
		if (size - i < 16)
			length_line = size - i;
		else
			length_line = 16;
		print_memory_address((addr + i));
		print_content_in_hex((addr + i), length_line);
		print_content((addr + i), length_line);
		write(1, "\n", 1);
		i = i + 16;
	}
	return (addr);
}
