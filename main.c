#include "includes/ps.h"



    /*
        replace  with parse

            if (ac != 2)
                return (perror("need path of valid map\n"),1);
                
        t_parse_data *data;
        data = parse(ac, av)
    */

void	ff(void)
{
	system("leaks -q cub3D ");
}
int main(int ac, char **av)
{
    t_main_s *var;
    t_parse_data *data;

    // data = parse(ac, av);
    var = init_main_var(av, NULL);
    work_of_art(var);
    mlx_loops_and_hooks(var);
}