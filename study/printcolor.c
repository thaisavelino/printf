#include <stdio.h>
 
void color_text(int color)
{
    if(color == -1)
    {
        printf("\x1B[0;39m");
        return;
   }
   printf("\x1B[1;%dm", 30 + color);
}
 
int main()
{
    color_text(2);
    printf("Test 0123456789012345678901234567890.\n");
    return 0;
}
