#include "../includes/parsing.h"

t_pre_data	*safe_malloc(void)
{
	t_pre_data	*dt;

	dt = malloc(sizeof(t_pre_data));
	if (!dt)
		exit(1);
	return (dt);
}

int	safe_open(char *file, t_pre_data *dt)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(dt);
		exit(1);
	}
	return (fd);
}
