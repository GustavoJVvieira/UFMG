#include <stdio.h>


int main (){

    float celsius;

    scanf("%f", &celsius);

    float f = ((1.8 * celsius) +32);

    printf("Valor em Fahrenheit: %0.f \n", f);
    
}
