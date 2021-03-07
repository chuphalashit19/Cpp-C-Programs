
#include<stdio.h>

void ffToCC(double fahren, double *cel)
{
    *cel = (fahren-32)*5/9;
}

int main()
{
    double fahren = 28.6, cel;

    printf("\nAddress of cel = %p", &cel);

    //Call the ffToCC function, properly passing the 2 required parameters
    ffToCC(fahren, &cel);

    //Assuming fahren = 28.6, the output should report about a -1.9 celsius temperature.

    printf("\n\nFor fahrenheit %.1lf = %lf celsius\n", fahren, cel);

    return 0;
}
