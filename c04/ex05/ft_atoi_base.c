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

int	check_base(char *base)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45 || is_space(base[i]))
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

int	is_space(char c)
{
	if (c == 32 || c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
	{
		return (1);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	m;
	int	d;
	int	base_size;
	int	idx;

	i = 0;
	m = 0;
	d = 0;
	base_size = check_base(base);
	if (base_size == 0)
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (*(str + i) == 45)
			m++;
		i++;
	}
	while (idx == base_number(str[i], base) != -1)
	{
		d = d * base_size + idx;
		i++;
	}
	if (m % 2 != 0)
		d = -d;
	return (d);
}