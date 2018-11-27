#The % Format Specifiers
The *%* specifiers that you can use in *ANSI C* are:
Usual variable type Display

*%c* char single character
*%d* (%i) int signed integer
*%e* (%E) float or double exponential format
*%f* float or double signed decimal
*%g* (%G) float or double use %f or %e as required
*%p* pointer address stored in pointer
*%s* array of char sequence of characters
*%u* int unsigned decimal
*%x* (%X) int unsigned hex value (to see the address in hex)
*%o* int unsigned octal value (to see the address in octal)

*’l’* in front of a specifier to mean a long form of the variable typ
*’h’* to indicate a short form 
*Combining*
%ld means a long integer variable (usually four bytes) and %hd means short int. 
Notice that there is no distinction between a four-byte float and an eight-byte double. The reason is that a float is automatically converted to a double precision value when passed to printf - so the two can be treated in the same way. (In pre-ANSI all floats were converted to double when passed to a function but this is no longer true.) The only real problem that this poses is how to print the value of a pointer? The answer is that you can use %x to see the address in hex or %o to see the address in octal. Notice that the value printed is the segment offset and not the absolute address - to understand what we am going on about you need to know something about the structure of your processor.
