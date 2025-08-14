/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:23:54 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/14 17:53:52 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	negative_number(int nb);

void	ft_putnbr(int nb)
{
	int	num;
	int	degit;

	if (nb < 0)
	{
		negative_number(nb);
	}
	else if (nb <= 9)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		degit = nb / 10;
		ft_putnbr(degit);
		num = (nb % 10) + '0';
		ft_putchar(num);
	}
}

void	negative_number(int nb)
{
	ft_putchar('-');
	if (nb == -2147483648)
	{
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else
	{
		nb = nb * -1;
		ft_putnbr(nb);
	}
}
