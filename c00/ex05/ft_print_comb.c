/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:05:54 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/13 23:04:59 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_print_comb(void)
{
	char ci;
	char ce;
	char cd;
	int i;
	int e;
	int d;

	i = 0;
	while (i <= 7)
	{
		e = 1;
		ci = i + '0';
		while (e <= 8)
		{
			ce = e + '0';
			d = 2;
			while (d <= 9)
			{
				if (i != e && i != d && e != d)
				{
					cd = d + '0';
					ft_putchar(ci);
					ft_putchar(ce);
					ft_putchar(cd);
					if (i == 7 && e == 8 && d == 9) {
						break;
					}
					write (1, ", ", 2);
				}
				d++;
			}
			e++;
		}
		i++;
	}
}

void main()
{
	ft_print_comb();
	return;
}
