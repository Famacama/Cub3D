#include "../include/parse.h"
#include "../utils/get_next_line/get_next_line.h"

int g_y;

void go_to_next_value(char *line)
{
	while ((((line)[g_y] > '9') || ((line)[g_y] < '0') || 
	((line)[g_y] == ' ')) && (line)[g_y])		
		g_y++;
}

int find_next_value(char *line)
{
	int n;

	n = 0;
	
	go_to_next_value(line);
	while (((line)[g_y] <= '9') && ((line)[g_y] >= '0') && ((line)[g_y]))
	{
		n *= 10;
		n += (line)[g_y] - 48;
		g_y++;
	}
	return (n);
}

void add_value_to_C_F_R(char *line)
{
    if (line[g_y] == 'R')
    {
        g_dotcube.reso_w = find_next_value(line);
		g_dotcube.reso_h = find_next_value(line);
    }
	if (line[g_y] == 'C')
    {
        g_color_c.R = find_next_value(line);
		g_color_c.G = find_next_value(line);
		g_color_c.B = find_next_value(line);
    }
	if (line[g_y] == 'F')
    {
        g_color_f.R = find_next_value(line);
		g_color_f.G = find_next_value(line);
		g_color_f.B = find_next_value(line);
    }
}





void add_value_texture(char *line)
{
	g_y++;
	if (line[g_y] == 'O' && line[g_y - 1] == 'N')
		g_texture.no = ft_substr(line, 3, (ft_strlen(line) - 4)); //Je malloc ici
	else if (line[g_y] == 'O' && line[g_y - 1] == 'S')
		g_texture.so = ft_substr(line, 3, (ft_strlen(line) - 4)); //Je malloc ici
	else if (line[g_y] == 'E')
		g_texture.we = ft_substr(line, 3, (ft_strlen(line) - 4)); //Je malloc ici
	else if (line[g_y] == 'A')
		g_texture.ea = ft_substr(line, 3, (ft_strlen(line) - 4)); //Je malloc ici
	else if ((line[g_y] == ' ') && (line[g_y - 1] == 'S'))
		g_texture.s = ft_substr(line, 2, (ft_strlen(line) - 4)); //Je malloc ici
}

void count_len_map(void)
{
	int i;
    int j;

	i = 0;
    while (g_tab[i])
    {
        j = 0;
        while (g_tab[i][j])
            j++;
        i++;
    }
	g_rows = i;
	g_cols = j;
}

void add_value_map(char *line, int fd)
{
	int r;
	int o;
	char *src;

	o = 1;
	src = "";
	src = ft_strjoin(src, line);
	src = ft_strjoin(src, "\n");
	while ((r = get_next_line(fd, &line)) || (o == 1))
	{
		src = ft_strjoin(src, line);
		src = ft_strjoin(src, "\n");
		if (r == 0)
		{
			g_tab = ft_split(src, '\n');
			o = 0;
		}
	}
	count_len_map();
}

void dotcube_value(int fd)
{
    int r;
    char *line;
	int o;
	line = NULL;
	
	o = 1;
    while ((r = get_next_line(fd, &line)) || (o == 1))
    {
        g_y = 0;
        if (line[g_y] == 'C' || line[g_y] == 'F' || line[g_y] == 'R')
			add_value_to_C_F_R(line);
		else if (line[g_y] == 'N'  || line[g_y] == 'S' || line[g_y] == 'W' || line[g_y] == 'E')
			add_value_texture(line);
		else if (ft_strchr(line, '1') != NULL)
			add_value_map(line, fd);
		if (r == 0)
			o = 0;
    }
}

int parsing(int argc, char **argv)
{
    int fd;

    if (argc != 2)
	{
		if (argc < 2)
			ft_putstr_fd("not enough files", 0);
		else if(argc > 2)
			ft_putstr_fd("too many aruments", 0);
	}
    fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error, cannot open file\n", 0);
		return (0);
	}
	dotcube_value(fd);
	// printf("H = %d\n and W = %d\n", g_dotcube.reso_h, g_dotcube.reso_w);
	// printf("C : r = %d -- g = %d -- b = %d\n", g_color_c.R, g_color_c.G, g_color_c.B);
	// printf("F : r = %d -- g = %d -- b = %d\n", g_color_f.R, g_color_f.G, g_color_f.B);
	// printf("no -- %s\n", g_texture.no);
	// printf("so -- %s\n", g_texture.so);
	// printf("we -- %s\n", g_texture.we);
	// printf("ea -- %s\n", g_texture.ea);
	// printf("s -- %s\n", g_texture.s);
    return (0);
}