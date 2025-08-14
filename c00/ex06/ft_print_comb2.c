/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:50:42 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/14 14:11:59 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_tens_units(int num)
{
	int	tens;
	int	units;

	if (num <= 9)
	{
		tens = num + '0';
		ft_putchar('0');
		ft_putchar(tens);
	}
	else
	{
		tens = (num / 10) + '0';
		units = (num % 10) + '0';
		ft_putchar(tens);
		ft_putchar(units);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_tens_units(a);
			write(1, " ", 1);
			ft_tens_units(b);
			if (a != 98)
			{
				write(1, ", ", 2);
			}
			b++;
		}
		a++;
	}
}
