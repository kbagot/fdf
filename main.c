/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:35:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 17:39:09 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_nb(int keycode, t_var *var)
{
	int nb;

	nb = var->i;
	if (keycode == 53)
		exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	int		**map;
	int		l;
	t_var	*var;

	l = 0;
	map = NULL;
	var = (t_var*)malloc(sizeof(t_var));
	var->mlx = NULL;
	if (argc != 2)
	{
		write(1, "Usage : ./fdf <filename> [ case_size z_size i]\n", 47);
		return (0);
	}
	map = stock_map(map, argv, l);
	if (map == NULL)
		return (0);
	var->mlx = mlx_init();
	l = find_data(argv, l);
	fdf_fill(map, l, var);
	mlx_key_hook(var->win, key_nb, var);
	mlx_loop(var->mlx);
}
