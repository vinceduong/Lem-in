/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmenia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 13:57:36 by carmenia          #+#    #+#             */
/*   Updated: 2018/10/18 13:57:38 by carmenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				ft_chrstr(char *find, int c)
{
	int i;

	i = -1;
	while (find[++i])
	{
		if (find[i] == c)
			return (1);
	}
	return (find[i] == c ? 1 : 0);
}

int				ft_check_value(int *error_tab)
{
	int i;

	i = 0;
	while (i != 6)
	{
		if (error_tab[i] <= 0)
			return (0);
		i++;
	}
	return (1);
}

static char		*ft_strdup_matrice(char *tab)
{
	int		i;
	char	*str;

	i = 0;
	while (tab[i] != ' ')
		i++;
	str = ft_strndup(tab, i);
	if (!str)
		exit(0);
	return (str);
}

int				ft_matrice(char **tab, t_lemin *lemin, int *error_tab, int i)
{
	int n;

	n = 1;
	if (!(lemin->m.cases = (char**)malloc(sizeof(char*) *
		lemin->m.nbcases + 15)))
		return (0);
	lemin->m.cases[0] = ft_strdup_matrice(tab[error_tab[0]]);
	while (i < error_tab[6])
	{
		if (tab[i][0] == '#')
			i++;
		else
		{
			if (i == error_tab[1] || i == error_tab[0])
				i++;
			else
				lemin->m.cases[n++] = ft_strdup_matrice(tab[i++]);
		}
	}
	lemin->m.cases[n++] = ft_strdup_matrice(tab[error_tab[1]]);
	lemin->m.cases[n] = 0;
	if (!(ft_patatruc(tab, lemin, error_tab)))
		return (0);
	return (1);
}
