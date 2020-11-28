/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:21:33 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 12:36:15 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char *s, char c)
{
	int		flag;
	int		wcnt;

	flag = 0;
	wcnt = 0;
	while (*s != '\0')
	{
		if (ft_memchr(s, c, 1))
		{
			if (0 < flag)
				wcnt++;
			flag = 0;
		}
		else
			flag++;
		s++;
	}
	if (0 < flag)
		return (wcnt + 1);
	return (wcnt);
}

static int	word_len(char *s, char c)
{
	int		rtn;

	rtn = 0;
	while (s[rtn] != c && s[rtn] != '\0')
		rtn++;
	return (rtn);
}

static int	all_free(char **wordlist, int cnt)
{
	int		i;

	i = 0;
	while (i <= cnt)
		free(wordlist[i]);
	return (1);
}

static int	set_data(int wcnt, char **wordlist, char *s, char c)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < wcnt)
	{
		while (*s != '\0' && *s == c)
			s++;
		len = word_len(s, c);
		wordlist[i] = malloc(sizeof(char) + (len + 1));
		if (wordlist[i] == NULL)
			return (all_free(wordlist, i));
		j = 0;
		while (*s != c && *s != '\0')
		{
			wordlist[i][j] = *s;
			s++;
			j++;
		}
		wordlist[i][j] = '\0';
		i++;
	}
	wordlist[i] = NULL;
	return (0);
}

char		**ft_split(char const *s, char c)
{
	int		wcnt;
	char	**wordlist;

	if (s == NULL)
		return (NULL);
	wcnt = count_word((char *)s, c);
	wordlist = malloc(sizeof(char*) * (wcnt + 1));
	if (wordlist == NULL)
		return (NULL);
	if (set_data(wcnt, wordlist, (char *)s, c))
	{
		free(wordlist);
		return (NULL);
	}
	return (wordlist);
}
