/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguinin <mguinin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 13:08:54 by mguinin           #+#    #+#             */
/*   Updated: 2014/01/22 19:21:09 by mguinin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** en.wikipedia.org/wiki/Mersenne_twister#Pseudocode
*/

static unsigned int		g_mt[624];
static unsigned int		g_index_mt = 624;

void			ft_seed(int seed)
{
	unsigned int			i;

	g_index_mt = 624;
	g_mt[0] = seed;
	i = 0;
	while (++i < 624)
		g_mt[i] = 1812433253 * (g_mt[i-1] ^ (g_mt[i-1] >> 30)) + i;
}

static void		generate_number(void)
{
	int				i;
	int				k;
	int				l;
	unsigned int	y;

	i = k = 0;
	l = 397;
	while (i < 624)
	{
		k = (k + 1) & -(k != 623);
		l = (l + 1) & -(l != 623);
		y = (g_mt[i] & 0x80000000) + (g_mt[k] & 0x7fffffff);
		g_mt[i] = g_mt[l] ^ (y >> 1);
		if (y & 1)
			g_mt[i] ^= 2567483615;
		i++;
	}
}

int				ft_rand(void)
{
	unsigned int	y;

	if (g_index_mt == 624)
	{
		generate_number();
		g_index_mt = 0;
	}
	y = g_mt[g_index_mt];
	y ^= y >> 11;
	y ^= (y << 7) & 2636928640;
	y ^= (y << 15) & 4022730752;
	y ^= y >> 18;
	g_index_mt++;
	return ((int)y);
}

float			ft_frand(void)
{
	return ((float)(unsigned int)ft_rand() * (1.0 / (1L << 32)));
}
