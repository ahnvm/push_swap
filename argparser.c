/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acan <ahmetabdullahcan@outlook.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:09:45 by acan              #+#    #+#             */
/*   Updated: 2023/10/11 16:11:27 by acan             ###   ########.fr       */
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

	i = 0;
	j = 0;
	len = arglen (seperated) + countword_onearg (raw, ' ') + 1;
	while (raw[i] == ' ')
		i++;
	if (i == (int)ft_strlen(raw))
		print_error("Error\n");
	i = -1;
	ret = malloc (sizeof (char *) * (len));
	ret[len] = 0;
	new = ft_split(raw, ' ');
	while (seperated[++i])
		ret[i] = seperated[i];
	while (new[j])
		ret[i++] = new[j++];
	ret[i] = 0;
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
	if (!last)
	{
		print_error("Error\n");
	}
	while (av[i])
		last = argjoin(last, av[i++]);
	return (last);
}
