/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daugier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 00:42:30 by daugier           #+#    #+#             */
/*   Updated: 2016/06/21 01:07:31 by daugier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	*cpy;

	i = ft_strlen(str);
	j = -1;
	if (!(cpy = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	cpy[i--] = '\0';
	while (str[++j])
		cpy[i--] = str[j];
	return (cpy);
}
