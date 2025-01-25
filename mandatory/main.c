#include "includes/ps.h"



    /*
        replace  with parse

            if (ac != 2)
                return (perror("need path of valid map\n"),1);
                
        t_parse_data *data;
        data = parse(ac, av)
        t_parse_data *data;
        data = parse(ac, av)
    */

// void	ff(void)
// {
// 	system("leaks -q cub3D ");
// }

/*  
    START GAME

*/

int main(__unused int ac, char **av)
{
    t_main_s *var;
    t_parse_data *data;

    data = parse(ac, av);
    var = init_main_var(data);
    
    work_of_art(var);
    mlx_loops_and_hooks(var);
    (void)data;
    (void)ac;
}




    // atexit(ff);
    // if (ac != 2)
    //     return (perror("need path of valid map\n"),1);
//     var = init_main_var(av);
//     work_of_art(var);
//     mlx_loops_and_hooks(var);
// }


/**
 * ONLY PARSING
 * 
*/



// int main(int ac, char **av)
// {
// 	t_parse_data *data;

// 	// atexit(ff);
//     data = parse(ac , av);
//     printf("%d\n", ft_strslen(data->map));
// 	// print_data(data);
// 	free_data(data);
//     // free_split(data->map);
//     // free(data);
//     return 0;
// }
