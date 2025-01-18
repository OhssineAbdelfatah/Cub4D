# include "../includes/ps.h"

int ft_dstr_len(char **av)
{
    int i = 0;

    if (!av)
        return 0;
    while (av[i])
        i++;
    return (i);
}


void fill_map(char **av,t_main_s *var)
{
    int fd;
    int maplen;
    char *line;
    int i = 0;

    maplen = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("path of the file is invalid !");
       return;
    }
    line  = get_next_line(fd);
    while (line)
    {
        if (maplen == 0)
            maplen++;
        free(line);
        line = get_next_line(fd);
        maplen ++;
    }
    close (fd);
    var->map = (char **)malloc(sizeof (char *) * (maplen + 1));
    if (!var->map)
        perror ("malloc failed !\n");
    fd = open(av[1], O_RDONLY);
    while (i < maplen)
    {
        var->map[i] = get_next_line(fd);
        i++;
    }
    var->map[i] = NULL;
    var->map_hight = ft_dstr_len(var->map);
    var->map_width = ft_strlen(var->map[0]) - 1;

    // var->map_hight = 0;
    // var->map_width = 0;
} 

void	ff(void)
{
	system("leaks -q cub3D ");
}

    /*
        replace  with parse

            if (ac != 2)
                return (perror("need path of valid map\n"),1);
                
        t_parse_data *data;
        data = parse(ac, av)
    */

// int main(int ac, char **av)
// {
//     t_main_s *var;
//     // atexit(ff);
//     if (ac != 2)
//         return (perror("need path of valid map\n"),1);
//     var = init_main_var(av);
//     work_of_art(var);
//     mlx_loops_and_hooks(var);
// }