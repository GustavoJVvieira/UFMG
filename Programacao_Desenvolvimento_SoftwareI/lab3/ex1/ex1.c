#include <stdio.h>

int main  (){

    int menor, maior, num;

    scanf ("%d", &menor);
    scanf("%d", &maior);

    if (menor < 1 && maior > 10000) return 0;
    while ( menor <= maior ){
        num = 0;

        for (int i = 1; i <= menor; i++){
            
            if (menor % i == 0){

                num++;

            }
        }

        if (num == 2) printf("%d\n", menor);
        
        menor++;
    }

    return 0;
}