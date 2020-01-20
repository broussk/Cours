#include <stdio.h>

int main()
{
    float c;
    float f=0;
    printf("Fahrenheit Convertion Celsius\n");
    while(f<=300)
    {
        c = (5.0/9.0)*(f-32);
        printf("%.1f           *****     %.1f \n",f,c);
        f+=20;
        
    }
    return(0);
}

