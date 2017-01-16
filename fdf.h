/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbagot <kbagot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:35:55 by kbagot            #+#    #+#             */
/*   Updated: 2017/01/16 19:02:07 by kbagot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define IX 6
# define IY 0.8
# define XVARL 4.5
# define YVARL 2.8
# define XORIGIN 800
# define YORIGIN 100

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			i;
	int			j;
}				t_var;

typedef struct	s_line
{
	int			i;
	int			xinc;
	int			yinc;
	int			cumul;
	int			x;
	int			y;
	double		dx;
	double		dy;
}				t_line;

void			draw_line(char *line, int x1, int y1);
int				main(int argc, char **argv);
int				**stock_map(int **map, char **argv, int l);
int				find_data(char **argv, int l);
void			fdf_fill(int **map, int l, t_var *var);

#endif
