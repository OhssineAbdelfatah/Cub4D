#include"../includes/cube.h"

int main(int ac, char **av)
{
	t_parse_data *data;

    data = parse(ac , av);
    printf("%d\n", ft_strslen(data->map));
    free_split(data->map);
    free(data);
    return 0;
}