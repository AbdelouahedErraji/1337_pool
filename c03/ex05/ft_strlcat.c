/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:12:36 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/23 16:45:58 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	length(char *c)
{
	int	i;

	i = 0;
	while (*(c + i))
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	sl;
	unsigned int	dl;
	unsigned int	i;
	unsigned int	d;

	sl = length(src);
	dl = length(dest);
	i = 0;
	if (size <= dl)
	{
		return (size + sl);
	}
	d = dl;
	while (*(src + i) && d + 1 < size)
	{
		*(dest + d) = *(src + i);
		i++;
		d++;
	}
	*(dest + d) = '\0';
	return (sl + dl);
}
