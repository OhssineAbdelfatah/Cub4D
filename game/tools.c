#include "../includes/ps.h"

void panic(char *s)
{
    if (s)
        perror(s);
    exit(1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double adjust_angle(double angle)
{
    if (angle > (2 * M_PI))
        return (angle - (2 * M_PI));
    if (angle < 0)
        return ((2 * M_PI) + angle);
    return angle;
}

void paintit(t_data *img, int color, int hight, int width)
{
    int i = 0;
    int j = 0;
    while (i < hight)
    {
        while (j < width)
        {
            my_mlx_pixel_put(img, j, i, color);
            j ++;
        }
        j = 0;
        i++;
    }
}