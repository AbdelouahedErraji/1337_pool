/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:42:54 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/29 11:53:52 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	length(int size, char **strs)
{
	int	i;
	int	j;
	int	strs_size;

	i = 0;
	strs_size = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
		}
		strs_size += j;
		i++;
	}
	return (strs_size);
}

void ft_join(int size, char **strs, char *sep, char *res)
{
	int	i;
	int	e;
	int	j;

	i = 0;
	e = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			res[e++] = strs[i][j++];
		if (i < size - 1)
		{
			j = 0;
			while (sep[j])
				res[e++] = sep[j++];
		}
		i++;
	}
	res[e] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_size;
	int		strs_size;
	char	*res;
	char	*empty;

	if (size == 0)
	{
		empty = malloc(1);
		if (empty)
			empty[0] = '\0';
		return (empty);
	}
	sep_size = 0;
	while (sep[sep_size])
		sep_size++;
	strs_size = length(size, strs);
	res = malloc(strs_size + sep_size * (size - 1) + 1);
	if (!res)
		return (NULL);
	ft_join(size, strs, sep, res);
	return (res);
}
