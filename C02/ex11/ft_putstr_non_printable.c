/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: denilson42 <denilson42@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 19:21:31 by denilson42        #+#    #+#             */
/*   Updated: 2026/03/06 19:21:31 by denilson42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexadecimal(int num)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[(num / 16) % 16]);
	ft_putchar(hex[num % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			ft_putchar('\\');
			ft_hexadecimal(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
