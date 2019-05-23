/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhealitt <rhealitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:41:45 by rhealitt          #+#    #+#             */
/*   Updated: 2019/05/07 17:01:17 by rhealitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_printf
{
	char		conversion;
	int			precision;
	int			min_width;
	int			zero;
	int			plus;
	int			minus;
	int			hash;
	int			space;
	int			l;
	int			o;
	int			h;
	int			j;
	int			z;
	int			inf;
	int			nan;
}				t_printf;

int			ft_printf(const char *format, ...);
int			parse_percentage(va_list *arg, char **format);
int			print_num(va_list *arg, t_printf p);
int			print_f(va_list *arg, int char_printed, t_printf p);
int			print_d_longlong(int char_written, t_printf p, long long nb);
int			print_o_longlong(int char_written, t_printf p, long long nb);
int			print_o_unsigned(va_list *arg, int char_written, t_printf p);
int			print_u_long(int char_written, t_printf p, unsigned long long nb);
int			print_x_long(int char_written, t_printf p, unsigned long long nb);
int			width(char *str);
int			precision(char *str);
int			length(char *str, char c);
int			zero_flag(char *str, int minus);
int			plus_flag(char *str);
int			minus_flag(char *str);
int			hash_flag(char *str);
int			space_flag(char *str, int plus);
int			print_sc(va_list *arg, t_printf p);
int			print_ptr(int char_printed, va_list *arg, t_printf p);
int			print_simple_char(int char_printed, t_printf p);
int			print_space(t_printf p, long long nb);
int			print_hash(t_printf p, long long nb);
int			hash_length(t_printf p, long long nb);
int			print_plus(t_printf p, long long nb);
int			print_width(t_printf p, int written);
int			print_zero_padding(t_printf p, int char_printed);
int			print_width_minus(t_printf p, int char_printed);
int			print_precision(t_printf p, long long nb, int nb_len);

int			len_f(long double nb);
char		*decimal_f(long double nb, t_printf p, char *integer_f);
char		*integer_f(long double nb);
long double	round_ld(long double nb, t_printf p);
long double	ft_atof(char *s);
int			write_f(t_printf p, char *integer, char *decimal, long double nb);
t_printf	flag_manager_f(long double nb, t_printf p);
size_t		ft_u_len_base(unsigned long long nb, char base);
size_t		ft_u_longlong_len(unsigned long long nb);
char		*ft_str_multi_chr(char *str, char *c);
size_t		ft_longlong_len(long long int nbr);
size_t		ft_len_base(long long nb, char base);
int			ft_hex_len(unsigned long long nb);
void		ft_put_longlong_base(long long nbr, char base);
void		ft_putnchar(char c, size_t n);
void		ft_put_u_longlong_base(unsigned long long nb, char base);
size_t		ft_ptr_len_base(size_t ptr, unsigned int base);
void		ft_print_u_hex(unsigned long long nb, const char *str);

void		ft_bzero(void *s, size_t n);
void		*ft_memalloc(size_t size);
int			ft_atoi(const char *str);
void		*ft_memset(void *b, int c, size_t len);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlen(const char *str);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strnew(size_t size);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putnstr(const char *str, size_t n);

#endif
