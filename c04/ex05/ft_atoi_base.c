/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 16:59:57 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/25 07:43:21 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == 32 || c == '\n'
		|| c == '\t' || c == '\v'
		|| c == '\f' || c == '\r')
	{
		return (1);
	}
	return (0);
}

int	check_base(char *base)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || is_space(base[i]))
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

int	number(char *str, char *base, int base_size, int i)
{
	int	j;
	int	res;

	res = 0;
	while (str[i])
	{
		j = 0;
		while (j < base_size && base[j] != str[i])
			j++;
		if (j == base_size)
			break ;
		res = res * base_size + j;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	s;
	int	d;
	int	base_size;

	i = 0;
	s = 1;
	d = 0;
	base_size = check_base(base);
	if (base_size == 0)
		return (0);
	while (is_space(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	d = number(str, base, base_size, i);
	return (d * s);
}
