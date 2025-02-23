/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:38:24 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 22:38:26 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_BONUS_H
# define MACROS_BONUS_H

// FOR NEW MLX
# define A 65
# define D 68
# define S 83
# define W 87
# define ESC 66
# define R_ARROW 262
# define L_ARROW 263

# define SQ_LEN 64
# define P_RADIUS 10
# define EPSILON 1e-6

typedef enum dir
{
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	UP_LEFT,
	UP_RIGHT,
	DOWN_LEFT,
	DOWN_RIGHT
}	t_direction;

#endif
