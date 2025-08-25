/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 17:32:34 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/25 07:09:51 by aerraji          ###   ########.fr       */
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

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int	return_val(char *str, int i, int m)
{
	int	d;

	d = 0;
	while (str[i])
	{
		if (!is_num(str[i]))
		{
			break ;
		}
		else
		{
			d = d * 10 + str[i] - '0';
		}
		i++;
	}
	if (m % 2 == 0)
	{
		return (d);
	}
	else
	{
		return (d * -1);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	m;
	int	d;

	i = 0;
	m = 0;
	d = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
		{
			m++;
		}
		i++;
	}
	return (return_val(str, i, m));
}
