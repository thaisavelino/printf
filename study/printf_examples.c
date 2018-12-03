#include <stdio.h>

int div(int a, int b)
{
	if(b)
		return a / b;
    else
		return 0;
}

int main()
{
    printf("display %% \n");
	printf("--- conversions --- \n");
		//  % says the type and format something must be displayed
		printf("  - %%d - signed integer value\n");
		printf("	%%d -> Printing letter 'a' will show ascii decimal %d\n", 'a');
		printf("	%%d -> Printing float number converted: %d\n", div(18, 5));
		/* If you have a double or float it will be displayed as int.
		 * The reason for this is twofold.
		 	* 1. The first difference is that an int uses two bytes to store its 
		 	* value, while a float uses four and a double uses eight. If you try 
		 	* to display a float or a double using %d then only the first 2 bytes
		 	* of the value are actually used.
			* 2. The second problem is that even if there wasn't a size
			*  difference ints, floats and doubles use a different binary 
			*  representation and %d expects the bit pattern to be a simple 
			*  signed binary integer.
		*****/
		float f10 = 12345.7890;
		printf("\n--- width and precision ---\n");
		printf("  - %%f Float number\n");
		printf("	%%8.3f 8 caractheres total, 3 digits after . = %8.3f \n", f10);
		printf("	note that will show less then 10 \n");
		printf("	%%10.3f 10 caractheres total, 2 digits after . = %10.2f \n", f10);
		printf("	note that will show more then 4");
		printf("	%%4.2f 4 caractheres total, 2 digits after . =   %4.2f \n", f10);
		printf("	%%5.3f 5 caractheres total, 3 digits after . = %5.3f \n", f10);
		printf("	%%5.3f 5 caractheres total, 3 digits after . = %5.3f \n", f10);
		printf("	%%5.3f 5 caractheres total, 3 digits after . = %5.3f \n", f10);
		printf("\n ---------------------- \n");

		int i = 40;
		float x = 839.21f;

		printf("|%%d|%%5d|%%-5d|%%5.3d|\n|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
		printf("|%%10.3f|%%10.3e|%%-10g|\n|%10.3f|%10.3e|%-10g|\n", x, x, x);
    return 0;
}
