/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:51:40 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/23 16:11:53 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	d;
	int	e;
	int	l;

	i = 0;
	l = 0;
	while (*(to_find + l))
	{
		l++;
	}
	if (l == 0)
	{
		return (str);
	}
	else
	{
		while (*(str + i))
		{
			if (*(str + i) == *to_find)
			{
				e  = i;
				d = 0;
				while (*(to_find + d) && *(to_find + d) == *(str + e))
				{
					d++;
					e++;
				}
				if (l == d)
				{
					return  (str + i);
				} 
			}
			i++;
		}
		return (NULL);
	}
}
