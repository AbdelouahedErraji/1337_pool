/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 11:04:03 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/24 11:06:03 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_uppercase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	is_lowercase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int	is_num_alpha(char c)
{
	if ((c >= '0' && c <= '9')
			|| is_uppercase(c)
			|| is_lowercase(c))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_uppercase(str[i]))
                {
                        str[i] = str[i] + 32;
                }
		if ((i == 0 || !is_num_alpha(str[i - 1])) && is_lowercase(str[i]))
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}
