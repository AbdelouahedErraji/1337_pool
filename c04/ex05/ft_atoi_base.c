/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:59:57 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/24 18:34:44 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	if (c == 32 || c == '\n' || c == '\t')
	{
		return (1);
	}
	return (0);
}

int	is_valid(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	base_number(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	return_val(int i, char *str, char *base, int base_size)
{
	int	d;

	d = 0;
	while (str[i])
	{
		if (!is_valid(str[i], base))
			break ;
		else
		{
			d = d * base_size + base_number(str[i], base);
		}
		i++;
	}
	return d;
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	m;
	int	d;
	int	base_size;

	i = 0;
	m = 0;
	d = 0;
	base_size = 0;
	while (is_space(*(str + i)))
		i++;
	while (*(str + i) == 45 || *(str + i) == 43)
	{
		if (*(str + i) == 45)
			m++;
		i++;
	}
	while (base[base_size])
		base_size++;
	d = return_val(i, str, base, base_size);
	if (m % 2 != 0)
		d = -d;
	return (d);
}
