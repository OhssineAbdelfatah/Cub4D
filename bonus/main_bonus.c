/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:59:11 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:59:12 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ps_bonus.h"

int	main(int ac, char **av)
{
	t_main_s		*var;
	t_parse_data	*data;

	data = parse(ac, av);
	var = init_main_var(data);
	mlx_set_cursor_mode(var->mlx, MLX_MOUSE_DISABLED);
	work_of_art(var, 1);
	mlx_loops_and_hooks(var);
	(void)ac;
}
