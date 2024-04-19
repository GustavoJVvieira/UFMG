#include <stdio.h>

int main(){

    int vetor[3], maior = 0, i;
    
    for(i = 0; i < 3; i++){
        
        scanf("%d", &vetor[i]);
        
        if(vetor[i] > maior) maior = vetor[i];
        
    }
    
    printf("%d", maior);
    
    return 0;
}