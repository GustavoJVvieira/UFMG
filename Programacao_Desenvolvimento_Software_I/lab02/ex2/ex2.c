#include <stdio.h>
#include <math.h>
int main(){
    double pi = 3.14159265358979323846;
    int contador = 0, sinal = 0;
    double meupi = 4, entrada, divisor = 1, erro;
   
    scanf("%lf", &entrada);
    
        do{
            erro = fabs(meupi - pi);
            divisor += 2;

            if( sinal == 0){

            meupi -= (4/divisor);
            contador++;
            sinal = 1;

        }else {

            meupi += (4/divisor);
            contador++;
            sinal = 0;
        }
        
    }while(erro >= entrada); 
    
    printf("%d %.15lf \n", contador, meupi);

    return 0;
}