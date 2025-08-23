/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:41:19 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/23 14:37:07 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	put_hex(char c)
{
	char	a;

	if (c / 16 < 10)
	{
		a = c / 16 + '0';
	}
	else
	{
		a = (c / 16 - 10) + 'a';
	}
	write(1, &a, 1);
	if (c % 16 < 10)
	{
		a = c % 16 + '0';
	}
	else
	{
		a = (c % 16 - 10) + 'a';
	}
	write(1, &a, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 32 && *(str + i) <= 126)
		{
			write(1, (str + i), 1);
		}
		else
		{
			write(1, "\\", 1);
			put_hex(*(str + i));
		}
		i++;
	}
}
