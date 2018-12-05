/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tavelino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:34:08 by tavelino          #+#    #+#             */
/*   Updated: 2018/12/03 18:53:18 by tavelino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int sum(int, ...);

int main () {
	   printf("Sum of 15 and 56 = %d\n",  sum(2, 15, 56));
	      return 0;
}

int sum(int num_args, ...) {
	int val = 0;
	va_list ap;
	int i;

	va_start(ap, num_args);
	for(i = 0; i < num_args; i++) {
		val += va_arg(ap, int);
	}
	va_end(ap);
					   
	return val;
}
