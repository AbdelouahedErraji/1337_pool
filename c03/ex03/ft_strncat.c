/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 15:45:30 by aerraji           #+#    #+#             */
/*   Updated: 2025/08/23 15:50:25 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	d;
	unsigned int	i;

	i = 0;
	d = 0;
	while (*(dest + d))
	{
		d++;
	}
	while (*(src + i) && i < nb)
	{
		*(dest + d) = *(src + i);
		i++;
		d++;
	}
	*(dest + d) = '\0';
	return (dest);
}
