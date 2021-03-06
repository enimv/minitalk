/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoueldma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 07:30:04 by aoueldma          #+#    #+#             */
/*   Updated: 2022/06/26 07:31:17 by aoueldma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	sighandler(int siguser)
{
	static char	c;
	static int	b;

	if (siguser == SIGUSR1)
	{
		c = c | (1 << b);
		b++;
	}		
	else if (siguser == SIGUSR2)
	{
		c = c | (0 << b);
		b++;
	}
	if (b == 8)
	{
		ft_putchar(c);
		c = '\0';
		b = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sighandler;
	sa.sa_flags = 0;
	ft_printf ("pid === %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
