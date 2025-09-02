/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aerraji <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 10:25:31 by aerraji           #+#    #+#             */
/*   Updated: 2025/09/02 12:50:44 by aerraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	words_count;
	int	is_word;

	is_word = 0;
	words_count = 0;
	i = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset))
		{
			if (!is_word)
				words_count++;
			is_word = 1;
		}
		else
			is_word = 0;
		i++;
	}
	return (words_count);
}

void	allocate(char **p, char *str, char *charset)
{
	int	i;
	int	word_size;
	int	j;

	i = 0;
	j = 0;
	word_size = 0;
	while (str[i])
	{
		if (!is_separator(str[i], charset))
		{
			word_size++;
			if (is_separator(str[i + 1], charset) || str[i + 1] == '\0')
			{
				p[j] = malloc((word_size + 1) * sizeof(char));
				if (!p[j])
					return ;
				j++;
				word_size = 0;
			}
		}
		i++;
	}
}

void	fill(char **p, char *str, char *charset, int words_count)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] && (count < words_count))
	{
		if (!is_separator(str[i], charset))
		{
			p[count][j] = str[i];
			j++;
			if (is_separator(str[i + 1], charset) || str[i + 1] == '\0')
			{
				p[count][j] = '\0';
				count++;
				j = 0;
			}
		}
		i++;
	}
	p[count] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		words_count;
	char	**p;

	words_count = count_words(str, charset);
	p = malloc((words_count + 1) * sizeof(char *));
	if (!p)
		return (NULL);
	allocate(p, str, charset);
	fill(p, str, charset, words_count);
	return (p);
}
