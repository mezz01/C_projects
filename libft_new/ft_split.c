/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezzat <mmezzat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:41:15 by mmezzat           #+#    #+#             */
/*   Updated: 2022/11/15 19:20:13 by mmezzat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_of_words(char const *str, char c)
{
	int	chr_id;
	int	word_count;

	chr_id = 0;
	word_count = 0;
	while (str[chr_id])
	{
		if (str[chr_id] != c)
			word_count++;
		while (str[chr_id] != c && str[chr_id + 1] != '\0')
			chr_id++;
		chr_id++;
	}
	return (word_count);
}

static void	*free_mem(char **str, int word_id)
{
	while (str[word_id])
	{
		free(str[word_id]);
		word_id--;
	}
	free(str);
	return (0);
}

static int	num_char_in_word(char const *str, char delim_char)
{
	int	num_char;

	num_char = 0;
	while (str[num_char] && str[num_char] != delim_char)
		num_char++;
	return (num_char);
}

char	**ft_split(char const *s, char c)
{
	char	**splited_s;
	int		num_words;
	int		chr_id;
	int		word_id;

	if (!s)
		return (0);
	num_words = num_of_words(s, c);
	splited_s = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!splited_s)
		return (0);
	chr_id = 0;
	word_id = 0;
	while (word_id < num_words)
	{
		while (s[chr_id] != '\0' && s[chr_id] == c)
			chr_id++;
		splited_s[word_id] = ft_substr(s, chr_id,
				num_char_in_word(s + chr_id, c));
		if (!splited_s[word_id])
			return (free_mem(splited_s, word_id - 1));
		chr_id = chr_id + num_char_in_word(s + chr_id, c);
		word_id++;
	}
	return (splited_s[num_words] = NULL, splited_s);
}
