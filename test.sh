make &&
gcc -Wall -Werror -Wextra main.c libftprintf.a -I libft -I includes/ -g &&
./a.out | cat -e
