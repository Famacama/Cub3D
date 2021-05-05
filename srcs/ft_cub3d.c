#include <stdio.h>
#include <math.h>
#include "../include/milx.h"
#include "../include/parse.h"

#define X_EVENT_KEY_PRESS        2
#define X_EVENT_KEY_EXIT        17 //Exit program key code

#define KEY_ESC            53

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md

# define KEY_Q            12
# define KEY_W            13
# define KEY_E            14
# define KEY_R            15
# define KEY_A            0
# define KEY_S            1
# define KEY_D            2

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24
#define tile_size 32
#define TO_COORD(X, Y) ((int)floor(Y) * g_dotcube.reso_w + (int)floor(X))
#define PI 3.1415926535


void init_window(void)
{
    g_mlx.mlx_ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_dotcube.reso_w, g_dotcube.reso_h, "fama");
    // g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_dotcube.reso_w, g_dotcube.reso_h);
}

void	draw_wall(int x, int y)
{
	int i;
	int j;

	x *= tile_size;
	y *= tile_size;
	i = 0;
	// printf("test f\n");
	while (i < tile_size)
	{
		// printf("test g\n");
		j = 0;
		while (j < tile_size)
		{
			// printf("test h\n");
			// printf("y + i = %d\n", (y + i));
			// printf("x + j = %d\n", (x + j));
			// printf("===%d===\n", ((y + i) * g_dotcube.reso_w + (x + j)));
			g_mlx.img.data[(y + i) * g_dotcube.reso_w + (x + j)] = 0xFFFFFF;
			// printf("test i\n");
			j++;
		}
		i++;
	}
}

void	draw_square(int x, int y)
{
	int i;
	int j;

	x *= tile_size;
	y *= tile_size;
	i = 0;
	// printf("test f\n");
	while (i < tile_size)
	{
		// printf("test g\n");
		j = 0;
		while (j < tile_size)
		{
			g_mlx.img.data[(y + i) * g_dotcube.reso_w + (x + j)] = 0x000000;
			j++;
		}
		i++;
	}
}

void	draw_player(float x, float y)
{
	int i;
	int j;

	x *= tile_size - g_position.px;
	y *= tile_size - g_position.py;
	i = 0;

	printf("x == %f and y == %f\n", x, y);
	// printf("test f\n");
	while (i < 5)
	{
		// printf("test g\n");
		j = 0;
		while (j < 5)
		{
			g_mlx.img.data[(int)(y + i) * g_dotcube.reso_w + (int)(x + j)] = 0xFFFF00;
			j++;
		}
		i++;
	}
}

void	draw_view(float x, float y)
{
	int i;
	int j;

	x *= tile_size - g_position.px - g_position.deltaX;
	y *= tile_size - g_position.py - g_position.deltaY;
	i = 0;
	// printf("test f\n");
	while (i < 3)
	{
		// printf("test g\n");
		j = 0;
		while (j < 3)
		{
			g_mlx.img.data[(int)(y + i) * g_dotcube.reso_w + (int)(x + j)] = 0xFFFFF0;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(void)
{
	int		i;
	int		j;

	float		a;
	float		b;
	i = 0;
	while (i < g_rows)                                                   
	{
		j = 0;
		while (j < g_cols)
		{
			if (g_tab[i][j] == '1')
				draw_wall(j, i);
			if (g_tab[i][j] == '0')
				draw_square(j, i);
			if (g_tab[i][j] == 'N')
			{
				a = i;
				b = j;
				draw_square(j, i);
			}
				
			j++;
		}
		i++;
	}
	draw_player(b, a);
	draw_view(b, a);
}

void draw_line(double x1, double y1, double x2, double y2)
{
	double    deltaX;
    double    deltaY;
    double    step;

	deltaX = x2 - x1;
    deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
    deltaX /= step;
    deltaY /= step;
    while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
    {
        g_mlx.img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
        x1 += deltaX;
        y1 += deltaY;
    }
}

void draw_lines(void)
{
	int        i;
    int        j;

    i = 0;
    while(i < g_cols)
	{
		draw_line(i * tile_size, 0, i * tile_size, g_dotcube.reso_h);
		i++;
	}
	draw_line(g_cols * tile_size - 1, 0, g_cols * tile_size - 1, g_dotcube.reso_h);
    j = 0;
	while (j < g_rows)
    {
        draw_line(0, j * tile_size, g_dotcube.reso_w, j * tile_size);
        j++;
    }
    draw_line(0, g_rows * tile_size - 1, g_dotcube.reso_w, g_rows * tile_size - 1);
}

int main_loop(void)
{
    draw_rectangles();
	draw_lines();
    mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
    return (0);
}

int key_check(int key_value)
{
	if (key_value == KEY_A)
	{
		// g_position.px++;
		g_position.pa -= 0.1;
		if (g_position.pa < 0)
			g_position.pa += 2 * PI;
		g_position.deltaX = cos(g_position.pa);
		g_position.deltaY = sin(g_position.pa);
	}
	else if (key_value == KEY_D)
	{
		// g_position.px--;
		g_position.pa += 0.1;
		if (g_position.pa > 0)
			g_position.pa -= 2 * PI;
		g_position.deltaX = cos(g_position.pa);
		g_position.deltaY = sin(g_position.pa);
	}
	else if (key_value == KEY_W)
	{
		// g_position.py++;
		g_position.px += g_position.deltaX;
		g_position.py += g_position.deltaY;
	}
	else if (key_value == KEY_S)
	{
		// g_position.py--;
		g_position.px -= g_position.deltaX;
		g_position.py -= g_position.deltaY;
	}
	else if (key_value == KEY_ESC)
		exit(0);
	printf("px = %f and py = %f\n", g_position.px, g_position.py);
	return (0);
}

int main(int argc, char **argv)
{
    // g_reso.reso_x = 800;
    // g_reso.reso_y = 800;
    if (argc != 2)
	{
		if (argc < 2)
			ft_putstr_fd("not enough files", 0);
		else if(argc > 2)
			ft_putstr_fd("too many aruments", 0);
	}
    parsing(argc, argv);
	g_mlx.mlx_ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_dotcube.reso_w, g_dotcube.reso_h, "fama");
    g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_dotcube.reso_w, g_dotcube.reso_h);
	g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
	
	mlx_hook(g_mlx.win, X_EVENT_KEY_PRESS, 0, &key_check, &g_mlx);
    mlx_loop_hook(g_mlx.mlx_ptr, &main_loop, &g_mlx);
	mlx_loop(g_mlx.mlx_ptr);	
}


































// int i;
	// int j;
	// int rows;
	// int cols;
	// int tile_size;

	// tile_size = 32;
	// rows = g_dotcube.reso_h / tile_size;
	// cols = g_dotcube.reso_w / tile_size;
	// printf("cols %d and rows %d\n", cols, rows);
	// printf("test a\n");
	// i = 0;
	// while (i < rows)
	// {
	// 	// printf("test b\n");
	// 	j = 0;
	// 	while (j < cols)
	// 	{

	// 		// printf("test c\n");
	// 		// printf("g_cols = %d\n", g_cols);
	// 		// printf("i = %d et j %d\n", i, j);
	// 		// printf("g_tab de j = %c\n", g_tab[i][j]);
	// 		if (g_tab[i][j] == '1')
	// 		{
	// 			// printf("test d\n");
	// 			// printf("g_tab de j = %c\n", g_tab[i][j]);
	// 			draw_rectangles(j, i);
	// 			//printf("test e\n");
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }

	
	
	
	
	
	
	
	
	
	// int wd;
	// int hd;
	// int count_x;
	// int count_y;

	
	
	// wd = g_dotcube.reso_w / 32;
	// hd = g_dotcube.reso_h / 32;
	// while (hd >= 0)
	// {
	// 	while(wd >= 0)
	// 	{
	// 		count_y = 0;
	// 		while (count_y <= 32)
	// 		{
	// 			count_x = 0;
	// 			while(count_x <= 32)
	// 			{
	// 				g_mlx.img.data[count_y * g_reso.reso_x + count_x] = 0xFF0000;
	// 				count_x++;
	// 			}
	// 			count_y++;
	// 		}
	// 		wd--;
	// 	}
	// 	hd--;
	// }
	
	
	
	
	
	
	
	// int		i;
	// int		j;
	// int a = 0; //i
	// int b = 0; //j
	// int g = 0; 
	// int h = 0;

	// i = 0;
	
	// printf("a\n");
	// while (i < g_rows)                                                   
	// {
	// 	j = 0;
	// 	printf("b\n");
	// 	while (j < g_cols)
	// 	{
	// 		printf("c\n");
	// 		printf("i = %d et j = %d\n", i, j);
	// 		printf("tab %c\n", g_tab[j][i]);
	// 		if (g_tab[i][j] == '1')
	// 		{
	// 			printf("d\n");
	// 			// i *= 32;
	// 			// j *= 32;
				
	// 			// a = 0; 
	// 			g = 0;
	// 			while (g < 32) 
	// 			{
	// 				// b = 0; 
	// 				h = 0;
	// 				while (h < 32)  
	// 				{
	// 					g_mlx.img.data[(j  + a) * g_dotcube.reso_w + i + b] = 0xFFFFFF;
	// 					//game->img.data[(y  + i) * WIDTH + x + j] = 0xFFFFFF;
	// 					h++; 
	// 				}
	// 				g++;
	// 			}
	// 		}
	// 		else
	// 		{
	// 			g = 0;
	// 			while (g < 32) 
	// 			{
	// 				// b = 0; 
	// 				h = 0;
	// 				while (h < 32)  
	// 				{
	// 					g_mlx.img.data[(j  + a) * g_dotcube.reso_w + i + b] = 0xFF0000;
	// 					//game->img.data[(y  + i) * WIDTH + x + j] = 0xFFFFFF;
	// 					h++; 
	// 					a++;
	// 				}
	// 				g++;
	// 				b++;
	// 			}
	// 		}
	// 		j++;
	// 	}
	// 	i++;
	// }
	
	// mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
	// mlx_loop(g_mlx.mlx_ptr);
	
	
	
	
	// double posX = 22, posY = 12;  //x and y start position
    // double dirX = -1, dirY = 0; //initial direction vector
    // double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    // double time = 0; //time of current frame
    // double oldTime = 0; //time of previous frame

    // screen(screenWidth, screenHeight, 0, "Raycaster");
	// g_mlx.mlx_ptr = mlx_init();
    // g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, 480, 352, "fama");
    // printf("ROWS %d -- COLS %d\n", g_rows, g_cols);
    //init_window();
    // main_loop(); 
    // mlx_loop_hook(g_mlx.mlx_ptr, &main_loop, &g_mlx);
	// g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, 480, 352);
	// g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
    // //parsing (int argc, char **argv)
    // mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
	//mlx_loop(g_mlx.mlx_ptr);
