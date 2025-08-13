/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brunofer <brunofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 07:02:52 by brunofer          #+#    #+#             */
/*   Updated: 2025/07/27 10:49:46 by brunofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clear_spaces(char **nbstr);
static void	handle_positive_or_negative_sign(char **nbstr, int *sign);

int	ft_atoi(const char *nptr)
{
	int		result;
	int		i;
	int		sign;
	char	*nbstr;

	nbstr = (char *)nptr;
	clear_spaces(&nbstr);
	handle_positive_or_negative_sign(&nbstr, &sign);
	result = 0;
	i = -1;
	while (ft_isdigit(nbstr[++i]))
		result = result * 10 + (nbstr[i] - '0');
	return (result * sign);
}

static void	clear_spaces(char **nbstr)
{
	while (**nbstr == ' ' || (**nbstr > 8 && **nbstr < 14))
		*nbstr = *nbstr + 1;
}

static void	handle_positive_or_negative_sign(char **nbstr, int *sign)
{
	*sign = 1;
	if (*nbstr[0] == '-' || *nbstr[0] == '+')
	{
		if (*nbstr[0] == '-')
			*sign = -1;
		*nbstr = *nbstr + 1;
	}
}
