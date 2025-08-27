#include <unistd.h>

void ft_print_rev(char *str, int i)
{
	if (str[i])
	{
		ft_print_rev(str, i + 1);
		write(1, &str[i], 1);
	}
}

int main(int argc, char *argv[])
{
	int	i;

	i = 1;
	while(i < argc)
	{
		ft_print_rev(argv[i], 0);
		write(1, "\n", 1);
		i++;
	}
	return 0;
}