/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:38:42 by aerraji           #+#    #+#             */
/*   Updated: 2025/09/02 09:42:39 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_char_special(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13) || c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi_base(char *nbr, char *base, int base_size)
{
	int	d;
	int	i;
	int	j;
	int	s;

	d = 0;
	i = 0;
	s = 1;
	while (is_char_special(nbr[i]))
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
			break ;
		d = d * base_size + j;
		i++;
	}
	return (d * s);
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
		if (is_char_special(base[i]))
			return (1);
		i++;
	}
	return (0);
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
	return (0);
}
