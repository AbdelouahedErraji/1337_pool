/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:54:30 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/25 09:54:56 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *base)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		while (t < i)
		{
			if (base[i] == base[t])
				return (0);
			t++;
		}
		t = 0;
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	putnbr_base(int nbr, char *base, int base_size)
{
	if (nbr >= base_size)
		putnbr_base(nbr / base_size, base, base_size);
	write(1, &base[nbr % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	base_size = check_base(base);
	if (base_size == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			write(1, "2", 1);
			nbr = -147483648;
		}
		nbr *= -1;
	}
	putnbr_base(nbr, base, base_size);
}
