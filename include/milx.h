/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   milx.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famacama <famacama@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:37:03 by famacama          #+#    #+#             */
/*   Updated: 2020/12/09 20:58:41 by famacama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MILX_H
# define MILX_H

// #include "parse.h"
#include "../lib/libft/libft.h"
//#include "../lib/minilibx_mms/mlx.h"
#include "../lib/minilibx_opengl/mlx.h"
#include "ggl_mlx_define.h"


typedef struct  s_resolution
{
    //resolution de lecrant
    unsigned int reso_x;
    unsigned int reso_y;
}               t_resolution;

typedef struct	s_img
{
    void        *img_ptr;
    int         *data;
    int         size_l;
    int         bpp;
    int         endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_img		img;
}				t_mlx;

typedef struct  s_position
{
    float px;
    float py;
    float pa; //player angle
    float deltaX; //
    float deltaY; //
}               t_position;

t_img   g_img;
t_mlx   g_mlx;
t_position   g_position;
t_resolution    g_reso;

int	close_program(void *param);

# endif
