#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
**	Includes.
*/

// # include <stdlib.h>
// # include <stdio.h>
// # include <fcntl.h>
# include "libft.h"

/*
**	Defines.
*/

/*
**	Types.
*/

/*
%% :	percent sign
\% :	percent sign
.5 :	precision
5		minimum width (right-justified)

FLAGS
#		prepounding, 0x
0		the zero flag (fill with zeros)
+		the plus flag (if possitive)
-		Finally, the minus sign will cause the output to be left-justified. 
		This is important if you are using the width specifier and you want 
		the padding to appear at the end of the output instead of the beginning:
ex.: printff("%-+5d", 10) = '10   '	left-justified and plus sign and size 5

FORMAT
x		hexa
X		hexa upper case
l		long
lu		long unsigned
s		string
c		char
u		unsigned decimal (integer) number
x		number in hexadecimal (base 16)
d		decimal (integer) base 10
e		exponential floating-point number
f		floating-point number
i		integer (base 10)
o		octal number (base 8)

Special characters
\a	audible alert
\b	backspace
\f	form feed
\n	newline, or linefeed
\r	carriage return
\t	tab
\v	vertical tab
\\	backslash
\%  percent


https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1048379655&id=1043284385
*/

#define	PRINTF_FLAG_FLAG1 0x01
#define	PRINTF_FLAG_FLAG2 0x02
#define	PRINTF_FLAG_FLAG3 0x04

#define PRINTF_MODIFIER_SCHAR 0x01
#define PRINTF_MODIFIER_SHORT 0x02
#define PRINTF_MODIFIER_LONG 0x03
#define PRINTF_MODIFIER_LLONG 0x04

struct	s_param
{
	int		arg_index;
	int		flags;
	int		precision;
	char	modifier;
};

/*
**	ft_printf functions.
*/

int	ft_printf(const char *format, ...);

#endif
