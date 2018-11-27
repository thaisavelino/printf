# printf

This project challange is recoding the libc's printf function.
This function will be called ft_printf and will be part of my [libft](https://github.com/thaisavelino/Libft) and will be used in all of my future projects.

### Rules 

* The project must be written in accordance with the Norm.
* In no way can your program quit in an unexpected manner (Segmentation fault, bus error, double free, etc).
* Your must submit a Makefile which will compile a libft printf.a. This lib will be
linked to the school testing main to give you your results.
* You are just allowed to use the following libc functions:
  * write
  * malloc
  * free
  * exit
  * The functions of man 3 *stdarg*

### Mandatory part

* Your function will be called ft_printf and will be prototyped similarly to printf.
* You won’t do the buffer management in the printf function.
* You have to manage the following conversions: **csp**
* You have to manage the following conversions: **diouxX** with the following flags: **hh**,
**h**, **l** and **ll**.
* You have to manage the following conversion: **f** with the following flags: **l** and **L**.
* You must manage **%%**
* You must manage the flags **#0-+** and **space**
* You must manage the minimum **field-width**
* You must manage the **precision**
