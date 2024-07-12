/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyeh <kyeh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:59:09 by kyeh              #+#    #+#             */
/*   Updated: 2024/07/12 15:59:09 by kyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strclean(char *str, const char *charset, int free)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			len++;
		i++;
	}
	res = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	len = 0;
	while (str[i])
	{
		if (!ft_strchr(charset, str[i]))
			res[len++] = str[i];
		i++;
	}
	if (free == 1)
		free_string(&str);
	res[len] = '\0';
	return (res);
}

//	Subtract the characters in the charset from str and return the new str.