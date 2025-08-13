/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:02:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/27 12:21:30 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				size;
	unsigned int	len_str;
	char			*sub;

	if ((!s && !start))
		return (NULL);
	len_str = (unsigned int)ft_strlen(s);
	if (!s || (start > len_str))
		return ((char *)ft_calloc(1, 1));
	size = len;
	if (len > (len_str - start))
		size = len_str - start;
	sub = (char *)ft_calloc(size + 1, 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], size + 1);
	return (sub);
}
