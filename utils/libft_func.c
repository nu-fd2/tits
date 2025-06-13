/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:47:16 by mdakni            #+#    #+#             */
/*   Updated: 2025/05/23 20:47:09 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Token_and_lex.h"

bool is_space(char c)
{
	if(c == ' ' || (c >= 9 && c <= 13))
		return true;
	return false;
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if(!s)
		return(0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, int n)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i < n)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	str = malloc(ft_strlen(s1) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char *ft_realloc(char *ptr, const char *new)
{
    free(ptr);
    return(ft_strdup(new));
}
