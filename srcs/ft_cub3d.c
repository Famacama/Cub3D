#include <stdio.h>
#include "../include/milx.h"
#include "../include/parse.h"

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

void init_window(void)
{
    g_mlx.mlx_ptr = mlx_init();
    g_mlx.win = mlx_new_window(g_mlx.mlx_ptr, g_dotcube.reso_w, g_dotcube.reso_h, "fama");
    g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, g_dotcube.reso_w, g_dotcube.reso_h);
}

void	draw_rectangle(int x, int y)
{
	int i;
	int j;
	int tile_size;

	tile_size = 32;
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

void	draw_rectangles(void)
{
	int		i;
	int		j;

	i = 0;
	while (i < g_rows)                                                   
	{
		j = 0;
		while (j < g_cols)
		{
			if (g_tab[i][j] == 1)
				draw_rectangle(j, i);
			j++;
		}
		i++;
	}
}

int main_loop(void)
{
    draw_rectangles();
    mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
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
	
	int i;
	int j;
	int rows;
	int cols;
	int tile_size;

	tile_size = 32;
	rows = g_dotcube.reso_h / tile_size;
	cols = g_dotcube.reso_w / tile_size;
	printf("cols %d and rows %d\n", cols, rows);
	printf("test a\n");
	i = 0;
	while (i < rows)
	{
		// printf("test b\n");
		j = 0;
		while (j < cols)
		{

			// printf("test c\n");
			// printf("g_cols = %d\n", g_cols);
			// printf("i = %d et j %d\n", i, j);
			// printf("g_tab de j = %c\n", g_tab[i][j]);
			if (g_tab[i][j] == '1')
			{
				// printf("test d\n");
				// printf("g_tab de j = %c\n", g_tab[i][j]);
				draw_rectangle(j, i);
				// printf("test e\n");
			}
			j++;
		}
		i++;
	}

	
	
	
	
	
	
	
	
	
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
	
	mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
	mlx_loop(g_mlx.mlx_ptr);
	
	
	
	
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
    //mlx_loop_hook(g_mlx.mlx_ptr, &main_loop, &g_mlx);
	// g_mlx.img.img_ptr = mlx_new_image(g_mlx.mlx_ptr, 480, 352);
	// g_mlx.img.data = (int *)mlx_get_data_addr(g_mlx.img.img_ptr, &g_mlx.img.bpp, &g_mlx.img.size_l, &g_mlx.img.endian);
    // //parsing (int argc, char **argv)
    // mlx_put_image_to_window(g_mlx.mlx_ptr, g_mlx.win, g_mlx.img.img_ptr, 0, 0);
	//mlx_loop(g_mlx.mlx_ptr);

}