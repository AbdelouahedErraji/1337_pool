/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:05:54 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/14 20:56:10 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_three_chars(char a, char b, char c)
{
	while (c <= '9')
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(c);
		if (a == '7' && b == '8' && c == '9')
		{
			break ;
		}
		write (1, ", ", 2);
		c++;
	}
}

void	ft_print_comb(void)
{
	int	digit1;
	int	digit2;
	int	digit3;

	digit1 = 0 + '0';
	while (digit1 <= '7')
	{
		digit2 = digit1 + 1;
		while (digit2 <= '8')
		{
			digit3 = digit2 + 1;
			ft_put_three_chars(digit1, digit2, digit3);
			digit2++;
		}
		digit1++;
	}
}
