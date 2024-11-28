#include <stdio.h>

int main (){

    int f[800], i, num = 0;

    f[0] = 0;
    f[1] = 1;

    for(i = 2; i < 800; i++){

        f[i] = f[i - 1] + f[i - 2];
    
    }

     do{
        
        scanf("%d", &num);

        if(num >= 0 && num < 800) printf("%d\n",f[num]);
        
    }while( num >= 0 && num < 800);
    


    return 0;
}