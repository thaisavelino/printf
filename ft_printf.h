/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:27:18 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/05 16:04:46 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	Includes.
*/

// # include <stdlib.h>
// # include <stdio.h>
// # include <fcntl.h>
#include <stdarg.h>
# include "libft.h"

/*
**	Defines.
*/

/*
**	Types.
*/

/*

ARGUMENT FORMAT
%[flags][width][.precision][length]specifier

%%		: percent sign
.number	: precision
number	: width

FLAGS
#		prepounding, 0x
0		the zero flag (padding with zeros)
+		the plus flag (if possitive)
-		Finally, the minus sign will cause the output to be left-justified.
		This is important if you are using the width specifier and you want
		the padding to appear at the end of the output instead of the beginning:
<space> A blank should be left before a positive number produced by a signed conversion

SPECIFIER
d / i	int
o		octal
u		unsigned int
x		hexa
X		hexa upper case
l		long
lu		long unsigned
f		decimal float
F		decimal float (uppercase?)
s		string
c		char

LEN
hh h l ll

https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1048379655&id=1043284385
*/

# define FLAG_PREPOUND	0x01
# define FLAG_ZERO		0x02
# define FLAG_PLUS		0x04
# define FLAG_MINUS		0x08
# define FLAG_SPACE		0x10

typedef struct	s_formatinfo	t_formatinfo;
typedef enum	e_specifier		t_specifier;
typedef enum	e_length		t_length;

// enum	e_flags
// {
// 	prepound = 0x01,
// 	zero = 0x02,
// 	plus = 0x04,
// 	minus = 0x08,
// 	space = 0x10
// };

#define	SPEC_COUNT 9

enum	e_specifier
{
	spec_none,
	spec_int,
	spec_uint,
	spec_octal,
	spec_hex,
	spec_hexup,
	spec_float,
	spec_str,
	spec_char,
};

enum	e_length
{
	none,
	len_char,
	len_short,
	len_long,
	len_llong
};

struct	s_formatinfo
{
	int			precision;
	int			width;
	t_length	length;
	t_specifier	specifier;
	char		flags;
};

/*
**	ft_printf functions.
*/

int			ft_printf(const char *format, ...);
void		append(char *str, size_t *pos, char c);

void		parse_flags(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_width(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_precision(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_length(t_formatinfo *info, const char *restrict format, int *format_pos);
void		parse_specifier(t_formatinfo *info, const char *restrict format, int *format_pos);

int			print_arg_type(t_formatinfo *info, va_list ap);

int			print_int(t_formatinfo *info, va_list ap);
int			print_uint(t_formatinfo *info, va_list ap);
int			print_octal(t_formatinfo *info, va_list ap);
int			print_hex(t_formatinfo *info, va_list ap);
int			print_hexup(t_formatinfo *info, va_list ap);
int			print_float(t_formatinfo *info, va_list ap);
int			print_str(t_formatinfo *info, va_list ap);
int			print_char(t_formatinfo *info, va_list ap);
int			ft_nbrlen(long long num, int base_len);

#endif
