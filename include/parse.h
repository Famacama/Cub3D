#ifndef PARSING_H
# define PARSING_H

#include "../lib/libft/libft.h"
#include <fcntl.h>

typedef struct  s_color
{
    int R;
    int G;
    int B;
}               t_color;

typedef struct  s_dotcube
{
    unsigned int reso_h;
    unsigned int reso_w;
    // t_color         color;
}               t_dotcube;

typedef struct  s_texture
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *s;
}               t_texture;

int parsing(int argc, char **argv);

t_dotcube g_dotcube;
t_color g_color_c;
t_color g_color_f;
t_texture g_texture;
char    **g_tab;
int     g_y;
int     g_rows;
int     g_cols;
# endif