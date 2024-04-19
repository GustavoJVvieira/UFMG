#include <stdio.h>

int main (){

    int x,y,i,j;

    scanf("%d", &x);

    int aeds[x]; 

     for (i = 0; i< x; i++){
        scanf("%d", &aeds[i]);
     }

    scanf("%d", &y);

    int calc[y];

    for (i = 0; i< y; i++){

        scanf("%d", &calc[i]);
     }


    for (i = 0; i < x; i++){
        for(j = 0; j < y; j++){

            if(aeds[i] == calc[j]) printf("%d\n", aeds[i]);
        }
    }



    return 0;
}