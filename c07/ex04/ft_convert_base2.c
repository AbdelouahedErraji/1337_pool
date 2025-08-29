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
