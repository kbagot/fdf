/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:35:55 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/10 17:16:02 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>

# define ix 10
# define iy 7
# define xvarl 8
# define yvarl 12

static void	*mlx = NULL;

typedef struct	fdf_list
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		i;
	int		j;
	void	*win;
	int		xstart;
	int 	ystart;
}				var_list;

void		draw_line(char *line, int x1, int y1, void *mlx);
int			main(int argc, char **argv);
int			**stock_map(int **map, char **argv, int l);
int			find_data(char **argv, int l);
void		fdf_fill(int **map, void *mlx, int l);

#endif
