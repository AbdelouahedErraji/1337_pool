/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:51:40 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/25 13:28:22 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

int	found_chars(char *to_find, char *str)
{
	int	d;

	d = 0;
	while (to_find[d] && to_find[d] == str[d])
		d++;
	return (d);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	d;
	int	l;

	i = 0;
	l = length(to_find);
	if (l == 0)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[0])
		{
			d = found_chars(to_find, &str[i]);
			if (l == d)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
