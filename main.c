/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:35:33 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 15:48:14 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_lol(int keycode, var_list *var)
{
	int lol;

	lol = var->i;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	int			**map;
	int			l;
	var_list	*var;

	l = 0;
	map = NULL;
	var = (var_list*)malloc(sizeof(var_list));
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
	mlx_key_hook(var->win, key_lol, var);
	mlx_loop(var->mlx);
}
