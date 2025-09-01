/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:37:03 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/29 14:20:15 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	check_base(char *base);

int ft_atoi_base(char *nbr, char *base, int base_size);

char	*ft_nbr_base(char *res, int nbr, char *base, int base_size, int i)
{
	unsigned int	n;

	if (nbr < 0)
	{
		res[0] = '-';
		n = -(unsigned int)nbr;
	}
	else
		n = (unsigned int)nbr;
	if (n >= (unsigned int)base_size)
	{
		ft_nbr_base(res, n / base_size, base, base_size, i - 1);
	}
	res[i] = base[n % base_size];
	return res;
}

int ft_res_size(int nbr, char *base, int base_size)
{
	int size = 0;

	if (nbr < 0)
	{
		size++;
		if (nbr == -2147483648)
		{
			size++;
			nbr = -147483648;
		}
		nbr *= -1;
	}
	if (nbr >= base_size)
	{
		size++;
		return (size + ft_res_size(nbr / base_size, base, base_size));
	}
	size++;
	return size;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int from = check_base(base_from);
	int to_size = check_base(base_to);
	if (!(to_size && from))
	{
		return NULL;
	}

	int	nbr_from = ft_atoi_base(nbr, base_from, from);
	int res_size = ft_res_size(nbr_from, base_to, to_size);

	printf("base from: %d\n", from);
	printf("base to size: %d\n", to_size);
	printf("nbr from: %d\n", nbr_from);
	printf("result size: %d\n", res_size);

	char *res = malloc(res_size);
	ft_nbr_base(res, nbr_from, base_to, to_size, res_size - 1);
	return res;
}

int main()
{
	char *res = ft_convert_base("-3648", "0123456789", "0123456789abcdef");
	printf("%s\n", res);
	return 0;
}
