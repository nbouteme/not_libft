/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_defs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <nbouteme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 17:52:07 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/27 16:56:57 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_DEFS_H
# define KEY_DEFS_H

# ifdef __linux__
#  include <X11/keysym.h>
#  define ESCAPE XK_Escape
#  define LEFT XK_Left
#  define RIGHT XK_Right
#  define UP XK_Up
#  define DOWN XK_Down
#  define KP_ADD XK_KP_Add
#  define KP_SUBTRACT XK_KP_Subtract
# else
#  define ESCAPE 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
#  define KP_ADD 69
#  define KP_SUBTRACT 78
# endif

#endif
