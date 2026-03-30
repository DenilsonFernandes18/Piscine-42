/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denilson42 <denilson42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:44:33 by denilson42        #+#    #+#             */
/*   Updated: 2026/03/30 14:44:33 by denilson42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	if (tab[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	i;

	i = -1;
	if (n <= 0 || n >= 10)
		return ;
	while (++i < n)
		tab[i] = i;
	while (1)
	{
		ft_print(tab, n);
		i = n - 1;
		while (i >= 0 && tab[i] == 10 - n + i)
			i--;
		if (i < 0)
			break ;
		tab[i]++;
		while (i < n - 1)
		{
			tab[i + 1] = tab[i] + 1;
			i++;
		}
	}
}
