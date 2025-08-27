#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;
	char *arg;

	i = 1;
	while(i < argc)
	{
		arg = argv[i];
		while (*arg)
		{
			write(1, arg, 1);
			arg++;
		}
		write(1, "\n", 1);
		i++;
	}
}