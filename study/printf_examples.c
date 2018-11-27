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
		printf();
    return 0;
}
