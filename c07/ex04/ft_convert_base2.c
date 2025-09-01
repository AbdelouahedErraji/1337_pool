/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:38:42 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/29 14:18:41 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi_base(char *nbr, char *base, int base_size)
{
	int	d;
	int	i;
	int	j;
	int	s;

	d = 0;
	i = 0;
	s = 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			s *= -1;
		i++;
	}
	while (nbr[i])
	{
		j = 0;
		while (base[j] && nbr[i] != base[j])
			j++;
		if (j == base_size)
			break;
		d = d * base_size + j;
		i++;
	}
	return d * s;
}

int	ft_length(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		i++;
	}
	return (i);
}

int	is_special(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ' ' || base[i] < 14 || base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}

int	is_duplicates(char *base, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (-1);
}

int	check_base(char *base)
{
	int	size;

	size = ft_length(base);
	if (size < 2)
		return (-1);
	if (is_special(base) == 1)
		return (-1);
	if (is_duplicates(base, size) == 1)
		return (-1);
	return (size);
}
