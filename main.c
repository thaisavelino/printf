/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <tavelino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:02:41 by juazouz           #+#    #+#             */
/*   Updated: 2018/12/11 19:21:25 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define TEST_ROUTINE(name,type)\
void	name(char *format, type value)\
{\
	int	retcorrect;\
	int	retactual;\
	ft_putendl("===========================");\
	ft_putendl(format);\
	ft_putstr("Correct\t|");\
	retcorrect = printf(format, value);\
	fflush(stdout);\
	ft_putendl("");\
	ft_putstr("Actual\t|");\
	retactual = ft_printf(format, value);\
	ft_putendl("");\
	ft_putendl("Return values:");\
	printf("Correct\t(%d)\nActual\t(%d)\n", retcorrect, retactual);\
	fflush(stdout);\
}

#define TEST_ROUTINE_NOARG(name)\
void	name(char *format)\
{\
	int	retcorrect;\
	int	retactual;\
	ft_putendl("===========================");\
	ft_putendl(format);\
	ft_putstr("Correct\t|");\
	retcorrect = printf(format);\
	fflush(stdout);\
	ft_putendl("");\
	ft_putstr("Actual\t|");\
	retactual = ft_printf(format);\
	ft_putendl("");\
	ft_putendl("Return values:");\
	printf("Correct\t(%d)\nActual\t(%d)\n", retcorrect, retactual);\
	fflush(stdout);\
}

int		float_info(double fnum)
{
	unsigned long	tmp;
	int				exp;
	unsigned long	mantissa;

	tmp = *(long*)&fnum;
	mantissa = (tmp & 0x0007FFFFFFFFFFFF);
	exp = (tmp & 0x7FF8000000000000) - 128;
	printf("value\t\t%lF\n", fnum);
	printf("raw\t\t%08lX\n", tmp);
	printf("exp\t\t%d\n", exp);
	printf("mantissa\t%ld\n", mantissa);
	printf("trunc ll\t%lld\n", (long long)fnum);
	printf("\n");
	return (0);
}

TEST_ROUTINE(test_string, char*)
TEST_ROUTINE(test_int, int)
TEST_ROUTINE(test_long, long)

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	// printfloat(0.000001f);
	// printfloat(1.000000f);
	// printfloat(1.000001f);
	// printfloat(1.000002f);
	// printfloat(2.000002f);
	// putfloat(1.12f, 10);
	// test_float("%.1f", 1.12f);
	// test_float("%.2f", 1.12f);
	// test_float(__DBL_MAX__);
	// test_float(__DBL_MIN__);
	// test_float(0.0F);
	// test_float(1.0F);
	// test_char("%s\t|%%\n",'c');

	// test_string("%10s","test");
	// test_string("%-10s","test");
	// test_string("%10.6s","alphabeta");
	// test_string("%-10.6s","alphabeta");
	// test_string("%s", "alphabeta");
	// test_string("%+ -#0s", "alphabeta");

	// test_int("%10d", 12);
	// test_int("%+d", 123456);
	// test_int("% +d", 123456);
	// test_int("% d", 123456);
	// test_int("% d", -123456);
	// test_int("%10u", 12);
	// test_int("%+u", 123456);
	// test_int("% +u", 123456);
	// test_int("% u", 123456);
	// test_int("% u", -1);
	// test_int("% u", 0);
	// test_int("% d", 0);
	// test_int("% u", 1);
	// test_int("% d", 1);
	// test_int("%+u", 0);
	// test_int("%+d", 0);
	// test_int("%+ u", 0);
	// test_int("%+ d", 0);
	// test_int("%.0o", 0);
	//test_int("%#.0o", 0);
	//test_int("%#.o", 0);
	//test_int("%#.0x", 0);
	//test_int("%#.x", 0);
	//test_int("%#x", 0);

	// Int precision tests
	// test_int("%.0d", 0);
	// test_int("%.d", 36);
	// test_int("%.2d", 36);
	// test_int("%.5d", 36);
	// test_int("%10.5d", 36);
	// test_int("%+010d", 36);
	// test_int("%-+010d", 36);
	// test_int("%+010x", 36);

	// Pointers tests
	test_int("%#d", -1);
	// test_int("%#d", 1);
	// test_int("%#+d", 1);
	// test_int("%#o", 1);
	// test_int("%#x", 1);
	// test_int("%#u", 1);
	// test_int("%#u", 0);
	// test_int("%#d.0", 0);
	// test_int("%#x", 0xdead);
	// test_int("%p", 0xdead);

	// Extra len tests
	test_long("%lx", 4294967296);

	// Percent sign
	// test_noarg("%%", 0xdead);
	// test_noarg("%5%");
	// test_noarg("% 05%");
	// printf("%.0%\n");
	// fflush(stdout);
	// ft_printf("%.0%\n");
	// printf("int: %ld\nlong: %ld\nlong: %ld\n", sizeof(int), sizeof(long), sizeof(long long));
	// fflush(stdout);
	// ft_printf("%5%\n");
	return (0);
}
