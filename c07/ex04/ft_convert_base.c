/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:37:03 by aerraji           #+#    #+#             */
/*   Updated: 2025/09/02 09:45:02 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_special(char *base);

int	is_duplicates(char *base, int size);

int	ft_length(char *base);

int	ft_atoi_base(char *nbr, char *base, int base_size);

int	check_base(char *base)
{
	int	size;

	size = ft_length(base);
	if (size < 2)
		return (0);
	if (is_special(base) == 1)
		return (0);
	if (is_duplicates(base, size) == 1)
		return (0);
	return (size);
}

char	*ft_nbr_base(char *res, int nbr, char *base, int i)
{
	unsigned int	n;
	int				base_size;

	base_size = check_base(base);
	if (nbr < 0)
	{
		res[0] = '-';
		n = -(unsigned int)nbr;
	}
	else
		n = (unsigned int)nbr;
	if (n >= (unsigned int)base_size)
	{
		ft_nbr_base(res, n / base_size, base, i - 1);
	}
	res[i] = base[n % base_size];
	return (res);
}

int	ft_res_size(int nbr, char *base, int base_size)
{
	int	size;

	size = 0;
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
	return (size);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_from_size;
	int		base_to_size;
	int		nbr_from;
	int		res_size;
	char	*res;

	base_from_size = check_base(base_from);
	base_to_size = check_base(base_to);
	if (!(base_to_size && base_from_size))
	{
		return (NULL);
	}
	nbr_from = ft_atoi_base(nbr, base_from, base_from_size);
	res_size = ft_res_size(nbr_from, base_to, base_to_size);
	res = malloc(res_size + 1);
	if (!res)
		return (NULL);
	res[res_size] = '\0';
	ft_nbr_base(res, nbr_from, base_to, res_size - 1);
	return (res);
}
