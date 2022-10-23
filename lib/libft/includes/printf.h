/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ivellinga <Izaakvellinga@gmail.com>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/10 17:55:58 by ivellinga     #+#    #+#                 */
/*   Updated: 2022/02/13 17:34:02 by ivellinga     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

# ifndef NO_MIN
#  define NO_MIN 0
# endif

typedef struct s_data
{
	int	i;
	int	d_zero;
	int	d_dash;
	int	d_star;
	int	d_width;
	int	d_dot;
	int	d_pre;
	int	d_hexlen;
	int	xcheck;
	int	printed;
	int	check;
	int	negative_w;
	int	negative_p;
}			t_struct;

typedef void	(*t_printfunct)(t_struct *data, va_list list);
typedef void	(*t_list_arr)(va_list list);

int				ft_printf(const char *str, ...);
void			init_struct(t_struct *data);
void			reset_struct(t_struct *data);

void			parse_all(const char *str, t_struct *data, va_list va);
void			flags(const char *str, t_struct *data);
void			width(const char *str, t_struct *data, va_list va);
void			precision(const char *str, t_struct *data, va_list va);
void			conversion(const char *str, t_struct *data, va_list va);

void			convert_char(t_struct *data, va_list va);
void			convert_string(t_struct *data, va_list va);
void			convert_int(t_struct *data, va_list va);
void			convert_uns_int(t_struct *data, va_list va);
void			convert_pointer(t_struct *data, va_list va);
void			convert_hexidecimal(t_struct *data, va_list va);
void			convert_percent(t_struct *data, va_list va);

void			zero_print(t_struct *data, int conversion, int check);
void			width_print(t_struct *data, int conv_width);
int				width_int_print(t_struct *data, int conv_width, int check);

#endif
