/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 20:54:30 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/26 14:23:43 by aerraji          ###   ########.fr       */
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
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = -(unsigned int)nbr;
	}
	else
		n = (unsigned int)nbr;
	if (n >= base_size)
		putnbr_base(n / base_size, base, base_size);
	write(1, &base[n % base_size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;

	base_size = check_base(base);
	if (base_size == 0)
		return ;
	putnbr_base(nbr, base, base_size);
}
