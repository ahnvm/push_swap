/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:09:45 by acan              #+#    #+#             */
/*   Updated: 2023/09/24 14:43:26 by acan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arglen(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char	**argjoin(char **seperated, char *raw)
{
	int		i;
	int		j;
	int		len;
	char	**ret;
	char	**new;

	i = -1;
	j = 0;
	len = arglen (seperated) + countword_onearg (raw, ' ') + 1;
	if (!seperated)
		seperated = ft_calloc (1, 1);
	ret = malloc (sizeof (char *) * (len));
	ret[arglen(seperated) + countword_onearg(raw, ' ')] = 0;
	new = ft_split(raw, ' ');
	while (seperated[++i])
		ret[i] = seperated[i];
	while (new[j])
		ret[i++] = new[j++];
	free (new);
	free (seperated);
	return (ret);
}

char	**seperate_all(char **av)
{
	int		i;
	char	**last;

	i = 1;
	last = ft_calloc (1, 1);
	while (av[i])
		last = argjoin(last, av[i++]);
	return (last);
}
