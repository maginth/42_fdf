#include "win.h"

void			print_int(int nn)
{
	int			sgn;
	long		m;
	long		n;
	size_t		len;
	char		res[30];

	sgn = nn < 0;
	n = sgn ? 0L - nn : nn;
	m = n;
	len = 0;
	while (m)
	{
		len++;
		m /= 10;
	}
	len += sgn || n == 0;
	m = len;
	while (len--)
	{
		res[len] = '0' + (n % 10);
		n /= 10;
	}
	if (sgn)
		res[0] = '-';
	write(1, res, m);
}

int				key_pressed(unsigned int key)
{
	char		c;

	print_int(key & 0XFF);
	write(1, " ", 1);
	c = key;
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}

int				loop(void *v)
{
	unsigned int		i;

	i = 256;
	while (i--)
	{
		if (is_pressed(i))
		{
			write(1, &i, 1);
			write(1, " ", 1);
		}
	}
	return (0);
}

int				main()
{
	t_win	*win;

	win = open_win(100, 100, "get key code");
	mlx_hook(win->mlx_win, 2, 1, key_pressed, 0);
	loop_func(loop, 0);
	return (0);
}